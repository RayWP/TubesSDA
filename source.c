#include "header.h"

void init_List(ListParent *LP)
{
	(*LP).first = NULL;
}

adrParent alokasiNota(Nota N)
{
	adrParent P=NULL;
	P = (adrParent) malloc(sizeof(Parent));
	P->N = N;
	P->nextParent = NULL;
	P->firstMakanan = NULL;
	P->firstMinuman = NULL;
	
	return P;
}

adrChild alokasiMenu(Pesanan M)
{
	adrChild menu;
	menu = (adrChild) malloc(sizeof(ChildPesanan));
	menu->M = M;
	menu->nextMenu = NULL;
	
	return menu;
}

Nota makeNota (int no_nota, string nama, string tanggalnota, int no_meja, float total)
{
	Nota N;
	
	N.no_nota=no_nota;	
	strcpy(N.nama,nama);
	strcpy(N.tanggalNota,tanggalnota);
	N.no_meja=no_meja;
	N.total=total;
	
	return N;
}

Pesanan makePesanan ( string nama,int jumlah,float harga, string keterangan)
{
	Pesanan M;
	strcpy(M.nama,nama);
	M.jumlah_pcs = jumlah;
	M.harga = harga;
	strcpy(M.keterangan,keterangan);
	return M;
}

/* TANGGAAAAL */
char* GetSystemNow()
{
	string a;
	int day, month, year;
	string tanggal;

	time_t now;
	strcpy(tanggal,"");

	time(&now);

    struct tm* local = localtime(&now);


	day = local->tm_mday;			// get day of month (1 to 31)
	month = local->tm_mon  + 1;		// get month of year (0 to 11)
	year = local->tm_year + 1900 ;
	
	
	sprintf(tanggal,"%02d %s %04d",day,GetBulan(month),year);
	
	return tanggal;
	
}

char* GetBulan(int bulan)
{
	switch(bulan)
	{
		case 1 :
			return "Januari";
			break;
		
		case 2 :
			return "Febreuari";
			break;
		
		case 3 :
			return "Maret";
			break;
		
		case 4 :
			return "April";
			break;
		
		case 5 :
			return "Mei";
			break;
		
		case 6 :
			return "Juni";
			break;
		
		case 7 :
			return "Juli";
			break;
		
		case 8 :
			return "Agustus";
			break;
			
		case 9 :
			return "September";
			break;
			
		case 10 :
			return "Oktober";
			break;
		
		case 11:
			return "November";
			break;
		
		case 12:
			return "Desember";
			break;
		
	}
}

/*TANGGGAAAL AKHIR*/



void inputNota (ListParent *LP)
{
	printf("\n\nMENU INPUT DATA NOTA");
}

void insertFirstParent(ListParent *L, Nota N)
{
	adrParent P;
	P=alokasiNota(N);
	P->nextParent=(*L).first;
	(*L).first=P;
}

void insertLastParent(ListParent *L,Nota X)
{
	adrParent P,last;
	if(isEmpty(*L))
		insertFirstParent(&(*L),X);
	else{
		P=alokasiNota(X);
		last=(*L).first;
		while(last->nextParent!=NULL)
		{
			last=last->nextParent;
		}
		last->nextParent=P;
	}	
}

int isEmpty(ListParent L)
{
	if(L.first==NULL)
		return 1;
	else
		return 0;
}

int HaveChildMakanan (adrParent P)
{
	if(P->firstMakanan!=NULL)
		return 1;
	else
		return 0;	
}

int HaveChildMinuman (adrParent P)
{
	if(P->firstMinuman!=NULL)
		return 1;
	else
		return 0;	
}

adrParent FindParentbyNomor (ListParent L,int id)
{
	adrParent P=L.first;
	while(P!=NULL && P->N.no_meja!=id)
	{
		P=P->nextParent;
	}
	return P;
}

adrParent FindParentbyNota (ListParent L,int id)
{
	adrParent P=L.first;
	while(P!=NULL && P->N.no_nota!=id)
	{
		P=P->nextParent;
	}
	return P;
}


adrParent FindParentbyNama (ListParent L,string nama)
{
	adrParent P=L.first;
	while(P!=NULL && strcmpi(P->N.nama,nama)!=0)
	{
		P=P->nextParent;
	}
	return P;
}

void deleteFirstParent(ListParent *L)
{
	adrParent del;
	if(isEmpty(*L))
		printf("List kosong");
	else
	{
		del=(*L).first;
		(*L).first=(*L).first->nextParent;
		free(del);
	}	
}


void deleteAtParent(ListParent *L, adrParent X)
{
	adrParent del;
	adrParent P = (*L).first;
	if(P==X)
	{
		deleteFirstParent(&(*L));
	}
	else
	{
		while(P!=NULL)
		{
			if(P->nextParent==X)
			{
				while(P->nextParent->firstMakanan!=NULL)
				{
					
					deleteFirstMakanan (&P->nextParent);
				}
				
				while(P->nextParent->firstMinuman!=NULL)
				{
					deleteFirstMinuman (&P->nextParent);
				}
//				
				del=X;
				P->nextParent=P->nextParent->nextParent;
				free(del);
				break;
			}
			P=P->nextParent;	
		}
			
	}	
}

void deleteFirstMakanan (adrParent *X)
{
	adrChild c;
	c=(*X)->firstMakanan;
	(*X)->firstMakanan = (*X)->firstMakanan->nextMenu;
	free(c);
}

void deleteFirstMinuman (adrParent *X)
{
	adrChild c;
	c=(*X)->firstMinuman;
	(*X)->firstMinuman=(*X)->firstMinuman->nextMenu;
	free(c);
}

