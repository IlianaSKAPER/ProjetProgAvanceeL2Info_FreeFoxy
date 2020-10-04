#include "affichage_SDL.h"



SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer) {
    SDL_Surface* surf = SDL_LoadBMP(nomfichier);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return tex;
}

SDL_Texture* charger_fond_uni (SDL_Renderer* renderer, const Uint32 color_map) {
    SDL_Surface* surf = SDL_CreateRGBSurface(0, LARGEUR_FENETRE, HAUTEUR_BG, 32, 0, 0, 0, 0);
    SDL_FillRect(surf, NULL, color_map);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return tex;
}

SDL_Texture* charger_fond_uni_rgb (SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b) {
    SDL_Surface* surf = SDL_CreateRGBSurface(0, LARGEUR_FENETRE, HAUTEUR_BG, 32, 0, 0, 0, 0);
    SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, r, g, b));
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return tex;
}



SDL_Texture* charger_image_transparente_map(const char* nomfichier, SDL_Renderer* renderer, const Uint32 color_map) {
    SDL_Surface* surf = SDL_LoadBMP(nomfichier);
    SDL_SetColorKey(surf, SDL_TRUE, color_map);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return tex;
}

SDL_Texture* charger_image_transparente_rgb(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b) {
    SDL_Surface* surf = SDL_LoadBMP(nomfichier);
    SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, r, g, b));
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return tex;
}


SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,TTF_Font *font, SDL_Color color){
    SDL_Surface* surf = TTF_RenderText_Solid(font, message, color) ;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return tex;
}



