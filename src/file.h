#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>

#include "define.h"

/************************************
 *        File management
 ************************************/

FILE* openFile(char* path, char* mode);
void closeFile(FILE* file);

/************************************
 *        JSON Translation
 ************************************/

int translateWord(char* word);
char* reverseTranslateWord(int value);
void readJSON(char * path, miniCube cube[6][N][N]);

/************************************
 *        ROT translation
 ************************************/

void translateRotation(miniCube cube[6][N][N], char car, const int direction);
void ReadROT(char* path, miniCube cube[6][N][N]);

/************************************
 *        Save management
 ************************************/

void saveCubeJSON(int cube[6][N][N]);
void saveCube(miniCube cube[6][N][N], char* extension);

/************************************
 *        Misc functions
 ************************************/

char* getExtension(char* path);

#endif /* __FILE_H__ */