void insertFirstMakanan(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C;
	adrParent P;
	P=FindParentbyNomor((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else
	{
		C=alokasiMenu(X);
		C->nextMenu=P->firstMakanan;
		P->firstMakanan=C;
	}	
}

void insertFirstMinuman(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C;
	adrParent P;
	P=FindParentbyNomor((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else
	{
		C=alokasiMenu(X);
		C->nextMenu=P->firstMinuman;
		P->firstMinuman=C;
	}	
}

void insertLastMakanan(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C, lastChild;
	adrParent P;
	
	P=FindParentbyNomor((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChildMakanan(P))
	{
//		printf("nomor nota: %d",P->N.no_nota);
		insertFirstMakanan(&(*L),no_nota,X);
	}
	else
	{
		C=alokasiMenu(X);
		lastChild=P->firstMakanan;
		while(lastChild->nextMenu!=NULL)
		{
			lastChild=lastChild->nextMenu;
		}
		lastChild->nextMenu=C;
	}				
}
///////////////////////////////////////////////////////////////////////////
void insertFirstMakananforFH(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C;
	adrParent P;
	P=FindParentbyNota((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else
	{
		C=alokasiMenu(X);
		C->nextMenu=P->firstMakanan;
		P->firstMakanan=C;
	}	
}

void insertLastMakananforFH(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C, lastChild;
	adrParent P;
	
	P=FindParentbyNota((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChildMakanan(P))
	{
		insertFirstMakananforFH(&(*L),no_nota,X);
	}
	else
	{
		C=alokasiMenu(X);
		lastChild=P->firstMakanan;
		while(lastChild->nextMenu!=NULL)
		{
			lastChild=lastChild->nextMenu;
		}
		lastChild->nextMenu=C;
	}				
}
void insertLastMinumanforFH(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C, lastChild;
	adrParent P;
	P=FindParentbyNota((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChildMinuman(P))
		insertFirstMinumanforFH(&(*L),no_nota,X);
	else
	{
		C=alokasiMenu(X);
		lastChild=P->firstMinuman;
		while(lastChild->nextMenu!=NULL)
		{
			lastChild=lastChild->nextMenu;
		}
		lastChild->nextMenu=C;
	}				
}

void insertFirstMinumanforFH(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C;
	adrParent P;
	P=FindParentbyNota((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else
	{
		C=alokasiMenu(X);
		C->nextMenu=P->firstMinuman;
		P->firstMinuman=C;
	}	
}


////////////////////////////////////////////////////////////////////////////
void insertLastMinuman(ListParent *L,int no_nota, Pesanan X)
{
	adrChild C, lastChild;
	adrParent P;
	P=FindParentbyNomor((*L),no_nota);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChildMinuman(P))
		insertFirstMinuman(&(*L),no_nota,X);
	else
	{
		C=alokasiMenu(X);
		lastChild=P->firstMinuman;
		while(lastChild->nextMenu!=NULL)
		{
			lastChild=lastChild->nextMenu;
		}
		lastChild->nextMenu=C;
	}				
}

void printChildByParentNama(ListParent L,string idP)
{
	adrParent P;
	adrChild C;
	int x = 10;
	int y= 0;
	
	int A[3]={20,20,20};
	string temp;
	if(isEmpty(L))
		printf("List kosong");
	else
	{
		P=FindParentbyNama(L,idP);
		if(P==NULL)
			printf("\nParent tdk ada");
		else
		{
			printf("\n\t   Nomor Nota	 	: %d",P->N.no_nota);
			printf("\n\t   Nomor Meja		: %d",P->N.no_meja);
			printf("\n\t   Customer			: %s",P->N.nama);
			if(!HaveChildMakanan(P) && !HaveChildMinuman(P))			
				printf("\nTidak punya anak");	
			else
			{
				y+=3;
				printf("\n\t   Nomor Nota	 	: %d",P->N.no_nota);
				printf("\n\t   Nomor Meja		: %d",P->N.no_meja);
				printf("\n\t   Customer			: %s",P->N.nama);
				if(!HaveChildMakanan(P) && !HaveChildMinuman(P))	
				{		
					printf("\n\t  [!] Tidak Ada Menu yang di Pesan!! [!]");	
				}
				else
				{
					y+=2;
					headerRingkasan(x,y,A,3,"NAMA","JUMLAH","Keterangan");
					y+=4;
					C= P->firstMakanan;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL && P->firstMinuman == NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
						}
						else 
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
						}
						C=C->nextMenu;
					}
					C= P->firstMinuman;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
						}
						else
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
						}
						C=C->nextMenu;
					}
				}	
			}	
		}		
	}
}

void printChildByParentMakanan(ListParent L,int idP)
{
	adrParent P;
	adrChild C;
	int x = 10;
	int y= 5;
	int A[3]={20,20,20};
	string temp;
	string harga;
	
	if(isEmpty(L))
		printf("List kosong");
	else
	{
		P=FindParentbyNomor(L,idP);
		if(P==NULL)
			printf("\nParent tdk ada");
		else
		{
				y+=3;
				printf("\n\t Nomor Nota	 	: %d",P->N.no_nota);
				printf("\n\t Nomor Meja		: %d",P->N.no_meja);
				printf("\n\t Customer		: %s",P->N.nama);
				if(!HaveChildMakanan(P) && !HaveChildMinuman(P))	
				{		
					printf("\n\t  [!] Tidak Ada Menu yang di Pesan!! [!]");	
				}
				else
				{
					y+=2;
					headerRingkasan(x,y,A,3,"NAMA","JUMLAH","HARGA");
					y+=4;
					C= P->firstMakanan;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						sprintf(harga,"%.2f",C->M.harga);
						if(C->nextMenu==NULL && P->firstMinuman == NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,harga);
						}
						else 
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,harga);
						}
						C=C->nextMenu;
					}
					C= P->firstMinuman;
					while(C!=NULL)
					{
						y+=2;
						sprintf(harga,"%.2f",C->M.harga);
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,harga);
						}
						else
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,harga);
						}
						C=C->nextMenu;
					}
			}	
		}		
	}
}


void printChildByParentNamaUntukEdit(int x, int y,ListParent L,string idP)
{
	adrParent P;
	adrChild C;
	
	int A[3]={20,15,20};
	string temp;
	if(isEmpty(L))
		printf("List kosong");
	else
	{
		P=FindParentbyNama(L,idP);
		if(P==NULL)
			printf("\nParent tdk ada");
		else
		{
			if(!HaveChildMakanan(P) && !HaveChildMinuman(P))			
				printf("\nTidak punya anak");	
			else
			{
				y+=0;
				printf("\n\t Nomor Nota	 	: %d",P->N.no_nota);
				printf("\n\t Nomor Meja		: %d",P->N.no_meja);
				printf("\n\t Customer		: %s",P->N.nama);
				if(!HaveChildMakanan(P) && !HaveChildMinuman(P))	
				{		
					printf("\n\t  [!] Tidak Ada Menu yang di Pesan!! [!]");	
				}
				else
				{
					y+=2;
					headerRingkasan(x,y,A,3,"NAMA","JUMLAH","Keterangan");
					y+=4;
					C= P->firstMakanan;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL && P->firstMinuman == NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
						}
						else 
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
						}
						C=C->nextMenu;
					}
					C= P->firstMinuman;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
						}
						else
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
						}
						C=C->nextMenu;
					}
				}	
			}	
		}		
	}
}

