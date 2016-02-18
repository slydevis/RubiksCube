#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include<SDL/SDL.h>

#include "define.h"

SDL_Surface* screenGlobal; // Main surface screen

/************************************
 *          Color Management
 ************************************/

Uint32 getSDLColor(const int color);
void changeFaceColor(miniCube cube[6][N][N], const int side, const int i, const int j, const int color);

/************************************
 *        Surface management
 ************************************/

SDL_Surface* createFace();
void freeFace(SDL_Surface* screen);

/************************************
 *          Cube display
 ************************************/

void printLeftSide(miniCube cube[N][N]);
void printFrontSide(miniCube cube[N][N]);
void printUpperSide(miniCube cube[N][N]);
void printBottomSide(miniCube cube[N][N]);
void printRightSide(miniCube cube[N][N]);
void printBehindSide(miniCube cube[N][N]);
void printLibelleCube(miniCube cube[6][N][N]);

/************************************
 *          Keyboard event
 ************************************/

/**
 * \struct Input
 * \brief Status de touche du clavier (appuyé ou non)
 */
typedef struct {
    char key[SDLK_LAST]; /*!< Tableau de touche avec des données avec une valeur 0 ou 1 (0 pour non appuyé
 * et 1 pour appuyé) */
} Input;

void keyboardEventManager(SDLKey key, miniCube cube[6][N][N], Input* in);
void UpdateEvents(Input* in, miniCube cube[6][N][N]);

/************************************
 *       Display main function
 ************************************/

void displayCube2D(miniCube cube[6][N][N]);

#endif /* __DISPLAY_H__ */
