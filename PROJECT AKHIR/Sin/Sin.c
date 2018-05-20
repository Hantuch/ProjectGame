#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void game(), intro(), menu(), gameover(), win(), choice(), txt2(), txt(), error(), act1(), actA(), actB(), endA1(), endA2(), endB1(), endB2();

int i;			//i : variable untuk For-Loop
int pilover; 	//Pilover : integer yang dipakai pada ending untuk menentukan lanjut bermain atau kembali ke menu 
int branch[9];	//Branch : Array berisi pilihan pemain seiring jalannya cerita
int pil;		//Integer yang berisi pilihan pemain di main menu (1:Main 2:Instruksi 3:Keluar)
char name[10];	//Name : Array yang menyimpan nama karakter setelah diinput di intro function



int main()	//Main Function (Menu)
{
	SetConsoleTitle("Sin by Hanif R & Reza P");
 	system("color 4");

	menu();		
	
	printf("\nYour Choice : ");

	inputmenu : scanf("%d",&pil);
	
	switch(pil){
		case 1 :
			fflush(stdin);
			fflush(stdout);
			game();
			break;
	
		case 2 :
			menu();
			
			printf("\n");
			txt2("This game is a text based game that focus on narrative & nonlinear (Branching) story\n");
			txt2("You only need to use the input 1 or 2 to play the game\n");
			txt2("As the story progress, you'll face 2 options that you can choose, each with its own \nconsequences'\n");
			txt2("Give attention to details in the Narration \nand choose the path you think are the best\n");
			txt2("Please turn the window into fullscreen for better aesthetic & immersion!\n\n");
			txt2("Input 1 if you want to play now! : ");	
   			fflush(stdin);
   			pil = 0;
   			goto inputmenu;
   			break;
   	
	   	case 3 :
		 	txt2("Thanks for trying this (shitty) game! see you later!\n");
			getch();
			return 0;
			break;
		
		default : //Error Handling
			menu();
			error("pil");
			goto inputmenu;
			break;				
	}
return 0;
}

void game() //The Game Function (Complete with Branching)
{
	intro();
	act1();
	
	switch(branch[2])
	{
		case 1 :
			actA();
			switch(branch[7])
			{
				case 1 : 
					endA1(); 
					gameover();	
					break;
				case 2 : 
					endA2();
					gameover();
					break;
			}
		case 2 :
			actB();
			switch(branch[7])
			{
				case 1 :
					endB1();
					win();
					break;
				case 2 :
					endB2();
					win();
					break;
			}
	}		
}

void intro() // Intro & Name Input Function
{	
	system("cls");
	
	printf("\n\n\n");
	txt2("You're a Girl,");
	usleep(500000);
	txt2(" please enter an appropriate name : ");
	gets(name);
}

void menu() //Main Menu Layout
{
	system("cls");
	printf("         __.__.__.__.__.__.__.__.__.__.__.__.__.__.__\n");
	printf("                            _      					 \n");
	printf("                           /_` . _ 					 \n");
	printf("                          ._/ / / /					 \n");
	printf("         __.__.__.__.__.__.__.__.__.__.__.__.__.__.__\n");
	printf("                       Hanif R & Reza P				 \n\n");
	
	printf("                   [1] 'Play'   [2] Insctruction	 \n");
	printf("                           [3] Exit					 \n");
}

void gameover()	//Gameover Function (Bad Ending)
{	
	system("cls");
	txt("...", 500000, 1);
    printf("\n\n\n");
    txt("Somehow... ", 80000, 10000);
    usleep(400000);
    txt("You Died..", 80000, 10000);
    usleep(800000);
    printf("\n\n\n");
    txt2("[1] Play Again [2] Back to Menu \n\nYour Choice? : ");
    
	inputover : scanf("%d", &pilover);
	
	switch(pilover){
		case 1 : 
			fflush(stdin);
			fflush(stdout);
			game();
			break;
		case 2 :
			fflush(stdin);
			main();
			break;
		default :
			system("cls");
			printf("...\n\n\n");
			printf("Somehow... You Died..\n\n\n");
			printf("[1] Play Again [2] Back to Menu \n");
			error("pilover");
			goto inputover;
			break;	
	}
}

