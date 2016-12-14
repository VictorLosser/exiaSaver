#include <stdlib.h>		//Bibliothèque fondamentales
#include <stdio.h>		//Contenant printf, scanf, ...
#include <ncurses.h>		//Bibliothèque pour quitter le processus sur commande de touches
#include <string.h>

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


int main (int argc, char *argv[])
    {
        system("clear");      		//Fonction qui nettoie la console    	
	FILE* fichier1 = NULL;     	//Pointeur initialisé à NULL
	char chaine[TAILLE_MAX];        
	int chaine2[2];
        int i=0, j=0;
        int a,b;
	char c;
	int nombre;
	
	fichier1 = fopen(argv[1], "r");						//Ouverture du fichier correspondant à la commande tapée en lecture simple
										//Le pointeur fichier devient le pointeur de l'image correspondant
        
        if (fichier1 != NULL) 							//On peut lire le fichier
            {
                fseek(fichier1, 3, SEEK_SET);                   
                fscanf(fichier1, "%d %d", &chaine2[0], &chaine2[1]);
                a = chaine2[0];
                b = chaine2[1];
                a = (a*2)-1;
        	fseek(fichier1, 9, SEEK_SET);
                if (nombre != 2)
			{			
				printf("\n\n\n\n\n\n\n");  		//Affichage centré verticalement
			}
		else
			{
				printf("\n");  				//Affichage centré verticalement
			}
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
			printf_center(chaine);                  	//On affiche la ligne centré
                    }
			fclose(fichier1);   				// On ferme le fichier ouvert
            }
        else 								//On lit le fichier, tant qu'on ne recoit pas d'erreur
            {
               	//On affiche un message d'erreur
                printf("Impossible d'ouvrir le fichier, alors arrête de SPAM!\n");
            }
	initscr();							//Commande qui permet de quitter le processus en cours
	c = getchar();							//Sur commande d'une touche
	if (c != '\0');							//Si c est différent de rien, on sort de la boucle
	endwin();						       	//Fonction qui permet de revenir au terminal par default en terminant le processus
	system("clear");						//Nettoie la console
	return 0;
    }