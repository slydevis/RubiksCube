/************************************
 * \file display.c
 * \brief Affichage du cube
 *
 * Affichage du Rubik's cube à l'aide
 * de la SDL et gestion au clavier
 *
 ************************************/

#include <SDL/SDL.h>

#include "display.h"
#include "cube.h"
#include "util.h"
#include "rotations.h"
#include "resolution_mecanique.h"
#include "resolveBacktrack.h"
#include "file.h"

static int goContinue = 1; // Stop program variable

/************************************
 *          Color Management
 ************************************/

/**
 * \fn Uint32 getSDLColor(int color)
 * \brief Fais la traduction code couleur => couleur SDL.
 * \param color correspond au code couleur voulu (cf define.h).
 * \return Valeur de la couleur SDL, renvoie 0 si elle est inconnue
 */
Uint32 getSDLColor(const int color) {
    switch(color) {
        case COLOR_WHITE:
            return SDL_MapRGB(screenGlobal->format, 255, 255, 255);
        case COLOR_BLUE:
            return SDL_MapRGB(screenGlobal->format, 38, 18, 222);
        case COLOR_GREEN:
            return SDL_MapRGB(screenGlobal->format, 18, 222, 35);
        case COLOR_RED:
            return SDL_MapRGB(screenGlobal->format, 222, 18, 18);
        case COLOR_ORANGE:
            return SDL_MapRGB(screenGlobal->format, 222, 89, 18);
        case COLOR_YELLOW:
            return SDL_MapRGB(screenGlobal->format, 226, 245, 24);
        case COLOR_NONE:
        default:
            return 0;
    }
}

/**
 * \fn void changeFaceColor(miniCube cube[6][N][N], int side, int i, int j, int color)
 * \brief Met à jour la couleur d'une structure
 * \param cube Tableau de miniCube correspondant au rubik's cube
 * \param side Face à traiter
 * \param i indice de ligne
 * \param j indice de colonne
 * \param color code couleur (cf define.h)
 */
void changeFaceColor(miniCube cube[6][N][N], const int side,
                                            const int i, const int j,
                                            const int color) {
    cube[side][i][j]->color = color;
}

/************************************
 *        Surface management
 ************************************/

/**
 * \fn SDL_Surface* createFace()
 * \return Renvoie une surface SDL de taille FACE_SIZE (cf define.h)
 */
SDL_Surface* createFace() {
    return SDL_CreateRGBSurface(SDL_HWSURFACE, FACE_SIZE, FACE_SIZE, 32, 0, 0, 0, 0);
}

/**
 * \fn void freeFace(SDL_Surface* screen)
 * \brief Libère la mémoire d'une surface SDL
 * \param screen Surface SDL a liberer
 */
void freeFace(SDL_Surface* screen) {
    SDL_FreeSurface(screen);
}

/************************************
 *          Cube display
 ************************************/

/**
 * \fn void printLeftSide(miniCube cube[N][N])
 * \brief Affiche la face gauche du Rubik's cube.
 * \param cube Tableau de tableau correspondant à la face gauche
 */
void printLeftSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screenGlobal, &pos);
            freeFace(faceScreen);
        }
    }
}

/**
 * \fn void printFrontSide(miniCube cube[N][N])
 * \brief Affiche la face de devant du Rubik's cube.
 * \param cube Tableau de tableau correspondant à la face de devant
 */
void printFrontSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screenGlobal, &pos);
            freeFace(faceScreen);
        }
    }
}

/**
 * \fn void printUpperSide(miniCube cube[N][N])
 * \brief Affiche la face du dessus du Rubik's cube.
 * \param cube Tableau de tableau correspondant à la face du dessus
 */
void printUpperSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i)) - (3*FACE_SIZE + 4*5);
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screenGlobal, &pos);
            freeFace(faceScreen);
        }
    }
}

/**
 * \fn void printBottomSide(miniCube cube[N][N])
 * \brief Affiche la face de dessous du Rubik's cube.
 * \param cube Tableau de tableau correspondant à la face de dessous
 */
void printBottomSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i)) + (3*FACE_SIZE + 4*5);
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screenGlobal, &pos);
            freeFace(faceScreen);
        }
    }
}

/**
 * \fn void printRightSide(miniCube cube[N][N])
 * \brief Affiche la face droite du Rubik's cube.
 * \param cube Tableau de tableau correspondant à la face droite
 */
void printRightSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5)*2;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screenGlobal, &pos);
            freeFace(faceScreen);
        }
    }
}

/**
 * \fn void printBehindSide(miniCube cube[N][N])
 * \brief Affiche la face de derrière du Rubik's cube.
 * \param cube Tableau de tableau correspondant à la face de derrière
 */
void printBehindSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5)*3;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screenGlobal, &pos);
            freeFace(faceScreen);
        }
    }
}

/**
 * \fn void printLibelleCube(miniCube cube[6][N][N])
 * \brief Affiche sur la console une représentation du cube avec les positions final
 * \param cube Variable correspondant au Rubik's cube
 */
void printLibelleCube(miniCube cube[6][N][N]) {
/*
 *
 * Exemple :
                     ----- ----- -----
                    | 200 | 201 | 202 |
                     ----- ----- -----
                    | 210 | 211 | 212 |
                     ----- ----- -----
                    | 220 | 221 | 222 |
                     ----- ----- -----
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
| 000 | 001 | 002 | | 100 | 101 | 102 | | 400 | 401 | 402 | | 500 | 501 | 502 |
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
| 010 | 011 | 012 | | 110 | 111 | 112 | | 410 | 411 | 412 | | 510 | 511 | 512 |
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
| 020 | 021 | 022 | | 120 | 121 | 122 | | 420 | 421 | 422 | | 520 | 521 | 522 |
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
                     ----- ----- -----
                    | 300 | 301 | 302 |
                     ----- ----- -----
                    | 310 | 311 | 312 |
                     ----- ----- -----
                    | 320 | 321 | 322 |
                     ----- ----- -----
 */

    /* Space for upper side */
    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < 20; ++k)
            printf(" ");

        printf(" ----- ----- -----\n");

        for(int k = 0; k < 20; ++k)
            printf(" ");

        for(int j = 0; j < N; ++j) {
            printf("| %03d ", cube[SIDE_UPPER][i][j]->finalPos);
        }

        printf("|\n");
    }

    /* Top border */

    for(int k = 0; k < 20; ++k)
        printf(" ");

    printf(" ----- ----- -----\n");

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < N; ++j) {
            printf(" -----");
        }

        printf("  ");
    }

    printf("\n");

    int selectColumn = 0;
    while(selectColumn != N) {
        int sideSelect = SIDE_LEFT;

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < N; ++j) {
                printf("| %03d ", cube[sideSelect][selectColumn][j]->finalPos);
            }

            sideSelect++;

            if(sideSelect == SIDE_UPPER || sideSelect == SIDE_BOTTOM)
                sideSelect = SIDE_RIGHT;

            printf("| ");
        }

        printf("\n");

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < N; ++j) {
                printf(" -----");
            }
            printf("  ");
        }

        printf("\n");
        ++selectColumn;
    }

    /* Bottom side */

    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < 20; ++k)
            printf(" ");

        printf(" ----- ----- -----\n");

        for(int k = 0; k < 20; ++k)
            printf(" ");

        for(int j = 0; j < N; ++j) {
            printf("| %03d ", cube[SIDE_BOTTOM][i][j]->finalPos);
        }

        printf("|\n");
    }

    for(int k = 0; k < 20; ++k)
        printf(" ");

    printf(" ----- ----- -----\n");
}

/************************************
 *          Keyboard event
 ************************************/

/**
 * \fn void keyboardEventManager(SDLKey key, miniCube cube[6][N][N], Input* in)
 * \brief Lance les fonctions correspondante au touches appuyées
 * \param key Touche appuyé
 * \param cube Correspond au Rubik's cube
 * \param in structure avec l'état des touches
 */