void win() //Win Function (Good Ending)
{
	system("cls");
	printf("\n\n\n");
	txt2("Wow..."); usleep(500000);
	printf("\n\n");
	txt2("You survived!! Congratulations!!");
	printf("\n\n\n");
	txt2("Thank you for putting up with this inexcusable piece of program \nwith a sub-par story!!!");
	
	 printf("\n\n\n");
    txt2("[1] Play Again [2] Back to Menu \n\nPlay Again if you haven't seen the bad ending!! : ");
    
    inputwin: scanf("%d", &pilover);
	
	switch(pilover){
		case 1 : 
			fflush(stdin);
			fflush(stdout);
			game();
			break;
		case 2 :
			fflush(stdin);
			main();
			break;
		default :
			system("cls");
			printf("\n\n\n");
			printf("Wow...\n\n");
			printf("You survived!! Congratulations!!");
			printf("\n\n\n");
			printf("Thank you for putting up with this inexcusable piece of program \nwith a sub-par story!!!");
			
			
			printf("\n\n\n");
			printf("[1] Play Again [2] Back to Menu \n");
			error("pilover");
			goto inputwin;
			break;
	}
}

void choice(char pil1[],char pil2[], char consq1[], char consq2[], int x) //Choice Mechanism (Pil1 Pil2 : Deskripsi Pilihan; Consq1 Consq2: Konsekuensi pilihan; x: branch ke-
{
	fflush(stdin);
	fflush(stdout);
	printf("\n\n");
	txt("[1]",50000,20000);
	txt(pil1, 50000, 20000);
	printf("\n");
	txt("[2]",50000,20000);
	txt(pil2, 50000, 20000);
	printf("\n\n");
	txt2("your choice? : ");
	
	branchinput : scanf("%d", &branch[x]);
	
	switch(branch[x]){
		case 1 : 
			fflush(stdin);
			system("cls");
			txt(consq1, 60000, 20000);
			getch();
			break;
		case 2 :
			fflush(stdin);
			system("cls");
			txt(consq2, 60000, 20000);
			getch();
			break;
		default :
			printf("\aPilihan Invalid, Mohon Coba Lagi : ");
			fflush(stdin);
			branch[x] = 0;
			goto branchinput;
			break;	
	}
}

void txt2(char text[]) //Running Text Player (For The Story), with fixed speed & Randomness (20000 & 10000)
{
	for(i = 0; i < strlen(text); i++) {
    	usleep(30000 + rand() % 10000);
    	printf("%c", text[i]);
    	fflush(stdout);
   	}   	
}

void txt(char text[], int speed, int random) //Running Text Player, with adjustable speed & randomness 
{
	for(i = 0; i < strlen(text); i++) {
    	usleep(speed + rand() % random);
    	printf("%c", text[i]);
    	fflush(stdout);
   	}
}

void error(char input[]) //Base Error Handlinng Function
{
	printf("\n\aInvalid Input, Please try again : ");
	fflush(stdin);
	input = 0;
}

