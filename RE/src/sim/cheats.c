/* DEV CHEATS typed in chat (ENHANCED ruleset only). Applied in ExecuteCommands 0x445930, chat case (kind 0x65, 0x445fff), i.e. at the
 * same lockstep point on every peer, for the SENDER (record byte +0x21 = player, set from 0x668ccc by the chat poster 0x4657c6).
 * Randomness: own xorshift seeded from the game tick 0x6df3b0, the sender and a use counter => identical on all peers; the game's
 * own RNGs (0x90a27c table, CRT rand) are not touched.
 *  "cheese steak khaos" : credits 0x834a00[p] += 10000.
 *  "khaos car"  : free unit of the sender's faction (0x6df140[p]: 0 7th Legion, 1 Chosen) next to their HQ (building type 0).
 *                 Rosters = the AI's per-side build lists (0x4c4260 side 0, 0x4c4210 side 1). Pick weight = 60000/cost (UnitTypeTable
 *                 +0xc), so an 8000 unit is 16x rarer than a 500 one. Rank (ENT +0xae, 0..4): 1 50%, 2 30%, 3 13%, 4 7%; xp +0xb0 set to
 *                 the threshold (0x4af820), and each rank adds +2 max hp like a real promotion (0x42cb46), hp full.
 *                 CreateUnit 0x424c20(type,p,x,y,0) enforces the unit cap: at cap nothing happens. Position: 0x4245c0(hq, UnitType+4).
 *  "khaos box"  : crate (effect type 0x1b) next to the HQ, content from the game's crate table 0x4af878[64] (same call as cmd kind 2 /
 *                 owner 0x2707: 0x429de0(0x1b,1,x,y,-1,kind)). */
typedef short s16; typedef unsigned short u16; typedef unsigned int u32; typedef int s32; typedef unsigned char u8;
extern u8 g_ruleset; void ruleset_init(void);
#define S16(a) (*(volatile s16*)(u32)(a))
#define S32(a) (*(volatile s32*)(u32)(a))
#define BLD 0x805df0u
#define ENT 0x67fe10u
#define UT  0x4c0858u

static u32 s_rng, s_uses;
static u32 rnd(void){ u32 x=s_rng; x^=x<<13; x^=x>>17; x^=x<<5; s_rng=x; return x; }
static u32 rnd_n(u32 n){ return n ? rnd()%n : 0; }

static int lower(int c){ return (c>='A'&&c<='Z') ? c+32 : c; }
static int said(const char *msg,const char *phrase){        /* case-insensitive, ignores leading/trailing spaces */
  while(*msg==' ') msg++;
  while(*phrase){ if(lower((u8)*msg)!=*phrase) return 0; msg++; phrase++; }
  while(*msg==' ') msg++;
  return *msg==0;
}
static int find_hq(int p){
  for(int i=0;i<800;i++){ u32 b=BLD+(u32)i*0xe0;
    if(S32(b)==p && S32(b+4)==0 && S32(b+8)!=0) return i; }
  return -1;
}
static const u8 k_side0[]={2,4,6,8,10,14,19,21,33,34,36,38};   /* 7th Legion (from 0x4c4260) */
static const u8 k_side1[]={2,3,9,15,19,21,33,34,37,38};        /* Chosen     (from 0x4c4210) */
static int pick_type(int side){
  const u8 *l = side ? k_side1 : k_side0; int n = side ? sizeof k_side1 : sizeof k_side0;
  u32 w[16], tot=0;
  for(int i=0;i<n;i++){ s32 c=S32(UT+(u32)l[i]*0x4c+0xc); if(c<100) c=100; w[i]=60000u/(u32)c; if(!w[i]) w[i]=1; tot+=w[i]; }
  u32 r=rnd_n(tot);
  for(int i=0;i<n;i++){ if(r<w[i]) return l[i]; r-=w[i]; }
  return l[0];
}
/* CreateUnit only searches for a free ENT slot when word 0x6e5a60==0; otherwise it takes the preset slot int 0x4b5650 (normally
 * filled by the network executor) and fails with -1. 0x6e5a60 is set by UI/menu code, so in the original cheat build "khaos car"
 * only worked some of the time. Same search as CreateUnit (owner slice, or 0..0xb1 with one human), deterministic on all peers. */
