#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stats.h"

#define TAILLE_MAX 100

int main()
{
    system("clear");
    int choix;


    printf
    ("Bienvenue dans l'espace dédié aux stats.\n\
    ----------------------\n\
    Vous pouvez consulter différentes stats :\n\n\
       1. Le tri des stats selon l'heure\n\n\
       2. Les stats sur le termSaver exécuté\n\n\
       3. Les stats sur l'image chargé pour le type statique\n\n\
    Merci de faire votre choix :\n");
    scanf("%d", &choix);
    system("clear");

        printf("\nSuccès pour l'ouverture de l'historique\n");

        /*---------STATS SUR LA DATE---------*/
        if(choix == 1)
        {
            Input newInput[1000] = {0}; //Création d'une nouvelle entrée
            Lecture_stats(newInput); //Lance la fonction Lecture_stats qui lit les stats comme son nom l'indique !
            tri_Heure(newInput); //Lance la fonction tri_heure qui tri... l'heure !
        }

        /*---------STATS SUR LE TYPE DE FICHIER EXECUTE---------*/
        else if(choix == 2)
        {
            Input newInput[TAILLE_MAX] = {0}; //Création d'une nouvelle entrée
            Lecture_stats(newInput); //Lance la fonction Lecture_stats qui lit les stats comme son nom l'indique !
            Type_tS(newInput); //Lance la fonction Type_tS
            return 0;
        }

        /*---------STATS SUR L'IMAGE CHARGEE POUR LE TYPE STATISTIQUE---------*/
        else if(choix == 3)
        {
            Image_tS1_lu(); //Lance la fonction image_ts1_lu (description plus bas avant la fonction)

        }
}

/*-------------FONCTION POUR LIRE ET STOCKER TOUTES LES VALEURS DE L'HISTORIQUE-------------*/
void Lecture_stats(Input input[])
{
    FILE *fichier = NULL;
    fichier = fopen("historique.txt", "r");
    if (fichier != NULL) {
        char log[50] = "";
        int i = 0;
        while (fgets(log, 50, fichier) != NULL) {
            strcpy(input[i].date, strtok(log, " "));
            strcpy(input[i].heure, strtok(NULL, ";"));
            strcpy(input[i].type, strtok(NULL, ";"));
            strcpy(input[i].parametre, strtok(NULL, "  "));
            i++;
        }
    }
    fclose(fichier);
}


/*-------------FONCTION POUR TRIER L'HEURE DANS L'ORDRE CHRONOLOGIQUE-------------*/
void tri_Heure(Input input[])
{
    int k = 0, trie = 0;
    while (trie == 0)
    {
        trie = 1;
        for (k = 0; k < 100; k++)
        {
            if (strcmp(input[k].heure, input[k + 1].heure) > 0)
            {
                char echangeDate[11];
                strcpy(echangeDate, input[k].date);
                strcpy(input[k].date, input[k + 1].date);
                strcpy(input[k + 1].date, echangeDate);

                char echangeHeure[11];
                strcpy(echangeHeure, input[k].heure);
                strcpy(input[k].heure, input[k + 1].heure);
                strcpy(input[k + 1].heure, echangeHeure);

                char echangeType[6];
                strcpy(echangeType, input[k].type);
                strcpy(input[k].type, input[k + 1].type);
                strcpy(input[k + 1].type, echangeType);

                char echangeParametre[20];
                strcpy(echangeParametre, input[k].parametre);
                strcpy(input[k].parametre, input[k + 1].parametre);
                strcpy(input[k + 1].parametre, echangeParametre);
                trie = 0;
            }
        }
    }
    Afficher_stats(input);
}


/*-------------FONCTION POUR AFFICHER LES DIFFERENTES VALEURS DANS L'HISTORIQUE-------------*/
void Afficher_stats(Input input[])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        //printf("%d", i);
        printf("%s  ", input[i].date);
        printf("%s  ", input[i].heure);
        printf("%s  ", input[i].type);
        printf("%s  ", input[i].parametre);
        printf("\n  ");
    }
}

