/* MULTIPLAYER / SKIRMISH LOBBY (0x440450) changes for the ENHANCED ruleset (ruleset=1). See functions/00440450.md.
 * FACTS [O]: rows 0..5; row r = slot button id r (type 7 "None|AI Player" for empty rows), its faction button id r+0x32 ("7th|Ch", 0/1).
 * Humans occupy rows 0..H-1 (H = word 0x9e7600). Host flag word 0x4aee00 (1 = created the game), skirmish flag dword 0x719fa4 (1).
 * Button toolkit: 0x475be0(id,en) sets enabled (slot+0x10), 0x475cd0(id,v) sets value (slot+0x14), 0x476010(id) reads value.
 * Original: every empty row and every AI faction button is disabled on each refresh (0x440add..0x440b63); skirmish only forces
 * row H to AI. At start (0x441563..) factions are read in ROW order into 0x6df140[1+r] and AIs are counted, so AI players
 * H+1..H+n take factions from rows H..H+n-1 => AI rows must be contiguous.
 * Hook 1 (0x440add, `cmp [0x4aee00],si` 7 bytes): per empty row r=EDI: editable (host or skirmish) => row enabled, faction enabled iff AI.
 * Hook 2 (0x441563, `xor si,si; mov [0x8574f8],ax` 9 bytes): pack AI rows (value 1) to H.. keeping their faction values. Runs on
 * every peer from the same synced button values => same result everywhere (lockstep-safe). */
typedef unsigned short u16; typedef short s16; typedef unsigned int u32;
extern unsigned char g_ruleset; void ruleset_init(void); void teams_from_lobby(void);
#define EN(id,v)  ((void(*)(int,int))0x475be0)((id),(v))
#define SETV(id,v) ((void(*)(int,int))0x475cd0)((id),(v))
#define GETV(id)  ((s16)((int(*)(int))0x476010)((id)))
#define HUMANS    (*(volatile s16*)0x9e7600)
int lobby_row_patch(int r){                 /* returns 1 => handled (skip original), 0 => run original code */
  ruleset_init();
  if(!g_ruleset) return 0;
  int edit = *(volatile s16*)0x4aee00==1 || *(volatile u32*)0x719fa4==1;
  int ai = GETV(r)==1;
  EN(r, edit);
  EN(r+0x32, edit && ai);
  return 1;
}
void lobby_pack_ai(void){
  ruleset_init();
  if(!g_ruleset) return;
  int h=HUMANS, n=0; s16 side[6], team[6];
  if(h<0||h>6) return;
  for(int r=h;r<6;r++) if(GETV(r)==1){ side[n]=GETV(r+0x32); team[n]=GETV(0x69+r); n++; }   /* team buttons: src/sim/teams.c */
  for(int r=h;r<6;r++){ int k=r-h; SETV(r, k<n ? 1:0); SETV(r+0x32, k<n ? side[k] : 0); SETV(0x69+r, k<n ? team[k] : 0); }
  teams_from_lobby();
}
__asm__(".globl lobby_row_stub\nlobby_row_stub:\n"           /* at 0x440add; EDI=row, ESI=1 */
 " pushl %edi\n call lobby_row_patch\n add $4,%esp\n test %eax,%eax\n jz 1f\n"
 " mov $0x440b63,%eax\n jmp *%eax\n"
 "1: cmp %si,0x4aee00\n mov $0x440ae4,%eax\n jmp *%eax\n");   /* mov keeps flags; 0x440ae4 = jnz */
__asm__(".globl lobby_start_stub\nlobby_start_stub:\n"       /* at 0x441563; AX = local_14 must reach [0x8574f8] */
 " pushal\n call lobby_pack_ai\n popal\n"
 " xor %si,%si\n mov %ax,0x8574f8\n mov $0x44156c,%ecx\n jmp *%ecx\n");
