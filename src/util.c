#include "util.h"
#include "define.h"

void printError(char* str) {
    color(PRINT_COLOR_RED);
    printf("Error : %s\n", str);
    color(PRINT_COLOR_WHITE);
    exit(EXIT_FAILURE);
}

void getGlobalColor(face* cube[6][N][N], int res[6][N][N]) {
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k)
                res[i][j][k] = cube[i][j][k]->color;
        }
    }
}
