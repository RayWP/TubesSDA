#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define JUMLAHMEJA 15
#define SIKUKANANATAS 187
#define SIKUKIRIATAS 201
#define SIKUKANANBAWAH 188
#define SIKUKIRIBAWAH 200
#define INTERSECTIONATAS 209
#define INTERSECTIONBAWAH 207
#define GARISTENGAH 179
#define GARISMENDATAR 205
#define GARISTEPI 186
#define INTERSECTIONDOUBLEGARISTENGAH 216
#define SIMPANGTIGAKIRI 204
#define SIMPANGTIGAKANAN 185
#define batasAkhirMakanan 6
//struct time_t;
typedef char string[2000];
int no_nota;
typedef struct tChild* adrChild;
typedef struct tParent* adrParent;

typedef struct
{
	int tahun;
	int bulan;
	int tanggal;
	
}Tanggal;

typedef struct
{
	int makanan[6];
	int minuman[6];
}JMakan;


typedef struct {
	int no_nota;
	string nama;
	string tanggalNota;
	int no_meja;
	float total;
}Nota;

typedef struct {
	string nama;
	float harga;
	int jumlah_pcs;	
	string keterangan;
}Pesanan;

typedef struct tChild
{
	Pesanan M;
	adrChild nextMenu;
}ChildPesanan;


typedef struct tParent
{
	Nota N;
	adrParent nextParent;
	adrChild firstMakanan;
	adrChild firstMinuman;
}Parent;

typedef struct
{
	adrParent first;
}ListParent;


//adrParent P;
//P->N.no_nota
/*CRUD NOTA*/
void init_List(ListParent *LP);

// KONSTRUKTOR 
Nota makeNota (int no_nota, string nama, string tanggalnota, int no_meja, float total);
Pesanan makePesanan ( string nama,int jumlah,float harga, string keterangan);

adrParent alokasiNota(Nota N);
adrChild alokasiMenu(Pesanan M);

// adrChild alokasiMenu(MakananMinuman M);
adrChild alokasiMenu(Pesanan M);

// TANGGAL
// char get
char* GetSystemNow();
char* GetBulan(int bulan);
char* GetNamaMinuman(int menu);
char* GetNamaMakanan(int menu);

void insertFirstParent(ListParent *L, Nota N);

void insertFirstMakanan(ListParent *L,int no_nota, Pesanan X);
void insertLastMakanan(ListParent *L,int no_nota, Pesanan X);

int isEmpty(ListParent L);
int HaveChildMakanan (adrParent P);
int HaveChildMinuman (adrParent P);

float GetHargaMakanan(int menu);
float GetHargaMinuman(int menu);

//VIEW
void gotoxy(int x, int y);

void sortingNota (ListParent *LP);
void isiTabelMinuman(int x,int y,int columnsize,int jumlahKolom,int jumlahMenu);
void isiTabelMakanan(int x,int y,int columnsize,int jumlahKolom,int jumlahMenu);
void headerTabel(int x,int y,int lebar,int jumlah, ...);
void summonTabelMakanan(int X,int Y);
void summonTabelMinuman(int x,int y);
void maximize();

adrParent FindParentbyNama (ListParent L,string nama); 
adrParent FindParentbyNomor (ListParent L,int id);

//DELETE PARENT
void deleteAtParent(ListParent *L, adrParent X);
void deleteFirstParent(ListParent *L);

//DELETE CHILD
void deleteFirstMakanan (adrParent *X);
void deleteFirstMinuman (adrParent *X);

void menuPembayaran (ListParent *LP);
void menuPembayaranLangsung (ListParent *LP);
void isiRingkasan(int x,int y,int Ukuran[],int Last,int Jumlah,...);
void headerRingkasan(int x,int y,int Ukuran[],int Jumlah,...);

void gabungNota (ListParent *LP);
void splitNota (ListParent *LP);

int mejaisFound(ListParent LP,int nomor_meja); /*tambahan by raymond*/ /*digunakan di main.c Line 34*/
char* GetNamaPembeli(ListParent LP,int nomor_meja); /*tambahan by raymond */ // digunakan buat tabel 

void hitungJumlahMakanan (string nama, JMakan *J, int jumlah);//untuk mengetahui jumlah setiap makanan
void printChildByParentNama(ListParent L,string idP);

void inieJumlah (JMakan *J);

int isEmptyMi (JMakan J);
int isEmptyMa (JMakan J);
void tampilanListMeja(int xOrdinat,int YOrdinat,ListParent LP);

void printChildByParentNamaUntukEdit(int x, int y,ListParent L,string idP);// print summar yuntuk edit.
void printChildByParentMakananUntukEdit(int x,int y,ListParent L,int idP);// print summar untuk edit lagi.

adrChild cekMakanan (adrChild Z,string nama );
void printChildUntukHapus(int x, int y,adrParent P);
adrChild findMakananUntukDelete(int nomor,adrParent X);
int getJumlahNota (ListParent LP);

void deleteAtMinuman(adrParent P,adrChild C);//dipakai buat split
void deleteAtMakanan(adrParent P,adrChild C);
void lepasNode(ListParent *LP, adrParent P);//melepas node

void ReadMakananTerbanyak(JMakan *X);
void SaveMakananTerbanyak(JMakan X);
void SaveNotaLaporan(adrParent Nota);
void BacaNotaLaporan(ListParent *LP,float *OmzetALltime, float *OmzetToday);

void sortingNotaSplit(adrParent P,int minorplus);//sorting untuk split
float hitungOmzetNow (ListParent *LP);

void insertFirstMinumanforFH(ListParent *L,int no_nota, Pesanan X);
void insertLastMinumanforFH(ListParent *L,int no_nota, Pesanan X);
