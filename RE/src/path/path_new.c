/* ENHANCED pathfinder for legion.exe (drop-in for PathStep 0x439a00; same pathState/slot interface).
 * Freestanding 32-bit, absolute game addresses. Built into a patch section (tools/build_patch.sh).
 * Differences vs classic: true A* (f=g+h, octile costs 10/14, indexed binary heap, decrease-key),
 * whole-map search (no 1491-node cap), 128 expansions/call, completes inline (state 3 directly),
 * unreachable goal -> path to the closest reachable tile instead of failing. Walkability rules are
 * IDENTICAL to classic (terrain==1, footprint override, occupancy rules, owner mines, flee influence).
 * Deterministic (no RNG, no float, no clock) => lockstep-safe if every peer runs the same ruleset. */
typedef signed short s16; typedef unsigned short u16; typedef unsigned char u8; typedef unsigned int u32; typedef int s32;
#define S16(a) (*(__attribute__((may_alias)) s16*)(u32)(a))
#define U16(a) (*(__attribute__((may_alias)) u16*)(u32)(a))
#define S32(a) (*(__attribute__((may_alias)) s32*)(u32)(a))
#define U32(a) (*(__attribute__((may_alias)) u32*)(u32)(a))
#define U8(a)  (*(volatile u8*)(u32)(a))
#define SLOTS 0x6e75c0u
#define SLOT_STRIDE 0x2ef4u
#define CLS 0x8352f0u
#define OCC 0x6d3920u
#define TILE 0x773450u
#define OWNM 0x8464f0u
#define ENT0 0x67fe10u
#define BLD0 0x805df0u
#define EXPANSIONS_PER_CALL 128
#define MAXWP 299

u8 g_ruleset;            /* 0 classic, 1 enhanced; set by game start / ini */
static u32 g_epoch;
static struct Slot {
  u32 stamp[16384]; s32 g[16384]; s32 f[16384]; u8 par[16384]; u8 closed[16384];
  u16 heap[16384]; u16 pos[16384]; s32 hn; u32 epoch; u32 best; s32 besth; s32 bestg;
} slot[13];
static u16 tmp[16384];
static const s32 DX[8]={0,1,0,-1,-1,1,1,-1}, DY[8]={-1,0,1,0,-1,-1,1,1};

static s32 hcost(s32 x,s32 y,s32 gx,s32 gy){ s32 a=x>gx?x-gx:gx-x, b=y>gy?y-gy:gy-y; return a>b? a*10+b*4 : b*10+a*4; }
static int less(struct Slot*s,u32 a,u32 b){ if(s->f[a]!=s->f[b]) return s->f[a]<s->f[b]; return a<b; }
static void up(struct Slot*s,s32 i){ u16 n=s->heap[i]; while(i>0){ s32 p=(i-1)>>1; if(!less(s,n,s->heap[p]))break; s->heap[i]=s->heap[p]; s->pos[s->heap[i]]=i; i=p;} s->heap[i]=n; s->pos[n]=i; }
static void down(struct Slot*s,s32 i){ u16 n=s->heap[i]; for(;;){ s32 c=2*i+1; if(c>=s->hn)break; if(c+1<s->hn&&less(s,s->heap[c+1],s->heap[c]))c++; if(!less(s,s->heap[c],n))break; s->heap[i]=s->heap[c]; s->pos[s->heap[i]]=i; i=c;} s->heap[i]=n; s->pos[n]=i; }
static void push(struct Slot*s,u32 n){ s->heap[s->hn]=n; s->hn++; up(s,s->hn-1); }
static u32 pop(struct Slot*s){ u32 r=s->heap[0]; s->hn--; if(s->hn>0){ s->heap[0]=s->heap[s->hn]; down(s,0);} return r; }

#define PS(i) S16(p+2*(i))
static void freeslot(u32 p){ S16(SLOTS+PS(1)*SLOT_STRIDE)=-1; PS(1)=-1; }
static void fail(u32 p){ PS(0)=9999; freeslot(p); }
static void abort0(u32 p,u32 ent){ PS(0)=0; freeslot(p); S16(ent+0x62)=0; }

