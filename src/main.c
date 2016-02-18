/************************************
 * \file main.c
 * \brief Fichier principal
 *
 * Initialise et lance le programme
 *
 ************************************/

#include <stdio.h> // printf()

#include "cube.h" // initCube()
#include "util.h" // printTitle()
#include "display.h" // display2D()
#include "test/test.h" // executeTest()

/**
 * \fn void menu(miniCube cube[6][N][N])
 * \brief Gestion du menu et lance le programme
 * \param cube Rubik's cube initialisé
 */
void menu(miniCube cube[6][N][N]) {
    clearScreen();
    printTitle();

    printf("1) Voir en 2D\n");
    printf("2) Voir en 3D\n");
    printf("3) Quitter\n");
    printf("Votre choix ? ");

    int select = 0;
    // Preventing error
    if(scanf("%d", &select) != 1) {
        while (getchar() != '\n');
        menu(cube);
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
            return menu(cube);
    }
} 

int main(int argc, char** argv) {
    if(argc != 2)
        printError("Nombre d'argument invalide");
#ifdef DEBUG
    executeTest();
#endif
    changeStatusSave(NOT_SAVE_ROT);
    miniCube cube[6][N][N];
    initCube(cube);
    completeCube(cube, argv[1]);
    menu(cube);
    freeCube(cube);
    return EXIT_SUCCESS;
}