void printChildByParentMakananUntukEdit(int x,int y,ListParent L,int idP)
{
	adrParent P;
	adrChild C;
	int A[4]={20,15,20};
	string temp;
	if(isEmpty(L))
		printf("List kosong");
	else
	{
		P=FindParentbyNomor(L,idP);
		if(P==NULL)
			printf("\nParent tdk ada");
		else
		{
				y+=0;
				printf("\n\t   Nomor Nota	 	: %d",P->N.no_nota);
				printf("\n\t   Nomor Meja		: %d",P->N.no_meja);
				printf("\n\t   Customer		: %s",P->N.nama);
				if(!HaveChildMakanan(P) && !HaveChildMinuman(P))	
				{		
					printf("\n\t  [!] Tidak Ada Menu yang di Pesan!! [!]");	
				}
				else
				{
					y+=2;
					headerRingkasan(x,y,A,3,"NAMA","JUMLAH","Keterangan");
					y+=4;
					C= P->firstMakanan;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL && P->firstMinuman == NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
						}
						else 
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
						}
						C=C->nextMenu;
					}
					C= P->firstMinuman;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL)
						{
							isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
						}
						else
						{
							isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
						}
						C=C->nextMenu;
					}
			}	
		}		
	}
}

void printChildUntukHapus(int x, int y,adrParent P)
{
	adrChild C;
	
	int A[3]={10,15,20};
	string nomor;
	string temp;
				
		y+=2;
		headerRingkasan(x,y,A,3,"NO","NAMA","JUMLAH");
		y+=4;
		C= P->firstMakanan;
		int i = 0;
		while(C!=NULL)
		{
			i++;
			y+=2;
			sprintf(temp,"%d",C->M.jumlah_pcs);
			sprintf(nomor,"%02d",i);
			if(C->nextMenu==NULL && P->firstMinuman == NULL)
			{
				isiRingkasan(x,y,A,1,3,nomor,C->M.nama,temp);
			}
			else 
			{
				isiRingkasan(x,y,A,0,3,nomor,C->M.nama,temp);
			}
			C=C->nextMenu;
		}
		C= P->firstMinuman;
		while(C!=NULL)
		{
			i++;
			y+=2;
			sprintf(nomor,"%02d",i);
			sprintf(temp,"%d",C->M.jumlah_pcs);
			if(C->nextMenu==NULL)
			{
				isiRingkasan(x,y,A,1,3,nomor,C->M.nama,temp);
			}
			else
			{
				isiRingkasan(x,y,A,0,3,nomor,C->M.nama,temp);
			}
			C=C->nextMenu;
		}
}	
	


void printAll(ListParent L)
{
	adrParent P;
	string temp;
	adrChild C;
	int x = 10;
	int y= 0;
	int A[3]={20,20,20};
	if(isEmpty(L))
		printf("List kosong");
	else
	{
		P=L.first;
		while(P!=NULL)
		{
			y+=3;
			printf("\n\t   Nomor Nota	 	: %d",P->N.no_nota);
			printf("\n\t   Nomor Meja		: %d",P->N.no_meja);
			printf("\n\t   Customer		: %s",P->N.nama);
			printf("\n\t   Total Tagihan	: Rp. %.2f",P->N.total);
			if(!HaveChildMakanan(P) && !HaveChildMinuman(P))	
			{		
				printf("\n\t  [!] Tidak Ada Menu yang di Pesan!! [!]");	
			}
			else
			{
				y+=3;
				headerRingkasan(x,y,A,3,"NAMA","JUMLAH","Keterangan","Harga");
				y+=4;
				C= P->firstMakanan;
				while(C!=NULL)
				{
					y+=2;
					sprintf(temp,"%d",C->M.jumlah_pcs);
					if(C->nextMenu==NULL && P->firstMinuman == NULL)
					{
						isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
					}
					else 
					{
						isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
					}
					C=C->nextMenu;
				}
				C= P->firstMinuman;
				while(C!=NULL)
				{
					y+=2;
					sprintf(temp,"%d",C->M.jumlah_pcs);
					if(C->nextMenu==NULL)
					{
						isiRingkasan(x,y,A,1,3,C->M.nama,temp,C->M.keterangan);
					}
					else
					{
						isiRingkasan(x,y,A,0,3,C->M.nama,temp,C->M.keterangan);
					}
					C=C->nextMenu;
				}
			}
			P=P->nextParent;
			printf("\n\t===============================================================\n");	
		}
	}		
}

void menuPembayaran (ListParent *LP)
{
	char pil;
	
	do{
		system("cls");
		printf("\n\t======================= MENU PEMBAYARAN =======================\n");
		printf("\n\t   [1] Menggabungkan Nota");
		printf("\n\t   [2] Memisahkan Nota");
		printf("\n\t   [3] Bayar Langsung");
		printf("\n\t   Masukan Pilihan >>> ");
		pil=getche();
		
		switch(pil)
		{
			case '1' :
				system("cls");
				printf("\n\t======================= MENGGABUNGKAN NOTA =======================\n");
				if(getJumlahNota(*LP)>1)
				{
					gabungNota (&(*LP));
					sortingNota (&(*LP));
				}else
				{
					printf("\n\t            [!] Jumlah Nota Hanya 1[!]");
				}
				break;
			
			case '2' :
				system("cls");
				printf("\n\t======================= MEMISAHKAN NOTA =======================\n");
				splitNota (&(*LP));
				break;
			
			case '3' :
				system("cls");
				printf("\n\t======================= MENU PEMBAYARAN TAGIHAN =======================\n");
				menuPembayaranLangsung (&(*LP));
				break;
			
			case 27 :
				break;
				
			default :
				printf("\n\t     [!] Menu yang dipilih Tidak Ada!! [!]");
				break;
		}
		getch();
	}while(pil!=27);
}

void menuPembayaranLangsung (ListParent *LP)
{
	adrParent nota_single;
	Pesanan pesan;
	int cek=0,X=0;
	float uang,bayar;
	
	string keyword;
	do
	{
		tampilanListMeja(80,0,*LP);
		gotoxy(0,2);
		printf("\n\t   Masukan keyword [Nomor Meja/Nama]	: ");fflush(stdin);gets(keyword);
		
		nota_single=FindParentbyNama(*LP,keyword);
		if(nota_single!=NULL)
		{
			cek=1;
			getch();
			break;
		}
		else 
		{
			X = atoi(keyword);
			nota_single=FindParentbyNomor (*LP,X);
			if(nota_single==NULL)
			{
				printf("\n\t          [!] Keyword Nota tidak ditemukan!! [!]");
				return 0;
				getch();
			}else
			{
				cek=2;
				getch();
				break;
			}
		}
	}while(nota_single==NULL);
	
		if(cek==1)
		{
			printChildByParentNama(*LP,keyword);
		}else if (cek==2)
		{
			printChildByParentMakanan(*LP,X);
		}
			bayar=nota_single->N.total;
			printf("\n\t   Total Tagihan		: Rp. %.2f",bayar);
	do{
		printf("\n\t   Masukan Uang Anda		: Rp. ");scanf("%f",&uang);
		if(uang < bayar)
		{
			printf("\n\t         [!] Uang Anda Kurang!! [!]\n");
		}
	}while(uang<bayar);
	
	if(uang>bayar)
	{
		printf("\n\t   Kembalian			: Rp. %.2f",uang-bayar);
	}
	
	pesan.jumlah_pcs=0;
	insertLastMakanan(&(*LP),nota_single->N.no_meja,pesan);
	insertLastMinuman(&(*LP),nota_single->N.no_meja,pesan);
	SaveNotaLaporan(nota_single);
	deleteAtParent(&(*LP), nota_single);
	
	printf("\n\n\t          [~] PEMBAYARAN BERHASIL [~]");
	getch();
}

