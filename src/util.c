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

int getFaceStr(int face) {
    switch(face) {
        case SIDE_LEFT:
            return SIDE_LEFT;
        case SIDE_FRONT:
            return SIDE_FRONT;
        case SIDE_UPPER:
            return SIDE_UPPER;
        case SIDE_BOTTOM:
            return SIDE_BOTTOM;
        case SIDE_RIGHT:
            return SIDE_RIGHT;
        case SIDE_BEHIND:
            return SIDE_BEHIND;
        default:
            return 9;
    }
}

int getFinalLibelle(int face, int x, int y) {
    int libelle;
    libelle = 100*getFaceStr(face) + 10*x + y;
    return libelle;
}

//ULFRBDU'L'F'R'B'D'MuM'lEfE'rSbS'du'Xl'X'f'Yr'Y'b'Zd'Z'U2