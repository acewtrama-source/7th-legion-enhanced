/* PAGED SAVE/LOAD SLOTS for the ENHANCED ruleset (ruleset=1). Replaces the two slot menus:
 *   load menu 0x40e1d0 (called from 0x40dc2b main menu, 0x43fb1b in-game), save menu 0x40e340 (called from 0x43fafd).
 * Original: 10 slot buttons (ids 0..9) + Back (id 600); chosen slot -> load: word [0x835034] (consumed as slot arg of the loader 0x433a60 and
 * 0x435510 preview reader) / save: SaveGame 0x4321f0(slot, editedText 0x475fc0(id)). All of those only use the slot number in sprintf("data//SAVE%d.SAV"),
 * so any slot number works. Here: page p shows slots p*10..p*10+9 (button id i -> slot p*10+i), extra buttons 601 "<< PAGE n-1" / 602 "PAGE n+1 >>".
 * Load: pages 0..lastPageWithAFile. Save: same, plus one new page once the last page is completely full ("11th slot appears when the 10th is taken").
 * Menu toolkit (all cdecl): 0x4752b0/0x475700 begin, 0x4758b0 button(id,type,x,y,w,h,text) [type 0 label-button, 5 edit field; x=-1 centres; text is
 * upper-cased IN PLACE and must stay valid until 0x4757c0 end], 0x476aa0 poll (==1: click, id in [0x59f890]; hover id [0x5927a4]), 0x476160 focus/sound. */
typedef signed short s16; typedef unsigned short u16; typedef unsigned char u8; typedef unsigned int u32; typedef int s32;
#define S16(a) (*(volatile s16*)(u32)(a))
extern u8 g_ruleset; void ruleset_init(void); void teams_save(int slot); void teams_path(char*,int);

typedef void (*FV)(void);
typedef int (*FBTN)(s32,s32,s32,s32,s32,s32,const char*);
typedef int (*FSP)(char*,const char*,...);
#ifndef UI_MOCK
#define M_BEGIN1 ((FV)0x4752b0)
#define M_BEGIN2 ((FV)0x475700)
#define M_END    ((FV)0x4757c0)
#define M_BTN    ((FBTN)0x4758b0)
#define M_POLL   ((int(*)(void))0x476aa0)
#define M_FOCUS  ((void(*)(s32))0x476160)
#define M_TEXT   ((const char*(*)(s32))0x475fc0)
#define M_WIDTH  ((int(*)(const char*))0x4941f0)
#define G_SPRINTF ((FSP)0x49c430)
#define G_FOPEN  ((void*(*)(const char*,const char*))0x49c410)
#define G_FREAD  ((int(*)(void*,s32,s32,void*))0x49c980)
#define G_FCLOSE ((int(*)(void*))0x49c330)
#define SAVEGAME ((void(*)(s32,const char*))0x4321f0)
#define ORIG_LOAD ((FV)0x40e1d0)
#define ORIG_SAVE ((FV)0x40e340)
typedef int (__attribute__((stdcall)) *FDEL)(const char*);
#define G_DELETE (*(FDEL*)0xac4550)  /* IAT: DeleteFileA */
#endif
#define MAXPAGES 100
#define ID_BACK 600
#define ID_PREV 601
#define ID_NEXT 602
#define ID_DEL  100   /* 100+i = delete button of row i */

static s32 s_page;                 /* remembered between menu openings (reset at game start = 0) */
static char nm[10][48];            /* slot labels (button text is edited in place for save) */
static s16 ex[10];
static char prevT[24], nextT[24], delT[10][8], cl1[40], cl2[64], yesT[8], noT[8];

static void cpy(char*d,const char*s){ while((*d++=*s++)); }

/* modal Yes/No built from the same toolkit; labels are plain buttons whose clicks are ignored. returns 1 = yes */
static int confirm_delete(const char*name){
  int j=0; cpy(cl1,"ARE YOU SURE YOU WANT TO DELETE"); while(name[j] && j<40){ cl2[j]=name[j]; j++; } cl2[j++]='?'; cl2[j]=0;
  cpy(yesT,"YES"); cpy(noT,"NO");
  M_BEGIN1(); M_BEGIN2();
  M_BTN(10,0,-1,0xb0,200,0x10,cl1); M_BTN(11,0,-1,0xd0,200,0x10,cl2);
  M_BTN(1,0,-1,0x100,200,0x10,yesT); M_BTN(0,0,-1,0x120,200,0x10,noT);
  M_FOCUS(-1);
  for(;;){ int r=(s16)M_POLL(); if(r==1){ s32 id=S16(0x59f890); if(id==1||id==0){ M_END(); return id; } } }
}

