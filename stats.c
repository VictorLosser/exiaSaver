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
       1. Les stats sur la date\n\n\
       2. Les stats sur le termSaver exécuté\n\n\
       3. Les stats sur l'image chargé pour le type statique\n\n\
       4. Les stats sur la taille utilisé pour le mode dynamique\n\n\
    Merci de faire votre choix :\n");
    scanf("%d", &choix);
    system("clear");

        printf("\nSuccès pour l'ouverture de l'historique\n");

        /*---------STATS SUR LA DATE---------*/
        if(choix == 1)
        {



        }

        /*---------STATS SUR LE TYPE DE FICHIER EXECUTE---------*/
        else if(choix == 2)
        {
            Input newInput[100] = {0};
            ReadStats(newInput); //Lance la fonction ReadSats
            Type_tS(newInput); //Lance la fonction Type_tS
            return 0;
        }

        /*---------STATS SUR L'IMAGE CHARGEE POUR LE TYPE STATISTIQUE---------*/
        else if(choix == 3)
        {
            Image_tS1_lu();

        }

        /*---------STATS SUR LA TAILLE UTILISE POUR LE MODE DYNAMIQUE---------*/
        else if(choix == 4)
        {
            printf("J'ai rien développé :'( \n");


        }
}

int nombreLignes(void)
{
	int c;
	int nb_lignes = 0;

	FILE* fhistorique = NULL; //initialise le pointeur à NULL
	fhistorique = fopen("historique.txt", "r+"); //OUVRE LE FICHIER historique.c

    while ((c = getc(fhistorique)) != EOF)
    {
        if (c == '\n')
        ++nb_lignes;
    }
    nb_lignes = nb_lignes-5;

	return nb_lignes;
}

/*-------------FONCTION POUR LIRE ET STOCKER TOUTES LES VALEURS DANS L'HISTORIQUE-------------*/
void ReadStats(Input input[])
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

/*-------------FONCTION POUR TRIER LA DATE DANS L'ORDRE CHRONOLOGIQUE-------------*/
void triDate(Input input[])
{
    int i = 0, tri = 0;
    while (tri == 0)
    {
        tri = 1;
        for (i = 0; i < 100; i++)
        {
            if (strcmp(input[i].date, input[i + 1].date) > 0)
            {
                char echangeDate[11];
                strcpy(echangeDate, input[i].date);
                strcpy(input[i].date, input[i + 1].date);
                strcpy(input[i + 1].date, echangeDate);

                char echangeHeure[11];
                strcpy(echangeHeure, input[i].heure);
                strcpy(input[i].heure, input[i + 1].heure);
                strcpy(input[i + 1].heure, echangeHeure);

                char echangeType[6];
                strcpy(echangeType, input[i].type);
                strcpy(input[i].type, input[i + 1].type);
                strcpy(input[i + 1].type, echangeType);

                char echangeParametre[20];
                strcpy(echangeParametre, input[i].parametre);
                strcpy(input[i].parametre, input[i + 1].parametre);
                strcpy(input[i + 1].parametre, echangeParametre);
                tri = 0;
            }
        }
    }
    PrintStats(input);
}

/*-------------FONCTION POUR TRIER L'HEURE DANS L'ORDRE CHRONOLOGIQUE-------------*/
void triHeure(Input input[])
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
    PrintStats(input);
}

/*-------------FONCTION POUR AFFICHER LES DIFFERENTES VALEURS DANS L'HISTORIQUE-------------*/
void PrintStats(Input input[])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        printf("%d", i);
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

void Image_tS1_lu(void)
{
    int compteur[5]; //Déclaration des compteurs pour les images lu

    FILE* fhistorique = NULL; //initialise le pointeur à NULL
	fhistorique = fopen("historique.txt", "r"); //OUVRE LE FICHIER historique.c

		int i;

		char image1c[] = "1_XD.pbm"; //char de comparaison pour l'image 1_XD.pbm
		char image2c[] = "2_chateau.pbm"; //char de comparaison pour l'image 2_chateau.pbm
		char image3c[] = "3_fusee.pbm"; //...
		char image4c[] = "4_maison.pbm";
		char image5c[] = "5_sapin.pbm";

        int date[3][TAILLE_MAX] = {0};
        int heure[3][TAILLE_MAX] = {0};
        int mode[1][TAILLE_MAX] = {0};
        char nom[50] = {""};


	if (fhistorique != NULL)
	{


		/*------Le type lu est-il bien 1 ?------*/

		while (fgetc(fhistorique) != EOF)
		{

        fscanf(fhistorique, "%d/%d/%d %d:%d:%d;%d;%s",  &date[0][i], &date[1][i], &date[2][i], &heure[0][i], &heure[1][i], &heure[2][i], &mode[0][i], &nom);


				if (strcmp(nom,image1c) == 0)
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
		printf("non\n");
	}
	fclose(fhistorique);
    printf("Image XD: %d\nImage chateau: %d\nImage fusee: %d\nImage maison: %d\nImage sapin: %d\n", compteur[0], compteur[1], compteur[2], compteur[3], compteur[4]);
}
