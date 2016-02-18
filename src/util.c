/************************************
 * \file util.c
 * \brief Fonction utile
 *
 * Fonction utile pour le fonctionnement
 * du programme
 *
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // topupper()

#include "util.h"
#include "define.h"

/************************************
 *          Display message
 ************************************/

/**
 * \fn void printError(char* str)
 * \brief Affiche une erreur dans la console et arrête le programme de force
 * \param str Chaine de caractère à afficher
 */
void printError(const char* str) {
    color(PRINT_COLOR_RED);
    printf("Error : %s\n", str);
    color(PRINT_COLOR_WHITE);
    exit(EXIT_FAILURE);
}

/**
 * \fn void printInfo(char* str)
 * \brief Affiche un message d'information dans la console
 * \param str Chaine de caractère à afficher
 */
void printInfo(const char* str) {
    color(PRINT_COLOR_BLUE);
    printf("Info : %s\n", str);
    color(PRINT_COLOR_WHITE);
}

/**
 * \fn void printTitle()
 * \brief Affiche le titre du programme en ascii art
 */
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

/**
 * \fn void printHelp()
 * \brief Affiche la liste des touches et leur effet
 */
void printHelp() {
    printf("Rappel :\n\n");
    printf("- U : Rotation haut\n");
    printf("- L : Rotation gauche\n");
    printf("- F : Rotation de face\n");
    printf("- R : Rotation droite\n");
    printf("- B : Rotation face arriere\n");
    printf("- D : Rotation bas\n");
    printf("- M : Rotation milieu vertical\n");
    printf("- E : Rotation milieu horizontal\n");
    printf("- X : Rotation du cube de facon vertical\n");
    printf("- Y : Rotation du cube de facon horizontal\n");
    printf("- Tab : Reset du cube\n");
    printf("- CTRL : Inverse le sens de rotation\n");
    printf("- S : Sauvegarde le cube courant\n");
    printf("- Entree : Resoudre le cube de facon mecanique\n");
    printf("- CTRL + Entree : Resoudre le cube de facon optimise\n");
    printf("- * : Melange le cube\n\n");
}

/************************************
 *          Misc functions
 ************************************/

/**
 * \fn char* concatStr(char* s1, char* s2)
 * \brief Concatene deux chaines de caractère
 * \param s1 Première chaine de caractère
 * \param s2 Deuxième chaine de caractère
 * \return Renvoie le résultat une chaine de caractère s1 + s2
 */
char* concatStr(char *s1, char *s2) {
    int s1Length = strlen(s1);
    int s2Length = strlen(s2);
    char *result = malloc(s1Length + s2Length + 1);// s1 + s2 + \0 (It's a NTCTS)

    memcpy(result, s1, s1Length);
    memcpy(result + s1Length, s2, s2Length + 1);
    return result;
}

/**
 * \fn char* toUpper(char* str)
 * \brief Met en majuscule la chaine de caractère
 * \param str Chaine de caractère
 * \return Renvoie la chaine de caractère en majuscule
 */
char* toUpper(char* str) {
    for(int i = 0; i < strlen(str); ++i)
        str[i] = (char) toupper((int) str[i]);
    return str;
}

/**
 * \fn void clearScreen()
 * \brief Efface la console (unix seulement)
 */
void clearScreen() {
#ifndef DEBUG
    printf("\033[H\033[2J");
#endif /* DEBUG */
}

/**
 * \fn void changeStatusSave(int status)
 * \brief Change la variable global de sauvegarde de rotation
 * \param status Status de la sauvegarde (cf define.h)
 */
void changeStatusSave(int status) {
    save = status;
}

/************************************
 *        Cube misc functions
 ************************************/

/**
 * \fn int getFinalColorId(const int id)
 * \brief Donne la couleur final de la face
 * \param id Numéro de face (cf define.h)
 * \return Renvoie le code couleur par rapport à la face
 */
int getFinalColorId(const int id) {
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

/**
 * \fn void getColorArray(miniCube cube[6][N][N], int cubeTmp[6][N][N])
 * \brief Crée un cube sans la structure (que les couleurs des faces)
 * \param cube Rubik's cube courant (avec la structure)
 * \param cubeTmp Rubik's cube sans la structure de sortie
 */
void getColorArray(miniCube cube[6][N][N], int cubeTmp[6][N][N]) {
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k)
                cubeTmp[i][j][k] = cube[i][j][k]->color;
        }
    }
}

/**
 * \fn int getFinalLibelle(const int face, const int x, const int y)
 * \brief Calcule l'identifiant correspondant à la case final d'un mini cube
 * \param face Numéro de face (cf define.h)
 * \param x indice de ligne
 * \param y indice de colonne
 * \return Renvoie un entier
 */
int getFinalLibelle(const int face, const int x, const int y) {
    return 100*face + 10*x + y;
}
