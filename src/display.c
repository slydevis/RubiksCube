#include <SDL/SDL.h>11

#include "display.h"
#include "define.h"

static int goContinue = 1;
static SDL_Surface* screen = NULL;

Uint32 getSDLColor(int color) {
	switch(color) {
	case COLOR_WHITE:
		return SDL_MapRGB(screen->format, 255, 255, 255);
	case COLOR_BLUE:
		return SDL_MapRGB(screen->format, 38, 18, 222);
	case COLOR_GREEN:
		return SDL_MapRGB(screen->format, 18, 222, 35);
	case COLOR_RED:
		return SDL_MapRGB(screen->format, 222, 18, 18);
	case COLOR_ORANGE:
		return SDL_MapRGB(screen->format, 222, 89, 18);
	case COLOR_YELLOW:
		return SDL_MapRGB(screen->format, 226, 245, 24);
	case COLOR_NONE:
	default:
		return 0;
	}
}

SDL_Surface* createFace() {
	return SDL_CreateRGBSurface(SDL_HWSURFACE, FACE_SIZE, FACE_SIZE, 32, 0, 0, 0, 0);
}

void freeFace(SDL_Surface* screen) {
	SDL_FreeSurface(screen);
}

void printLeftSide(face* cube[N][N]) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			SDL_Rect pos;
			face* tmp = cube[i][j];
			pos.x = i*FACE_SIZE + 5*i + 100;
			pos.y = SCREEN_HEIGHT/2 - (j*FACE_SIZE + 5*j);
			SDL_FillRect(tmp->screen, NULL, getSDLColor(tmp->color));
			SDL_BlitSurface(tmp->screen, NULL, screen, &pos);
		}
	}
}

void printRightSide(face* cube[N][N]) {

}

void printBottomSide(face* cube[N][N]) {

}

void printUpperSide(face* cube[N][N]) {

}

void printBackSide(face* cube[N][N]) {

}

void displayCube(face* cube[6][N][N]) {
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Rubik's Cube", NULL);

	if(screen == NULL) {
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	while(goContinue) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				goContinue = 0;
			break;
		}

		SDL_FillRect(screen, NULL, getSDLColor(COLOR_NONE));
		printLeftSide(cube[0]);

		/* Update screen */
		SDL_Flip(screen);
	}

	SDL_Quit();
}
