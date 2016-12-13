#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
        system("clear");
        int choix;

        printf
        ("Bienvenue dans l'espace dédié aux stats.\n\
        ----------------------\n\
        Vous pouvez consulter différentes stats :\n\n\
           1. Les stats sur la date\n\n\
           2. Les stats sur le type de fichier exécuté\n\n\
           3. Les stats sur l'image chargé pour le type statique\n\n\
           4. Les stats sur la taille utilisé pour le mode dynamique\n\n\
        Merci de faire votre choix :\n");
        scanf("%d", &choix);
        system("clear");



        FILE* fhistorique = NULL; //initialise le pointeur à NULL
        fhistorique = fopen("historique.txt", "r+"); //OUVRE LE FICHIER historique.c

        if (fhistorique != NULL) //Vérifie si le fichier est bien ouvert, car si fichier=NULL signifie qu'il y a une erreur
        {
            printf("\nSuccès pour l'ouverture de l'historique\n");

            switch(choix)
            {

                /*---------STATS SUR LA DATE---------*/

                case(1):



                break;

                /*---------STATS SUR LE TYPE DE FICHIER EXECUTE---------*/

                case(2):

                    printf("J'ai rien développé :'( \n");

                break;

                /*---------STATS SUR L'IMAGE CHARGEE POUR LE TYPE STATISTIQUE---------*/

                case(3):

                    printf("J'ai rien développé :'( \n");

                break;

                /*---------STATS SUR LA TAILLE UTILISE POUR LE MODE DYNAMIQUE---------*/

                case(4):

                    printf("J'ai rien développé :'( \n");

                break;


                fclose(fhistorique);//FERME LE FICHIER
            }
        }

        else
        {
            printf("\nImpossible d'ouvrir le fichier historique...");
        }




}




