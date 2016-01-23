#ifndef __FILE_H__
#define __FILE_H__

#include "define.h"

FILE* openFile(char* path, char* mode);
void closeFile(FILE* file);
char* toUpper(char* str);
int translateWord(char* word);
void readJSON(char * path, miniCube tmp[6][N][N]);
void ReadROT(char* path, miniCube tmp[6][N][N]);
char* getExtension(char* path);
void saveCube(miniCube cube[6][N][N], char* extension);

#endif /* __FILE_H__ */
