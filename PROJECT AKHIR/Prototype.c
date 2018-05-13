#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int i;
char name[10];

void menu() //Main Menu Layout
{
	system("cls");
	printf("       __.__.__.__.__.__.__.__.__.__.__.__.__.__.__	\n");
	printf("                          _      					\n");
	printf("                         /_` . _ 					\n");
	printf("                        ._/ / / /					\n");
	printf("       __.__.__.__.__.__.__.__.__.__.__.__.__.__.__	\n\n");
	
	printf("              [1] 'Mainkan'   [2] Instruksi			\n");
	printf("                      [3] Keluar					\n");
}

void gameover()	//Gameover Function
{
	int pilover;
	char gameover1[] = "...";
	char gameover2[] = "Somehow... You Died..";
	char gameover3[] = "[1] Main Lagi [2] Balik ke Menu \n\nPilihan Anda? : ";
	
	system("cls");
	for(i = 0; i < strlen(gameover1); i++){
    	 	usleep(500000);
    	   	printf("%c", gameover1[i]);
    	    fflush(stdout);
    	}
    printf("\n\n\n");
    for(i = 0; i < strlen(gameover2); i++){
    	 	usleep(75000 + rand() % 10000);
    	   	printf("%c", gameover2[i]);
    	    fflush(stdout);
    	}
    usleep(800000);
    printf("\n\n\n");
    for(i = 0; i < strlen(gameover3); i++){
    	 	usleep(50000 + rand() % 10000);
    	   	printf("%c", gameover3[i]);
    	    fflush(stdout);
    	}	
	
	inputover : scanf("%d", &pilover);
	
	switch(pilover){
		case 1 : 
			fflush(stdin);
			
			break;
		case 2 :
			fflush(stdin);
			main();
			break;
		default :
			printf("\aPilihan Invalid, Mohon Coba Lagi : ");
			fflush(stdin);
			pilover = 0;
			goto inputover;
			break;	
	}
}



int main()	//Main Function (Menu)
{
	
	int pil;
	
	menu();		
	
	printf("\nPilihan anda : ");

	inputmenu : scanf("%d",&pil);
		
	if(pil != 1 && pil != 2 && pil != 3)
	{
		menu();
		printf("\n\aPilihan Invalid, Mohon Coba Lagi : ");
		fflush(stdin);
		goto inputmenu;
	}
	else if(pil == 3)
	{
		char bye[] = "Terimakasih sudah mencoba program ini! sampai jumpa kembali!!!";	
	
		end : //Untuk End (mungkin bakal kepake)
		
		for(i = 0; i < strlen(bye); i++){
    	 	usleep(23000 + rand() % 12000);
    	   	printf("%c", bye[i]);
    	    fflush(stdout);
		}
		return 0;
	}
	else if(pil == 2)
	{
		menu();
		char instruksi[] = "Game ini merupakan game berbasis teks dan gambar yang bersifat narratif\nKamu hanya perlu memasukkan angka sesuai opsi pilihan yang ingin dipilih\nSeiring jalannya cerita,Karakter Kamu akan dihadapkan kepada beberapa pilihan\nPerhatikan narasi dengan jeli dan pilih pilihan yang terbaik bagi anda!\n\nPilih 1 Untuk main sekarang! : ";
		
		printf("\n");
		for(i = 0; i < strlen(instruksi); i++) {
    	 	usleep(20000 + rand() % 15000);
    	   	printf("%c", instruksi[i]);
    	    fflush(stdout);
   		 }
   		fflush(stdin);
   		pil = 0;
   		goto inputmenu;
	}
	else if(pil == 1) 
	{	
		fflush(stdin);
		fflush(stdout);
		game();
	}
return 0;
}

void game() //The Game Function
{
	intro();
}


void intro()
{
	
	system("cls");
	printf("\n\n\n");
	
	char entername[] = "Kamu adalah seorang perempuan, nama kamu : ";

	for(i = 0; i < strlen(entername); i++){
    	 	usleep(30000 + rand() % 15000);
    	   	printf("%c", entername[i]);
    	    fflush(stdout); 
    	}
	gets(name);
}

