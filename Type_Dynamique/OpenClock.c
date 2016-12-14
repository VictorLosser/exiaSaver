#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

int InitTime()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant=*localtime(&secondes);
	int TimeS1 = (instant.tm_sec)/10;
	int TimeS2 = (instant.tm_sec)-(TimeS1*10);
	int TimeM1 = (instant.tm_min)/10;
	int TimeM2 = (instant.tm_min)-(TimeM1*10);
	int TimeH1 = (instant.tm_hour)/10;
	int TimeH2 = (instant.tm_hour)-(TimeH1*10);
	
	if (TimeH1 == 1)
	printf("Horloge --> %u%u : %u%u : %u%u\n",TimeH1 ,TimeH2,TimeM1 ,TimeM2,TimeS1 ,TimeS2);
}

int main()
{

	int RefreshT = 10;
	int ctrlc = 0;
	int i;
	int a = 15,b = 10,c = 9,d = 28;
	system("clear");
	while (ctrlc != 1)
	{
		int y = 57;
		gotoxy(c,d);
		InitTime();
		gotoxy(a,b);
		printf("Cet écran sera actualisé dans quelques secondes");
		printf ("\n\n\n");

		for (i=0; i<RefreshT; i++)
		{
			sleep(1);
			gotoxy(a,y);
			printf(".\n");
			y++;
		}
		y=y-RefreshT;
		gotoxy(a,y);
		printf("                            ");
	}
	return 0;
}

