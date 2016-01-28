#ifndef __UTIL_H__
#define __UTIL_H__

#include "define.h"

void printError(char* str);
void printTitle();
int getFinalColorId(int id);
char* getFinalLibelle(int face, int x, int y);
void getColorArray(miniCube cube[6][N][N], int cubeTmp[6][N][N]);

#endif /* __UTIL_H__ */
