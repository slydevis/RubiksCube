#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../define.h"
#include "../file.h"
#include "../rotations.h"

/* Launch test for a function without argument */
void test(int (*f)(), void (*init)(), int result) {
    int res;
    (*init)();
    res = (*f)();

    printf("Run test : ");
    if(res == 0) {
        color(PRINT_COLOR_GREEN);
        printf("OK\n");
        color(PRINT_COLOR_WHITE);
    }
    else {
        color(PRINT_COLOR_RED);
        printf("FAIL !\n");
        color(PRINT_COLOR_WHITE);
        exit(EXIT_FAILURE);
    }
}

void testCube(void (*f)(int cube[6][N][N]), char* fileInitPath, char* fileResultPath) {
    int tmp[6][N][N];
    int result[6][N][N];

    readJSON(fileInitPath, tmp);
    readJSON(fileResultPath, result);

    (*f)(tmp);

    printf("Run test : ");

    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                int colorTmp = tmp[i][j][k];
                int colorResult = result[i][j][k];

                if(colorTmp != colorResult) {
                    color(PRINT_COLOR_RED);
                    printf("FAIL !\n");
                    color(PRINT_COLOR_WHITE);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    color(PRINT_COLOR_GREEN);
    printf("OK\n");
    color(PRINT_COLOR_WHITE);

}

void executeTest() {
    printf("===> Test Unit : \n");
    testCube(cube_rotation_upside_down, "input/cube.json", "input/testUpsideDownRotation.json");
    printf("===> DONE\n");
}
