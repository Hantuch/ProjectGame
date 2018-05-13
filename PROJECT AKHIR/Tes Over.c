#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int main()	//Gameover Function
{
	int i;
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
    	 	usleep(70000 + rand() % 10000);
    	   	printf("%c", gameover2[i]);
    	    fflush(stdout);
    	}
    usleep(700000);
    printf("\n\n\n");
    for(i = 0; i < strlen(gameover3); i++){
    	 	usleep(50000 + rand() % 10000);
    	   	printf("%c", gameover3[i]);
    	    fflush(stdout);
    	}	
	
	inputover : scanf("%d", &pilover);
	
	switch(pilover){
		case 1 : 
			//To Game Function
			fflush(stdin);
			break;
		case 2 :
			fflush(stdin);
			return main();
			break;
		default :
			printf("\aPilihan Invalid, Mohon Coba Lagi : ");
			fflush(stdin);
			pilover = 0;
			goto inputover;
			break;	
	}
	return 0;
}