/* same walkability test as classic */
static int walkable(u32 ent,s32 self,u32 nx,u32 ny){
  u32 idx=nx*128+ny; u32 occ=U8(OCC+idx);
  if(self-(s32)occ==-1) occ=0;
  if((s32)S16(ent+0x48)-(s32)occ==-1) occ=0;
  if(occ){
    if(S16(ent)!=S16(0x67f740+occ*0x6d0) && S16(0x4c0874+S16(ent+2)*0x4c)!=0 && S16(0x4c0874+S16(0x67f742+occ*0x6d0)*0x4c)==0) occ=0;
    if(occ){ if(S32(0x67f76c+occ*0x6d0)!=0||S32(0x67f770+occ*0x6d0)!=0) occ=0; }
    if(S16(occ*0x6d0+0x67f7a2)==5) occ=0;
  }
  u8 cls=U8(CLS+idx);
  s32 tb=S16(ent+0x46);
  if(tb!=-1){ u32 b=BLD0+tb*0xe0;
    if(U32(b+0x18)<=nx&&U32(b+0x1c)<=ny&&nx<(u32)(S32(b+0x20)+S32(b+0x18))&&ny<(u32)(S32(b+0x24)+S32(b+0x1c))) cls=1; }
  if(cls!=1) return 0;
  s16 t=S16(TILE+idx*2);
  if((t==0x3e6||t==0x3e5)&&(U8(OWNM+idx)&0xf)==U16(ent)) return 0;
  return occ==0;
}

static void finish(u32 p,struct Slot*s,u32 end){
  s32 n=0; u32 c=end;
  for(;;){ tmp[n++]=c; u32 k=s->par[c]; if(k==0)break; k--; s32 x=(c>>7)-DX[k], y=(c&127)-DY[k]; c=x*128+y; }
  /* tmp[0]=end ... tmp[n-1]=start ; emit start->end */
  s32 cnt=n>MAXWP?MAXWP:n;
  for(s32 i=0;i<cnt;i++){ u32 node=tmp[n-1-i]; PS(0x13+i)=node>>7; PS(0x13f+i)=node&127; }
  PS(0x26b)=cnt; PS(2)=1; PS(5)=tmp[0]>>7; PS(6)=tmp[0]&127;
  S16(SLOTS+PS(1)*SLOT_STRIDE)=-1; PS(0)=3; PS(1)=-1;
}