void act1() //Intro Act
{
	system("cls");
  	txt2("The day goes by,"); usleep(500000); txt2(" all the other laborants had been leaving the laboratory, only you decided to run more tests.\n\n"); usleep(500000);
  	txt2(name); txt2(" is a medical student who were given a task by the proffessor to analyse the rate of decaying cells\non a dead specimen. A one-day dead rat was given to be examined by you");
  	
  	getch();
  	
  	system("cls");
  	txt2(name); txt2(" carefully peaks through the microscope to study the behaviour of the decaying cells.");
  	txt2("\nAs "); txt2(name); txt2(" examines,"); usleep(500000); txt2("a woman screaming for help echoes by the hallway"); usleep(500000);
  	
  	choice("Continue Examining the cells", "Check on the hallway", "The scream sounded far away but it did not bother you from examining the decaying cells.", "You proceeds to the hallway and found nothing then goes back to the microscope.", 1);
  	
  	txt2("\n\nAs "); txt2(name); txt2(" writes out the reports on the collected data, "); txt2("she then goes to the cryo room to retrieve a different sample. "); usleep(500000); txt2("\nAgain,"); txt2(" she hears a woman screaming for help but this time it sounded closer.\n\n"); usleep(500000);
  	txt2(name); txt2(" approaches her desk to disect the fresh sample,"); usleep(500000); txt2(" As She holds the blade to deskin the sample, right next to her left ear,\na lady whispers softly saying\n\n\"Help, me..\"\n\n Half of her body goes extremely cold and she threw the blade and slits through her's left hand.");
  	txt2("\nShe then runs as fast as She can just to get out of the building.");
  	
  	getch();
  	
  	system("cls");
  	txt2("The Next Day.....");
  	usleep(500000);
  	printf("\n\n");
  	txt2("The class seems very crowded and alive. It seems that none of the students were absent that day.\nAs the class ends, the professor is approaching you to check on the progress. \n");
  	txt2("\"Howsit' goin "); txt2(name); txt2("?\" asked the professor in a very strong voice. you spooked out because of what happened last night.\n\nAfter the professor left, Lucas, your bestfriend comes by and asked: \"Why were you so scared of him? Did something happened?\""); usleep(500000);
  	
  	choice("Tell him what happened last night", "don't telling him what happened last night", "\"Bullshit, you must be tired. Go get some sleep\" He responded","\"Look at your left hand. My gut is telling me that something happened last night. I will accompany you for the next few days ok in case something happens to you.\"\n\nHe is now by your side for the next few days", 2);	
}

void actA() //Branch A
{
	system("cls");
	txt2("And the day goes by night again, and again, ");usleep(500000); txt2(name); txt2(" still has an unfinished business on the laboratory.\n\n");usleep(500000);
	txt2("You proceeds to take a new sample to examine, She then peaks through the microscope to study the decaying cells.");
	
	txt2("\nFew minutes later, ");usleep(500000); txt2(name); txt2("smells a very bad smell coming from the cryo room.\nA smell that distinct the smell of a fresh corpse. \n");
	txt2("Out of curiosity, you decides to check on the cryo room to identify the smell.\n\n");
	txt2("As you enters the room, nothing seems out of the ordinary and you proceeds back to the table\n");
	
	getch();
	
	txt2("\nAs you closes the cryo door which has a glass window in the center, on its reflections\n");
	txt2("you can clearly see a really pale lady just standing behind her back.\n\n");
	
	choice("Quickly open the door and get the hell out of the cryo room","Face back just to see if she exists", "you screams and quickly get out of the room", "you quickly turned your body back but the lady appears very close and hover right through your body and you scream.", 3);
	
	txt2("\n\nOn the way back to the table, you stampedes on a corner table which flies a bunch of files to the air.");
	txt2("\nyou takes the messed up files and sort them one by one.\nAs you hover paper-by-paper, she found a file ");
	txt2("about the profile of a medical student which happened to be the same year as you is but you completely has no idea on who she is.\n\n");
	
	choice("Take the file home ","Put back where is was ","you quickly put the file through her bag","you puts it back to where it was",4);
	
	txt2("\n\nYou then starts to tidy up everything on the desk and proceeds back home.");
	getch();
	
	system("cls");
	txt2("The next day, all the meds student are taking a visit to the anatomy room. There are preserved animals, and even human corpses"); usleep(500000);
	txt2("Around 5 human corpses are displayed in a tank with a bloated face as a result of over-hydration from the tank fluids.\n4 of them seems to be males on the later age.");usleep(500000);
	
	choice("Examine further the female body corpse","Tell your friend about the female body corpse", "\"I wonder why her neck has some bruises and marks\" speaks on her mind.", "\"Wonder how she died..\" said by her friend.",5);
	
	txt2("\n\nThe professor comes by and announces the end of the class.");
	getch();
	
	system("cls");
	txt2("Later at night, "); usleep(500000); txt2(name); txt2(" decided to stay up all-night on the laboratory to finish up an unfinished business on the previous task.\n");
	txt2("As she grabs a cup of coffee, she still questions the mysterious medical student that she found on a file.\n");
	txt2("And suddenly, all the lights are dead and in the darkness, the ground starts to shake.\n");
	txt2("After awhile, the lights turns back on and instead of grabbing the coffee, you're grabbing a knife with tainted blood.\n\n");usleep(500000);
	
	txt("\"What the hell is this?\"\n\n", 100000, 20000);
	
	choice("Keep the knife", "Throw away the knife", "you put the knife to your bag", "Out of hesitation, you throws away the knife", 6);
	
	system("cls");
	txt2("Sun has shine, morning breeze flies to the skies.\nyou wake up, while looking through the window from the laboratory and see a crowd of people encircling a body.\n");
	txt2("The body happens to be Lucas, with the same knife she hold, ruptured through his spine.");
	getch();
	
	system("cls");
	txt2("It is Friday, it is now the last class of the week.\n\n"); usleep(500000);
	txt2(name); txt2("'s body looks very peel and not as healthy as before."); usleep(500000);
	
	txt2("\n\nThe professor came by and asks: \"Is everything okay with you, "); txt2(name); txt2("?\"\n\n");
	getch();
	
	choice("Tell him what happened","Do not tell him what happened","\"You can skip the class if you want, I won't forbid you\" says the professor","\"I am sorry on what happened to your best friend\" says the professor",7);
}

