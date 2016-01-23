#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../define.h"
#include "../file.h"
#include "../rotations.h"
#include "../display.h"

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


    printf("Run test : ");

    readJSON(fileInitPath, tmp);
    readJSON(fileResultPath, result);

    (*f)(tmp);
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                int colorTmp = tmp[i][j][k];
                int colorResult = result[i][j][k];

                if(colorTmp != colorResult) {
                    color(PRINT_COLOR_RED);
                    printf("FAIL !\n");
                    color(PRINT_COLOR_WHITE);
                    saveCube(tmp, EXTENSION_JSON);
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
    testCube(up_rotation, "input/cube.json", "input/testUpRotation.json");
    testCube(up_rotation_reverse, "input/testUpRotation.json", "input/cube.json");
    testCube(down_rotation, "input/cube.json", "input/testDownRotation.json");
    testCube(down_rotation_reverse, "input/testDownRotation.json", "input/cube.json");
    testCube(front_rotation, "input/cube.json", "input/testFrontRotation.json");
    testCube(front_rotation_reverse, "input/testFrontRotation.json", "input/cube.json");
    testCube(right_rotation, "input/cube.json", "input/testRightRotation.json");
    testCube(right_rotation_reverse, "input/testRightRotation.json", "input/cube.json");
    testCube(left_rotation, "input/cube.json", "input/testLeftRotation.json");
    testCube(left_rotation_reverse, "input/testLeftRotation.json", "input/cube.json");
    testCube(cube_rotation_side, "input/cube.json", "input/testSideRotation.json");
    testCube(cube_rotation_upside_down, "input/cube.json", "input/testUpsideDownRotation.json");
    testCube(middle_vectical_rotation, "input/cube.json", "input/testMiddleVecticalRotation.json");
    testCube(middle_vectical_rotation_reverse, "input/testMiddleVecticalRotation.json", "input/cube.json");
    testCube(middle_horizontal_rotation, "input/cube.json", "input/testMiddleHorizontalRotation.json");
    testCube(middle_horizontal_rotation_reverse, "input/testMiddleHorizontalRotation.json", "input/cube.json");
    testCube(middle_rotation_side, "input/cube.json", "input/testMiddleSideRotation.json");
    testCube(middle_rotation_side_reverse, "input/testMiddleSideRotation.json", "input/cube.json");
    printf("===> DONE\n");
}