void gabungNota (ListParent *LP)
{
	adrParent nota_single;
	string keyword;
	int cek=0,X=0;
	float bayar,uang;
	ListParent B;
	init_List(&B);
	int i=1,jml;
	adrChild Ma=NULL;
	adrChild Mi=NULL;
	int cekP=0;
	Pesanan pesan;
	int nomeja;
	
	tampilanListMeja(80,1,*LP);
	gotoxy(15,2);
	adrParent K;
//	K=getLastParent ((*LP));
	int o=getJumlahNota (*LP);
	printf("\n\t  Jumlah Nota 		:  %d",o);
	do{
		printf("\n\t  Masukan Jumlah Nota	: ");scanf("%d",&jml);
		if(o<jml || jml<=1)
		{
			printf("\n\t     [!] Jumlah Nota Tidak sesuai dengan Data yang ada!! [!]");
		}
	}while(o<jml || jml<=1);
	no_nota-=jml-1;
	
	do
	{
		printf("\n\t   Masukan keyword %d [Nomor Meja/Nama]	: ",i);fflush(stdin);gets(keyword);
		Ma = NULL;
		Mi = NULL;
		nota_single=FindParentbyNama((*LP),keyword);	
		if(nota_single!=NULL)
		{
			nota_single=FindParentbyNama((*LP),keyword);	
		}else
		{
			X = atoi(keyword);
			nota_single=FindParentbyNomor((*LP),X);	
		}
		
		Ma=nota_single->firstMakanan;
		Mi=nota_single->firstMinuman;
		int nomor_meja= nota_single->N.no_nota;
		if(nota_single!=NULL)
		{
			cek=1;
			i++;
			jml--;
			
			if(cekP==0)
			{
				cekP++;
				insertLastParent(&B,nota_single->N);
				nomeja=nota_single->N.no_meja;/// AMAN
			}
			
			while(Ma!=NULL)
			{
				getch();
				insertLastMakanan(&B,nomeja,Ma->M);
				Ma=Ma->nextMenu;
			}
			while(Mi!=NULL)
			{
				insertFirstMinuman(&B,nomeja,Mi->M);
				Mi=Mi->nextMenu;
			}
			bayar=bayar+nota_single->N.total;
			deleteAtParent(&(*LP), nota_single);
		}
		else 
		{
			printf("\n\t          [!] Keyword Nota tidak ditemukan!! [!]");
		}
		
		
	}while(nota_single==NULL || jml!=0);
	

	system("cls");
	printAll(B);
	
	
	printf("\n\t   Total Tagihan		: Rp. %.2f",bayar);
	do{
		printf("\n\t   Masukan Uang Anda		: ");scanf("%f",&uang);
		if(uang < bayar)
		{
			printf("\n\t     [!] Uang Anda Kurang!! [!]");
		}
	}while(uang<bayar);
	
	if(uang>bayar)
	{
		printf("\n\t   Kembalian		: Rp. %.2f",uang-bayar);
	}
	
	printf("\n\t          [!] PEMBAYARAN BERHASIL [!]");
	
	pesan.jumlah_pcs=0;
	B.first->N.total = bayar;
	insertLastMakanan(&B,B.first->N.no_meja,pesan);
	insertLastMinuman(&B,B.first->N.no_meja,pesan);
	SaveNotaLaporan(B.first);
	
	deleteAtParent(&B, nota_single);
	
	getch();
	
}

/*Tambahan ku*/
int mejaisFound(ListParent LP,int nomor_meja)
{
	adrParent X = LP.first;
	while(X!=NULL)
	{
		if(X->N.no_meja == nomor_meja)
		{
			return 1;
		}	
		X=X->nextParent;
	}
	return 0;
}

char* GetNamaPembeli(ListParent LP,int nomor_meja)
{
	adrParent X = LP.first;
	while(X!=NULL)
	{
		if(X->N.no_meja == nomor_meja)
		{
			return X->N.nama;
		}	
		X=X->nextParent;
	}
	return "Kosong";
}

//untuk melakukan pengurutan nomor nota /merge / gabung
void sortingNota (ListParent *LP)
{
	adrParent X = (*LP).first;
	
	if(!isEmpty((*LP)))
	{
		if(X->N.no_nota!=1)
		{
			X->N.no_nota=1;
		}
		while(X->nextParent!=NULL)
		{
			if((X->nextParent->N.no_nota)-(X->N.no_nota)!=1)
			{
				X->nextParent->N.no_nota=(X->N.no_nota)+2;
			}
			X=X->nextParent;
		}
	}
}

//split / pisah
void sortingNotaSplit(adrParent P,int minorplus)
{
	adrParent temp = P;
	while(temp!=NULL)
	{
		temp->N.no_nota += minorplus;	
		temp = temp->nextParent;
	}	
} 

