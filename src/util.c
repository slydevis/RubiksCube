#include <stdlib.h>
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

char* getFaceStr(int face) {
    switch(face) {
        case SIDE_LEFT:
            return SIDE_LEFT_STR;
        case SIDE_FRONT:
            return SIDE_FRONT_STR;
        case SIDE_UPPER:
            return SIDE_UPPER_STR;
        case SIDE_BOTTOM:
            return SIDE_BOTTOM_STR;
        case SIDE_RIGHT:
            return SIDE_RIGHT_STR;
        case SIDE_BEHIND:
            return SIDE_BEHIND_STR;
        default:
            return "";
    }
}

char* getFinalLibelle(int face, int x, int y) {
    char* libelle = malloc(sizeof(char) + 3);
    sprintf(libelle, "%s%d%d", getFaceStr(face), x, y);
    return libelle;
}