void endA1() //Branch A Ending 1
{
	system("cls");
	txt2("Later that evening, you decided to take her belongings on the laboratory.\n");
	txt2("Passing through the hallway, you sees her professor on his room screaming inaudibly.\n\n"); usleep(500000);
	
	txt2("You runs quickly to the laboratory.\n");
	txt2("After taking her belongings, just before she exits the room, the door appears to be locked from the outside.\nyou are now trapped on the laboratory.\n");
	
	txt2("It appears that the same pale lady appears to be sitting down on her table.\n\n");
	txt2("\"Help me get that man to justice\" murmurs the pale lady.\n\n");
	getch();
	txt2("The room suddenly turned dark.\n");
	txt2("Out of nowhere, the professor appears behind you with red glowing eyes, holding the same knife that killed Lucas.\nyou try to run away and looks for a hiding spot\n\n");
	
	choice("Stay in the hiding spot","Scream as hard as you can",
			"After hiding for a while, the professor found YOU and kill YOU with the same knife.\nHe put your body to a tank full of water, rendering your face unidentified.\nLater on, he brings your body to the preserved human body tank.",
			"No help were given, the professor found YOU and kill YOU with the same knife.\nHe put your body to a tank full of water, rendering your face unidentified\n. Later on, he brings your body to the preserved human body tank.",
			8);
}

void endA2() //Branch A Ending 2
{
	system("cls");
	txt2("Later that evening, you decided to take her belongings on the laboratory.\n");
	txt2("Passing through the hallway, you see the professor on his room grabbing the same knife that killed Lucas.\n\n"); usleep(500000);
	
	txt2("You runs quickly to the laboratory.\n");
	txt2("After taking her belongings, just before she exits the room, the door appears to be locked from the outside.\nyou are now trapped on the laboratory.\n");
	
	txt2("It appears that the same pale lady appears to be sitting down on her table.\n\n");
	txt2("\"Help me get that man to justice\" murmurs the pale lady.\n\n");
	getch();
	txt2("The room suddenly turned dark.\n");
	txt2("Out of nowhere, the professor appears behind you with red glowing eyes, holding the same knife that killed Lucas.\nyou try to run away and looks for a hiding spot\n\n");
	
	choice("Stay in the hiding spot","Scream as hard as you can",
			"After hiding for a while, the professor found YOU and kill YOU with the same knife.\nHe put your body to a tank full of water, rendering your face unidentified.\nLater on, he brings your body to the preserved human body tank.",
			"No help were given, the professor found YOU and kill YOU with the same knife.\nHe put your body to a tank full of water, rendering your face unidentified\n. Later on, he brings your body to the preserved human body tank.",
			8);
}