void splitNota (ListParent *LP)
{
	ListParent X;
	init_List(&X);
	string keyword;
	Nota N;
	int cek=0,s;
	adrParent nota_single;
	int jum;
	do
	{
		tampilanListMeja(80,1,*LP);
		gotoxy(0,0);
		printf("\n\t======================= MEMISAHKAN NOTA =======================\n");
		printf("\n\t   Masukan keyword [Nomor Meja/Nama]	: ");fflush(stdin);gets(keyword);
		nota_single=FindParentbyNama((*LP),keyword);// Cari nota berdasar nama pembeli
		if(nota_single!=NULL)
		{
			cek=1;
			getch();
			break;
		}
		else //Jika pakai nama tidak ketemu, pakai nomor meja
		{
			s = atoi(keyword);
			nota_single=FindParentbyNomor ((*LP),s);  // <- ini pakai nomor meja
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
	//ini dah bgaus
	  system("cls");
	}while(nota_single==NULL);
	system("cls");
	printf("\n\t======================= MEMISAHKAN NOTA =======================\n");
	printf("\n\t Jumlah Menu pada Nota			: %d",hitungJumlahMenu(nota_single));
	
	do
	{
		printf("\n\t Masukan Jumlah Nota yang akan di split	: ");scanf("%d",&jum);
		
	}while(jum>hitungJumlahMenu(nota_single));

	int makananYangHapus;
	adrChild C;
	int jumlahMakan;
	Pesanan MakananMinuman;
	int pil,control;
	string nama;
	jum--;
	int nomor_meja = nota_single->N.no_meja;
	sortingNotaSplit(nota_single->nextParent,jum);
	while(jum)
	{
		int nomor_nota_baru = nota_single->N.no_nota+jum;
		
		do
		{
			printf("\n\t Nama Customer Baru			: ");fflush(stdin);gets(nama);
		}while(strlen(nama)==0);
		N = makeNota(nomor_nota_baru,nama,nota_single->N.tanggalNota,nomor_meja,0);
		insertLastParent(&X,N);
		
		do
		{
			system("cls");
			printChildUntukHapus(75,0,nota_single);
			gotoxy(0,0);
			printf("\n\t======================= MEMISAHKAN NOTA =======================\n");
			
			if(hitungJumlahMenu(nota_single)<=1)
			{
				pil = 2;
				break;
			}
			
			do
			{
				printf("\n\n\t Pilih nomor makanan yang akan di masukkan ke nota baru: ");
				scanf("%d",&makananYangHapus);
				C = findMakananUntukDelete(makananYangHapus,nota_single);
				if(C==NULL)
				{
					printf("\n\t     [!] Keyword Nota tidak ditemukan!! [!]");
				}
			}while(C==NULL);

			MakananMinuman = C->M;
			MakananMinuman.jumlah_pcs = 0;
			printf("\n\t Makanan yang dipilih	: %s\n",MakananMinuman.nama);
			do
			{
				printf("\t Jumlah makanan		: "); scanf("%d",&jumlahMakan);
				if (C->M.jumlah_pcs - jumlahMakan <= 0 && hitungJumlahMenu(nota_single)-jumlahMakan <1)
				{
					continue;
				}
//			}while(jumlahMakan > C->M.jumlah_pcs && jumlahMakan>hitungJumlahMenu(nota_single));
			}while(C->M.jumlah_pcs - jumlahMakan <= 0 && hitungJumlahMenu(nota_single)-jumlahMakan <1);
			
				C->M.jumlah_pcs -= jumlahMakan;
				MakananMinuman.jumlah_pcs += jumlahMakan;
				
				
				if(JenisMakanAtauMinum(MakananMinuman.nama)==1)
				{
					insertFirstMakanan(&X, nomor_meja,MakananMinuman);
					if(C->M.jumlah_pcs == 0)
					{
						deleteAtMakanan(nota_single,C);//ini delete node makanan klo makanannya dah habis
					}
				}
				else
				{
					insertFirstMinuman(&X, nomor_meja,MakananMinuman);
					if(C->M.jumlah_pcs == 0)
					{
						deleteAtMinuman(nota_single,C);
					}
				}
				
				nota_single->N.total -= jumlahMakan*MakananMinuman.harga; // update harga makanan setiap d ambil
				X.first->N.total = X.first->N.total + (jumlahMakan * MakananMinuman.harga); //update harga makanan setiap tambah
				if(hitungJumlahMenu(nota_single)<=1)
				{
					pil = 2;
					break;
				}
				else
				{
					do
					{
						printf("\n\n\t [1] Tambah Lagi \n\t [2] Selesai \n\t >>");scanf("%d",&pil);
					}while(pil!=2 && pil!=1);
				}
			
			
		}while(pil==1 || pil !=2);
		jum--;
		no_nota++;
	}
	
	
	lepasNode(&(*LP),nota_single);
	if(X.first==NULL)
	{
		X.first = nota_single;
	}
	else
	{
		nota_single->nextParent = X.first;
		X.first = nota_single;
	}
	
	float uang,bayar,kembalian;
	adrParent M=X.first;
	
	
	do{
		
		system("cls");
		printf("\n\t======================= MEMISAHKAN NOTA =======================\n");
		printChildByParentMakananUntukEdit(10,4,X,nomor_meja);
		printf("\n\n\t  Total Bayar			: Rp. %.2f",M->N.total);
		do{
			printf("\n\t  Masukan Uang Anda		: Rp. ");scanf("%f",&uang);
			if(uang < bayar)
			{
				printf("\n\t     [!] Uang Anda Kurang!! [!]");
			}
		}while(uang<bayar);
		
		if(uang>bayar)
		{
			printf("\n\t  Kembalian			: Rp. %.2f",uang-M->N.total);
		}
		
		Pesanan pesan;
		pesan.jumlah_pcs=0;
		insertLastMakananforFH(&X,X.first->N.no_nota,pesan);
		insertLastMinumanforFH(&X,X.first->N.no_nota,pesan);
		
		SaveNotaLaporan(X.first);
		getch();
		deleteFirstParent(&X);
		
		printf("\n\n\t              [~] PEMBAYARAN BERHASIL [~]");
		
		getch();
		M=M->nextParent;
	}while(M!=NULL);
	
	
	getch();
}


int JenisMakanAtauMinum(string nama)
{
	int i;
	for(i=1;i<=6;i++)
	{
		if(strcmpi(nama,GetNamaMakanan(i))==0)
		{
			return 1;
		}
	}
	return 2;
}

adrChild findMakananUntukDelete(int nomor, adrParent X)
{
	adrChild C = X->firstMakanan;
		while(nomor)
		{
			nomor--;
			if(nomor==0)
			{
				return C;
			}
			C=C->nextMenu;
			if(C==NULL)
			{
				break;
			}
		}
		
		C = X->firstMinuman;
		while(nomor)
		{
			nomor--;
			if(nomor==0)
			{
				return C;
			}
			C=C->nextMenu;
			if(C==NULL)
			{
				break;
			}
		}
}

//ini untuk menghitung jumlah menu di suatu nota digunakan dalam merge
int hitungJumlahMenu (adrParent P)
{
	adrChild X=P->firstMakanan;
	adrChild Z=P->firstMinuman;
	
	int temp=0;
	if(HaveChildMakanan(P))
	{
		while(X!=NULL)
		{
			temp=temp+X->M.jumlah_pcs;
			X=X->nextMenu;
		}
	}
	
	if(HaveChildMinuman(P))
	{
		while(Z!=NULL)
		{
			temp=temp+Z->M.jumlah_pcs;
			Z=Z->nextMenu;
		}
	}
	return temp;
}

int getindexMaxMakanan (JMakan J)
{
	int i,temp,max;
	temp=J.makanan[0];
	
	for(i=0;i<6;i++)
	{
		if(temp<J.makanan[i])
		{
			max=i;
			temp=J.makanan[max];
		}
	}
	return max+1;
}

int getindexMaxMinuman (JMakan J)
{
	int i,temp,max;
	temp=J.minuman[0];
	
	for(i=0;i<6;i++)
	{
		if(temp<J.minuman[i])
		{
			max=i;
			temp=J.minuman[max];
		}
	}
	return max+7;
}

void inieJumlah (JMakan *J)
{
	int i;
	for(i=0;i<6;i++)
	{
		(*J).makanan[i]=0;
		(*J).minuman[i]=0;
	}
}

int isEmptyMa (JMakan J) 
{
	int i;
	for(i=0;i<6;i++)
	{
		if(J.makanan[i]!=0)
		{
			return 99;
		}
	}
	return 0;
}

int isEmptyMi (JMakan J) 
{
	int i;
	for(i=0;i<6;i++)
	{
		if(J.minuman[i]!=0)
		{
			return 99;
		}
	}
	return 0;
}

int getJumlahNota (ListParent LP)
{
	adrParent j;
	j=LP.first;
	int i=0;
	
	while(j!=NULL)
	{
		i++;
		j=j->nextParent;
	}
	
	return i;
}

int getNoNotaMax (ListParent X)
{
	int temp=0;
	adrParent P=X.first;
	temp=P->N.no_nota;
	
	while(P!=NULL)
	{
		if(temp<P->N.no_nota)
		{
			temp=P->N.no_nota;
		}
		P=P->nextParent;
	}
	
	return temp;
}

adrChild cekMakanan (adrChild Z,string nama )
{
	while(Z != NULL )
	{
		if(strcmpi(Z->M.nama,nama)==0)
		{
			return Z;
		}
		Z = Z->nextMenu;
	}
	return NULL;
}

void deleteAtMakanan(adrParent P,adrChild C)
{
	adrChild temp = P->firstMakanan;
	adrChild del;
	if(C == P->firstMakanan)
	{
		P->firstMakanan = P->firstMakanan->nextMenu;
		temp = C;
		free(temp);
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->nextMenu==C)
			{
				break;
			}
			temp= temp->nextMenu;
		}
		del = temp->nextMenu;
		temp->nextMenu = temp->nextMenu->nextMenu;
		free(del);
	}	
}

