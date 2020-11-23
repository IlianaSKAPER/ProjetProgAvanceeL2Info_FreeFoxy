
#ifndef DATA_INIT_H_INCLUDED
#define DATA_INIT_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constantes.h"
#include "structures.h"
#include "fonctions_fichiers.h"

typedef struct nb_elements{
    int walls;
    int rocks;
    int bushes;
    int chests;
    int keys;
    int dragons;
    int doors;
    int foxy;
} nb_elements;

typedef struct objets{
    int num;
    int case_x;
    int case_y;
    int pos_x;
    int pos_y;
} objets;

typedef struct liste liste;
struct liste{
    objets element;
    liste* next;
};

void load_level (int level, int** map);

void print_map(int** map);

void print_map_char(char** map);

void setZeroNBElements(nb_elements* nb);

liste** create_tabObjets();

void ajouter_element(liste** tab, int obj, int x, int y);

liste** analyse_map(int** map, nb_elements* nb_el);

#endif