static int find_slot(int p){
  int n=S16(0x834f88); if(n<1) n=1; int per=180/n, st=(p-1)*per, len=per;
  if(S16(0x803c40)==1){ st=0; len=0xb2; }
  for(int i=st;i<st+len-1 && i<0xb2;i++){ u32 e=ENT+(u32)i*0x6d0; if(S16(e)==0 && S32(e+8)==0) return i; }
  return -1;
}
int unit_cap(int cap);                                  /* src/sim/teams.c: min(cap, 178/N) when ruleset=1 */
static int at_cap(int p){
  int n=S16(0x834f88); if(n<1) n=1; int cap=180/n;
  if(p>S16(0x803c40)) cap=S16(0x507484)*8+8;
  return S16(0x804700+p*2) >= unit_cap(cap);
}
static int create_unit(int type,int p,int x,int y){    /* 0 ok */
  int slot=find_slot(p); if(slot<0 || at_cap(p)) return 1;
  if(S16(0x6e5a60)) S32(0x4b5650)=slot;
  S32(0x4b5bb0)=-1; S32(0x4b5bb4)=-1;                    /* no rally point */
  return ((s32(*)(int,int,int,int,int))0x424c20)(type,p,x,y,0) & 0xffff;
}
static int pick_rank(void){ u32 r=rnd_n(100); return r<50?1 : r<80?2 : r<93?3 : 4; }

static void cheat_car(int p){
  int hq=find_hq(p); if(hq<0) return;
  int side=S16(0x6df140+p*2)?1:0, type=pick_type(side);
  s32 pos=((s32(*)(int,int))0x4245c0)(hq, S16(UT+(u32)type*0x4c+4)); if(!pos) return;
  int x=pos&0xffff, y=(pos>>16)&0xffff;
  if(create_unit(type,p,x,y)) return;                                               /* cap reached / no slot */
  int occ=*(volatile u8*)(0x6d3920u+(u32)((x>>5)*128+(y>>5)));                     /* CreateUnit marks tile with slot+1 */
  if(!occ) return;
  u32 e=ENT+(u32)(occ-1)*0x6d0;
  if(S16(e)!=p) return;                                                             /* (CreateUnit turns Chosen type 38 into 43) */
  int rank=pick_rank();
  S16(e+0xae)=(s16)rank;
  S16(e+0xb0)=S16(0x4af820+(rank-1)*2);
  S16(e+0x14)=(s16)(S16(e+0x14)+2*rank);                                            /* max hp, as 0x42cb46 does per promotion */
  S32(e+0x10)=(s32)S16(e+0x14)<<16;                                                  /* full hp (16.16) */
}
static void cheat_box(int p){
  int hq=find_hq(p); if(hq<0) return;
  s32 pos=((s32(*)(int,int))0x4245c0)(hq,0x20); if(!pos) return;
  int kind=S16(0x4af878+rnd_n(64)*2);
  ((int(*)(int,int,int,int,int,int))0x429de0)(0x1b,1,pos&0xffff,(pos>>16)&0xffff,-1,kind);
}
/* ---- HQ -> truck ("pack up"), the reverse of the truck's deploy (handler 0x4573a0, type 42: when order state ent+0x62==0x14 it
 * clears occupancy, CreateBuilding(0,owner,tx-2,ty-1), then 0x4210c0 removes the truck). Posted by the local UI as a hidden chat
 * command "\x01HQ<idx 3 digits>" (kind 0x65) so it runs in lockstep; executed here for the sender. */
