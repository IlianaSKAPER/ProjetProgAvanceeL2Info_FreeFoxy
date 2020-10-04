#ifndef AFFICHAGE_SDL_H_INCLUDED
#define AFFICHAGE_SDL_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constantes.h"


SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer);


SDL_Texture* charger_fond_uni (SDL_Renderer* renderer, const Uint32 color_map);


SDL_Texture* charger_fond_uni_rgb (SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);


SDL_Texture* charger_image_transparente_map(const char* nomfichier, SDL_Renderer* renderer, const Uint32 color_map);


SDL_Texture* charger_image_transparente_rgb(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b) ;


SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,TTF_Font *font, SDL_Color color) ;


#endif