/* Back/Cancel button on the campaign (side choice) screen 0x40d3a0, ruleset=1 only.
 * FACT: that screen's title button text (==0x866cb0) makes 4758b0 set toolkit mode [0x4c5894]=2; in mode 2 the poll 0x476aa0 only DRAWS
 * the buttons and returns -1 (jump 0x477b3e) -> no hit-test, no hover, no click. So we do our own hit-test after each poll:
 * mouse x/y from the message pumps 0x406000/0x406140, button state [0x4c5aa4] (prev [0x4c5aa0]); slot table 0x592bb0 stride 0x3c0
 * (+0 type word, +2 id, +4 x, +6 y, +8 w, +0xa h, +0x12 hover flag).
 * Esc: the screen exits on key press, then the main menu still sees Esc ([0x71b3e2]) and quits the game. We swallow Esc: clear the word each
 * frame for ~30 polls, then exit.
 * Hooks: call 0x4758b0 at 0x40d48a -> camp_btn (adds button id 7); call 0x476aa0 at 0x40d49c -> camp_poll_stub; movw at 0x40d560 -> camp_esc_stub. */
typedef signed short s16; typedef unsigned short u16; typedef unsigned int u32; typedef int s32;
extern unsigned char g_ruleset; void ruleset_init(void); void teams_clear(void);
typedef void (*BTN)(s32,s32,s32,s32,s32,s32,const char*);
#define BTNF ((BTN)0x4758b0)
#define W(a) (*(volatile u16*)(u32)(a))
void camp_btn(s32 id,s32 type,s32 x,s32 y,s32 w,s32 h,const char*t){
  BTNF(id,type,x,y,w,h,t);
  teams_clear();                               /* campaign: no teams */
  ruleset_init();
  if(g_ruleset) BTNF(7,0,-1,0x1c2,200,0x10,(const char*)0x8644b0);   /* 0x8644b0 = game's Cancel string */
}
unsigned char esc_pend;
static u16 s_prev;
/* called after every poll; returns 1 => leave the screen */
int camp_post(void){
  if(!g_ruleset) return 0;
  if(esc_pend){ W(0x71b3e2)=0; if(++esc_pend>=30){ esc_pend=0; return 1; } return 0; }
  int slot=-1;
  for(int i=0;i<50;i++){ u32 b=0x592bb0u+(u32)i*0x3c0; if((s16)W(b)!=-1 && (s16)W(b+2)==7){ slot=i; break; } }
  if(slot<0) return 0;
  u32 b=0x592bb0u+(u32)slot*0x3c0;
  int mx=(s16)((int(*)(void))0x406000)(), my=(s16)((int(*)(void))0x406140)();
  int x=(s16)W(b+4), y=(s16)W(b+6), w=(s16)W(b+8), h=(s16)W(b+0xa);
  int in = mx>=x && mx<x+w && my>=y && my<y+h;
  W(b+0x12)=in?1:0;                                 /* hover flag read by the draw routine */
  u16 cur=W(0x4c5aa4); int click = in && cur && !s_prev; s_prev=cur;
  if(click){                                        /* same click sound the toolkit plays (poll 0x4772d2) */
    u32 snd=*(volatile u32*)0x4b95f0;
    if(snd){ typedef void (*SND)(u32,s32,s32,s32,s32); SND f=(SND)0x46f780; f(snd,0,0x40,0x55f0,0); f(*(volatile u32*)0x4b95f0,0x40,0x40,0x52d0,0x40); }
  }
  return click;
}
__asm__(".globl camp_esc_stub\ncamp_esc_stub:\n"            /* replaces movw $0x3e7,[0x5474b4] at 0x40d560 */
 " cmpb $0,g_ruleset\n je 1f\n movb $1,esc_pend\n movw $0,0x71b3e2\n push $0x40d56e\n ret\n"
 "1: movw $0x3e7,0x5474b4\n push $0x40d567\n ret\n");
__asm__(".globl camp_poll_stub\ncamp_poll_stub:\n"
 " mov $0x476aa0,%eax\n call *%eax\n"
 " call camp_post\n test %eax,%eax\n jz 1f\n"
 " movw $0x3e7,0x5474b4\n mov $1,%esi\n"
 "1: ret\n");