static void restore_ground(int b){                     /* 0x4207a0 without the crater decal: ground art back on the footprint */
  u32 B=BLD+(u32)b*0xe0; int x0=S32(B+0x18), y0=S32(B+0x1c), w=S32(B+0x20), h=S32(B+0x24), type=S32(B+4), side=S32(B+0x10);
  for(int r=0;r<h;r++){
    for(int c=0;c<w;c++){
      int i=(x0+c)*0x80+y0+r; if(i<0||i>=0x4000) continue;
      if(S16(0x4bb7f0+(type*0x102+(r+side*10)*10+c)*2)!=-1){
        *(volatile u8*)(0x8352f0u+i)=1; *(volatile u8*)(0x8464f0u+i)=0;
        S16(0x773450+i*2) = S16(0x70db34)==3 ? S16(0x4b5b70+(rnd()&1)*2) : S16(0x4b5b50+(rnd()&15)*2);
      }
      u32 m=(u32)S32(0x77b770+i*4); *(volatile u8*)(0x78bdd0u+(m&0xfff)+((s16)(m>>16))*0x80)=0;
    }
    ((void(*)(void))0x41e0e0)();
  }
  ((void(*)(int,int,int,int))0x41e900)(x0-1,y0-1,w+1,h+1);
}
static void hq_pack(int p,int b){
  if(b<0||b>=800) return;
  u32 B=BLD+(u32)b*0xe0;
  if(S32(B)!=p || S32(B+4)!=0 || S32(B+8)==0 || S32(B+0x68)==1) return;   /* own, HQ, alive, not under construction */
  if(find_slot(p)<0 || at_cap(p)) return;                                 /* never lose the HQ */
  int tx=S32(B+0x18)+2, ty=S32(B+0x1c)+1;                                 /* deploy put the HQ at truck tile -2,-1 */
  s32 hp=S32(B+0x54), mx=S32(B+0x58);
  if(S16(0x716d70+p*2)==b) S16(0x716d70+p*2)=-1;                          /* skip the 'base destroyed' message */
  restore_ground(b);
  ((void(*)(int))0x420240)(b);                                            /* quiet building removal (counts, footprint) */
  int x=tx*32+16, y=ty*32+16;
  if(create_unit(42,p,x,y)) return;
  int occ=*(volatile u8*)(0x6d3920u+(u32)((x>>5)*128+(y>>5))); if(!occ) return;
  u32 e=ENT+(u32)(occ-1)*0x6d0; if(S16(e)!=p) return;
  if(mx>0 && hp>=0){ s32 q=(hp>>16)*1024/mx; if(q>1024) q=1024; s32 v=(S32(e+0x10)>>10)*q; if(v<0x10000) v=0x10000; S32(e+0x10)=v; }  /* keep HQ health fraction (bldg +0x54 16.16, +0x58 max) */
}
static int is_pack(const char *m){ return m[0]==1 && m[1]=='H' && m[2]=='Q'; }
int cheat_chat(u32 rec){                    /* rec = offset of the command record from 0x79fdf0 */
  ruleset_init();
  if(!g_ruleset) return 0;
  const char *msg=(const char*)(0x79fdf4u+rec);
  int p=*(volatile u8*)(0x79fe11u+rec);
  if(p<1||p>8) return 0;
  s_rng = (u32)S32(0x6df3b0)*2654435761u ^ (u32)p*40503u ^ (++s_uses)*0x9e3779b9u; if(!s_rng) s_rng=1;
  if(is_pack(msg)){ hq_pack(p,(msg[3]-'0')*100+(msg[4]-'0')*10+(msg[5]-'0')); return 1; }   /* hidden: not shown in chat */
  if(said(msg,"cheese steak khaos")) S32(0x834a00+p*4)+=10000;
  else if(said(msg,"khaos car")) cheat_car(p);
  else if(said(msg,"khaos box")) cheat_box(p);
  return 0;
}

/* ---- "RE-ASSEMBLE HQ" build-list entry (ruleset=1). Build list = fn around 0x4659c2: types 0x4c1fc8..0x4c1fcc (1..0x16, type 0 never
 * listed), shown if 0x754fb0[p*0x50+type]!=0, max 8 icons (x si += 0x34, y di), per entry: active 0x6682e0[k], value 0x4e1180[k]
 * (type, 500 'more', 600 'back'), x 0x4e1230[k], y 0x4e0f88[k]. Icon frame = 0x4bb7ec[type*0x102+side] in sheet 0x6ce120 (ICONSB.BIM /
 * ICONSB1.BIM); HQ (type 0) = frame 1. Hover (0x465d01): type <500 -> "name cost" message 0x41fa90(text,3). Release (0x465dcf):
 * >=500 page nav, else 0x6729b0 = type to place. We add entry value 700 first on page 1 when the local player has a finished HQ. */
#define ENTRY_PACK 700
static int own_hq(int p){
  for(int i=0;i<800;i++){ u32 B=BLD+(u32)i*0xe0; if(S32(B)==p && S32(B+4)==0 && S32(B+8)!=0 && S32(B+0x68)!=1) return i; }
  return -1;
}
int hq_entry(int x,int y){                              /* hook 0x465a5a; returns 1 if an entry was added (caller: si+=0x34, bx++) */
  ruleset_init();
  int p=S16(0x668ccc);
  if(!g_ruleset || S16(0x4c1fc8)!=1 || own_hq(p)<0) return 0;
  if(!S16(0x8564e0)){ int side=S16(0x6df140+p*2)?1:0;
    ((void(*)(u32,int,int,int))0x4932f0)(*(volatile u32*)0x6ce120, S16(0x4bb7ec+side*2), x, y); }
  S16(0x6682e0)=1; S16(0x4e1180)=ENTRY_PACK; S16(0x4e1230)=(s16)x; S16(0x4e0f88)=(s16)y;
  return 1;
}
static char k_pack_txt[]="RE ASSEMBLE HQ";              /* font has no '-' (or '/') glyph */
void hq_entry_hover(void){ ((void(*)(char*,int))0x41fa90)(k_pack_txt,3); }
void hq_entry_click(void){                              /* post hidden lockstep command, executed by hq_pack() for the sender */
  int p=S16(0x668ccc), b=own_hq(p); if(b<0) return;
  char *d=(char*)0x773410; for(int i=0;i<0x26;i++) d[i]=0;
  d[0]=1; d[1]='H'; d[2]='Q'; d[3]='0'+b/100; d[4]='0'+(b/10)%10; d[5]='0'+b%10;
  *(volatile u8*)0x77342d=(u8)p; S32(0x9e2d80)=0x26;
  ((void(*)(int,void*))0x444c00)(0x65,(void*)0x773410);
  ((void(*)(u32,u32,int))0x46f640)(*(volatile u32*)0x8595fc, *(volatile u32*)0x71a03c, 0x40);   /* same click sound as the list */
}
int s_tmp3;
__asm__(".globl hq_list_stub\nhq_list_stub:\n"      /* 0x465a5a: mov bp,[0x4c1fc8] (7). si = x, di = y, bx = count (0) */
 " pushal\n movswl %di,%eax\n push %eax\n movswl %si,%eax\n push %eax\n call hq_entry\n add $8,%esp\n mov %eax,s_tmp3\n popal\n"
 " cmpl $0,s_tmp3\n je 1f\n add $0x34,%si\n inc %bx\n"
 "1: mov 0x4c1fc8,%bp\n push $0x465a61\n ret\n");
