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

	printf("Bonjour et bienvenue dans exiaSaver !\nVeuillez appuyez sur Entrée pour continuer...");
	getchar();
	printf("\nNous allons voir ensemble quel écran de veille nous allons lancer\nVeuillez appuyez sur Entrée pour continuer...\n\n");
	getchar();
	printf("Le nombre random est de : %d\n\n", nb);
	if (nb ==1)
	{
		printf("Nous allons lancer le type statique !\n");
	}
	else if (nb ==2)
	{
		printf("Nous allons lancer le type dynamique !\n");
	}
	else if (nb ==3)
	{
		printf("Nous allons lancer le type interactif !\n");
	}
	saveDate(nb);
}

/*-----------------------FONCTION NOMBRE RANDOM-----------------------*/

int nb_rand(void)
	{
	    return (rand());
	}

/*-----------------------FONCTION POUR EXPORTER DANS L'HISTORIQUE-----------------------*/

void saveDate(int type)
{
	FILE* fhistorique = NULL; //initialise le pointeur à NULL
	fhistorique = fopen("historique.txt", "r+"); //OUVRE LE FICHIER historique.c

	if (fhistorique != NULL) //Vérifie si le fichier est bien ouvert, car si fichier=NULL signifie qu'il y a une erreur
	{
		printf("\nSuccès pour l'ouverture de l'historique\n");

		/*----------------RECUPERER L'HEURE ET LA DATE----------------*/

		//Lire l'heure courante
		time_t HeureDate;
		HeureDate = time(NULL);

		//Convertir l'heure en heure locale
		struct tm tm_HeureDate = *localtime (&HeureDate);

		//Crée une chapine JJ/MM/AAAA HH:MM:SS
		char s_HeureDate[sizeof "JJ/MM/AAAA HH:MM:SS"];

		strftime (s_HeureDate, sizeof s_HeureDate, "%d/%m/%Y %H:%M:%S", &tm_HeureDate);


		fseek(fhistorique, 0, SEEK_END); //Place le curseur à la fin du fichier

		//Récupère le paramètre associé



		/*-----------ECRITURE DE TOUTES LES DONNEES DANS L'HISTORIQUE-----------*/

		fseek(fhistorique, 0, SEEK_END); //Place le curseur à la fin du fichier

		//Ecrit la date
		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique,"%s", s_HeureDate);
		fprintf(fhistorique,";");

		//Ecrit le type lancé
		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique, "%d", type);
		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique,";");

		if(nb == 1)
		{
			//Récupère le paramètre associé
			//Ecrit le paramètre associé
			fseek(fhistorique, 0, SEEK_END);
			fprintf(fhistorique,"\n");
		}
		else if (nb == 2)
		{
			//Récupère le paramètre associé
			//Ecrit le paramètre associé
			fseek(fhistorique, 0, SEEK_END);
			fprintf(fhistorique,"\n");
		}
		else if (nb == 3)
		{
		

		fclose(fhistorique);//FERME LE FICHIER
		printf("Ecriture dans l'historique réussie\n\n");
	}
	else
	{
		printf("\nImpossible d'ouvrir le fichier historique...");
	}
}

