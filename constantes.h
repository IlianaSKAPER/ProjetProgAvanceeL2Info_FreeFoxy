/** \file constantes.h
* \brief D�finition des constantes pour le programme Free Foxy
* \author Iliana SKAPER
* \version 2
* \date 10-12.2020
*/




#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

    


    #define TAILLE_MENU_H       474
    #define TAILLE_MENU_L       553
    #define TAILLE_BLOC_H       92
    #define TAILLE_BLOC_L       88
    #define NB_BLOCS_LARGEUR    16
    #define NB_BLOCS_HAUTEUR    9
    #define LARGEUR_FENETRE     TAILLE_BLOC_L * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE     TAILLE_BLOC_H * (NB_BLOCS_HAUTEUR + 1)
    #define HAUTEUR_BG          TAILLE_BLOC_H * NB_BLOCS_HAUTEUR
    #define HEARTS_MAX          3
    #define NB_COLORS           4


    /** \enum direction
    */
    enum direction {HAUT=0, BAS=1, GAUCHE=2, DROITE=3};


    /** \enum bloc
    * \brief �numeration des status possibles d'un bloc
    */
    enum bloc {EMPTY=0, WALL=1, ROCK=2, BUSH=3, CHEST=4, DOOROPEN=5, DOORCLOSE=6, WOLPHY=7, FOXY=8};


    enum etats {IN_PROGRESS, WIN, FAIL};

    enum bg_colors {WHITE=0, GRASS=1, GREYFLOOR=2, DARKNESS=3};
    /*const int NB_COLORS = 4;

    
    const int wolfy_x[3] = {8, 55, 104};
    const int wolfy_y[4] = {148, 6, 52, 101};
    const int wolfy_size = 31;
    */

/*
    const Uint32 fuschia_color = SDL_MapRGB(ecran->format, 255, 0, 255);
    const Uint32 greengrass_color = SDL_MapRGB(ecran->format, 62, 72, 35);
    const Uint32 greyfloor_color = SDL_MapRGB(ecran->format, 195, 195, 195);
    const Uint32 darkness_color = SDL_MapRGB(ecran->format, 68, 68, 68);
    const Uint32 white_color = SDL_Map(ecran->format, 0, 0, 0);
*/


#endif // CONSTANTES_H_INCLUDED
