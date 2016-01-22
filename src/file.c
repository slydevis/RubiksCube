#include "stdio.h"
#include "file.h"
#include "util.h"

FILE* openFile(char* path, char* mode) {
    FILE* file = fopen(path, mode);
    return file;
}

void closeFile(FILE* file) {
    fclose(file);
}

char* toUpper(char* str) {
    for(int i = 0; i < strlen(str); ++i)
        str[i] = (char) toupper((int) str[i]);
    return str;
}

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
void readJSON(char * path, int tmp[6][N][N]) {
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

    char str[200];
    char* buff;
    int index;
    int i = 0;
    int j = 0;
    int lastTranslated;

    FILE* file = openFile(path, OPEN_READ);

    if(!file)
        printError("Impossible d'ouvrir le fichier demande");

    while(fgets(str, 200, file)) {
        i = 0;
        j = 0;
        buff = strtok (str, "{}:[], \"");
        do {
            if(buff != NULL) {
                buff = toUpper(buff);
                lastTranslated = translateWord(buff);
                if(lastTranslated < 10) // TODO : Improve this condition
                    index = lastTranslated;
                else {
                    if(j == N) {
                        j = 0;
                        ++i;
                    }
                    if(i == N)
                        i = 0;
                    tmp[index][i][j] = lastTranslated;
                    ++j;
                }
            }
            buff = strtok (NULL, "{}:[], \"");
        } while(buff != NULL);
    }
    closeFile(file);
}

char* getExtension(char* path) {
    char *dotPosition = strrchr(path, '.');
    if(dotPosition == NULL || dotPosition == path)
    	return "";
    return dotPosition;
}

void saveCube(int cube[6][N][N]) {
    FILE* file = openFile("output/save.json", "w");

    if (file != NULL)
    {
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
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }
}