void deleteAtMinuman(adrParent P,adrChild C)
{
	adrChild temp = P->firstMinuman;
	adrChild del;
	if(C == P->firstMinuman)
	{
		P->firstMinuman = P->firstMinuman->nextMenu;
		temp = C;
		free(temp);
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->nextMenu==C)
			{
				break;
			}
			temp= temp->nextMenu;
		}
		del = temp->nextMenu;
		temp->nextMenu = temp->nextMenu->nextMenu;
		free(del);
	}	
}

void lepasNode(ListParent *LP, adrParent P)
{
	adrParent  temp = (*LP).first;
	
	if(temp == P)
	{
		(*LP).first = (*LP).first->nextParent;
	}
	else
	{
		while(temp->nextParent!=NULL)
		{
			if(temp->nextParent == P)
			{
				temp->nextParent = temp->nextParent->nextParent;
				break;
			}
			temp = temp->nextParent;
		}

	}
}


//FILE HANDLING 
void SaveMakananTerbanyak(JMakan X)
{
	FILE* fp;
	
	fp = fopen("JumlahMakanan.txt","w");
	int i;
	for(i=0;i<7;i++)
	{
		fprintf(fp,"\n%d",X.makanan[i]);
		fprintf(fp,"\n%d",X.minuman[i]);
	}
	
	fclose(fp);
}

void ReadMakananTerbanyak(JMakan *X)
{
	FILE* fp;
	
	fp = fopen("JumlahMakanan.txt","r");
	int i;
	if(fp!=NULL)
	{
		for(i=0;i<7;i++)
		{
			fscanf(fp,"\n%d",&(*X).makanan[i]);
			fscanf(fp,"\n%d",&(*X).minuman[i]);
		}
	}
	
	fclose(fp);
}

void SaveNotaLaporan(adrParent NotaSimpan)
{
	FILE* fp;
	adrParent temp = NotaSimpan;
	adrChild tempPesanan;
	fp = fopen("LaporanMakanan.bin","ab");
	Nota NotaToSave;
	Pesanan Makanannya;
	
		NotaToSave = temp->N;
		fwrite(&NotaToSave,sizeof(Nota),1,fp);
		
		tempPesanan = temp->firstMakanan;
		while(tempPesanan!=NULL)
		{
			Makanannya = tempPesanan->M;
			fwrite(&Makanannya,sizeof(Pesanan),1,fp);
			tempPesanan = tempPesanan->nextMenu;
		}
		
		tempPesanan = temp->firstMinuman;
		while(tempPesanan!=NULL)
		{
			Makanannya = tempPesanan->M;
			fwrite(&Makanannya,sizeof(Pesanan),1,fp);
			tempPesanan = tempPesanan->nextMenu;
		}
		temp = temp->nextParent;

	fclose(fp);
}

void BacaNotaLaporan(ListParent *LP,float *OmzetAlltime, float *omzetToday)
{
	FILE* fp;
	adrParent temp;
	adrChild tempPesanan;
	Nota NotaToRead;
	Pesanan Makanannya;
	fp = fopen("LaporanMakanan.bin","rb");
	if(fp!=NULL)
	{
		while(fread(&NotaToRead,sizeof(Nota),1,fp)==1)
		{
			(*OmzetAlltime) += NotaToRead.total;
			if(strcmpi(NotaToRead.tanggalNota,GetSystemNow())==0)
			{
				(*omzetToday) += NotaToRead.total;
			}
			insertLastParent(&(*LP),NotaToRead);
			while(1)
			{
				fread(&Makanannya,sizeof(Pesanan),1,fp);
				if(Makanannya.jumlah_pcs!=0)
				{
					insertLastMakananforFH(&(*LP),NotaToRead.no_nota,Makanannya);
				}
				else
				{
					break;
				}
				
			}

			
			while(1)
			{
				fread(&Makanannya,sizeof(Pesanan),1,fp);
				if(Makanannya.jumlah_pcs!=0)
				{
					insertLastMinumanforFH(&(*LP),NotaToRead.no_nota,Makanannya);
				}
				else
				{
					break;
				}
			}	
		}
	}
		fclose(fp);
}

