/************************************
 * \file file.c
 * \brief Gestionnaire de fichier
 *
 * Lis et sauvegarde des cubes à partir
 * de fichier .rot ou .json
 *
 ************************************/

#include <string.h> // strcmp()
#include <ctype.h> // isdigit()

#include "file.h"
#include "util.h"
#include "rotations.h"

/************************************
 *        File management
 ************************************/

/**
 * \fn FILE* openFile(char* path, char* mode)
 * \brief Ouvre un fichier
 * \param path Chemin du fichier
 * \param mode Mode d'ouverture (cf define.h)
 * \return Renvoie l'objet du type FILE (peut être NULL)
 */
FILE* openFile(char* path, char* mode) {
    FILE* file = fopen(path, mode);
    return file;
}

/**
 * \fn FILE* closeFile(FILE* file)
 * \brief Ferme un fichier
 * \param file Objet de type FILE
 */
void closeFile(FILE* file) {
    fclose(file);
}

/************************************
 *        JSON Translation
 ************************************/

/**
 * \fn int translateWord(char* word)
 * \brief Fait la correspondance mot => id de couleur ou de face
 * \param word Chaine de caractère a traduire
 * \return Renvoie un entier correspondant à un id (cf define.h) renvoie -1 si c'est un identifiant inconnu
 */
int translateWord(char* word) {
    char* str = toUpper(word);
    if(strcmp(str, JSON_LEFT) == 0)
        return SIDE_LEFT;
    if(strcmp(str, JSON_FRONT) == 0)
        return SIDE_FRONT;
    if(strcmp(str, JSON_UPPER) == 0)
        return SIDE_UPPER;
    if(strcmp(str, JSON_BOTTOM) == 0)
        return SIDE_BOTTOM;
    if(strcmp(str, JSON_RIGHT) == 0)
        return SIDE_RIGHT;
    if(strcmp(str, JSON_BEHIND) == 0)
        return SIDE_BEHIND;
    if(strcmp(str, JSON_RED) == 0)
        return COLOR_RED;
    if(strcmp(str, JSON_BLUE) == 0)
        return COLOR_BLUE;
    if(strcmp(str, JSON_YELLOW) == 0)
        return COLOR_YELLOW;
    if(strcmp(str, JSON_WHITE) == 0)
        return COLOR_WHITE;
    if(strcmp(str, JSON_GREEN) == 0)
        return COLOR_GREEN;
    if(strcmp(str, JSON_ORANGE) == 0)
        return COLOR_ORANGE;
    if(strcmp(str, JSON_NONE) == 0)
        return COLOR_NONE;
    return -1;
}

/**
 * \fn int reverseTranslateWord(int value)
 * \brief Fait la correspondance id de couleur ou de face => mot
 * \param value Identifiant à traduire
 * \return Renvoie une chaine de caractère correspondant a un identifiant
 */
char* reverseTranslateWord(int value) {
    switch(value) {
        case SIDE_LEFT:
            return JSON_LEFT;
        case SIDE_FRONT:
            return JSON_FRONT;
        case SIDE_UPPER:
            return JSON_UPPER;
        case SIDE_BOTTOM:
            return JSON_BOTTOM;
        case SIDE_RIGHT:
            return JSON_RIGHT;
        case SIDE_BEHIND:
            return JSON_BEHIND;
        case COLOR_RED:
            return JSON_RED;
        case COLOR_BLUE:
            return JSON_BLUE;
        case COLOR_YELLOW:
            return JSON_YELLOW;
        case COLOR_WHITE:
            return JSON_WHITE;
        case COLOR_GREEN:
            return JSON_GREEN;
        case COLOR_ORANGE:
            return JSON_ORANGE;
        default:
            return JSON_NONE;
    }
}

/**
 * \fn void readJSON(char* path , miniCube cube[6][N][N])
 * \brief Traduis un fichier JSON en un rubik's cube
 * \param path Chemin du fichier JSON à traduire
 * \param cube Rubik's cube initialisé
 */
void readJSON(char * path, miniCube cube[6][N][N]) {
    /*
     * Exemple of syntax :
     * {
            "left": ["BLUE", "RED", "GREEN", "YELLOW", "YELLOW", "WHITE", "RED", "YELLOW", "GREEN"],
            "front": ["RED", "GREEN", "WHITE", "GREEN", "BLUE", "WHITE", "YELLOW", "ORANGE", "GREEN"],
            "upper": ["YELLOW", "GREEN", "YELLOW", "YELLOW", "RED", "BLUE", "WHITE", "RED", "BLUE"],
            "bottom": ["ORANGE", "BLUE", "WHITE", "ORANGE", "ORANGE", "WHITE", "YELLOW", "WHITE", "ORANGE"],
            "right": ["RED", "YELLOW", "BLUE", "ORANGE", "WHITE", "BLUE", "ORANGE", "BLUE", "BLUE"],
            "behind": ["RED", "ORANGE", "ORANGE", "RED", "GREEN", "GREEN", "WHITE", "RED", "GREEN"],
        }
     */

    FILE* file = openFile(path, OPEN_READ);

    if(!file)
        printError("Impossible d'ouvrir le fichier demande");

    char str[200];
    while(fgets(str, 200, file)) {

        char* buff = strtok (str, "{}:[], \"");

        int i = 0;
        int j = 0;
        int index = 0;
        int lastTranslated = 0;
        do {
            if(buff != NULL) {

                buff = toUpper(buff);
                lastTranslated = translateWord(buff);

                // Color identifiers are always bigger than face identifiers
                if(lastTranslated < COLOR_NONE)
                    index = lastTranslated;
                else {

                    if(j == N) {
                        j = 0;
                        ++i;
                    }
                    if(i == N)
                        i = 0;

                    cube[index][i][j]->color = lastTranslated;

                    ++j;
                }
            }
            buff = strtok (NULL, "{}:[], \"");
        } while(buff != NULL);
    }
    closeFile(file);
}