void actB() //Branch B
{
	system("cls");
	txt2("And the day goes by night. ");usleep(500000); txt2("Accompanied by Lucas, they both decided to go to the laboratory to finish their task.\n\n");usleep(500000);
	txt2("You proceeds to take a new sample to examine, She then peaks through the microscope to study the decaying cells.");
	
	txt2("\nFew minutes later, ");usleep(500000); txt2(name); txt2(" smells a very bad smell coming from the cryo room.\nA smell that distinct the smell of a fresh corpse. \n");
	
	txt2("\n\"What the hell is this smell?\""); usleep(500000); txt2("says by Lucas in a very shocked way.\n\n"); usleep(500000);
	txt2("They both go to the cryo room to check the smell. \n"); 
	txt2("It appears that they found a pale lady laying on the floor, with her neck bruised and marked.\n\n");
	
	choice("Check the lady further", "Run the hell out of the room", "As they head to the pale lady, the lights turns off and they hear a whisper \"Help me\".\n\nAfter the lights goes on, the lady disappears", "As they run away from the room, they can hear a woman screaming \"HELP ME\" fiercefully.", 3);

	txt2("\n\nOn the way back to the table, they stampedes on a corner table which flies a bunch of files to the air.");
	txt2("\nyou takes the messed up files and sort them one by one.\nAs you hover paper-by-paper, uou found a file ");
	txt2("about the profile of a medical student which happened to be the same year as you is\nbut you completely has no idea on who she is.\n\n");

	choice("Show him and put it on your bag","Show him and leave it to where it was","you quickly put the file through her bag","you puts it back to where it was",4);	
	
	txt2("\n\nthey then starts to tidy up everything on the desk and proceeds back home.");
	getch();
	
	system("cls");
	txt2("The next day, all the meds student are taking a visit to the anatomy room. There are preserved animals, and even human corpses\n\n"); usleep(500000);
	txt2("Around 5 human corpses are displayed in a tank with a bloated face as a result of over-hydration from the tank fluids.\n4 of them seems to be males on the later age.");usleep(500000);
	
	choice("Examine further the female body corpse","Ask your professor who the female body is", "\"Look she has a bruised neck\"you said to Lucas", "\"She was a dying patient on a cancer hospital and decided to donate her body for educational use\" says the professor",5);
	
	txt2("\n\nThe professor comes by and announces the end of the class.");
	getch();
	
	system("cls");
	txt2("Later at night, "); usleep(500000); txt2(name); txt2(" decided to stay up all-night on the laboratory to finish up an unfinished business on the previous task.\n");
	txt2("As promised, Lucas decided to accompany her. They both questions and discusses the mysterious medical student that she found on a file.\n");
	txt2("And suddenly, all the lights are dead and in the darkness, the ground starts to shake.\n");
	txt2("After awhile, the lights turns back on and suddenly the pale lady appears while grabbing a knife with tainted blood. \n\n");usleep(500000);
	
	txt("\"What the hell do you want?\" says Lucas angrily.\n\n", 100000, 20000);

	choice("Calm him away","Let him be","You calms him down by telling him to back off. The pale lady suddenly disappears","Lucas still raises up his voice and suddenly the pale lady disappears", 6);
	
	system("cls");
	txt2("Sun has shine, morning breeze flies to the skies.\n\n"); usleep(500000); 
	txt2(name); txt2(" wakes up next to Lucas, while looking through the window from the laboratory,you sees a crowd of people encircling a body.\n");
	txt2("Out of curiosity, she decides to run and check up on who that body is.\n");
	txt2("The body happens to be her classmate, with the same knife she they saw, ruptured through her spine.\n\n");usleep(500000);
	
	txt("......", 200000, 200000);
	getch();
	
	system("cls");
	txt2("It is Friday, it is now the last class of the week. your body looks very peel and not as healthy as before.\n\n");

	txt2("The professor came by and asks: \"Is everything okay with you, "); txt2(name); txt2("?\"\n\n");
	
	choice("Tell him what happened","Do not tell him what happened","\"You can skip the class if you want, I won't forbid you\" says the professor","\"I am sorry on what happened to your friend\" says the professor",7);
}

