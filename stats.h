typedef struct Input Input;
struct Input{
    char date[11];
    char heure[11];
    char type[6];
    char parametre[20]; //Le nom de nos fichiers ne depassera pas les 20 caracteres et les dimensions non plus
};

int nombreLignes(void);
void ReadStats(Input input[]);
void triDate(Input input[]);
void triHeure(Input input[]);
void PrintStats(Input input[]);
void Type_tS(Input input[]);
void Image_tS1_lu(void);
