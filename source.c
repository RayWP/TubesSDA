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

//void deleteFirstChild(ListParent *L,int idP)
//{
//	adrChild del;
//	adrParent P;
//	P=FindParent((*L),idP);
//	if(P==NULL)
//		printf("Parent tidak ada");
//	else if(!HaveChild(P))			
//		printf("\nTidak punya anak");
//	else{
//		del=P->firstChild;
//		P->firstChild=P->firstChild->nextChild;
//		free(del);
//		printf("DELETED");
//	}	
//}
//void deleteLastChild(ListParent *L,int idP)
//{
//	adrChild del, bantu;
//	adrParent P,temp;
//	P=FindParent((*L),idP);
//	if(P==NULL)
//		printf("Parent tidak ada");
//	else if(!HaveChild(P))			
//		printf("\nTidak punya anak");
//	else if(P->firstChild->nextChild==NULL)
//		deleteFirstChild(&(*L),idP);
//	else{
//		bantu=P->firstChild;
//		while(bantu->nextChild->nextChild!=NULL)
//		{
//			bantu=bantu->nextChild;
//		}
//		del=bantu->nextChild;
//		bantu->nextChild=NULL;
//		free(del);
//		printf("DELETED");		
//	}				
//}

void printChildMakanan (adrChild C)
{
	if(C!=NULL)
	{
//		printf("\nList Makanan");
		while(C!=NULL)
		{
			printf("\n\t   %s	%d	%s",C->M.nama, C->M.jumlah_pcs,C->M.keterangan);
			C=C->nextMenu;
		}
	}
}

void printChildMinuman (adrChild C)
{
	if(C!=NULL)
	{
//		printf("\nList Minuman");
		while(C!=NULL)
		{
			printf("\n\t   %s	%d	%s",C->M.nama, C->M.jumlah_pcs,C->M.keterangan);
			C=C->nextMenu;
		}
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
//				C=P->firstMakanan;
//				printChildMakanan(C);
//				C=P->firstMinuman;
//				printChildMinuman(C);
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
	int y= 0;
	int A[4]={20,20,20,30};
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
				y+=3;
				printf("\n\t Nomor Nota	 	: %d",P->N.no_nota);
				printf("\n\t Nomor Meja		: %d",P->N.no_meja);
				printf("\n\t Customer			: %s",P->N.nama);
				if(!HaveChildMakanan(P) && !HaveChildMinuman(P))	
				{		
					printf("\n\t  [!] Tidak Ada Menu yang di Pesan!! [!]");	
				}
				else
				{
					y+=2;
					headerRingkasan(x,y,A,4,"NAMA","JUMLAH","HARGA","Keterangan");
					y+=4;
					C= P->firstMakanan;
					while(C!=NULL)
					{
						y+=2;
						sprintf(temp,"%d",C->M.jumlah_pcs);
						if(C->nextMenu==NULL && P->firstMinuman == NULL)
						{
							isiRingkasan(x,y,A,1,4,C->M.nama,temp,C->M.keterangan,"INI Harga");
						}
						else 
						{
							isiRingkasan(x,y,A,0,4,C->M.nama,temp,C->M.keterangan,"Ini harga");
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
							isiRingkasan(x,y,A,1,4,C->M.nama,temp,C->M.keterangan,"INi harga");
						}
						else
						{
							isiRingkasan(x,y,A,0,4,C->M.nama,temp,C->M.keterangan,"ini harga");
						}
						C=C->nextMenu;
					}
			
			
//			printf("\n\t   Nomor Nota	 	: %d",P->N.no_nota);
//			printf("\n\t   Nomor Meja		: %d",P->N.no_meja);
//			printf("\n\t   Customer			: %s",P->N.nama);
//			if(!HaveChildMakanan(P) && !HaveChildMinuman(P))			
//				printf("\nTidak punya anak");	
//			else
//			{
//				C=P->firstMakanan;
//				printChildMakanan(C);
//				C=P->firstMinuman;
//				printChildMinuman(C);
//			}	
			}	
		}		
	}
}


void printChildByParentNamaUntukEdit(int x, int y,ListParent L,string idP)
{
	adrParent P;
	adrChild C;
//	int x = 10;
//	int y= 0;
	
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
//				C=P->firstMakanan;
//				printChildMakanan(C);
//				C=P->firstMinuman;
//				printChildMinuman(C);
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
			
			
//			printf("\n\t   Nomor Nota	 	: %d",P->N.no_nota);
//			printf("\n\t   Nomor Meja		: %d",P->N.no_meja);
//			printf("\n\t   Customer			: %s",P->N.nama);
//			if(!HaveChildMakanan(P) && !HaveChildMinuman(P))			
//				printf("\nTidak punya anak");	
//			else
//			{
//				C=P->firstMakanan;
//				printChildMakanan(C);
//				C=P->firstMinuman;
//				printChildMinuman(C);
//			}	
			}	
		}		
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
				y+=2;
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
//				C=P->firstMakanan;
//				printChildMakanan(C);
//				C=P->firstMinuman;
//				printChildMinuman(C);
			}
			P=P->nextParent;
			printf("\n\t===============================================================\n");	
		}
	}		
}

