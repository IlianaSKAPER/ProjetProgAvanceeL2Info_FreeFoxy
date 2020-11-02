#include "fonctions_fichiers.h"

//julliette.gaillemein3@etu.univ-lorraine.fr


char** allouer_tab_2D(int n, int m) {
    char** tab = malloc(sizeof(char*)*n);
    for(int i = 0; i<n; i++){
        tab[i] = malloc(sizeof(char)*m);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            tab[i][j] = ' ';
        }
    }
    return tab;
}
//allouer un tableau de caractères de taille n*m, où n et m sont les nombres de lignes et de colonnes, 
//et initialiserce tableau avec le caractère espace (’ ’)

void desallouer_tab_2D(char** tab, int n){
    for(int i = 0; i<n; i++){
        free(tab[i]);
    }
    free(tab);
}
//libérer un tableau à deuxdimensions, denlignes


void afficher_tab_2D(char** tab, int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}
 //a cher le contenu d’untableau de caractères de taille m
 
void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol){
    FILE* f = fopen(nomFichier, "r");
    int l = 0, c = 0;
    int c_max = 0;
    char val;

    while((val = fgetc(f)) != EOF){
        if(val == '\n'){
            l++;
            if(c_max < c) {
                c_max = c;
            }
            c = 0;
        } else {
            c++;
        }
    }

    *nbLig = l;
    *nbCol = c_max;

    fclose(f);
}
//compter le nombre max de lignes (nbLig) et de colonnes (nbCol) dans le fichier
//dont le nom estnomFichier.
 
char** lire_fichier(const char* nomFichier){
    FILE* f = fopen(nomFichier, "r");
    int nbl, nbc;
    char c;

    taille_fichier(nomFichier, &nbl, &nbc);

    char** tab = allouer_tab_2D(nbl, nbc);

    for(int i = 0; i<nbl; i++){
        for(int j = 0; j<nbc; j++){
            if((c = getc(f)) == '\n'){
                for(int k = j; k<nbc; k++){
                    tab[i][k] = ' ';
                }
                j = nbc;
            } else {
                tab[i][j] = c;
            }
        }
    }

    return tab;

}
/*lire un fichier dont le nomestnomFichier, 
 et retourner le tableau qui contient les caractères du fichier
 tel qu’une ligne du tableau correspond à une ligne du fichier */