typedef struct Input Input;
struct Input{
    char date[11];
    char heure[11];
    char type[6];
    char parametre[20]; //Le nom de nos fichiers ne depassera pas les 20 caracteres et les dimensions non plus
};

int nombreLignes(void);
void Lecture_stats(Input input[]);
void tri_Date(Input input[]);
void tri_Heure(Input input[]);
void Afficher_stats(Input input[]);
void Type_tS(Input input[]);
void Image_tS1_lu(void);