__asm__(".globl hq_hover2_stub\nhq_hover2_stub:\n"  /* 0x465d01: mov cx,[0x8564e0]; cmp ax,0x1f4; jge 0x465d5f (13). ax = entry value */
 " mov 0x8564e0,%cx\n cmp $700,%ax\n jne 1f\n test %cx,%cx\n jne 2f\n"
 " pushal\n call hq_entry_hover\n popal\n"
 "2: push $0x465d5f\n ret\n"
 "1: cmp $0x1f4,%ax\n jge 2b\n push $0x465d0e\n ret\n");
__asm__(".globl hq_click_stub\nhq_click_stub:\n"   /* 0x465dcf: mov dx,[esi]; cmp dx,0x1f4 (8); then jl 0x465e3e at 0x465dd7. cx = 0x8564e0 */
 " mov (%esi),%dx\n cmp $700,%dx\n jne 1f\n"
 " test %cx,%cx\n jne 2f\n pushal\n call hq_entry_click\n popal\n"
 "2: push $0x465eb7\n ret\n"
 "1: cmp $0x1f4,%dx\n push $0x465dd7\n ret\n");
/* ---- truck deploy: find room (ruleset=1). Truck handler 0x4573a0 calls CreateBuilding(0,owner,tx-2,ty-1) at 0x45746b after clearing
 * only its OWN occupancy; any other unit / building / tree / bad tile under the HQ footprint makes it return -1 and the truck silently
 * stays a truck (in-game report Oct 24). We try the original spot, then nearby offsets (nearest first, up to 3 tiles), and tell the
 * local owner when nothing fits. CreateBuilding's checks run identically on every peer before it queues => lockstep-safe. */
static const signed char k_off[][2]={{0,0},{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1},{2,0},{-2,0},{0,2},{0,-2},
  {2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2},{2,2},{-2,2},{2,-2},{-2,-2},{3,0},{-3,0},{0,3},{0,-3}};
static char k_noroom[]="No room to deploy here.";
int deploy_try(int type,int owner,int x,int y){
  typedef s16 (*CB)(int,int,int,int);
  s16 r=((CB)0x421d40)(type,owner,x,y);
  ruleset_init();
  if(r!=-1 || !g_ruleset) return r;
  for(unsigned k=1;k<sizeof k_off/sizeof k_off[0];k++){ r=((CB)0x421d40)(type,owner,x+k_off[k][0],y+k_off[k][1]); if(r!=-1) return r; }
  if((s16)owner==S16(0x668ccc)){                        /* same message path as CreateBuilding's "Too Many Buildings" */
    S16(0x773408)=1; char *d=(char*)0x6df1b0; int i=0; while(k_noroom[i]){ d[i]=k_noroom[i]; i++; } d[i]=0;
    S16(0x805a54)=0x96; S32(0x4b5b3c)=0x96; S32(0x4b5b40)=0xf; S16(0x79fde4)=0;
  }
  return -1;
}
int s_hide;
__asm__(".globl cheat_stub\ncheat_stub:\n"     /* at 0x445fff: lea eax,[ecx+0x79fdf4] (6 bytes); ecx = record offset */
 " pushal\n push %ecx\n call cheat_chat\n add $4,%esp\n mov %eax,s_hide\n popal\n"
 " cmpl $0,s_hide\n jne 1f\n"
 " lea 0x79fdf4(%ecx),%eax\n push $0x446005\n ret\n"
 "1: push $0x4460ea\n ret\n");                       /* hidden command: skip the chat log display */

