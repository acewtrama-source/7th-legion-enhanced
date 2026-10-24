/* TEAMS for the ENHANCED ruleset (ruleset=1). Players p=1..6 = lobby rows 0..5 (colour = player: Blue Red Green Yellow Black White).
 * g_team[p]: 0 = no team (free for all), 1..3 = team. allied(a,b) = a==b, or (teams on && same nonzero team).
 * With ruleset=0 or no teams chosen, allied(a,b) == (a==b), i.e. every hook below behaves exactly like the original compare.
 * Lockstep: g_team is computed on every peer from the host-synced lobby buttons (ids 0x69+r), so all peers agree.
 * HOOKS (site: original -> skip-if-allied target / continue target):
 *  H1 0x4556a4 idle auto-acquire (0x454d20)  mov ax,[ebp]; cmp [esi+67fe10],ax; je   -> 0x45585d / 0x4556b5
 *  H2 0x44f4f3 fire-on-move scan (0x44e8d0)   cmp ax,cx; je                         -> 0x44f54b / 0x44f4f8
 *  H3 0x45a6ce gun/supergun target scan        mov eax,[esi+805df0]; cmp ecx,eax; je  -> 0x45a754 / 0x45a6d8
 *  H4 0x45a954 gun current-target check        mov ecx,[esi+805df0]; cmp eax,ecx; je  -> 0x45af86 / 0x45a962
 *  H5 0x46898d AI enemy candidates (0x468920)  cmp edx,[5bcd74]; je                 -> 0x4689f4 / 0x468995
 *  H6 0x46ad47 AI pick targets (0x46ad10)      cmp [5bcd74],ecx; je                 -> 0x46ad5e / 0x46ad4f
 *  H7 0x46adb0 AI pick targets (0x46ad10)      cmp [5bcd74],eax; je                 -> 0x46ae37 / 0x46adb8
 *  H8 0x4686e3 AI friendly/enemy strength      mov ax,[esp+12]; cmp [esp+18],ax; je -> 0x468708 (friendly) / 0x4686ef
 *  H9 0x44d6e0 AI card target player (0x44d680) mov edx,[5bcd74]; cmp edx,eax; je    -> 0x44d869 / 0x44d6ee
 *  H10 0x41c4f4 win check: others' buildings/units  cmp ebx,ecx; je; cmp [edx+85e7d0],si -> 0x41c516 / (cmp; 0x41c4ff)
 *  H11 0x41c554 win check: other ents (mode 3)      cmp ax,[668ccc]; je                -> 0x41c563 / 0x41c55d
 * SAVES: teams live in a companion file data//SAVE<n>.TMS ("TMS1", on, team[8]) written after SaveGame 0x4321f0 (src/ui/saves.c) and
 *   read after every LoadGame 0x433a60(slot) call (5 call sites 0x40f4b2 0x40ff65 0x416941 0x416ce9 0x41cf21 -> load_game_hook). No file => no teams.
 * UNIT CAP (H12 0x424caf): CreateUnit caps owner units at 180/N (AI: Difficulty*8+8), but with one human every owner may use ANY of the
 *   178 ENT slots, so bots can fill the table and the human's factories finish units that never spawn (not charged). ruleset=1: every
 *   cap is also limited to 178/N so the table cannot run out.
 * Not covered yet: shared vision (fog), mines, radar colours, AI revenge on ally splash. */
