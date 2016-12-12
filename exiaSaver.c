#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "exiaSaver.h"


int main()
{
	system("clear");
	srand(time(NULL));
	int nb=nb_rand()%3+1;

	printf("Bonjour et bienvenue dans exiaSaver !\nVeuillez appuyez pour continuer...\n");
	getchar();
	printf("Nous allons voir ensemble quel écran nous allons lancer\n\n");
	printf("%d\n", nb);
	if (nb ==1)
	{
		printf("Nous allons lancer le type statique\n");
	}
	else if (nb ==2)
	{
		printf("Nous allons lancer le type dynamique\n");
	}
	else if (nb ==3)
	{
		printf("Nous allons lancer le type interactif\n");
	}
	saveDate;
}

int nb_rand(void)
	{
	    return (rand());
	}

void saveDate(void)
{
	FILE* fhistorique = NULL; //initialise le pointeur à NULL
	fhistorique = fopen("historique.c", "r+"); //OUVRE LE FICHIER historique.c

	if (fhistorique != NULL) //Vérifie si le fichier est bien ouvert, car si fichier=NULL signifie qu'il y a une erreur
	{
		printf("le fichier est ouvert\n\n");
		fseek(fhistorique, 0, SEEK_END); //Place le curseur à la fin du fichier
		//Récupère la date

		//Récupère l'heure

		//Récupère le paramètre associé

		//Ecrit la date
		
		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique," ");
		//Ecrit l'heure

		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique,";");
		//Ecrit le type lancé

		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique,";");
		//Ecrit le paramètre associé

		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique,"\n");

		fclose(fhistorique);//FERME LE FICHIER
	}
	else
	{
		printf("Impossible d'ouvrir le fichier");
	}
}

