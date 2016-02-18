/************************************
 * \file cube.c
 * \brief Gestionnaire du Rubik's cube
 *
 * Gére et initialise un rubik's cube
 *
 ************************************/

#include <stdio.h> // NULL
#include <stdlib.h> // srand()
#include <time.h> // rand()
#include <string.h> // strcmp()

#include "define.h"
#include "rotations.h"
#include "util.h"
#include "file.h"

/**
 * \fn void randomizeCube(miniCube cube[6][N][N])
 * \brief Mélange un cube aléatoirement
 * \param cube Rubik's cube initialisé
 */
void randomizeCube(miniCube cube[6][N][N]) {
    srand(time(NULL)); // init rand

    for(int i = 0; i < RAND_SIZE; ++i) {
        int selectRotation = rand()%36; // rand between 0 to 35
        switch(selectRotation) {
            case 0:
                cubeRotation(cube, "U");
            break;
            case 1:
                cubeRotation(cube, "U'");
            break;
            case 2:
                cubeRotation(cube, "L");
            break;
            case 3:
                cubeRotation(cube, "L'");
            break;
            case 4:
                cubeRotation(cube, "F");
            break;
            case 5:
                cubeRotation(cube, "F'");
            break;
            case 6:
                cubeRotation(cube, "R");
            break;
            case 7:
                cubeRotation(cube, "R'");
            break;
            case 8:
                cubeRotation(cube, "B");
            break;
            case 9:
                cubeRotation(cube, "B'");
            break;
            case 10:
                cubeRotation(cube, "D");
            break;
            case 11:
                cubeRotation(cube, "D'");
            break;
            case 12:
                cubeRotation(cube, "M");
            break;
            case 13:
                cubeRotation(cube, "M'");
            break;
            case 14:
                cubeRotation(cube, "u");
            break;
            case 15:
                cubeRotation(cube, "u'");
            break;
            case 16:
                cubeRotation(cube, "l");
            break;
            case 17:
                cubeRotation(cube, "l'");
            break;
            case 18:
                cubeRotation(cube, "E");
            break;
            case 19:
                cubeRotation(cube, "E'");
            break;
            case 20:
                cubeRotation(cube, "f");
            break;
            case 21:
                cubeRotation(cube, "f'");
            break;
            case 22:
                cubeRotation(cube, "r");
            break;
            case 23:
                cubeRotation(cube, "r'");
            break;
            case 24:
                cubeRotation(cube, "S");
            break;
            case 25:
                cubeRotation(cube, "S'");
            break;
            case 26:
                cubeRotation(cube, "b");
            break;
            case 27:
                cubeRotation(cube, "b'");
            break;
            case 28:
                cubeRotation(cube, "d");
            break;
            case 29:
                cubeRotation(cube, "d'");
            break;
            case 30:
                cubeRotation(cube, "X");
            break;
            case 31:
                cubeRotation(cube, "X'");
            break;
            case 32:
                cubeRotation(cube, "Y");
            break;
            case 33:
                cubeRotation(cube, "Y'");
            break;
            case 34:
                cubeRotation(cube, "Z");
            break;
            case 35:
                cubeRotation(cube, "Z'");
            break;
            default: break;
        }
    }
}

/*
 * Left side = cube[0]
 * Front side = cube[1]
 * Upper side = cube[2]
 * Bottom side = cube[3]
 * Right side = cube[4]
 * Behind side = cube[5]
 */
/**
 * \fn initCube(miniCube cube[6][N][N])
 * \brief Initialise la structure de cube par défaut
 * \param cube Rubik's cube non initialisé
 */
void initCube(miniCube cube[6][N][N]) {
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                miniCube cubeTmp = malloc(sizeof(face));
                cube[i][j][k] = cubeTmp;
                cube[i][j][k]->color = getFinalColorId(i);
                cube[i][j][k]->finalPos = getFinalLibelle(i, j, k);
            }
        }
    }
}

/**
 * \fn completeCube(miniCube cube[6][N][N], char* path)
 * \brief Initialise un rubik's cube à partir d'un fichier externe
 * \param cube Rubik's cube initialisé
 * \param path chemin du fichier à lire (extension en .json ou .rot)
 */
void completeCube(miniCube cube[6][N][N], char* path) {
    char* extension = getExtension(path);
    if(strcmp(extension, EXTENSION_JSON) == 0) {
        miniCube tmp[6][N][N];
        readJSON(path, tmp);
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    int buff  = cube[i][j][k]->color;
                    buff = tmp[i][j][k]->color;
                    cube[i][j][k]->color = buff;
                }
            }
        }
        // TODO : Determine final position
        // J'ai pas reussi à determiner un algorithme pour
        // Faire determiner la position final à partir de rien
    }
    else if(strcmp(extension, EXTENSION_ROT) == 0)
        ReadROT(path, cube);
    else // Unknown extension
        printError("Extension inconnue");
}

/**
 * \fn void freeCube(miniCube cube[6][N][N])
 * \brief Libère la place en mémoire du rubik's cube
 * \param cube Rubik's cube initialisé
 */
void freeCube(miniCube cube[6][N][N]) {
    for(unsigned int i = 0; i < 6; ++i) {
        for(unsigned int j = 0; j < N; ++j) {
            for(unsigned int k = 0; k < N; ++k) {
                free(cube[i][j][k]);
                cube[i][j][k] = NULL;
            }
        }
    }
}

/**
 * \fn int isCompleteCube(miniCube cube[6][N][N])
 * \brief Vérifie si un rubik's cube est terminé
 * \param cube Rubik's cube initialisé
 * \return Renvoie 1 si le cube est terminé sinon renvoie 0
 */
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
