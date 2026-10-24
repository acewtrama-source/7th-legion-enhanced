/* native unit test of ui_style: gcc -m32 -nostdlib -ffreestanding -static -fno-pic -no-pie -O1 -fno-stack-protector -o t tools/ui_test.c src/ui/ui_hooks.c && ./t */
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
extern u8 g_ruleset; u32 ui_style(int kind);
static int sc(int n,int a,int b,int c){int r;__asm__ volatile("int $0x80":"=a"(r):"0"(n),"b"(a),"c"(b),"d"(c):"memory");return r;}
static int mm(u32 addr,u32 len){int r;__asm__ volatile("push %%ebp\n xor %%ebp,%%ebp\n int $0x80\n pop %%ebp":"=a"(r):"0"(192),"b"(addr),"c"(len),"d"(3),"S"(0x32),"D"(-1):"memory");return r;}
u8 g_ruleset; void ruleset_init(void){}
#define W(a) (*(volatile u16*)(u32)(a))
static int fails; static void chk(int c,const char*m){ if(!c){fails++; sc(4,1,(int)m,5);} }
int cmain(void){
  mm(0x859000,0x1000); mm(0x71b000,0x1000); W(0x859580)=1;
  g_ruleset=0; W(0x71b41c)=1; chk(ui_style(1)==1,"A1\n");
  g_ruleset=1; W(0x71b41c)=0; chk(ui_style(1)==1,"B1\n");
  W(0x71b41c)=1; chk(ui_style(1)==2,"B2\n"); chk(ui_style(2)==2,"B3\n"); chk(ui_style(7)==1,"B4\n"); chk(ui_style(8)==1,"B5\n");
  sc(4,1,(int)(fails?"FAIL\n":"ok\n"),fails?5:3); return fails; }
__asm__(".globl _start\n_start:\n call cmain\n mov %eax,%ebx\n mov $1,%eax\n int $0x80\n");
