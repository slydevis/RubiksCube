#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "test/test.h"
#include "display.h"
#include "define.h"

/*
 * Left side = cube[0]
 * Front side = cube[1]
 * Upper side = cube[2]
 * Bottom side = cube[3]
 * Right side = cube[4]
 * Behind side = cube[5]
 */
face* cube[6][N][N];

void initCube() {
	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < N; ++k) {
				face* tmp = (face*) malloc(sizeof(face));
				tmp->screen = createFace();
				tmp->color = COLOR_WHITE;
				cube[i][j][k] = tmp;
			}
		}
	}

	// COLOR EXEMPLE (TO DEBUG DISPLAY)

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			face* tmp = cube[0][i][j];
				tmp->color = COLOR_WHITE;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			face* tmp = cube[1][i][j];
				tmp->color = COLOR_BLUE;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			face* tmp = cube[2][i][j];
				tmp->color = COLOR_RED;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			face* tmp = cube[3][i][j];
				tmp->color = COLOR_YELLOW;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			face* tmp = cube[4][i][j];
				tmp->color = COLOR_GREEN;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			face* tmp = cube[5][i][j];
				tmp->color = COLOR_ORANGE;
		}
	}
}

void freeCube() {
	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < N; ++k) {
				face* tmp = cube[i][j][k];
				freeFace(tmp->screen);
				tmp->screen = NULL;
				free(cube[i][j][k]);
			}
		}
	}
}

int main() {
	executeTest();
	initCube();
	displayCube(cube);
	freeCube();
    return EXIT_SUCCESS;
}
