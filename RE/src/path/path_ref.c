/* Bit-exact C port of legion.exe PathStep 0x439a00 (see functions/00439a00.md).
 * Operates on a flat image of the game's address space [0x400000,0xad0000) so every
 * stray byte matches the original. Entity/building/slot offsets are ABSOLUTE as in the decompile.
 * Scenario-driven test harness (main) — compare with tools/oracle32.c output. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 0x400000u
#define SIZE 0x6d0000u
static uint8_t *M;
#define A(a) (M+((uint32_t)(a)-BASE))
static int16_t S16(uint32_t a){int16_t v;memcpy(&v,A(a),2);return v;}
static uint16_t U16(uint32_t a){uint16_t v;memcpy(&v,A(a),2);return v;}
static int32_t S32(uint32_t a){int32_t v;memcpy(&v,A(a),4);return v;}
static uint32_t U32(uint32_t a){uint32_t v;memcpy(&v,A(a),4);return v;}
static uint8_t U8(uint32_t a){return *A(a);}
static void W16(uint32_t a,int v){uint16_t t=(uint16_t)v;memcpy(A(a),&t,2);}
static void W32(uint32_t a,uint32_t v){memcpy(A(a),&v,4);}
#define SLOTS 0x6e75c0u
#define SLOT_STRIDE 0x2ef4u
#define NODES 0x6e75c2u
#define FARR 0x6e817cu
#define GARR 0x6e98ecu
#define CURX 0x6ea4a4u
#define CURY 0x6ea4a6u
#define CURF 0x6ea4a8u
#define CURG 0x6ea4acu
#define CLS 0x8352f0u
#define OCC 0x6d3920u
#define TILE 0x773450u
#define OWNM 0x8464f0u
#define ENT0 0x67fe10u
#define BLD0 0x805df0u
static void octd(int a,int b,int *big,int *small){ if(a<0)a=-a; if(b<0)b=-b; *big=b; *small=a; if(a>=b){*big=a;*small=b;} }
static int fdist(int dx,int dy){ int big,small; octd(dx,dy,&big,&small); return (int)(int16_t)((int16_t)big+(int16_t)(small>>2)); }

void path_step(uint32_t p, int16_t self){
#define PS(i) S16(p+2*(i))
#define SETPS(i,v) W16(p+2*(i),(v))
  uint32_t ent=ENT0+(uint32_t)((int)self*0x6d0);
  SETPS(2,1); /* wrapper 0x438fb0 does this before every step */
  if(PS(0)==1){
    int n=-1;
    for(int i=0;i<13;i++) if(S16(SLOTS+i*SLOT_STRIDE)==-1){n=i;break;}
    if(n==-1){SETPS(0,0);return;}
    uint32_t sb=n*SLOT_STRIDE;
    W16(SLOTS+sb,0);
    W16(NODES+sb,(int)((PS(4)<<8)|PS(3)));
    W32(FARR+sb,(uint32_t)fdist(PS(5)-PS(3),PS(6)-PS(4)));
    W16(GARR+sb,0); W16(0x6ea4b0+sb,0);
    W16(CURX+sb,PS(3)); W16(CURY+sb,PS(4)); W16(CURF+sb,(int16_t)S32(FARR+sb)); W32(CURG+sb,U16(GARR+sb));
    SETPS(1,n); W16(0x6803f4+(int)self*0x6d0,0); SETPS(0x26b,0); SETPS(7,PS(3)); SETPS(8,PS(4)); SETPS(0,2);
  }
  int state=PS(0);
  if(state!=0x29a){
    #define FAIL() do{SETPS(0,9999);W16(SLOTS+PS(1)*SLOT_STRIDE,0xffff);SETPS(1,-1);return;}while(0)
    #define ABORT0() do{SETPS(0,0);W16(SLOTS+PS(1)*SLOT_STRIDE,0xffff);SETPS(1,-1);W16(ent+0x62,0);return;}while(0)
    if(state>2||state<1){int s=PS(1);SETPS(0,9999);W16(SLOTS+s*SLOT_STRIDE,0xffff);SETPS(1,-1);return;}
    int tb=S16(ent+0x46);
    if(tb!=-1){uint32_t b=BLD0+tb*0xe0; if(S32(b)==0||S32(b+8)==0) ABORT0();}
    int te=S16(ent+0x48);
    if(te!=-1){uint32_t e=ENT0+te*0x6d0; if(S16(e)==0||S16(e+0xc)==0) ABORT0();}
    if(S16(ent+2)!=1 && U16(ent+0x40)!=0xffff && S16(ent+0x42)!=-1){
      int idx=(int16_t)(U16(ent+0x40)&0xffe0)*4+(S16(ent+0x42)>>5);
      if(U8(CLS+idx)!=1) ABORT0();
    }
    int calls=0; uint32_t sbo=PS(1)*SLOT_STRIDE; uint32_t base=SLOTS+sbo;
    for(;;){
      int n=S16(base);
      uint32_t cx=U16(CURX+sbo),cy=U16(CURY+sbo),cg=U32(CURG+sbo);
      if(0x5d3<n){
        uint32_t best=0x7544;int bi=-1;
        for(int i=0;i<n;i++){uint32_t f=U32(FARR+sbo+i*4); if(f<best){best=f;bi=i;}}
        if(bi==-1) FAIL();
        uint16_t pk=U16(NODES+sbo+bi*2); SETPS(0,0x29a); SETPS(5,pk&0xff); SETPS(6,pk>>8); return;
      }
      int gx=PS(5);
      if(cx==(uint32_t)gx && PS(6)==(int)cy){SETPS(0,0x29a);return;}
      if(S16(ent+0x64)==2){
        int a=(int16_t)(gx<<5)-(int16_t)(cx<<5), b=(int16_t)(PS(6)<<5)-(int16_t)(cy<<5);
        int big,small; octd(a,b,&big,&small);
        int d=(int)(int16_t)((int16_t)(small>>2)+(int16_t)big);
        int tb2=S16(ent+0x46);
        if(tb2!=-1){uint32_t bb=BLD0+tb2*0xe0; d-=(S32(bb+0x24)+S32(bb+0x20))/4;}
        if(d<S16(ent+0x92)){SETPS(5,cx);SETPS(6,cy);SETPS(0,0x29a);return;}
      }
      for(int k=0;k<8;k++){
        uint32_t nx=cx+U32(0x4b66e0+k*4), ny=U32(0x4b6700+k*4)+cy;
        if(nx<0x80&&ny<0x80){
          uint32_t idx=nx*0x80+ny; uint32_t occ=U8(OCC+idx);
          if((int)self-(int)occ==-1) occ=0;
          if((int)S16(ent+0x48)-(int)occ==-1) occ=0;
          if(occ){
            if(S16(ent)!=S16(0x67f740+occ*0x6d0) && S16(0x4c0874+S16(ent+2)*0x4c)!=0 && S16(0x4c0874+S16(0x67f742+occ*0x6d0)*0x4c)==0) occ=0;
            if(occ){ if(S32(0x67f76c+occ*0x6d0)!=0||S32(0x67f770+occ*0x6d0)!=0) occ=0; }
            if(S16(occ*0x6d0+0x67f7a2)==5) occ=0;
          }
          uint8_t cls=U8(CLS+idx);
          int tb3=S16(ent+0x46);
          if(tb3!=-1){uint32_t bb=BLD0+tb3*0xe0;
            if(U32(bb+0x18)<=nx&&U32(bb+0x1c)<=ny&&nx<(uint32_t)(S32(bb+0x20)+S32(bb+0x18))&&ny<(uint32_t)(S32(bb+0x24)+S32(bb+0x1c))) cls=1;}
          if(cls==1){
            int ok=1; int16_t t=S16(TILE+idx*2);
            if((t==0x3e6||t==0x3e5)&&(U8(OWNM+idx)&0xf)==U16(ent)) ok=0;
            if(ok&&occ==0){
              uint16_t pk=(uint16_t)((int16_t)ny<<8|(uint16_t)nx);
              int found=0; for(int i=0;i<=n;i++) if(U16(NODES+sbo+i*2)==pk){found=1;break;}
              if(!found){
                n++;
                W16(NODES+sbo+n*2,pk);
                int f=fdist(gx-(int16_t)nx,PS(6)-(int16_t)ny);
                int g=(int16_t)((int16_t)cg+1);
                if(S16(ent+0x6e)==6||S16(ent+0x6e)==9){
                  for(int pl=1;pl<7;pl++) if(S16(ent)!=pl){
                    int inf=S16(0x78fde0+(nx&~1u)*0x40+(ny&~1u)+pl*0x2000);
                    g=(int16_t)(g+inf); f=f+inf*4;
                  }
                }
                W32(FARR+sbo+n*4,(uint32_t)f); W16(GARR+sbo+n*2,g);
              }
            }
          }
        }
      }
      W16(base,n);
      int bi=-1; uint32_t best=0x752e;
      for(int i=0;i<=n;i++){uint32_t f=U32(FARR+sbo+i*4); if(f<best){best=f;bi=i;}}
      if(bi==-1) FAIL();
      uint16_t pk=U16(NODES+sbo+bi*2);
      W16(CURX+sbo,pk&0xff); W16(CURY+sbo,pk>>8); W16(CURF+sbo,(int16_t)S32(FARR+sbo+bi*4));
      calls++; W32(CURG+sbo,U16(GARR+sbo+bi*2)); W32(FARR+sbo+bi*4,0x753a);
      if(calls>14) return;
    }
  }
  /* reconstruct */
  uint32_t sbo=PS(1)*SLOT_STRIDE; int cnt=S16(SLOTS+sbo);
  uint16_t goalpk=(uint16_t)((PS(6)<<8)|PS(5)); int gi=-1;
  for(int i=0;i<=cnt;i++) if(U16(NODES+sbo+i*2)==goalpk){gi=i;break;}
  if(gi==-1){SETPS(0,9999);W16(SLOTS+sbo,0xffff);SETPS(1,-1);return;}
  uint16_t pk=U16(NODES+sbo+gi*2); int cy=pk>>8,cxx=pk&0xff;
  SETPS(0x26b,0);SETPS(2,1);SETPS(0x13,cxx);SETPS(0x13f+PS(0x26b),cy);SETPS(0x26b,PS(0x26b)+1);
  for(;;){
    if(PS(3)==cxx&&PS(4)==cy){
      int c=PS(0x26b)-1,i=0;
      if(0<c){int a=0x13,b=PS(0x26b)+0x12;
        do{int x=PS(a),y=PS(a+300);SETPS(a,PS(b));SETPS(a+300,PS(b+300));SETPS(b,x);SETPS(b+300,y);c--;i++;a++;b--;}while(i<c);}
      W16(SLOTS+sbo,0xffff);SETPS(0,3);SETPS(1,-1);return;
    }
    uint16_t bg=30000;int bi=-1;
    for(int k=0;k<8;k++){
      uint16_t want=(uint16_t)(((int16_t)S32(0x4b6700+k*4)+cy)*0x100|((int16_t)S32(0x4b66e0+k*4)+(int16_t)cxx));
      int idx=-1; for(int i=0;i<=cnt;i++) if(U16(NODES+sbo+i*2)==want){idx=i;break;}
      if(idx!=-1){uint16_t g=U16(GARR+sbo+idx*2); if(g<bg){bi=idx;bg=g;}}
    }
    if(bi==-1){SETPS(0,9999);W16(SLOTS+sbo,0xffff);SETPS(1,-1);return;}
    pk=U16(NODES+sbo+bi*2); cy=pk>>8; cxx=pk&0xff;
    int c=PS(0x26b); SETPS(0x13+c,cxx); SETPS(0x13f+c,cy); SETPS(0x26b,c+1);
    if(0x12a<(int16_t)(c+1)){SETPS(0,9999);W16(SLOTS+sbo,0xffff);SETPS(1,-1);return;}
  }
}

