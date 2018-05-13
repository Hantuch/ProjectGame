#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void intro()
{
	int i;
	
	system("cls");
	printf("\n\n\n");
	
	char entername[] = "Kamu adalah seorang perempuan, nama kamu : ";

	for(i = 0; i < strlen(entername); i++){
    	 	usleep(30000 + rand() % 15000);
    	   	printf("%c", entername[i]);
    	    fflush(stdout); 
    	}
	char name[10];
	gets(name);
	
	printf("Tai Lo %s", name);
}
