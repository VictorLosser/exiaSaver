#include <stdlib.h>		//Bibliothèque fondamentales
#include <stdio.h>		//Contenant printf, scanf, ...

//#include <conio.h>		//Bibliothèque de la fonction "kbhit()"
#include <string.h>
#include <time.h>		//Bibliothèque contenant la fonction aléatoire

#define TAILLE_MAX 1000		//Taille maximum du fichier
#define LARGEUR_CONSOLE 80


int main(int argc, char *argv[])
	{
		system("clear");		//Fonction qui nettoie la console
		srand(time(NULL));		
		FILE* fichier1 = NULL;		//Pointeur initialisé à NULL			
		char caractere;
		int nbCaracteres = 2*(20*20);
		int i=0;
		int nombre = rand()%4+1;
		
		if (nombre == 1){fichier1 = fopen("château.pbm", "r");}				//Ouverture du fichier "château.pbm" en lecture simple
												//Le pointeur fichier devient le pointeur sur "château.pbm"
		if (nombre == 2){fichier1 = fopen("fusée.pbm", "r");}
		if (nombre == 3){fichier1 = fopen("XD.pbm", "r");}
		if (nombre == 4){fichier1 = fopen("maison.pbm", "r");}		
		

		if (fichier1!= NULL)
			{
				//On peut lire le fichier
				fseek(fichier1, 7, SEEK_SET);					//On lit le fichier, tant qu'on ne recoit pas d'erreur
				while (i<nbCaracteres)
					{
						caractere = fgetc(fichier1);
						if (caractere == '0')
							{
								caractere = ' ';		//Affiche les caractères correspondants en ' '
							}
						else if (caractere == ' ')
							{
								caractere = ' ';		//Affiche les caractères correspondants en ' '
							}
						else if (caractere == '1')
							{
								caractere = '|';		//Affiche les caractères correspondants en '|'
							}
						else if (caractere == '5')
							{
								caractere = '_';		//Affiche les caractères correspondants en '_'
							}
						else if (caractere == '6')
							{
								caractere = '~';		//Affiche les caractères correspondants en '~'
							}
						else if (caractere == '7')
							{
								caractere = '/';		//Affiche les caractères correspondants en '/'
							}
						else if (caractere == '8')
							{
								caractere = '-';		//Affiche les caractères correspondants en '-'
							}
						else if (caractere == '9')
							{
								caractere = ')';		//Affiche les caractères correspondants en ')'
							}
						
						printf("%c", caractere);			//On affiche la ligne
						"\n";
						i++;
					}
				
				fclose(fichier1);						// On ferme le fichier ouvert
			}
		else
			{
				//On affiche un message d'erreur
				printf("Impossible d'ouvrir le fichier, alors arrête de SPAM!\n");
			}

		return 0;
	}



