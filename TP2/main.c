#include "fonctions_fichiers.h"

int main(void) {
    int n = 4, m = 5;
    int nbLig, nbCol;


    char** tab = allouer_tab_2D(n, m);
    if(tab != NULL){
        printf("alouement réussi\n");
    } else {
        printf("alouement echoué\n");
    }

    afficher_tab_2D(tab, n, m);

    taille_fichier("tabCaracteres.txt", &nbLig, &nbCol);
    printf("taille tab : l=%d, c=%d\n", nbLig, nbCol);

    char** tabChar = lire_fichier("tabCaracteres.txt");
    afficher_tab_2D(tabChar, nbLig, nbCol);

    desallouer_tab_2D(tab, n);
    if(tab == NULL) {
        printf("désallouement réussi\n");
    } else {
        printf("désallouement echoué\n");
    }

    return 0;
}