void keyboardEventManager(SDLKey key, miniCube cube[6][N][N], Input* in) {
    clearScreen();
    printTitle();
    printHelp();

    switch (key) {
        case SDLK_u:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "U");
            else
                cubeRotation(cube, "U'");
        break;
        case SDLK_l:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "L");
            else
                cubeRotation(cube, "L'");
        break;
        case SDLK_f:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "F");
            else
                cubeRotation(cube, "F'");
        break;
        case SDLK_r:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "R");
            else
                cubeRotation(cube, "R'");
        break;
        case SDLK_b:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "B");
            else
                cubeRotation(cube, "B'");
        break;
        case SDLK_d:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "D");
            else
                cubeRotation(cube, "D'");
        break;
        case SDLK_m:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "M");
            else
                cubeRotation(cube, "M'");
        break;
        case SDLK_e:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "E");
            else
                cubeRotation(cube, "E'");
        break;
        case SDLK_x:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "X");
            else
                cubeRotation(cube, "X'");
        break;
        case SDLK_y:
            if(in->key[SDLK_LCTRL] == 0)
                cubeRotation(cube, "Y");
            else
                cubeRotation(cube, "Y'");
        break;
        case SDLK_TAB:
            initCube(cube);
        break;
        case SDLK_s:
            saveCube(cube, EXTENSION_JSON);
        break;
        case SDLK_RETURN:
            if(in->key[SDLK_LCTRL] == 0)
                resolution_mecanique(cube);
            else
                resolveBacktrack(cube);
        break;
        case SDLK_ASTERISK:
            randomizeCube(cube);
        break;
        default: break;
    }

    printLibelleCube(cube);

#ifdef DEBUG
    if(key >= 'a' && key <= 'z')
        printf("Key pressed : %c\n", key - 32);
    if(key == SDLK_TAB)
        printf("Key pressed : TAB\n");
    if(key == SDLK_RETURN)
        printf("Key pressed : RETURN\n");
    if(key == SDLK_ASTERISK)
        printf("Key pressed : ASTERISK\n");
#endif
}

/**
 * \fn void UpdateEvents(Input* in, miniCube cube[6][N][N])
 * \brief Met à jour les status des touches et gère la fermeture du programme via la croix
 * \param in structure avec l'état des touches
 * \param cube Variable de Rubik's cube
 */
void UpdateEvents(Input* in, miniCube cube[6][N][N]) {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                goContinue = 0;
            break;
            case SDL_KEYDOWN:
                in->key[event.key.keysym.sym] = 1;
                keyboardEventManager(event.key.keysym.sym, cube, in);
            break;
            case SDL_KEYUP:
                in->key[event.key.keysym.sym] = 0;
            break;
            default: break;
        }
    }
}

/************************************
 *       Display main function
 ************************************/

/**
 * \fn void displayCube2D(miniCube cube[6][N][N])
 * \brief Initialise SDL et affiche le Rubik's cube
 * \param cube Variable de Rubik's cube
 */
void displayCube2D(miniCube cube[6][N][N]) {
    SDL_Init(SDL_INIT_VIDEO);

    screenGlobal = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Rubik's Cube", NULL);

    if(screenGlobal == NULL) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Init keyboard status
    Input in;
    memset(&in,0,sizeof(in));

    clearScreen();
    printTitle();
    printHelp();
    printLibelleCube(cube);

    while(goContinue) {
        UpdateEvents(&in, cube);

        SDL_FillRect(screenGlobal, NULL, getSDLColor(COLOR_NONE));

        printLeftSide(cube[SIDE_LEFT]);
        printFrontSide(cube[SIDE_FRONT]);
        printUpperSide(cube[SIDE_UPPER]);
        printBottomSide(cube[SIDE_BOTTOM]);
        printRightSide(cube[SIDE_RIGHT]);
        printBehindSide(cube[SIDE_BEHIND]);

        /* Update screen */
        SDL_Flip(screenGlobal);
    }

    SDL_Quit();
}