/************************************
 *        ROT translation
 ************************************/

/**
 * \fn void translateRotation(miniCube cube[6][N][N], char car, const int direction)
 * \brief Fait une rotation adéquat celon le sens de rotation
 * \param cube Rubik's cube initialisé
 * \param car Caractère de rotation (notation Singmaster)
 * \param direction Indique le sens de rotation (cf define.h)
 */
void translateRotation(miniCube cube[6][N][N], char car, const int direction) {
    char* rotation = &car;

    if(direction == DIRECTION_REVERSE)
        rotation = concatStr(rotation, "\'");

    cubeRotation(cube, rotation);
}

/**
 * \fn void ReadROT(char* path, miniCube cube[6][N][N])
 * \brief Traduis un fichier .rot en un rubik's cube
 * \param path Chemin du fichier .rot
 * \param cube Rubik's cube initialisé
 */
void ReadROT(char* path, miniCube cube[6][N][N]) {
    /*
     * Exemple of syntax :
     * ULFRBDU'L'F'R'B'D'MuM'lEfE'rSbS'du'Xl'X'f'Yr'Y'b'Zd'Z'U2
     */

    changeStatusSave(SAVE_ROT);

    FILE* file = openFile(path, OPEN_READ);

    if(!file)
        printError("Impossible d'ouvrir le fichier demande");

    char car;
    do {
        car = getc(file);
        char buff = getc(file);

        // EOF = End of file
        if(car == EOF || buff == EOF)
            break;

        // Decrease the file cursor position of 1
        fseek(file, -1, SEEK_CUR);

        if(buff == '\'')
            translateRotation(cube, car, DIRECTION_REVERSE);
        else if(isdigit((int) buff)) {
            for(int i = 0; i < (int)(buff - '0'); ++i)
                translateRotation(cube, car, DIRECTION_NORMAL);
        }
        else if(car != '\'' && !(isdigit((int) car)) && car != 13) { // 13 = Carriage return
            translateRotation(cube, car, DIRECTION_NORMAL);
        }
    } while(car != EOF);

    changeStatusSave(NOT_SAVE_ROT);
}

/************************************
 *        Save management
 ************************************/

/**
 * \fn void saveCubeJSON(int cube[6][N][N])
 * \brief Traduis un Rubik's cube en un fichier .json pour sauvegarder
 * \param cube Rubik's cube avec seulement ses couleurs
 */
void saveCubeJSON(int cube[6][N][N]) {
    FILE* file = openFile("output/save.json", "w");

    if (file != NULL) {
        fprintf(file, "{\n");

        for(int i = 0; i < 6; ++i) {
            fprintf(file, "\t\"%s\": [", reverseTranslateWord(i));
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k)
                    if(j == N - 1 && k == N - 1)
                        fprintf(file, "\"%s\"", reverseTranslateWord(cube[i][j][k]));
                    else
                        fprintf(file, "\"%s\", ", reverseTranslateWord(cube[i][j][k]));
            }
            fprintf(file, "],\n");
        }

        fprintf(file, "}\n");

        closeFile(file);
    }
    else
        printError("Impossible d'ouvrir le fichier test.txt");
}

/**
 * \fn void saveCube(miniCube cube[6][N][N], char* extension)
 * \brief Lance la sauvegarde d'un rubik's cube celon l'extension désiré
 * \param cube Rubik's cube initialisé
 * \param extension Extension de sortie (cf define.h)
 */
void saveCube(miniCube cube[6][N][N], char* extension) {
    int cubeTmp[6][N][N];
    getColorArray(cube, cubeTmp);
    if(strcmp(extension, EXTENSION_JSON) == 0)
        saveCubeJSON(cubeTmp);
    else
        printError("Extension inconnue");
}

/************************************
 *        Misc functions
 ************************************/

/**
 * \fn char* getExtension(char* path)
 * \brief Extrais d'une chaine de caractère correspondant à un fichier l'extension de celui ci
 * \param path Chemin du fichier
 * \return Une chaine de caractère commancant par un "."
 */
char* getExtension(char* path) {
    char *dotPosition = strrchr(path, '.');
    if(dotPosition == NULL || dotPosition == path)
        return "";
    return dotPosition;
}
