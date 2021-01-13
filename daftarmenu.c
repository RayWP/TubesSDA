#include "header.h"


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

