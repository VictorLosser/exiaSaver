#include <stdlib.h>		//Bibliothèque fondamentales
#include <stdio.h>		//Contenant printf, scanf, ...

//#include <conio.h>		//Bibliothèque de la fonction "kbhit()"
#include <string.h>
#include <time.h>		//Bibliothèque contenant la fonction aléatoire

#define TAILLE_MAX 1000		//Taille maximum du fichier
#define LARGEUR_CONSOLE 80


void printf_center (const char* str)
	{
	    unsigned int n;
	    for (n = 0; n < (LARGEUR_CONSOLE-strlen(str)) / 2; n++)
	   	{
	        	putchar(' ');
	    	}
	    printf("%s", str);
	}


int main(int argc, char *argv[])
    {
        system("clear");      		//Fonction qui nettoie la console    
	srand(time(NULL));
	FILE* fichier1 = NULL;     	//Pointeur initialisé à NULL          
	char chaine[TAILLE_MAX];        
        int chaine2[2];
        int i=0, j=0;
        int a,b;
    	int nombre = rand()%4+1;

	if (nombre == 1){fichier1 = fopen("château.pbm", "r");}			//Ouverture du fichier "château.pbm" en lecture simple
										//Le pointeur fichier devient le pointeur sur"château.pbm"
     	if (nombre == 2){fichier1 = fopen("fusée.pbm", "r");}
	if (nombre == 3){fichier1 = fopen("XD.pbm", "r");}
	if (nombre == 4){fichier1 = fopen("maison.pbm", "r");}
        
        if (fichier1 != NULL) 							//On peut lire le fichier
            {
                fseek(fichier1, 3, SEEK_SET);                   
                fscanf(fichier1, "%d %d", &chaine2[0], &chaine2[1]);
                a = chaine2[0];
                b = chaine2[1];
                a = (a*2)-1;
        	fseek(fichier1, 9, SEEK_SET);
                    
		for(i=0; i<b; i++)                   			//Boucle qui va parcourir les lignes
                    {
                        fgets(chaine, TAILLE_MAX, fichier1);		//récupération de la ligne
                        for(j=0; j<a; j++)               		//boucle qui parcours la ligne
                            {
                            	if (chaine[j] == '0')
                                    chaine[j] = ' ';        		//Affiche les caractères correspondants en ' '
               			else if (chaine[j] == '1')
                                    	chaine[j] = '|';
				else if (chaine[j] == ' ')
                                    	chaine[j] = ' ';
				else if (chaine[j] == '5')
                                    	chaine[j] = '_';
				else if (chaine[j] == '6')
                                    	chaine[j] = '~';
				else if (chaine[j] == '7')
                                    	chaine[j] = '/';
				else if (chaine[j] == '8')
                                    	chaine[j] = '-';
				else if (chaine[j] == '9')
                                    	chaine[j] = ')';       
                            }
			printf_center(chaine);                  	//On affiche la ligne
                    }
			fclose(fichier1);   						// On ferme le fichier ouvert
            }
        else 										//On lit le fichier, tant qu'on ne recoit pas d'erreur
            {
               	//On affiche un message d'erreur
                printf("Impossible d'ouvrir le fichier, alors arrête de SPAM!\n");
            }
        return 0;
    }