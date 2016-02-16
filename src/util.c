#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "util.h"
#include "define.h"


void printError(char* str) {
    color(PRINT_COLOR_RED);
    printf("Error : %s\n", str);
    color(PRINT_COLOR_WHITE);
    exit(EXIT_FAILURE);
}

void printTitle() {
    printf("\n\n");
    printf("██████╗ ██╗   ██╗██████╗ ██╗██╗  ██╗███████╗     ██████╗██╗   ██╗██████╗ ███████╗\n");
    printf("██╔══██╗██║   ██║██╔══██╗██║██║ ██╔╝██╔════╝    ██╔════╝██║   ██║██╔══██╗██╔════╝\n");
    printf("██████╔╝██║   ██║██████╔╝██║█████╔╝ ███████╗    ██║     ██║   ██║██████╔╝█████╗  \n");
    printf("██╔══██╗██║   ██║██╔══██╗██║██╔═██╗ ╚════██║    ██║     ██║   ██║██╔══██╗██╔══╝  \n");
    printf("██║  ██║╚██████╔╝██████╔╝██║██║  ██╗███████║    ╚██████╗╚██████╔╝██████╔╝███████╗\n");
    printf("╚═╝  ╚═╝ ╚═════╝ ╚═════╝ ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝\n");
    printf("\n\n");
}

int getFinalColorId(int id) {
    switch(id) {
        case SIDE_LEFT:
            return COLOR_WHITE;
        case SIDE_FRONT:
            return COLOR_BLUE;
        case SIDE_UPPER:
            return COLOR_ORANGE;
        case SIDE_BOTTOM:
            return COLOR_RED;
        case SIDE_RIGHT:
            return COLOR_YELLOW;
        case SIDE_BEHIND:
            return COLOR_GREEN;
        default:
            return COLOR_NONE;
    }
}

void getColorArray(miniCube cube[6][N][N], int cubeTmp[6][N][N]) {
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k)
                cubeTmp[i][j][k] = cube[i][j][k]->color;
        }
    }
}

int getFinalLibelle(int face, int x, int y) {
    return 100*face + 10*x + y;
}

int isCompleteCube(miniCube cube[6][N][N]) {
	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < N; ++k) {
				int finalLibelle = getFinalLibelle(i, j, k);
				if(finalLibelle != cube[i][j][k]->finalPos)
					return 0;
			}
		}
	}
	return 1;
}

char* concatStr(char *s1, char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1);//+1 to copy the null-terminator
    return result;
}
