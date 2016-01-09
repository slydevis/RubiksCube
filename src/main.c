#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "test/test.h"
#include "util.h"
#include "display.h"
#include "file.h"


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
}

void completeCube(char* path) {
    char* extension = getExtension(path);
    if(strcmp(extension, EXTENSION_JSON) == 0) {
        int tmp[6][N][N];
        readJSON(path, tmp);
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    face* buff  = cube[i][j][k];
                    buff->color = tmp[i][j][k];
                    cube[i][j][k] = buff;
                }
            }
        }
    }
    else // Unknown extension
        printError("Extension inconnue");
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

void menu() {
    int select = 0;
    //clearScreen();
    printTitle();
    printf("1) Voir en 2D\n");
    printf("2) Voir en 3D\n");
    printf("3) Quitter\n");
    printf("Votre choix ? ");

    // Error preventing
    if(scanf("%d", &select) != 1) {
        while (getchar() != '\n');
        menu();
    }

    switch(select) {
        case 1:
            displayCube2D(cube);
        break;
        case 2:
            printError("OpenGL non implémenté");
        break;
        case 3:
        break;
        default:
            return menu();
    }
}

void cube_rotation_upside_down (face* cube[6][N][N]) {
    /* on crée deux carré temporaire pour retenir la face devant, celle de
    gauche et celle de droite */
    face* tmp1[N][N];
    face* tmp2[N][N];
    face* tmp3[N][N];
    int i,j;

    // on stocke la face de devant dans tmp1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp1[i][j] = cube[1][i][j];
        }
    }

    // on stocke la face de gauche dans tmp2 */
    for (i = 0; i < N; i++) {
        for  (j = 0; j < N; j++) {
            tmp2[i][j] = cube[0][i][j];
        }
    }

    // on stocke la face de droite dans tmp3 */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tmp3[i][j] = cube[4][i][j];
        }
    }

    // on tourne les faces de côté dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[1][i][j] = cube[3][i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[3][i][j] = cube[5][N-1-i][N-1-j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[5][i][j] = cube[2][N-1-i][N-1-j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[2][i][j] = tmp1[i][j];
        }
    }

    // on tourne la face de gauche dans le sens des aiguilles d'une montre
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[0][i][j] = tmp2[j][N-1-i];
        }
    }

    // on tourne la face de droite
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cube[4][i][j] = tmp3[N-1-j][i];
        }
    }
}

int main(int argc, char** argv) {
    if(argc != 2)
        printError("Nombre d'argument invalide");
#ifdef DEBUG
    executeTest();
#endif
    initCube();
    completeCube(argv[1]);
    cube_rotation_upside_down (cube);
    menu();
    freeCube();
    return EXIT_SUCCESS;
}