typedef unsigned short u16; typedef short s16; typedef unsigned int u32; typedef unsigned char u8;
extern u8 g_ruleset; void ruleset_init(void);
u8 g_team[8]; u8 g_teams_on; int g_team_tmp;
int allied(int a,int b){
  a=(s16)a; b=(s16)b;
  if(a==b) return 1;
  if(!g_teams_on || !g_ruleset) return 0;
  if(a<1||a>6||b<1||b>6) return 0;
  return g_team[a]!=0 && g_team[a]==g_team[b];
}
typedef void*(*FOPEN)(const char*,const char*); typedef int(*FRW)(void*,int,int,void*); typedef int(*FSP)(char*,const char*,...);
#define G_FOPEN ((FOPEN)0x49c410)
#define G_FREAD ((FRW)0x49c980)
#define G_FWRITE ((FRW)0x49d090)
#define G_FCLOSE ((int(*)(void*))0x49c330)
#define G_SPRINTF ((FSP)0x49c430)
static const char k_tms_fmt[]="data//SAVE%d.TMS";
void teams_path(char *buf,int slot){ G_SPRINTF(buf,k_tms_fmt,slot); }
void teams_save(int slot){                   /* after SaveGame; always writes (on=0 => free for all) */
  char path[40], b[13]; teams_path(path,slot);
  void *f=G_FOPEN(path,(const char*)0x4aeca0 /*"wb"*/); if(!f) return;
  b[0]='T'; b[1]='M'; b[2]='S'; b[3]='1'; b[4]=g_teams_on; for(int i=0;i<8;i++) b[5+i]=g_team[i];
  G_FWRITE(b,1,13,f); G_FCLOSE(f);
}
void teams_clear(void);
static void teams_load(int slot){
  char path[40], b[13]; teams_clear(); teams_path(path,slot);
  void *f=G_FOPEN(path,(const char*)0x4ae5e4 /*"rb"*/); if(!f) return;
  int n=G_FREAD(b,1,13,f); G_FCLOSE(f);
  if(n!=13 || b[0]!='T'||b[1]!='M'||b[2]!='S'||b[3]!='1') return;
  for(int i=0;i<8;i++){ u8 t=(u8)b[5+i]; g_team[i]= t<=3 ? t:0; }
  g_teams_on = b[4]?1:0;
}
int load_game_hook(int slot){ int r=((int(*)(int))0x433a60)(slot); teams_load((s16)slot); return r; }
int unit_cap(int cap){                       /* H12 */
  ruleset_init();
  if(!g_ruleset) return cap;
  int n=*(volatile s16*)0x834f88; if(n<1) n=1;
  int fair=178/n; return cap<fair ? cap : fair;
}
void teams_clear(void){ g_teams_on=0; for(int i=0;i<8;i++) g_team[i]=0; }

/* ---- lobby ---- */
#define EN(id,v)  ((void(*)(int,int))0x475be0)((id),(v))
#define SETV(id,v) ((void(*)(int,int))0x475cd0)((id),(v))
#define GETV(id)  ((s16)((int(*)(int))0x476010)((id)))
#define TEAMBTN 0x69
typedef void (*BTN)(int,int,int,int,int,int,char*);
static char k_team_txt[]="No Team|Team 1|Team 2|Team 3";
/* redirect of `call 0x4758b0` at 0x440720 (creates the 'Options...' header, after all player rows exist) */
void lobby_opts_btn(int id,int type,int x,int y,int w,int h,char *t){
  ruleset_init();
  if(g_ruleset){
    int edit = *(volatile s16*)0x4aee00==1 || *(volatile u32*)0x719fa4==1;
    /* team button at its first position (x 0xa0); faction buttons (ids 0x32..0x37, created at x 0xf0) move right so the
       widest team label ("NO TEAM", measured with the toolkit's text width 0x4941f0) fits in front of them. */
    static char k_wide[]="NO TEAM";
    int tx=0xa0, fx=tx+(s16)((int(*)(const char*))0x4941f0)(k_wide)+14;
    for(int r=0;r<6;r++){ ((BTN)0x4758b0)(TEAMBTN+r,7,tx,0x94+r*0x16,0x40,0x10,k_team_txt); EN(TEAMBTN+r,edit); }
    for(int i=0;i<50;i++){ u32 b=0x592bb0u+(u32)i*0x3c0; s16 id=*(volatile s16*)(b+2);
      if(*(volatile s16*)b!=-1 && id>=0x32 && id<0x38 && *(volatile s16*)(b+4)<fx) *(volatile s16*)(b+4)=(s16)fx; }
  }
  ((BTN)0x4758b0)(id,type,x,y,w,h,t);
}
/* called from lobby_pack_ai (src/ui/lobby.c) after AI rows are packed; ai_rows_old[k] = original row of packed AI k */
void teams_from_lobby(void){
  teams_clear();
  if(!g_ruleset) return;
  for(int r=0;r<6;r++){ int t=GETV(TEAMBTN+r); if(t<0||t>3) t=0; g_team[r+1]=(u8)t; if(t) g_teams_on=1; }
}
/* main-menu Load (redirect at 0x40dc2b): a loaded save has no team data -> free for all */
void load_menu_dispatch(void);
void load_menu_main(void){ teams_clear(); load_menu_dispatch(); }

