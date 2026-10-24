/* UI hook for the ENHANCED ruleset (patch section .patch, built with path_new.c).
 * Feature: hold A + left-click = AGGRESSIVE move/attack (movement characteristic 2) for the selected units. Ctrl+click keeps its vanilla force-attack.
 * Game facts (details in functions/00463550.md): local-UI order fn 0x463550 G(kind: 1 move, 2 attack); word [0x4e12d4] = style 0 Normal/1 Defensive/2 Aggressive,
 * captured at button press from default [0x859580] (0x463687); on release PostOrder + SetUnitMode(ent, mode) with move 4/6/5, attack 7/9/8.
 * 'A' key held = word [0x71b41c] (local scancode array 0x71b3e0, 0x1e*2).
 * Patch: 0x463687  mov [0x859580],%bx  ->  call hook_style. Only selects which mode the local player posts => lockstep-safe. */
typedef signed short s16; typedef unsigned short u16; typedef unsigned char u8; typedef unsigned int u32; typedef int s32;
#define U16(a) (*(volatile u16*)(u32)(a))
extern u8 g_ruleset; void ruleset_init(void);

u32 ui_style(s32 kind){
  u16 def=U16(0x859580);
  ruleset_init();
  if(!g_ruleset || U16(0x71b41c)==0 || (kind!=1 && kind!=2)) return def;
  return 2;
}

__asm__(
".text\n.globl hook_style\nhook_style:\n"            /* ret addr at [esp]; G's kind arg at [esp+4+0x28] */
" pushf\n push %eax\n push %ecx\n push %edx\n"
" movswl 0x3c(%esp),%eax\n"                    /* 4 pushes (16) + ret (4) + 0x28 = 0x3c */
" push %eax\n call ui_style\n add $4,%esp\n"
" mov %ax,%bx\n"
" pop %edx\n pop %ecx\n pop %eax\n popf\n ret\n");
