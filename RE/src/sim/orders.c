/* Phase 2 sim fixes (ruleset=1 only). Freestanding, linked at 0xade000 with the other patch objects.
 * Fix A: PostOrder (0x423710) drops an order identical to ent+0x78..0x80 (last order record) even when the unit has
 * long since gone idle (arrived short / blocked / aborted) -> "unit ignores my command". Skip the dedupe when idle. */
typedef unsigned short u16;
extern unsigned char g_ruleset; extern void ruleset_init(void);   /* u8! (was int: read g_inited too -> fixes ran with ruleset=0) */
#define ENT 0x67fe10u
/* off = byte offset of the entity (edi in PostOrder). Return 1 => bypass dedupe. */
int post_dedupe_skip(unsigned off){
    ruleset_init();
    if(!g_ruleset) return 0;
    return *(volatile u16*)(ENT+off+0x62)==0;      /* order state 0 = IDLE */
}
/* Stub patched over `cmp %si,0x67fe88(%edi)` at 0x42383f (7 bytes -> jmp + 2 nop). esi=kind, edi=ent off must survive. */
__asm__(".globl post_dedupe_stub\npost_dedupe_stub:\n"
 "push %edi\n call post_dedupe_skip\n add $4,%esp\n"
 "test %eax,%eax\n jnz 1f\n"
 "cmp %si,0x67fe88(%edi)\n"      /* original instruction */
 "mov $0x423846,%eax\n jmp *%eax\n"
 "1: mov $0x423880,%eax\n jmp *%eax\n");

/* Fix B: fire-on-move for plain Move (mode 4). Movement integrator 0x44e8d0 only runs its opportunistic-fire scan
 * (visible enemy in range -> aim/fire without stopping) for modes 5/8 or AI owners. With ruleset=1 mode 4 is treated as 5.
 * Patched at 0x44f471: `mov 0x67fe7e(%esi),%ax` (7 bytes) -> jmp stub; stub returns to 0x44f478 (cmp $5,%ax). Defensive (6) stays quiet. */
int mode_fix(int mode){ ruleset_init(); return (g_ruleset && mode==4) ? 5 : mode; }
__asm__(".globl mode_stub\nmode_stub:\n"
 "mov 0x67fe7e(%esi),%ax\n"
 "push %ecx\n push %edx\n movswl %ax,%eax\n push %eax\n call mode_fix\n add $4,%esp\n pop %edx\n pop %ecx\n"
 "push $0x44f478\n ret\n");
