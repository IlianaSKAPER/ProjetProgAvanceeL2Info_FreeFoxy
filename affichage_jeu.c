#include "affichage_jeu.h"


sprites* charger_sprites(SDL_Renderer* renderer){
    sprites* sp = malloc(sizeof(sprites));

    sp->decor = charger_image_transparente_rgb("img/decor.bmp", renderer, 255, 0, 255);
    sp->foxy = charger_image_transparente_rgb("img/foxy.bmp", renderer, 255, 0, 255);
    sp->wolfy = charger_image_transparente_rgb("img/wolfy.bmp", renderer, 255, 0, 255);
    sp->heart = charger_image_transparente_rgb("img/heart.bmp", renderer, 255, 0, 255);   

    return sp;
}



SDL_Texture** charger_background(SDL_Renderer* renderer){
    SDL_Texture** fond = malloc(sizeof(SDL_Texture*) * NB_COLORS);
    
    fond[WHITE] = charger_fond_uni_rgb(renderer, 255, 255, 255);
    fond[GRASS] = charger_fond_uni_rgb(renderer, 62, 72, 35);
    fond[GREYFLOOR] = charger_fond_uni_rgb(renderer, 195, 195, 195);
    //fond[DARKNESS] = charger_fond_uni_rgb(renderer, 68, 68, 68);
    fond[DARKNESS] = charger_fond_uni_rgb(renderer, 0, 0, 0);

    return fond;
}



void apply_textures(SDL_Renderer* renderer, SDL_Texture** fond, sprites* sprite, liste** objets, nb_elements* nb_el){
    liste* l = malloc(sizeof(liste));

    // background
    SDL_RenderCopy(renderer, fond[GRASS], NULL, NULL);

    //bandeau score
    SDL_Rect R;
    R.h = TAILLE_BLOC_H;
    R.w = LARGEUR_FENETRE;
    R.x = 0;
    R.y = 0;
    SDL_RenderCopy(renderer, fond[DARKNESS], &R, &R );

    //murs
    l = objets[WALL_OBJ];
    SDL_Rect SrcR_wall;
    SrcR_wall.h = TAILLE_BLOC_H;
    SrcR_wall.w = TAILLE_BLOC_L;
    SrcR_wall.x = 0;
    SrcR_wall.y = 0;
    SDL_Rect DestR_wall;
    DestR_wall.h = TAILLE_BLOC_H;
    DestR_wall.w = TAILLE_BLOC_L;
    while(l != NULL){
        DestR_wall.x = l->element.pos_x;
        DestR_wall.y = l->element.pos_y;
        SDL_RenderCopy(renderer, sprite->decor, &SrcR_wall, &DestR_wall);
        l = l->next;
    }



}
/*
    int walls;
    int rocks;
    int bushes;
    int chests;
    int keys;
    int dragons;
    int doors;
    int foxy;**/


void destroy_textures(sprites* sprite){
    SDL_DestroyTexture(sprite->wolfy);
    SDL_DestroyTexture(sprite->decor);
    SDL_DestroyTexture(sprite->heart);
    SDL_DestroyTexture(sprite->foxy);
}
    
