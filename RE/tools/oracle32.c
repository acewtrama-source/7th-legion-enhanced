/* Native oracle: runs the REAL legion.exe machine code of PathStep (0x439a00) inside a
 * freestanding 32-bit Linux process (no emulator). Usage: oracle32 legion.exe scenario.bin [patch.bin BASEHEX DISPATCHHEX RULESETADDRHEX VALUE INITEDADDRHEX]  (patch: redirect the call at 0x438fcf to DISPATCH)
 * Build: gcc -m32 -nostdlib -ffreestanding -static -fno-pic -no-pie -O1 -fno-tree-loop-distribute-patterns -o oracle32 oracle32.c
 * Output format identical to src/path/path_ref.c. */
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8; typedef unsigned long long u64;
static int sc(int n,int a,int b,int c){int r;__asm__ volatile("int $0x80":"=a"(r):"0"(n),"b"(a),"c"(b),"d"(c):"memory");return r;}
static int mmap2(u32 addr,u32 len,int prot,int flags){
  int r; __asm__ volatile("int $0x80":"=a"(r):"0"(192),"b"(addr),"c"(len),"d"(prot),"S"(flags),"D"(-1),"r"(0)); return r; }
/* note: ebp(pgoff)=0 supplied via "r" is not guaranteed; use explicit asm below */
static int mmap_fixed(u32 addr,u32 len){
  int r;
  __asm__ volatile("push %%ebp\n xor %%ebp,%%ebp\n int $0x80\n pop %%ebp":"=a"(r):"0"(192),"b"(addr),"c"(len),"d"(7),"S"(0x32),"D"(-1):"memory");
  return r;}
static int mmap_any(u32 len){
  int r;
  __asm__ volatile("push %%ebp\n xor %%ebp,%%ebp\n int $0x80\n pop %%ebp":"=a"(r):"0"(192),"b"(0),"c"(len),"d"(3),"S"(0x22),"D"(-1):"memory");
  return r;}
static void *mcpy(void*d,const void*s,u32 n){u8*a=d;const u8*b=s;while(n--)*a++=*b++;return d;}
void *memcpy(void*d,const void*s,u32 n){return mcpy(d,s,n);}
static int readfile(const char*path,u8*buf,u32 max){int fd=sc(5,(int)path,0,0);if(fd<0)return -1;u32 t=0;for(;;){int r=sc(3,fd,(int)(buf+t),max-t);if(r<=0)break;t+=r;}sc(6,fd,0,0);return (int)t;}
static void out(const char*s,u32 n){sc(4,1,(int)s,n);}
static char ob[256];static int ol;
static void flush(void){out(ob,ol);ol=0;}
static void pc(char c){ob[ol++]=c;if(ol>200)flush();}
static void phex(u64 v,int digits){for(int i=digits-1;i>=0;i--)pc("0123456789abcdef"[(v>>(i*4))&15]);}
static void pdec(int v){char t[16];int n=0;if(v<0){pc('-');v=-v;}if(!v)t[n++]='0';while(v){t[n++]='0'+v%10;v/=10;}while(n)pc(t[--n]);}
#define BASE 0x400000u
#define IMG 0xa92000u
typedef int (*fn_t)(void*,int);
static u64 fnv(u64 h,const u8*d,u32 n){while(n--){h^=*d++;h*=0x100000001b3ULL;}return h;}
static int S16(u32 a){return (short)*(u16*)a;}
static u32 hx(const char*t){u32 v=0;for(;*t;t++){int c=*t;v=v*16+(c<='9'?c-'0':(c|32)-'a'+10);}return v;}
static u64 rdtsc(void){u32 lo,hi;__asm__ volatile("rdtsc":"=a"(lo),"=d"(hi));return ((u64)hi<<32)|lo;}
static void err(const char*s_,u64 v){char b[40];int n=0;char t[24];int m=0;if(!v)t[m++]='0';while(v){t[m++]='0'+(int)(v%10);v/=10;}while(*s_)b[n++]=*s_++;while(m)b[n++]=t[--m];b[n++]='\n';sc(4,2,(int)b,n);}
int cmain(int*sp){
  int argc=sp[0];char**argv=(char**)(sp+1); if(argc<3)return 2;
  if(mmap_fixed(BASE,IMG)!=(int)BASE)return 3;
  u8*ex=(u8*)mmap_any(0x400000); int n=readfile(argv[1],ex,0x400000); if(n<0)return 4;
  mcpy((void*)0x401000,ex+0x400,0xa8600); mcpy((void*)0x4aa000,ex+0xa8a00,0x1200); mcpy((void*)0x4ac000,ex+0xa9c00,0x2e800);
  u8*sc_=(u8*)mmap_any(0x1000000); int sn=readfile(argv[2],sc_,0x1000000); if(sn<20)return 5;
  u32*h=(u32*)sc_; u32 self=h[1],maxc=h[2],p=h[3],ns=h[4]; u8*q=sc_+20;
  for(u32 i=0;i<ns;i++){u32 a=*(u32*)q,l=*(u32*)(q+4);q+=8;mcpy((void*)a,q,l);q+=l;}
  if(argc>=9){ u8*pb=(u8*)mmap_any(0x100000); int pn=readfile(argv[3],pb,0x100000); if(pn<0)return 6; u32 base=hx(argv[4]),disp=hx(argv[5]),rs=hx(argv[6]);
    mcpy((void*)base,pb,pn); *(int*)0x438fd0=(int)(disp-0x438fd4); *(u8*)rs=(u8)hx(argv[7]); *(u8*)hx(argv[8])=1; }
  fn_t fn=(fn_t)0x438fb0; u64 cyc=0;
  for(u32 c=1;c<=maxc;c++){
    u64 t0=rdtsc(); fn((void*)p,(int)(short)self); cyc+=rdtsc()-t0;
    u64 hh=0xcbf29ce484222325ULL; hh=fnv(hh,(u8*)(0x67fe10+self*0x6d0),0x6d0); hh=fnv(hh,(u8*)0x6e75c0,13*0x2ef4);
    int st=S16(p)&0xffff; pdec(c);pc(' ');phex(st,4);pc(' ');phex(hh,16);pc('\n');
    if(st==3||st==9999||st==0){
      if(st==3){int k=S16(p+2*0x26b);pc('W');pc(' ');pdec(k);for(int i=0;i<k;i++){pc(' ');pdec(S16(p+2*(0x13+i)));pc(',');pdec(S16(p+2*(0x13f+i)));}pc('\n');}
      break;}
  }
  flush(); err("cycles ",cyc); return 0;
}
__asm__(".globl _start\n_start:\n mov %esp,%eax\n push %eax\n call cmain\n mov %eax,%ebx\n mov $1,%eax\n int $0x80\n");