float hitungOmzetNow (ListParent *LP)
{
	adrParent P=(*LP).first;
	float temp=0;
	while(P!=NULL)
	{
		temp=temp+P->N.total;
		P=P->nextParent;
	}
	return temp;
	
}


void gotoxy(int x, int y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void isiTabelMinuman(int x,int y,int columnsize,int jumlahKolom,int jumlahMenu)
{
    int i,j,k,l;
    string tempHarga;
    for(k=1;k<jumlahMenu;k++) // mengulang sebanyak jumlah menu
    {
        for(i=k;i<=k+1;i++) // membuat baris ( terdiri dari 2 ) baris pembatas dan baris konten tabel
        {
        	gotoxy(x,y+k+i-2);
            if(i==k) //Kolom  isi tabel konten
            {
                printf("%c",GARISTEPI);
                printf(" %02d. %s ",k+batasAkhirMakanan,GetNamaMinuman(k+batasAkhirMakanan));
                sprintf(tempHarga," %02d. %s",k+batasAkhirMakanan,GetNamaMinuman(k+batasAkhirMakanan));
			 	for(l=0 ; l<columnsize-strlen(tempHarga) ;l++)
                {
                    printf(" ");
                }
                printf("%c",GARISTENGAH);
				
                sprintf(tempHarga," Rp. %.2f",GetHargaMinuman(k+batasAkhirMakanan));
                printf("%s ",tempHarga);
                for(l=0; l<columnsize-strlen(tempHarga); l++)
                {
                    printf(" ");
                }
                printf("%c",GARISTEPI);

            }
            else if(k==jumlahMenu-1)
			{
				printf("%c",SIKUKIRIBAWAH);
				int tempLebar = jumlahKolom;
	            while(tempLebar>0)
	            {
	                
	                    for(j=0;j<=columnsize;j++)
	                    {
	                        printf("%c",GARISMENDATAR);
	                    }
	
	                    if(tempLebar==1)
	                    {
	                        printf("%c",SIKUKANANBAWAH);
	                    }
	                    else
	                    {
	                        printf("%c",INTERSECTIONBAWAH);
	                    }
	                tempLebar--;
	            }
	            
			}
            else if(i==k+1) //* baris batas antar baris /
            {
            	printf("%c",SIMPANGTIGAKIRI);
				int tempLebar = jumlahKolom;
	            while(tempLebar>0)
	            {
	                
	                    for(j=0;j<=columnsize;j++)
	                    {
	                        printf("%c",GARISMENDATAR);
	                    }
	
	                    if(tempLebar==1)
	                    {
	                        printf("%c",SIMPANGTIGAKANAN);
	                    }
	                    else
	                    {
	                        printf("%c",INTERSECTIONDOUBLEGARISTENGAH);
	                    }
	                tempLebar--;
	            }
			}
        }
        printf("\n");
    }
}

void isiTabelMakanan(int x,int y,int columnsize,int jumlahKolom,int jumlahMenu)
{
    int i,j,k,l;
    string tempHarga;
    for(k=1;k<jumlahMenu;k++) // mengulang sebanyak jumlah menu
    {
        for(i=k;i<=k+1;i++) // membuat baris ( terdiri dari 2 ) baris pembatas dan baris konten tabel
        {
        	gotoxy(x,y+k+i-2);
            if(i==k) //Kolom  isi tabel konten
            {
                printf("%c",GARISTEPI);
                printf(" %02d. %s ",k,GetNamaMakanan(k));
                sprintf(tempHarga," %02d. %s",k,GetNamaMakanan(k));
			 	for(l=0 ; l<columnsize-strlen(tempHarga) ;l++)
                {
                    printf(" ");
                }
                printf("%c",GARISTENGAH);
				
                sprintf(tempHarga," Rp. %.2f",GetHargaMakanan(k));
                printf("%s ",tempHarga);
                for(l=0; l<columnsize-strlen(tempHarga); l++)
                {
                    printf(" ");
                }
                printf("%c",GARISTEPI);
            }
            else if(k==jumlahMenu-1)
			{
				printf("%c",SIKUKIRIBAWAH);
				int tempLebar = jumlahKolom;
	            while(tempLebar>0)
	            {
	                
	                    for(j=0;j<=columnsize;j++)
	                    {
	                        printf("%c",GARISMENDATAR);
	                    }
	
	                    if(tempLebar==1)
	                    {
	                        printf("%c",SIKUKANANBAWAH);
	                    }
	                    else
	                    {
	                        printf("%c",INTERSECTIONBAWAH);
	                    }
	                tempLebar--;
	            }
	            
			}
            else if(i==k+1) //* baris batas antar baris /
            {
            	printf("%c",SIMPANGTIGAKIRI);
				int tempLebar = jumlahKolom;
	            while(tempLebar>0)
	            {
	                
	                    for(j=0;j<=columnsize;j++)
	                    {
	                        printf("%c",GARISMENDATAR);
	                    }
	
	                    if(tempLebar==1)
	                    {
	                        printf("%c",SIMPANGTIGAKANAN);
	                    }
	                    else
	                    {
	                        printf("%c",INTERSECTIONDOUBLEGARISTENGAH);
	                    }
	                tempLebar--;
	            }
			}
			

        }
        printf("\n");
    }
    
    
    
}

void headerTabel(int x,int y,int lebar,int jumlah, ...)
{
  int i,j,k,l;
  int panjang_string=0;
  string temp;
  va_list arg;
  int tempLebar;
  for(i=0; i<3;i++)
  {
      gotoxy(x,y+i);
    tempLebar = jumlah;
    if(i==0 || i==2) //atas
    {
        
      if(i==0)
      {
            printf("%c",SIKUKIRIATAS);

            while(tempLebar>0)
            {
                
                    for(j=0;j<=lebar;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }

                    if(tempLebar==1)
                    {
                        printf("%c",SIKUKANANATAS);
                    }
                    else
                    {
                        printf("%c",INTERSECTIONATAS);
                    }
                tempLebar--;
            }
      }
      else
      {
            printf("%c",SIMPANGTIGAKIRI);

            while(tempLebar>0)
            {
                
                    for(j=0;j<=lebar;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }

                    if(tempLebar==1)
                    {
                        printf("%c",SIMPANGTIGAKANAN);
                    }
                    else
                    {
                        printf("%c",INTERSECTIONDOUBLEGARISTENGAH);
                    }
                tempLebar--;
            }
      }
      
      
    }

    else //isi tengah
    { 
      printf("%c",GARISTEPI);
      va_start(arg,jumlah);
      for(j=0 ;j <jumlah; j++)
      {
        strcpy(temp,va_arg(arg,char*));
        l =  strlen(temp);
        printf(" %s",temp);
        for(k=0; k<lebar-(l);k++)
        {
          printf(" ");
        }
        if(j==jumlah-1)
        {
            printf("%c",GARISTEPI);
        }
        else
        {
            printf("%c",GARISTENGAH);
        }
        
      }
    }
    printf("\n");
  }
}

void summonTabelMakanan(int X,int Y)
{
	headerTabel(X,Y,18,2,"     MAKANAN","       HARGA");
	isiTabelMakanan(X,Y+3,18,2,7);
}

void summonTabelMinuman(int x,int y)
{
	headerTabel(x,y,18,2,"     MINUMAN","      HARGA");
	isiTabelMinuman(x,y+3,18,2,7);
	
}

void maximize()
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_SHOWMAXIMIZED); // this mimics clicking on its' maximize button
}