/* ---- hook stubs: CHK(a,b) leaves ZF clear (jne) when allied; all registers preserved ---- */
#define CHK(a,b) " pushal\n push " b "\n push " a "\n call allied\n add $8,%esp\n mov %eax,g_team_tmp\n popal\n cmpl $0,g_team_tmp\n"
#define GO(x) " push $" #x "\n ret\n"
__asm__(
".globl tm_h1\ntm_h1:\n mov 0(%ebp),%ax\n pushal\n movswl %ax,%eax\n movswl 0x67fe10(%esi),%ecx\n push %ecx\n push %eax\n call allied\n add $8,%esp\n mov %eax,g_team_tmp\n popal\n cmpl $0,g_team_tmp\n jne 1f\n" GO(0x4556b5) "1:" GO(0x45585d)
".globl tm_h2\ntm_h2:\n pushal\n movswl %ax,%eax\n movswl %cx,%ecx\n push %ecx\n push %eax\n call allied\n add $8,%esp\n mov %eax,g_team_tmp\n popal\n cmpl $0,g_team_tmp\n jne 1f\n" GO(0x44f4f8) "1:" GO(0x44f54b)
".globl tm_h3\ntm_h3:\n mov 0x805df0(%esi),%eax\n" CHK("%ecx","%eax") " jne 1f\n" GO(0x45a6d8) "1:" GO(0x45a754)
".globl tm_h4\ntm_h4:\n mov 0x805df0(%esi),%ecx\n" CHK("%eax","%ecx") " jne 1f\n" GO(0x45a962) "1:" GO(0x45af86)
".globl tm_h5\ntm_h5:\n" CHK("%edx","0x5bcd74") " jne 1f\n" GO(0x468995) "1:" GO(0x4689f4)
".globl tm_h6\ntm_h6:\n" CHK("%ecx","0x5bcd74") " jne 1f\n" GO(0x46ad4f) "1:" GO(0x46ad5e)
".globl tm_h7\ntm_h7:\n" CHK("%eax","0x5bcd74") " jne 1f\n" GO(0x46adb8) "1:" GO(0x46ae37)
".globl tm_h8\ntm_h8:\n mov 0x12(%esp),%ax\n pushal\n movswl 0x32(%esp),%ecx\n movswl 0x38(%esp),%edx\n push %edx\n push %ecx\n call allied\n add $8,%esp\n mov %eax,g_team_tmp\n popal\n cmpl $0,g_team_tmp\n jne 1f\n" GO(0x4686ef) "1:" GO(0x468708)
".globl tm_h9\ntm_h9:\n mov 0x5bcd74,%edx\n" CHK("%edx","%eax") " jne 1f\n" GO(0x44d6ee) "1:" GO(0x44d869)
".globl tm_h10\ntm_h10:\n" CHK("%ebx","%ecx") " jne 1f\n cmp %si,0x85e7d0(%edx)\n push $0x41c4ff\n ret\n1:" GO(0x41c516)
".globl tm_h12\ntm_h12:\n pushal\n movswl %ax,%eax\n push %eax\n call unit_cap\n add $4,%esp\n mov %eax,g_team_tmp\n popal\n mov g_team_tmp,%eax\n movswl %si,%edx\n add %edx,%edx\n cmp %ax,0x804700(%edx)\n push $0x424cbb\n ret\n"
".globl tm_h11\ntm_h11:\n pushal\n movswl %ax,%eax\n movswl 0x668ccc,%ecx\n push %ecx\n push %eax\n call allied\n add $8,%esp\n mov %eax,g_team_tmp\n popal\n cmpl $0,g_team_tmp\n jne 1f\n" GO(0x41c55d) "1:" GO(0x41c563)
);
