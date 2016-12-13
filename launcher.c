#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Bibliothèque contenant les fonctions pour le parcours de dossiers*/
#include <dirent.h>

/* Si le système n'est pas windows, alors inclure sys/types.h*/
#ifndef WIN32
    #include <sys/types.h>
#endif

/*On inclut les prototypes des fonctions du launcher*/
#include "launcher.h"


int main(int argc,char *argv[])
{
	system("clear");
	srand(time(NULL));
	int choix_ts=nb_rand()%3+1;

	int nb_I_S;
	nb_I_S = nombreImagesStatique();

	int choix_I_S=nb_rand()%nb_I_S+1;

	printf("Bonjour et bienvenue dans exiaSaver !\nVeuillez appuyez sur Entrée pour continuer...");
	getchar();
	printf("\nNous allons voir ensemble quel écran de veille nous allons lancer\nVeuillez appuyez sur Entrée pour continuer...\n\n");
	getchar();
	printf("Le nombre random est de : %d\n\n", choix_ts);
	if (choix_ts ==1)
	{
		printf("Nous allons lancer le type statique !\n");


		/*-----------L'IMAGE QUE L'ON VA LANCER-----------*/
		/*switch (nbPic)
		{
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		}*/
	}
	else if (choix_ts ==2)
	{
		printf("Nous allons lancer le type dynamique !\n");
	}
	else if (choix_ts ==3)
	{
		printf("Nous allons lancer le type interactif !\n");
	}
	saveDate(choix_ts,choix_I_S);
}

/*-----------------------FONCTION NOMBRE RANDOM-----------------------*/

int nb_rand(void)
	{
	    return (rand());
	}


/*-----------------------FONCTION POUR EXPORTER DANS L'HISTORIQUE-----------------------*/

void saveDate(int type, int nombrePicture)
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



		/*-----------ECRITURE DE TOUTES LES DONNEES (SAUF PARAMETRE) DANS L'HISTORIQUE-----------*/

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

		/*-----------------ECRITURE DES PARAMETRES ASSOCIES AU TERMSAVER CHOISI-----------------*/
		if(type == 1)
		{
			//Ecrit l'image utilisé pour le type statique
			switch (nombrePicture)
			{
				case 1:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"1_XD.pbm\n");
				break;
				case 2:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"2_château.pbm\n");
				break;
				case 3:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"3_fusée.pbm\n");
				break;
				case 4:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"4_maison.pbm\n");
                break;
                case 5:
                    fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"5_sapin.pbm\n");
				break;
			}
		}
		else if (type == 2)
		{
			fseek(fhistorique, 0, SEEK_END);
			fprintf(fhistorique,"\n");
		}
		else if (type == 3)
		{
			fseek(fhistorique, 0, SEEK_END);
			fprintf(fhistorique,"\n");
		}
		fclose(fhistorique);//FERME LE FICHIER
		printf("Ecriture dans l'historique réussie\n\n");

	}
	else
	{
		printf("\nImpossible d'ouvrir le fichier historique...");
	}
}

/*-----------------------FONCTION POUR CONNAITRE LE NOMBRE D'IMAGE-----------------------*/

int nombreImagesStatique(void)
{
    int nombrePic = 0; //initalisation à 0 du nombre d'images

    DIR* repertoireImages = NULL; //déclaration et initialisation à NULL du pointeur repertoireImages

    struct dirent* ent = NULL;

    repertoireImages = opendir("PBM_statique/"); //Ouverture du dossier PBM_statique dans repertoireImages

    while ((ent = readdir(repertoireImages)) != NULL) //Tant que des fichiers sont lus (fichiers déjà tous lu = NULL)
    {
        if (strcmp(ent->d_name, ".") != 0 && //Si le fichier lu n'est pas .
            strcmp(ent->d_name, "..") != 0) //Et n'est pas .. non plus
        nombrePic++; //Alors on incrémente le compteur
    }

    closedir(repertoireImages);
    return nombrePic;

}