void menuPembayaran (ListParent *LP)
{
	char pil;
	adrParent X=getLastParent (*LP);
	
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
				if(X->N.no_nota>1)
				{
					gabungNota (&(*LP));
				}else
				{
					printf("\n\t     [!] Jumlah Nota Hanya 1!! [!]");
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
	int cek=0,X=0;
	float uang,bayar;
	
	string keyword;
	do
	{
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
				printf("\n\t     [!] Keyword Nota tidak ditemukan!! [!]");
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
	
	
	deleteAtParent(&(*LP), nota_single);
	
	printf("\n\t     [~] PEMBAYARAN BERHASIL [~]");
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
	
	tampilanListMeja(80,1,*LP);
	gotoxy(15,5);
	adrParent K;
	K=getLastParent ((*LP));
	
	do{
		printf("\n\t    Masukan Jumlah Nota : ");scanf("%d",&jml);
		if(K->N.no_nota<jml)
		{
			printf("\n\t     [!] Jumlah Nota Tidak sesuai dengan Data yang ada!! [!]");
		}
	}while(K->N.no_nota<jml);
	
	do
	{
		printf("\n   Masukan keyword %d [Nomor Meja/Nama]	: ",i);fflush(stdin);gets(keyword);
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
			insertLastParent(&B,nota_single->N);/// AMAN
			printf("NOMOR MEJA : %d\n",nomor_meja);
			while(Ma!=NULL)
			{
				printf("COPY makanan");
				getch();
				insertFirstMakanan(&B,nomor_meja,Ma->M);
				Ma=Ma->nextMenu;
			}
			while(Mi!=NULL)
			{
				insertFirstMinuman(&B,nomor_meja,Mi->M);
				Mi=Mi->nextMenu;
			}
			bayar=bayar+nota_single->N.total;
			deleteAtParent(&(*LP), nota_single);
		}
		else 
		{
//			X = atoi(keyword);
//			nota_single=FindParentbyNomor (*LP,X);
//			if(nota_single==NULL)
//			{
				printf("\n\t     [!] Keyword Nota tidak ditemukan!! [!]");
//				getch();
//			}else
//			{
//				cek=2;
//				i++;
//				jml--;
//				insertFirstParent(&B,nota_single->N);
//				while(Ma!=NULL)
//				{
//					insertFirstMakanan(&B,nota_single->N.no_nota,Ma->M);
//					Ma=Ma->nextMenu;
//				}
//				while(Mi!=NULL)
//				{
//					insertFirstMinuman(&B,nota_single->N.no_nota,Mi->M);
//					Mi=Mi->nextMenu;
//				}
//				bayar=bayar+nota_single->N.total;
//				deleteAtParent(&(*LP), nota_single);
//			}
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
	
	printf("\n\t     [!] PEMBAYARAN BERHASIL [!]");
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

//untuk melakukan pengurutan nomor nota 
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
				X->nextParent->N.no_nota=(X->N.no_nota)+1;
			}
			X=X->nextParent;
		}
	}
}

//untuk mendapatkan nomor nota
void autogenerateID (ListParent *LP,int *id)
{
	adrParent X=(*LP).first;
	
	if(!isEmpty((*LP)))
	{
		while(X->nextParent!=NULL)
		{
			X=X->nextParent;
		}
		(*id)=X->N.no_nota+1;
		
	}else
	{
		(*id)++;
	}
}

void splitNota (ListParent *LP)
{
	ListParent X;
	string keyword;
	int cek=0,s;
	adrParent nota_single;
	
	do
	{
		system("cls");
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
	}while(nota_single==NULL);
	printf("JUMLAHH MENU	: %d",hitungJumlahMenu(nota_single));
	do{
		printf("\nMasukan Jumlah Menu yang akan di Merge	: ");scanf("%d",&s);
	}while(s>hitungJumlahMenu(nota_single));
	
	if(cek==1)
	{
		printChildByParentNama(X,keyword);
		
	}else if (cek==2)
	{
		printChildByParentMakanan(X,s);
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
			temp=temp+X->M.jumlah_pcs;
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

adrParent getLastParent (ListParent LP)
{
	adrParent j;
	j=LP.first;
	
	while(j->nextParent!=NULL)
	{
		j=j->nextParent;
	}
	
	return j;
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