static int slot_exists(s32 slot){
  char path[40]; G_SPRINTF(path,(const char*)0x4b6994 /*"data\\save%d.sav"*/,slot);
  void*f=G_FOPEN(path,(const char*)0x4ae5e4 /*"rb"*/); if(!f) return 0; G_FCLOSE(f); return 1; }

/* pages: returns number of selectable pages (>=1) */
static s32 page_count(int saving){
  s32 last=0, p, i, full=0;
  for(p=0;p<MAXPAGES;p++){ int any=0,cnt=0; for(i=0;i<10;i++) if(slot_exists(p*10+i)){any=1;cnt++;} if(any){ last=p; full=(cnt==10); } }
  s32 n=last+1; if(saving && full && n<MAXPAGES) n++; return n; }

static void fmt_page(char*d,const char*pre,s32 n,const char*post){
  char t[12]; int k=0,j=0; if(!n){t[k++]='0';} while(n){ t[k++]='0'+n%10; n/=10; }
  while(*pre) d[j++]=*pre++; while(k) d[j++]=t[--k]; while(*post) d[j++]=*post++; d[j]=0; }

static void menu(int saving){
  for(;;){
    s32 pages=page_count(saving); if(s_page>=pages) s_page=pages-1; if(s_page<0) s_page=0;
    M_BEGIN1(); M_BEGIN2();
    for(s32 i=0;i<10;i++){
      char path[40]; ex[i]=0; nm[i][0]=0;
      G_SPRINTF(nm[i], saving? (const char*)0x4b69a4 /*"..Empty.."*/ : (const char*)0x864410, 0);
      G_SPRINTF(path,(const char*)0x4b6994,s_page*10+i);
      void*f=G_FOPEN(path,(const char*)0x4ae5e4);
      if(f){ G_FREAD(nm[i],1,0x14,f); G_FCLOSE(f); nm[i][0x14]=0; ex[i]=1; }
    }
    for(s32 i=0;i<10;i++){
      if(saving) M_BTN(i,5,0x4b,0xa0+0x1b*i,0x1ea,0x16,nm[i]);
      else       M_BTN(i,0,-1,0xa0+0x1b*i,200,0x10,nm[i]);
    }
    for(s32 i=0;i<10;i++) if(ex[i]){
      cpy(delT[i],"DELETE"); int w=(s16)M_WIDTH(delT[i]);
      M_BTN(ID_DEL+i,0, saving? 0x280-6-w : 0x1ae, 0xa0+0x1b*i, 60,0x10,delT[i]);
    }
    M_BTN(ID_BACK,0,-1,0x1c2,200,saving?0x16:0x10,(const char*)0x8644b0);
    if(s_page>0){ fmt_page(prevT,"<< PAGE ",s_page,""); M_BTN(ID_PREV,0,0x20,0x1c2,200,0x10,prevT); }
    if(s_page+1<pages){ fmt_page(nextT,"PAGE ",s_page+2," >>"); int w=M_WIDTH(nextT); w=(s16)w; M_BTN(ID_NEXT,0,0x280-0x20-w,0x1c2,200,0x10,nextT); }
    M_FOCUS(-1);
    s32 sel=-1, hl=-1;
    while(sel==-1){
      int r=(s16)M_POLL();
      if(r==1) sel=S16(0x59f890);
      else if(!saving){ s32 h=S16(0x5927a4); if(h!=-1 && h<100 && h!=hl){ hl=h; M_FOCUS(900);} }
    }
    if(sel>=ID_DEL && sel<ID_DEL+10){
      s32 i=sel-ID_DEL; char nmcopy[48]; cpy(nmcopy,nm[i]); M_END();
      if(confirm_delete(nmcopy)){ char path[40]; G_SPRINTF(path,(const char*)0x4b826c /*"data//SAVE%d.SAV"*/,s_page*10+i); G_DELETE(path); teams_path(path,s_page*10+i); G_DELETE(path); }
      continue; }
    if(sel==ID_PREV){ M_END(); s_page--; continue; }
    if(sel==ID_NEXT){ M_END(); s_page++; continue; }
    if(saving){ if(sel>=0 && sel<10){ const char*t=M_TEXT(sel); SAVEGAME(s_page*10+sel,t); teams_save(s_page*10+sel); } }
    else if(sel>=0 && sel<10 && ex[sel]) S16(0x835034)=(s16)(s_page*10+sel);
    M_END();
    return;
  }
}

void load_menu_dispatch(void){ ruleset_init(); if(g_ruleset) menu(0); else ORIG_LOAD(); }
void save_menu_dispatch(void){ ruleset_init(); if(g_ruleset) menu(1); else ORIG_SAVE(); }