void path_step_new(u32 p,s32 self16){
  s32 self=(s16)self16; u32 ent=ENT0+(u32)(self*0x6d0);
  if(PS(0)==1){
    s32 n=-1; for(s32 i=0;i<13;i++) if(S16(SLOTS+i*SLOT_STRIDE)==-1){n=i;break;}
    if(n==-1){ PS(0)=0; return; }
    struct Slot*s=&slot[n]; S16(SLOTS+n*SLOT_STRIDE)=0;
    s->epoch=++g_epoch; s->hn=0;
    u32 sx=(u16)PS(3), sy=(u16)PS(4); u32 si=(sx&127)*128+(sy&127);
    s->stamp[si]=s->epoch; s->g[si]=0; s->f[si]=hcost(sx,sy,PS(5),PS(6)); s->par[si]=0; s->closed[si]=0; push(s,si);
    s->best=si; s->besth=s->f[si]; s->bestg=0;
    PS(1)=n; S16(0x6803f4+self*0x6d0)=0; PS(0x26b)=0; PS(7)=PS(3); PS(8)=PS(4); PS(0)=2;
  }
  s32 state=PS(0);
  if(state<1||state>2){ s32 q=PS(1); PS(0)=9999; S16(SLOTS+q*SLOT_STRIDE)=-1; PS(1)=-1; return; }
  s32 tb=S16(ent+0x46);
  if(tb!=-1){ u32 b=BLD0+tb*0xe0; if(S32(b)==0||S32(b+8)==0){ abort0(p,ent); return; } }
  s32 te=S16(ent+0x48);
  if(te!=-1){ u32 e=ENT0+te*0x6d0; if(S16(e)==0||S16(e+0xc)==0){ abort0(p,ent); return; } }
  if(S16(ent+2)!=1 && U16(ent+0x40)!=0xffff && S16(ent+0x42)!=-1){
    s32 idx=(s16)(U16(ent+0x40)&0xffe0)*4+(S16(ent+0x42)>>5);
    if(U8(CLS+idx)!=1){ abort0(p,ent); return; } }
  struct Slot*s=&slot[PS(1)];
  s32 gx=PS(5), gy=PS(6), flee=(S16(ent+0x6e)==6||S16(ent+0x6e)==9), owner=S16(ent);
  for(s32 it=0;it<EXPANSIONS_PER_CALL;it++){
    if(s->hn==0){  /* open list exhausted: go to closest reached tile */
      if(s->best==(u32)((PS(3)&127)*128+(PS(4)&127))){ fail(p); return; }
      finish(p,s,s->best); return; }
    u32 u=pop(s); s->closed[u]=1; s32 ux=u>>7, uy=u&127;
    s32 h=hcost(ux,uy,gx,gy);
    if(h<s->besth||(h==s->besth&&s->g[u]<s->bestg)){ s->best=u; s->besth=h; s->bestg=s->g[u]; }
    if(ux==gx&&uy==gy){ finish(p,s,u); return; }
    if(S16(ent+0x64)==2){
      s32 a=(s16)(gx<<5)-(s16)(ux<<5), b=(s16)(gy<<5)-(s16)(uy<<5); if(a<0)a=-a; if(b<0)b=-b;
      s32 big=a>b?a:b, small=a>b?b:a; s32 d=(s16)((s16)(small>>2)+(s16)big);
      s32 tb2=S16(ent+0x46);
      if(tb2!=-1){ u32 bb=BLD0+tb2*0xe0; d-=(S32(bb+0x24)+S32(bb+0x20))/4; }
      if(d<S16(ent+0x92)){ finish(p,s,u); return; }
    }
    for(s32 k=0;k<8;k++){
      u32 nx=ux+DX[k], ny=uy+DY[k]; if(nx>=128||ny>=128) continue;
      u32 v=nx*128+ny;
      if(s->stamp[v]==s->epoch&&s->closed[v]) continue;
      if(!walkable(ent,self,nx,ny)) continue;
      s32 cost=k<4?10:14;
      if(flee){ s32 sum=0; for(s32 pl=1;pl<7;pl++) if(owner!=pl){ s32 inf=S16(0x78fde0+(nx&~1u)*0x40+(ny&~1u)+pl*0x2000); if(inf>0) sum+=inf; } cost+=sum*10; }
      s32 ng=s->g[u]+cost;
      if(s->stamp[v]!=s->epoch){
        s->stamp[v]=s->epoch; s->closed[v]=0; s->g[v]=ng; s->f[v]=ng+hcost(nx,ny,gx,gy); s->par[v]=k+1; push(s,v);
      } else if(ng<s->g[v]){
        s->f[v]+=ng-s->g[v]; s->g[v]=ng; s->par[v]=k+1; up(s,s->pos[v]);
      }
    }
  }
}

static const char k_ruleset[]="ruleset";
static u8 g_inited;
typedef u32 (__attribute__((stdcall)) *GPPI)(const char*,const char*,s32,const char*);
/* ruleset source: Siege.ini [options] ruleset=0|1 (read once, at first use: path request or UI hook). TODO: game-start UI + host sync in MP. */
void ruleset_init(void){
  if(!g_inited){ g_inited=1; GPPI f=(GPPI)S32(0xac4484); /* IAT: GetPrivateProfileIntA */
    g_ruleset=(u8)f((const char*)0x4b97a0 /*"options"*/,k_ruleset,0,(const char*)S32(0x4b95e0)/*Siege.ini path*/); }
}
void path_dispatch(u32 p,s32 self){
  ruleset_init();
  if(g_ruleset) path_step_new(p,self);
  else ((void(*)(u32,s32))0x439a00)(p,self);
}
