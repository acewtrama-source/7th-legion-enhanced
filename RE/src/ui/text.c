/* UI text overrides for the ENHANCED ruleset (ruleset=1). No data files are changed.
 * FACT: 0x450cb0 LoadLanguageText fills 0x85ef60 + i*0x50 (80-byte slots, i = 0-based line of DATA\gametext.txt;
 * language 0x4b9608: 0 gametext, 1 jivtext, 2 fretext, 3 spmtext). Callers: 0x40db87, 0x4510b0 (both redirected here).
 * Line 253 (slot 252, 0x863e20) = main-menu "Multiplayer Game" -> "Multiplayer or Skirmish" (English and jive only). */
typedef unsigned int u32;
extern unsigned char g_ruleset; void ruleset_init(void);
#define TEXT(i) ((char*)(0x85ef60u+(u32)(i)*0x50u))
static void put(int line, const char *s){ char *d=TEXT(line-1); int n=0; while(s[n] && n<0x4f){ d[n]=s[n]; n++; } d[n]=0; }
void text_load_hook(void){
  ((void(*)(void))0x450cb0)();
  ruleset_init();
  if(!g_ruleset) return;
  u32 lang=*(volatile u32*)0x4b9608;
  if(lang==0) put(253,"Multiplayer or Skirmish");
  else if(lang==1) put(253,"Multiplaya' or Skirmish");
}
