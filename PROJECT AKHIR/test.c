#include <stdio.h>
#include <windows.h>

int main() {
    int i;
    char gameover1[] = "...";
	char gameover2[] = "Somehow... You Died..\n\n\n[1] Main Lagi [2] Balik ke Menu";
	
	
	for(i = 0; i < strlen(gameover1); i++){
    	 	usleep(500000);
    	   	printf("%c", gameover1[i]);
    	    fflush(stdout);
    	}
    printf("\n\n\n");
    for(i = 0; i < strlen(gameover2); i++){
    	 	usleep(50000 + rand() % 10000);
    	   	printf("%c", gameover2[i]);
    	    fflush(stdout);
    	}
}
