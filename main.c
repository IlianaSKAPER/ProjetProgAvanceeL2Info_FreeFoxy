#include <time.h>

#include "affichage_SDL.h"



int main(int argc, char *argv[]){
    SDL_Window* window;
    SDL_Event events;
    bool run = true;
    //timerfps_t* timer = create_timer();
    clock_t start_t, end_t, diff_t;
    double t;
    int i = 0;



    // ----- Initialisation --------

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Initialisation de la SDL{
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    TTF_Init();

    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if(window == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(window, -1,  SDL_RENDERER_ACCELERATED);



    // ------ Couleurs : ----------
    /*
    const Uint32 fuschia_color = SDL_MapRGB(ecran->format, 255, 0, 255);
    const Uint32 greengrass_color = SDL_MapRGB(ecran->format, 62, 72, 35);
    const Uint32 greyfloor_color = SDL_MapRGB(ecran->format, 195, 195, 195);
    const Uint32 darkness_color = SDL_MapRGB(ecran->format, 68, 68, 68);
    const Uint32 white_color = SDL_MapRGB(ecran->format, 0, 0, 0);
    */




    // ------- Chargement des textures ------------

    SDL_Texture* fond[NB_COLORS];
    for (int i = 0; i<NB_COLORS; i++) {
        fond[i] = malloc(sizeof(SDL_Texture*));
    }
    /*
    fond[WHITE] = charger_fond_uni(ecran, white_color);
    fond[GRASS] = charger_fond_uni(ecran, greengrass_color);
    fond[GREYFLOOR] = charger_fond_uni(ecran, greyfloor_color);
    fond[DARKNESS] = charger_fond_uni(ecran, darkness_color);
    */
    fond[WHITE] = charger_fond_uni_rgb(ecran, 0, 0, 0);
    fond[GRASS] = charger_fond_uni_rgb(ecran, 62, 72, 35);
    fond[GREYFLOOR] = charger_fond_uni_rgb(ecran, 195, 195, 195);
    fond[DARKNESS] = charger_fond_uni_rgb(ecran, 68, 68, 68);

    SDL_Texture* wolfy_sprite = charger_image_transparente_rgb("img/wolfy.bmp", ecran, 255, 0, 255);
    


    // -----  Boucle principale ---------------
    while(run){
        start_t = clock();
        SDL_RenderClear(ecran);

        if(i%2) {
            SDL_RenderCopy(ecran, fond[WHITE], NULL, NULL);
        } else {
            SDL_RenderCopy(ecran, fond[GRASS], NULL, NULL);
        }
        

        i++;

        //accueil();

        /*
    	while(!(world->gameover)) {
    		timer->start_t = clock();

    		update(world);
    		refresh_graphics(world);

    		(world->game->nb_tours)++;

    		timer->end_t = clock();
            timer->diff_t = timer->end_t - timer->start_t;
            t = (double) timer->diff_t / CLOCKS_PER_SEC;
    		SDL_Delay(10 - t);
    	}
    	rejouer();
        */

        //gestionEvents();

        SDL_RenderPresent(ecran);

        end_t = clock();
        diff_t = end_t - start_t;
        t = (double) diff_t / CLOCKS_PER_SEC;
    	SDL_Delay(500 - t);
    }

    // -------- a la fin ----------

    for(int i = 0; i<NB_COLORS; i++) {
        SDL_DestroyTexture(fond[i]) ;
    }
    SDL_DestroyTexture(wolfy_sprite);
    // Fermer la police et quitter SDL_ttf
    //TTF_CloseFont( font );
    TTF_Quit();
    // Libération de l’écran (renderer)
    SDL_DestroyRenderer(ecran);
    // Quitter SDL
    SDL_DestroyWindow(window);
    SDL_Quit();


}