/* ---- scenario harness ---- */
static uint64_t fnv(uint64_t h,const uint8_t*d,size_t n){for(size_t i=0;i<n;i++){h^=d[i];h*=0x100000001b3ULL;}return h;}
int main(int argc,char**argv){
  M=calloc(1,SIZE);
  FILE*f=fopen(argv[1],"rb"); uint32_t hd[5]; if(!f||fread(hd,4,5,f)!=5)return 2;
  uint32_t self=hd[1],maxc=hd[2],p=hd[3],ns=hd[4];
  for(uint32_t i=0;i<ns;i++){uint32_t sh[2]; fread(sh,4,2,f); fread(A(sh[0]),1,sh[1],f);}
  fclose(f);
  for(uint32_t c=1;c<=maxc;c++){
    path_step(p,(int16_t)self);
    uint64_t h=0xcbf29ce484222325ULL;
    h=fnv(h,A(ENT0+self*0x6d0),0x6d0); h=fnv(h,A(SLOTS),13*SLOT_STRIDE);
    int st=S16(p)&0xffff; printf("%u %04x %016llx\n",c,st,(unsigned long long)h);
    if(st==3||st==9999||st==0){
      if(st==3){int n=S16(p+2*0x26b);printf("W %d",n);for(int i=0;i<n;i++)printf(" %d,%d",S16(p+2*(0x13+i)),S16(p+2*(0x13f+i)));printf("\n");}
      break;}
  }
  return 0;
}
