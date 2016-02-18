#ifndef __UTIL_H__
#define __UTIL_H__

#include "define.h"

/************************************
 *          Display message
 ************************************/

void printError(const char* str);
void printInfo(const char* str);
void printTitle();
void printHelp();

/************************************
 *          Misc functions
 ************************************/

char* concatStr(char *s1, char *s2);
char* toUpper(char* str);
void clearScreen();
void changeStatusSave(int status);

/************************************
 *        Cube misc functions
 ************************************/

int getFinalColorId(const int id);
void getColorArray(miniCube cube[6][N][N], int cubeTmp[6][N][N]);
int getFinalLibelle(const int face, const int x, const int y);

#endif /* __UTIL_H__ */
