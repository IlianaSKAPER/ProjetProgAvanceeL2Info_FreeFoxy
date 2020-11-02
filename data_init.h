
#ifndef DATA_INIT_H_INCLUDED
#define DATA_INIT_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constantes.h"
#include "fonctions_fichiers.h"

void load_level (int level, int** map);

void print_map(int** map);

void print_map_char(char** map);

#endif