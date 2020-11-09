#ifndef AFFICHAGE_JEU_H_INCLUDED
#define AFFICHAGE_JEU_H_INCLUDED


    #include "affichage_SDL.h"
    #include "data_init.h"

    typedef struct sprites{
        SDL_Texture* decor;
        SDL_Texture* wolfy;
        SDL_Texture* foxy;
        SDL_Texture* heart;
    }sprites;


    sprites* charger_sprites(SDL_Renderer* renderer);

    SDL_Texture** charger_background(SDL_Renderer* renderer);

#endif