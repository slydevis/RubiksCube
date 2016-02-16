#ifndef __UTIL_H__
#define __UTIL_H__

#include "define.h"

void printError(char* str);
void printTitle();
int getFinalColorId(int id);
int getFinalLibelle(int face, int x, int y);
void getColorArray(miniCube cube[6][N][N], int cubeTmp[6][N][N]);
int isCompleteCube(miniCube cube[6][N][N]);
char* concatStr(char *s1, char *s2);

#endif /* __UTIL_H__ */