void ringkasan(int x,int y, adrParent L)
{
    headerTabel(x,y,18,2,"     Nama","      Jumlah");
}

void isiRingkasan(int x,int y,int Ukuran[],int Last,int Jumlah,...)
{
    int i,j;
    int baris=2;
    string temp;
    va_list arg;

    while(baris)
    {
        gotoxy(x,y-baris);
        if(baris==2)
        {
                va_start(arg,Jumlah);
                printf("%c",GARISTEPI);
                for(i=0;i<Jumlah;i++)
                {
                    strcpy(temp,va_arg(arg,char*));
                    printf(" ");
                    printf("%s",temp);
                    
                    for(j=0;j<Ukuran[i]-(strlen(temp)+2);j++)
                    {
                        printf(" ");
                    }
                    if(i!=Jumlah-1)
                    {
                        printf("%c",GARISTENGAH);
                    }
                    else
                    {
                        printf("%c",GARISTEPI);
                    }   
                }
        }
        else
        {
                if(Last==1)
                {
                    printf("%c",SIKUKIRIBAWAH);
                }
                else
                {
                    printf("%c",SIMPANGTIGAKIRI);
                }
                
                for(i=0;i<Jumlah;i++)
                {
                    for(j=0;j<Ukuran[i]-1;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }
                    if(i!=Jumlah-1)
                    {
                        if(Last==0)
                        {
                            printf("%c",INTERSECTIONDOUBLEGARISTENGAH);
                        }
                        else
                        {
                            printf("%c",INTERSECTIONBAWAH);
                        }
                        
                    }
                    else
                    {
                        if(Last==0)
                        {
                            printf("%c",SIMPANGTIGAKANAN);
                        }
                        else
                        {
                            printf("%c",SIKUKANANBAWAH);
                        }
                        
                    }   
                }
        }
        baris--;
       
    }
    
}

void headerRingkasan(int x,int y,int Ukuran[],int Jumlah,...)
{
    int i,j;
    int baris=3;
    string temp;
    va_list arg;

    while(baris)
    {
        gotoxy(x,y+baris);
        if(baris==2)
        {
                va_start(arg,Jumlah);
                printf("%c",GARISTEPI);
                for(i=0;i<Jumlah;i++)
                {
                    strcpy(temp,va_arg(arg,char*));
                    printf(" ");
                    printf("%s",temp);
                    
                    for(j=0;j<Ukuran[i]-(strlen(temp)+2);j++)
                    {
                        printf(" ");
                    }
                    if(i!=Jumlah-1)
                    {
                        printf("%c",GARISTENGAH);
                    }
                    else
                    {
                        printf("%c",GARISTEPI);
                    }   
                }
        }
        else if(baris == 1)
        {
                printf("%c",SIKUKIRIATAS);
                for(i=0;i<Jumlah;i++)
                {
                    for(j=0;j<Ukuran[i]-1;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }
                    if(i!=Jumlah-1)
                    {
                        printf("%c",INTERSECTIONATAS);
                    }
                    else
                    {
                        printf("%c",SIKUKANANATAS);
                    }   
                }
        }
        else if(baris ==3)
        {
               
                printf("%c",SIMPANGTIGAKIRI);
                for(i=0;i<Jumlah;i++)
                {
                    for(j=0;j<Ukuran[i]-1;j++)
                    {
                        printf("%c",GARISMENDATAR);
                    }
                    if(i!=Jumlah-1)
                    {
                        printf("%c",INTERSECTIONDOUBLEGARISTENGAH);
                    }
                    else
                    {
                        printf("%c",SIMPANGTIGAKANAN);
                    }   
                }
        }
        baris--;
       
    }
    
}

void tampilanListMeja(int xOrdinat,int YOrdinat,ListParent LP)
{
	int A[2]= {13,20};
	headerRingkasan(xOrdinat,YOrdinat,A,2,"Nomor Meja","Nama");
	YOrdinat +=4;
	int showNomorMeja;
	string nama,nama_p;
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
}

char* GetNamaMinuman(int menu)
{
	
	switch(menu)
	{
		case 7: 
				return "Air Putih";
				break;
		
		case 8: 
				return "Teh";
				break;
		
		case 9: 
				return "Jeruk";
				break;
			
		case 10: 
				return "Jus Apel";
				break;
		
			
		case 11: 
				return "Jus Alpukat";
				break;
		
			
		case 12: 
				return "Kopi Hitam";
				break;	
		
	}
}

char* GetNamaMakanan(int menu)
{
	switch(menu)
	{
		case 1: 
				return "Nasi Goreng";
				break;
		
		case 2: 
				return "Bakmie";
				break;
		
		case 3: 
				return "Sapo Tahu";
				break;
			
		case 4: 
				return "Cap Jay";
				break;
		
			
		case 5: 
				return "Kwetiau";
				break;
		
			
		case 6: 
				return "Buyung Hai";
				break;
	}
}

float GetHargaMakanan(int menu)
{
	switch(menu)
	{
		case 1: 
				return 27000;
				break;
		
		case 2: 
				return 21000;
				break;
		
		case 3: 
				return 35000;
				break;
			
		case 4: 
				return 35000;
				break;
		
		case 5: 
				return 28000;
				break;
			
		case 6: 
				return 25000;
				break;
	}
}

float GetHargaMinuman(int menu)
{
	switch(menu)
	{
		case 7: 
				return 5000;
				break;
		
		case 8: 
				return 4000;
				break;
		
		case 9: 
				return 6000;
				break;
			
		case 10: 
				return 8000;
				break;
		
		case 11: 
				return 12000;
				break;
			
		case 12: 
				return 6000;
				break;
			
	}
	
}
