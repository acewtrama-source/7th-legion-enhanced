/* native test of the paged save/load menu logic with a mocked menu toolkit:
 * gcc -m32 -nostdlib -ffreestanding -static -fno-pic -no-pie -O1 -fno-stack-protector -DUI_MOCK -include tools/saves_test.c -o t src/ui/saves.c   (this file is force-included before saves.c) */
typedef unsigned int u32;
typedef void (*FV)(void); typedef int (*FBTN)(int,int,int,int,int,int,const char*); typedef int (*FSP)(char*,const char*,...);
static int sc_(int n,int a,int b,int c){int r;__asm__ volatile("int $0x80":"=a"(r):"0"(n),"b"(a),"c"(b),"d"(c):"memory");return r;}
static int mm_(u32 addr,u32 len){int r;__asm__ volatile("push %%ebp\n xor %%ebp,%%ebp\n int $0x80\n pop %%ebp":"=a"(r):"0"(192),"b"(addr),"c"(len),"d"(3),"S"(0x32),"D"(-1):"memory");return r;}
static int exists_[1000];            /* mock filesystem: slot -> exists */
static int btn_ids[64], nbtn, began, ended; static const char* btn_txt[64];
static int script[64], si_;          /* poll script: click ids */
static int saved_slot=-99; static int fails;
#define CHK(c,m) do{ if(!(c)){fails++; sc_(4,1,(int)(m "\n"),sizeof(m)); } }while(0)
static void M_BEGIN1(void){began++; nbtn=0;} static void M_BEGIN2(void){} static void M_END(void){ended++;}
static int M_BTN(int id,int t,int x,int y,int w,int h,const char*tx){btn_ids[nbtn]=id;btn_txt[nbtn++]=tx;return 1;}
static int M_POLL(void){ *(short*)0x59f890=(short)script[si_++]; return 1; }
static void M_FOCUS(int a){} static const char* M_TEXT(int id){return "nm";} static int M_WIDTH(const char*t){int n=0;while(t[n])n++;return n*8;}
static int last_n;
static int G_SPRINTF_(char*d,const char*f,...){ /* only formats we use: "%d" paths and plain strings */
  __builtin_va_list ap; __builtin_va_start(ap,f);
  if(f==(const char*)0x4b6994){ last_n=__builtin_va_arg(ap,int); __builtin_va_end(ap); d[0]='P'; d[1]=0; return 1; }
  if(f==(const char*)0x4b826c){ last_n=__builtin_va_arg(ap,int); } d[0]='E'; d[1]=0; return 1; }
static void* G_FOPEN_(const char*p,const char*m){ return (p[0]=='P' && last_n>=0 && last_n<1000 && exists_[last_n]) ? (void*)1 : (void*)0; }
static int G_FREAD_(void*b,int a,int n,void*f){ ((char*)b)[0]='N'; return 1; }
static int G_FCLOSE_(void*f){return 0;}
static void SAVEGAME_(int s,const char*t){saved_slot=s;}
static char del_path_[40]; static int deleted_=-1; typedef int (*FDEL_)(const char*); static int del_(const char*p){ deleted_=last_n; return 1; } static FDEL_ delp_=del_; 
static void ORIG_LOAD_(void){} static void ORIG_SAVE_(void){}
#define M_BEGIN1 M_BEGIN1
#define M_BEGIN2 M_BEGIN2
#define M_END M_END
#define M_BTN M_BTN
#define M_POLL M_POLL
#define M_FOCUS M_FOCUS
#define M_TEXT M_TEXT
#define M_WIDTH M_WIDTH
#define G_SPRINTF G_SPRINTF_
#define G_FOPEN G_FOPEN_
#define G_FREAD G_FREAD_
#define G_FCLOSE G_FCLOSE_
#define SAVEGAME SAVEGAME_
#define G_DELETE delp_
#define ORIG_LOAD ORIG_LOAD_
#define ORIG_SAVE ORIG_SAVE_
/* slot_exists in saves.c calls G_SPRINTF(path,fmt,slot) then fopen: our mock records last_n */
