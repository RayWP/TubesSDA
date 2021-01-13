#include "header.h"

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
//                for(l=0 ; l<columnsize-strlen(GetNamaMinuman(k+batasAkhirMakanan)) ;l++)
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



//int A[5]= {10,20,30,20,20};
//int a=5;
//while(a)
//{
//	isiRingkasan(5,A,"ini X","ini isi 2","DDDD","STELLY","ALISON");
//	a--;
//}
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
                    //  printf("nilai ukuran i: %d",Ukuran[i]);
                    //  printf("nilai nya =%d",Ukuran[i]-strlen(temp)-1);
                    for(j=0;j<Ukuran[i]-(strlen(temp)+2);j++)
                    {
                        // printf("%d",j);
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
                    //  printf("nilai ukuran i: %d",Ukuran[i]);
                    //  printf("nilai nya =%d",Ukuran[i]-strlen(temp)-1);
                    for(j=0;j<Ukuran[i]-(strlen(temp)+2);j++)
                    {
                        // printf("%d",j);
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
        // printf("\n");
        
       
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
//cara pake View ku
// int A[6]= {10,20,30,20,20,30};
// 		int a=6;
// 		int x=20;
// 		int y = 20;
// 		headerRingkasan(20,y,A,6,"Kolom 2","ini 3","K 3","STELL","AISON","intambahan lagi");
// 		y+=4;
// 		while(a)
// 		{
// 			y+=2;
// 			if(a==1)
// 			{
// 				isiRingkasan(20,y,A,1,6,"ini X","ini isi 2","DDDD","STELLY","ALISON","ini tambahan lagi");
// 			}
// 			else
// 			{
// 				isiRingkasan(20,y,A,0,6,"ini X","ini isi 2","DDDD","STELLY","ALISON","ini tambahan lagi");
// 			}
// 			a--;
// 		}
