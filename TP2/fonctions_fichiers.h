
#ifndef FONCTIONS_FICHIERS_H_INCLUDED
#define FONCTIONS_FICHIERS_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char** allouer_tab_2D(int n, int m);
//allouer un tableau de caractères detaillen◊m, où n et m sont les nombres de lignes et de colonnes, 
//et initialiserce tableau avec le caractère espace (’ ’)

void desallouer_tab_2D(char** tab, int n); 
//libérer un tableau à deuxdimensions, denlignes.

void afficher_tab_2D(char** tab, int n, int m);
 //a cher le contenu d’untableau de caractères de taille m
 
void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol);
//compter le nombre max de lignes (nbLig) et de colonnes (nbCol) dans le fichierdont le nom estnomFichier.
 
char** lire_fichier(const char* nomFichier);
/*lire un fichier dont le nomestnomFichier, 
 et retourner le tableau qui contient les caractères du fichier
 tel qu’une ligne du tableau correspond à une ligne du fichier */

#endif