/*-------------FONCTION POUR COMPTER ET AFFICHER LE NOMBRE DE TYPES TERMSAVER LANCES-------------*/
void Type_tS(Input input[])
{
    int i, type1=0, type2=0, type3=0;

    /*On va lire jusqu'à 100 lignes*/
    for (i = 0; i < 100; i++)
    {
        switch ((int)input[i].type[0])
        {
            /* Si le type lu est 1, on incrémente le compteur de type1 de 1*/
            case 49:
                type1++;
                break;

            /* Si le type lu est 2, on incrémente le compteur de type2 de 1*/
            case 50:
                type2++;
                break;

            /* Si le type lu est 3, on incrémente le compteur de type3 de 1*/
            case 51:
                type3++;
                break;
        }
    }
    printf("type 1: %d\ntype 2: %d\ntype 3: %d\n", type1, type2, type3);
}

/*------FONCTION POUR SAVOITR COMBIEN DE FOIS ON A LANCE TELLE OU TELLE IMAGE------*/
void Image_tS1_lu(void)
{
    int compteur[5]; //Déclaration des compteurs pour les images lu
    /*
    compteur[0] : compteur pour l'image 1_XD.pbm
    compteur|1] : compteur pour l'image 2_chateau.pbm
    compteur[2] : compteur pour l'image 3_fusee.pbm
    compteur[3] : compteur pour l'image 4_maison.pbm
    compteur[4] : compteur pour l'image 5_sapin.pbm
    */

    FILE* fhistorique = NULL; //initialise le pointeur à NULL
	fhistorique = fopen("historique.txt", "r"); //OUVRE LE FICHIER historique.c

		int i;

		char image1c[] = "1_XD.pbm"; //char de comparaison pour l'image 1_XD.pbm
		char image2c[] = "2_chateau.pbm"; //char de comparaison pour l'image 2_chateau.pbm
		char image3c[] = "3_fusee.pbm"; //...
		char image4c[] = "4_maison.pbm";
		char image5c[] = "5_sapin.pbm";

        int date[3][TAILLE_MAX] = {0}; //tableau contenant la date
        int heure[3][TAILLE_MAX] = {0}; //tableau contenant l'heure
        int mode[1][TAILLE_MAX] = {0}; //tableau contenant le type de tS
        char nom[50] = {""}; //tableau de char contenant le nom de l'image


	if (fhistorique != NULL) //Regarde si le fichier a bien été ouvert
	{

		while (fgetc(fhistorique) != EOF) //Tant que le caractère lu lit quelque chose
		{

        fscanf(fhistorique, "%d/%d/%d %d:%d:%d;%d;%s",  &date[0][i], &date[1][i], &date[2][i], &heure[0][i], &heure[1][i], &heure[2][i], &mode[0][i], &nom); //On lit toutes les valeurs qu'il nous faut


				if (strcmp(nom,image1c) == 0) //Regarde si le résultat de strcmp est 0 (donc les deux chaines sont identiques, donc ce qui est lu est ici 1_XD.pbm)
				{
                    compteur[0]++; //J'incrémente le compteur pour l'image 1 de 1
				}
				else if (strcmp(nom,image2c) == 0)
				{
                    compteur[1]++;
				}
				else if (strcmp(nom,image3c) == 0)
				{
                    compteur[2]++;
				}
				else if (strcmp(nom,image4c) == 0)
				{
                    compteur[3]++;
				}
				else if (strcmp(nom,image5c) == 0)
				{
                    compteur[4]++;
				}


		}

	}
	else
	{
		printf("non\n"); //Le fichier fhistorique n'a pas pu etre ouvert
	}
	fclose(fhistorique);
    printf("Image XD: %d\nImage chateau: %d\nImage fusee: %d\nImage maison: %d\nImage sapin: %d\n", compteur[0], compteur[1], compteur[2], compteur[3], compteur[4]); //Affiche le résultat des compteurs
}
