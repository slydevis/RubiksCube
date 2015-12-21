#ifndef __DISPLAY_H__

#include "define.h"

void displayCube2D(face* cube[6][N][N]);
SDL_Surface* createFace();
void freeFace(SDL_Surface* screen);

#endif /* __DISPLAY_H__ */
