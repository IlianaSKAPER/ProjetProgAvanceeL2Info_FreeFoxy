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





liste** analyse_map(int** map, nb_elements* nb_el){
    setZeroNBElements(nb_el);

    liste** tab = create_tabObjets();

    for(int j = 0; j<NB_BLOCS_HAUTEUR; j++) {
        for(int i = 0; i<NB_BLOCS_LARGEUR; i++) {
            switch (map[i][j]){
                case WALL_OBJ : 
                nb_el->walls = nb_el->walls + 1;
                ajouter_element(tab, WALL_OBJ, i, j);
                break;

                case ROCK_OBJ :
                nb_el->rocks =  nb_el->rocks + 1;
                ajouter_element(tab, ROCK_OBJ, i, j);
                break;

                case BUSH_OBJ :
                (nb_el->bushes)++;
                ajouter_element(tab, BUSH_OBJ, i, j);
                break;

                case CHEST_OBJ :
                (nb_el->chests)++;
                ajouter_element(tab, CHEST_OBJ, i, j);
                break;

                case KEY_OBJ :
                (nb_el->keys)++;
                ajouter_element(tab, KEY_OBJ, i, j);
                break;

                case DRAGON_OBJ :
                (nb_el->dragons)++;
                ajouter_element(tab, DRAGON_OBJ, i, j);
                break;

                case DOOR_OBJ :
                (nb_el->doors)++;
                ajouter_element(tab, DOOR_OBJ, i, j);
                break;

                case FOXY_OBJ :
                (nb_el->foxy)++;  
                ajouter_element(tab, FOXY_OBJ, i, j);
                break;              
            }
        }
    }

    return tab;
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

liste** create_tabObjets(){
    liste** tab = malloc(sizeof(liste*)*NB_OBJETS);

    for(int i = 0; i<NB_OBJETS; i++){
        tab[i] = NULL;
    }
    return tab;
}

void ajouter_element(liste** tab, int obj, int x, int y){       
    liste* l;

    if(tab[obj] == NULL){
        tab[obj] = malloc(sizeof(liste));
        tab[obj]->next = NULL;
        l = tab[obj];
    } else {
        l = tab[obj];
        while(l != NULL){
            l = l->next;
        }
        l = malloc(sizeof(liste));
        l->next = NULL;

    }

    l->element.case_x = x;
    l->element.case_y = y;
    l->element.num = obj;
    l->element.pos_x = x*TAILLE_BLOC_L;
    l->element.pos_y = TAILLE_BLOC_H + y*TAILLE_BLOC_H;
}