void endB1() //Branch B Ending 1
{
	system("cls");
	txt2("Later that evening, you and Lucas decided to take your belongings on the laboratory.\n");usleep(500000);
	txt2("Passing through the hallway, you sees your professor on his room screaming inaudibly.\n\n"); usleep(500000);
	
	txt2("You both then runs quickly to the laboratory.\n");
	txt2("After taking your belongings, just before you and lucas exits the room, the door appears to be locked from the outside.\nyou are now trapped on the laboratory.\n");
	
	txt2("It appears that the same pale lady appears to be sitting down on her table.\n\n");
	txt2("\"Help me get that man to justice\" murmurs the pale lady.\n\n");
	getch();
	txt2("The room suddenly turned dark.\n");
	txt2("Out of nowhere, the professor appears behind you with red glowing eyes, holding the same knife that killed Lucas.\nyou try to run away and looks for a hiding spot\n\n");
	
	choice(	"Stay in the hiding spot", 
			"Get to Lucas", 
			"After hiding for a while and bought some time,\nLucas found the correct time to take the professor down using a fire extinguisher. ", 
			"After reaching to Lucas,\nLucas found the correct time to take the professor down using a fire extinguisher. ", 8);

	txt2("\n\nThe professor passed out.");
	getch();
	
	system("cls");
	txt("...",500000, 1);
	txt2("\n\nAfter calling the police,"); usleep(500000); txt2("the professor is being held up to custody"); usleep(500000);
	
	txt2("\n\nDays passed by, "); usleep(500000); txt2("after interogation by interogation,"); usleep(500000); txt2("answers finally appear");
	
	txt2("\n\nIt appears that the professor were possesed by an evil demon that shake the laboratoy,"); usleep(500000); txt2("\nbeing influenced to kill the unidentified meds school student, ");
	usleep(500000); txt2("\n\nwho the corpse appears to be preserved in a tank......");
	getch();
}

void endB2() //Branch B Ending 2
{
		system("cls");
	txt2("Later that evening, you and Lucas decided to take your belongings on the laboratory.\n");usleep(500000);
	txt2("You both then sees the professor on his room grabbing the same knife that killed her classmate.\n\n"); usleep(500000);
	txt2("You both then runs quickly to the laboratory.\n");
	txt2("After taking your belongings, just before you and lucas exits the room, the door appears to be locked from the outside.\nyou are now trapped on the laboratory.\n");
	
	txt2("It appears that the same pale lady appears to be sitting down on her table.\n\n");
	txt2("\"Help me get that man to justice\" murmurs the pale lady.\n\n");
	getch();
	txt2("The room suddenly turned dark.\n");
	txt2("Out of nowhere, the professor appears behind you with red glowing eyes, holding the same knife that killed Lucas.\nyou try to run away and looks for a hiding spot\n\n");
	
	choice(	"Stay in the hiding spot", 
			"Get to Lucas", 
			"After hiding for a while and bought some time,\nLucas found the correct time to take the professor down using a fire extinguisher. ", 
			"After reaching to Lucas,\nLucas found the correct time to take the professor down using a fire extinguisher. ", 8);

	txt2("\n\nThe professor passed out.");
	getch();
	
	system("cls");
	txt("...",500000, 1);
	txt2("\n\nAfter calling the police,"); usleep(500000); txt2("the professor is being held up to custody"); usleep(500000);
	
	txt2("\n\nDays passed by, "); usleep(500000); txt2("after interogation by interogation,"); usleep(500000); txt2("answers finally appear");
	
	txt2("\n\nIt appears that the professor were possesed by an evil demon that shake the laboratoy,");usleep(500000); txt2("\nbeing influenced to kill the unidentified meds school student, ");
	usleep(500000); txt2("\n\nwho the corpse appears to be preserved in a tank......");
	getch();
}
