#include "header.h"

//Made with some headache, errors, and funs
//9875,9880,9963,9879
//by KWB
//Thank you Sir Edu for StrukturData
//vER 27 November 2019, Last Fix 20.38
	
int main(int argc, char *argv[]) {
	
	ListParent LP,ListBaca;
	adrParent nota_single,nota_nama,E;
	adrChild child;
	Nota Data_Nota;
	JMakan J;
	
	char pil;
	
	string nama_p;
	string nama,keterangan,tanggal;
	string keyword;
	
	Nota N;
	Pesanan P;
	
	
	
	int X=0,cek=0;
	int xOrdinat,YOrdinat;
	int counter=0,cekMasukPertama=0;
	int menu,jumlah,cekPilih;
	int no,nomor_meja,showNomorMeja;
	
	float OmzetToday=0,OmzetAllTime=0;
	float harga,total,totNota;
	
	no_nota=0;
	maximize();
	init_List(&LP);
	init_List(&ListBaca);
	inieJumlah (&J);
	BacaNotaLaporan(&ListBaca,&OmzetAllTime,&OmzetToday);
	ReadMakananTerbanyak(&J);
	int *x;
	int y = 12;
	x = &y;
	cekMasukPertama++;
	do
	{
		SaveMakananTerbanyak(J);
		xOrdinat= 75;
		YOrdinat = 0;
		system("CLS");
		printf("%p",*x);
		system("COLOR F5");
		printf("\n\t================== LA GRANDE CAFE =================\n");
		printf("\n\t   [1] Menu Input Nota dan Menu");
		printf("\n\t   [2] Tampil Data Pembelian Customer");
		printf("\n\t   [3] Tambah Menu Makanan dan Minuman");
		printf("\n\t   [4] Pembayaran");
		printf("\n\t   [5] Laporan");
		printf("\n\t   [6] History");
		printf("\n\t   [ESC]. Keluar");
		printf("\n\t   Masukan Pilihan >>>> ");
		
		pil = getche();
		
		switch(pil)
		{
			case '1': 
				if(cekMasukPertama==1 && !isEmpty(ListBaca))
				{
					cekMasukPertama=0;
					no_nota=getNoNotaMax (ListBaca)+1;
				}else
				{
					no_nota++;
				}
				
				system("cls");
				printf("\n\t======================= MENU INPUT NOTA =======================\n");
				printf("\n\t Nomor Nota	: %d",no_nota);
				printf("\n\t Tanggal	: %s",GetSystemNow());

				int A[2]= {12,20};
				headerRingkasan(xOrdinat,YOrdinat,A,2,"Nomor Meja","Nama");
				YOrdinat +=4;
				for(showNomorMeja=1;showNomorMeja<=15;showNomorMeja++)
				{
					YOrdinat+=2;
					sprintf(nama,"%02d",showNomorMeja);
					strcpy(nama_p,GetNamaPembeli(LP,showNomorMeja));
					if(showNomorMeja==15)
					{
						isiRingkasan(xOrdinat,YOrdinat,A,1,2,nama,nama_p);
					}
					else
					{
						isiRingkasan(xOrdinat,YOrdinat,A,0,2,nama,nama_p);
					}
				}
				gotoxy(0,4);
				do{
					printf("\n\t Nomor Meja	: ");scanf("%d",&nomor_meja);
					if(nomor_meja>15 || nomor_meja<1)
					{
						printf("\n\t     [!] Nomor Meja yang dipilih Tidak ada!! [!]\n");
					}
				}while(nomor_meja>15 || nomor_meja<1);
			
				
				if(mejaisFound(LP,nomor_meja)==1)
				{
					printf("\t NOMOR MEJA SUDAH ADA YANG DUDUK");
					no_nota--;
					break;	
				}
				
				do{
					printf("\t Nama pelanggan	: ");fflush(stdin);gets(nama_p);
					if(strlen(nama_p)<1)
					{
						printf("\n\t     [!] Nama Pelanggan Tidak boleh Kosong!! [!]\n\n");
					}
				}while(strlen(nama_p)<1);
				
				sprintf(tanggal,"%s",GetSystemNow());
				N = makeNota(no_nota,nama_p,tanggal,nomor_meja,0);
				fflush(stdin);
				insertLastParent(&LP,N);
				cekPilih=0;
				do{
					system("cls");
					printf("\n\t=============================== MENU INPUT MAKANAN DAN MINUMAN ===============================\n");
					summonTabelMakanan(14,3);
					summonTabelMinuman(55,3);
					printf("\n\t==============================================================================================\n");
					printf("\n\t Date 		: %s",N.tanggalNota);
					printf("\n\t Customer	: %s",nama_p);
					printf("\n\t No. Meja	: %d",nomor_meja);
					
					if(totNota>1)
					{
						printf("\n\t Total Tagihan	: Rp. %.2f",totNota);	
					}
					menu=-1;
					do
					{
						printf("\n\n\t Masukan Pilihan [0 = SELESAI]	: ");scanf("%d",&menu);
						if(cekPilih==0 && menu!=0)
							cekPilih++;
					}while(cekPilih==0);
					if(menu>12 || menu<0)
					{
						printf("\n\t     [!] Makanan yang dipilih Tidak Ada!! [!]");
						getch();
					}else if (menu==0)
						break;
					else if (menu<7)
					{
						sprintf(nama,"%s",GetNamaMakanan(menu));
						harga=GetHargaMakanan(menu);
					
						
						printf("\t Makanan		: %s\n",nama);
						jumlah = 0;
						do{	
							printf("\t Masukan Jumlah Makanan	: ");
							fflush(stdin);
							scanf("%d",&jumlah);
							if(jumlah<1)
							{
								printf("\n\t     [!] Inputan Jumlah tidak Valid!! [!]\n");
							}
						}while(jumlah<1);
						J.makanan[menu-1]=J.makanan[menu-1]+jumlah;
						
						do{
							printf("\t Keterangan		: ");fflush(stdin);gets(keterangan);
							if(strlen(keterangan)>15)
							{
								printf("\n\t     [!] Inputan Keterangan hanya 15 huruf!! [!]\n");
							}
						}while(strlen(keterangan)>15);

						total=(float)jumlah*harga;
						totNota=totNota+total;
						P = makePesanan (nama,jumlah,harga, keterangan);
						
						nota_single=FindParentbyNomor(LP,nomor_meja);
						if(cekMakanan(nota_single->firstMakanan,nama)!=NULL)
						{
							
							child=cekMakanan(nota_single->firstMakanan,nama);
							child->M.jumlah_pcs+=jumlah;
						}
						else
						{
							insertLastMakanan(&LP,nomor_meja, P);
						}
						getch();
					}else if (menu>6 && menu <13)
					{
						sprintf(nama,"%s",GetNamaMinuman(menu));
						harga=GetHargaMinuman(menu);
						printf("\t Minuman		: %s\n",nama);
						do{	
							printf("\t Masukan Jumlah Minuman	: ");
							fflush(stdin);
							scanf("%d",&jumlah);
							if(jumlah<1)
							{
								printf("\n\t     [!] Inputan Jumlah tidak Valid!! [!]\n");
							}
						}while(jumlah<1);
						J.minuman[menu-7]=J.minuman[menu-7]+jumlah;
						printf("\t Keterangan		: ");fflush(stdin);gets(keterangan);

						total=(float)jumlah*harga;
						P = makePesanan (nama, jumlah, harga, keterangan);
						nota_single=FindParentbyNomor(LP,nomor_meja);
						if(cekMakanan(nota_single->firstMinuman,nama)!=NULL)
						{
							
							child=cekMakanan(nota_single->firstMinuman,nama);
							child->M.jumlah_pcs+=jumlah;
						}
						else
						{
							insertLastMinuman(&LP,nomor_meja, P);
						}
						
						totNota=totNota+total;
					}
				}while(menu!=0);
					E=FindParentbyNomor(LP,nomor_meja);
					E->N.total=totNota;
					
					printf("\n\t Total Tagihan	: Rp. %.2f",totNota);	
					getch();
					totNota = 0;
				break;
			
				
				case '2' :
					if(!isEmpty(LP))
					{
						system("cls");
						printf("\n\t==================== TAMPIL DATA PESANAN ====================\n");
						printAll(LP);
						getch();
					}else
					{
						printf("\n\n\t     [!] DATA PESANAN MASIH KOSONG!! [!]");
					}
					break;
				
				case '3' :
					if(!isEmpty(LP))
					{
						do
						{
							system("cls");
							printf("\n\t==================== TAMBAH MENU PESANAN ====================\n");
							tampilanListMeja(80,1,LP);
							gotoxy(0,2);
							printf("\n\t   Masukan keyword [Nomor Meja/Nama]	: ");fflush(stdin);gets(keyword);
							nota_single=FindParentbyNama(LP,keyword);// Cari nota berdasar nama pembeli
							if(nota_single!=NULL)
							{
								cek=1;
								getch();
								break;
							}
							else //Jika pakai nama tidak ketemu, pakai nomor meja
							{
								X = atoi(keyword);
								nota_single=FindParentbyNomor (LP,X);  // <- ini pakai nomor meja
								if(nota_single==NULL)
								{
									printf("\n\t     [!] Keyword Nota tidak ditemukan!! [!]");
									getch();
								}else
								{
									cek=2;
									getch();
									break;
								}
							}
						}while(nota_single==NULL );
						
						totNota = nota_single->N.total;
						do{
							system("cls");			
							printf("\n\t========================== MENU EDIT MAKANAN DAN MINUMAN ==========================\n");
							summonTabelMakanan(9,3);
							summonTabelMinuman(50,3);
							printf("\n\t====================================================================================\n");
							nomor_meja = nota_single->N.no_meja;
							if(cek==1)
							{
								printChildByParentNamaUntukEdit(97,0,LP,keyword);
							}else if (cek==2)
							{
								printChildByParentMakananUntukEdit(97,0,LP,X);
							}
							
							gotoxy(20,23);
							printf("\n\t Total Tagihan		: Rp. %.2f",totNota);	
							printf("\n\n\t Masukan Pilihan	: ");scanf("%d",&menu);
							if(menu>12 || menu<0)
							{
								printf("\n\t     [!] Menu yang dipilih Tidak Ada!! [!]");
								getch();
							}else if (menu==0)
								break;
							else if (menu<7)
							{
								sprintf(nama,"%s",GetNamaMakanan(menu));
								harga=GetHargaMakanan(menu);
								printf("\t Makanan		: %s\n",nama);
								jumlah = 0;
								do{	
									printf("\t Masukan Jumlah Makanan	: ");
									fflush(stdin);
									scanf("%d",&jumlah);
									if(jumlah<1)
									{
										printf("\n\t     [!] Inputan Jumlah tidak Valid!! [!]");
									}
								}while(jumlah<1);
								J.makanan[menu-1]=J.makanan[menu-1]+jumlah;
								
								printf("\t Keterangan		: ");fflush(stdin);gets(keterangan);
		
								total=(float)jumlah*harga;
								totNota=totNota+total;
								P = makePesanan (nama,jumlah,harga, keterangan);
								nota_single=FindParentbyNomor(LP,nomor_meja);
								if(cekMakanan(nota_single->firstMakanan,nama)!=NULL)
								{
									
									child=cekMakanan(nota_single->firstMakanan,nama);
									child->M.jumlah_pcs+=jumlah;
								}
								else
								{
									insertLastMakanan(&LP,nomor_meja, P);
								}
								getch();
							}else if (menu>6 && menu <13)
							{
								sprintf(nama,"%s",GetNamaMinuman(menu));
								harga=GetHargaMinuman(menu);
								printf("\t Minuman		: %s\n",nama);
								do{	
									printf("\t Masukan Jumlah Minuman	: ");
									fflush(stdin);
									scanf("%d",&jumlah);
									if(jumlah<1)
									{
										printf("\n\t     [!] Inputan Jumlah tidak Valid!! [!]");
									}
								}while(jumlah<1);
								J.minuman[menu-7]=J.minuman[menu-7]+jumlah;
								
								printf("\t Keterangan		: ");fflush(stdin);gets(keterangan);
		
								total=(float)jumlah*harga;
								P = makePesanan (nama, jumlah, harga, keterangan);
								nota_single=FindParentbyNomor(LP,nomor_meja);
								if(cekMakanan(nota_single->firstMinuman,nama)!=NULL)
								{
									
									child=cekMakanan(nota_single->firstMinuman,nama);
									child->M.jumlah_pcs+=jumlah;
								}
								else
								{
									insertLastMinuman(&LP,nomor_meja, P);
								}
								totNota=totNota+total;
							}
						}while(menu!=0);
							E=FindParentbyNomor(LP,nomor_meja);
							E->N.total=totNota;
							printf("\n\t Total Tagihan		: Rp. %.2f",totNota);	
							getch();
							totNota = 0;
							
					}else
					{
						printf("\n\n\t     [!] DATA PESANAN MASIH KOSONG!! [!]");
					}
					break;
				
			case '4' :
				if(!isEmpty(LP))
				{
					menuPembayaran (&LP);
				}else
				{
					printf("\n\n\t     [!] DATA PESANAN MASIH KOSONG!! [!]");
				}
				break;
			
			case '5' :
				init_List(&ListBaca);
				OmzetAllTime = 0;
				OmzetToday = 0;
				BacaNotaLaporan(&ListBaca,&OmzetAllTime,&OmzetToday);
				if(!isEmpty(ListBaca))
				{
					printf("\n\n\t  Total Omzet ALL time		: Rp. %.2f\n",OmzetAllTime);
					printf("\n\t  Total Omzet Hari ini 		: Rp. %.2f\n",OmzetToday);
					if(isEmptyMa(J)==99)
					{
						sprintf(nama,"%s",GetNamaMakanan(getindexMaxMakanan(J)));
						printf("\n\n\t   Makanan Terbanyak adalah %s",nama);
					}if(isEmptyMi(J)==99)
					{
						sprintf(nama,"%s",GetNamaMinuman(getindexMaxMinuman(J)));
						printf("\n\n\t   Minuman Terbanyak adalah %s",nama);
					}
				}else
				{
					printf("\n\n\t     [!] DATA PESANAN MASIH KOSONG!! [!]");
				}
				
				break;
			case '6' :
				init_List(&ListBaca);
				BacaNotaLaporan(&ListBaca,&OmzetAllTime,&OmzetToday);
				system("cls");
				printAll(ListBaca);
				getch();
			case 27 :
				
				break;
			
			default :
				
				break;
		}
		getch();
	}while(pil != 27);
	
	return 0;
}
