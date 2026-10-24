
/* test driver, compiled with: -include tools/saves_test.c -DUI_MOCK  src/ui/saves.c tools/saves_test_main.c */
u8 g_ruleset=1; void ruleset_init(void){}
static void run(int saving,int*sc,int n){ for(int i=0;i<64;i++)script[i]=600; for(int i=0;i<n;i++)script[i]=sc[i]; si_=0; nbtn=0; began=ended=0; if(saving)save_menu_dispatch(); else load_menu_dispatch(); }
static int has(int id){ for(int i=0;i<nbtn;i++) if(btn_ids[i]==id) return 1; return 0; }
int cmain(void){
  mm_(0x59f000,0x1000); mm_(0x592000,0x1000); mm_(0x835000,0x1000);
  /* only page 0 has files: load shows no Next, save shows no Next unless page 0 full */
  exists_[3]=1; s_page=0;
  { int sc[]={600}; run(0,sc,1); CHK(!has(602)&&!has(601),"L0 nav"); CHK(began==1&&ended==1,"L0 begin/end"); }
  { int sc[]={600}; run(1,sc,1); CHK(!has(602),"S0 no next while page not full"); }
  /* fill page 0 completely + file 12 on page 1 */
  for(int i=0;i<10;i++) exists_[i]=1; exists_[12]=1;
  { int sc[]={602,600}; run(0,sc,2); CHK(s_page==1,"L1 next -> page1"); CHK(has(601),"L1a prev present"); CHK(!has(602),"L1b no next"); CHK(began==2&&ended==2,"L1 rebuilds"); }
  { s_page=1; *(short*)0x835034=-1; int sc[]={2}; run(0,sc,1); CHK(*(short*)0x835034==12,"L3 page1 id2 -> slot 12"); }
  { s_page=1; *(short*)0x835034=-1; int sc[]={3}; run(0,sc,1); CHK(*(short*)0x835034==-1,"L4 empty slot ignored"); }
  { s_page=0; *(short*)0x835034=-1; int sc[]={601,5}; run(0,sc,2); CHK(*(short*)0x835034==5,"L5 page0 slot5"); }
  /* page 1 has a file but is not full -> save has 2 pages only; fill page 1 -> 3 pages */
  { s_page=1; saved_slot=-99; int sc[]={4}; run(1,sc,1); CHK(saved_slot==14,"S1 save page1 id4 -> slot 14"); CHK(!has(602),"S1 no page 3 yet"); }
  for(int i=10;i<20;i++) exists_[i]=1;
  { s_page=1; int sc[]={600}; run(1,sc,1); CHK(has(602)&&has(601),"S2 page 3 appears when page 2 full"); }
  { s_page=1; int sc[]={602,0}; saved_slot=-99; run(1,sc,2); CHK(saved_slot==20,"S3 new page -> slot 20"); }
  { s_page=2; int sc[]={600}; run(0,sc,1); CHK(s_page==1,"L6 load clamps to last page with a file"); }
  exists_[13]=0;
  { s_page=1; deleted_=-1; int sc[]={102,0,600}; run(0,sc,3); CHK(deleted_==-1,"D1 No keeps file"); CHK(has(ID_DEL+2),"D1b delete btn on existing"); CHK(!has(ID_DEL+3),"D1c none on empty"); }
  { s_page=1; deleted_=-1; int sc[]={102,10,1,600}; run(0,sc,4); CHK(deleted_==12,"D2 Yes deletes slot 12 (label clicks ignored)"); }
  { s_page=0; deleted_=-1; int sc[]={105,1,600}; run(1,sc,3); CHK(deleted_==5,"D3 save menu delete slot 5"); }
  sc_(4,1,(int)(fails?"FAIL\n":"ok\n"),fails?5:3); return fails; }
__asm__(".globl _start\n_start:\n call cmain\n mov %eax,%ebx\n mov $1,%eax\n int $0x80\n");
