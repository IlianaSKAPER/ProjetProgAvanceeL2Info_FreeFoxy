#include "data_init.h"


void load_level (int level, int** map) {
    FILE* fichierNiveau;
    char** rawMap = allouer_tab_2D(NB_BLOCS_LARGEUR, NB_BLOCS_HAUTEUR);

    // ouverture du bon fichier
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
        

    // lecture du fichier et copie dans rawMap (char)
    for(int j=0; j<NB_BLOCS_HAUTEUR; j++) {
        for(int i=0; i< NB_BLOCS_LARGEUR; i++) {
            fscanf( fichierNiveau, " %c" , &rawMap[i][j]);
        }
    }

    print_map_char(rawMap);

    
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
    }

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

void analyse_map(int** map, nb_elements* nb_el){
    setZeroNBElements(nb_el);
    for(int j = 0; j<NB_BLOCS_HAUTEUR; j++) {
        for(int i = 0; i<NB_BLOCS_LARGEUR; i++) {
            switch (map[i][j]){
                case WALL : 
                (nb_el->walls)++;
                break;
                case ROCK :
                (nb_el->rocks)++;
                break;
                case BUSH :
                (nb_el->bushes)++;
                break;
                case CHEST :
                (nb_el->chests)++;
                break;
                case KEY :
                (nb_el->keys)++;
                break;
                case DRAGON :
                (nb_el->dragons)++;
                break;
                case DOORCLOSE :
                (nb_el->doors)++;
                break;
                case FOXY :
                (nb_el->foxy)++;                
            }
        }
    }
}

void setZeroNBElements(nb_elements* nb){
    nb->walls = 0;
    nb->rocks = 0;
    nb->bushes = 0;
    nb->chests = 0;
    nb->keys = 0;
    nb->dragons = 0;
    nb->doors = 0;
    nb->foxy = 0;
}