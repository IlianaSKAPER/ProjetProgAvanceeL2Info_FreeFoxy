#include "data_init.h"


void load_level (int level, int** map) {
    FILE* fichierNiveau;
    char** rawMap = allouer_tab_2D(NB_BLOCS_LARGEUR, NB_BLOCS_HAUTEUR);

    if(level == 1) {
        fichierNiveau = fopen("niveau1.lvl", "r");
    } else if (level == 2) {
        fichierNiveau = fopen("niveau2.lvl", "r");
    } else if (level == 3) {
        fichierNiveau = fopen("niveau3.lvl", "r");
    }
    
    if (fichierNiveau==NULL) {
        perror("Error opening file");
        printf("erreur ouverture fichier");
    }
        

    for(int j=0; j<NB_BLOCS_HAUTEUR; j++) {
        for(int i=0; i< NB_BLOCS_LARGEUR; i++) {
            fscanf( fichierNiveau, "%c" , &rawMap[i][j]);
        }
    }

    print_map_char(rawMap);

    /*
    for(int j = 0; j<NB_BLOCS_HAUTEUR; j++) {
        for(int i = 0; i<NB_BLOCS_LARGEUR; i++) {
            if(rawMap[i][j] == '#')
                map[i][j] = WALL;
            if(rawMap[i][j] == '.')
                map[i][j] = EMPTY;
            if(rawMap[i][j] == 'O')
                map[i][j] = BUSH;
            if(rawMap[i][j] == 'R')
                map[i][j] = ROCK;
            if(rawMap[i][j] == 'C')
                map[i][j] = CHEST;
            if(rawMap[i][j] == 'K')
                map[i][j] = KEY;
            if(rawMap[i][j] == 'D')
                map[i][j] = DRAGON;
            if(rawMap[i][j] == 'P')
                map[i][j] = DOORCLOSE;
        }
    }*/

    if(fclose(fichierNiveau)) {
        printf("erreur fermeture fichier niveau");
    }
}

void print_map(int** map) {
    for(int j = 0; j<NB_BLOCS_HAUTEUR; j++) {
        for(int i = 0; i<NB_BLOCS_LARGEUR; i++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void print_map_char(char** map) {
    for(int j = 0; j<NB_BLOCS_HAUTEUR; j++) {
        for(int i = 0; i<NB_BLOCS_LARGEUR; i++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}