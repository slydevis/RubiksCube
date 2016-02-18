#ifndef __CUBE_H__
#define __CUBE_H__

#include "define.h"

void randomizeCube(miniCube cube[6][N][N]);
void initCube(miniCube cube[6][N][N]);
void completeCube(miniCube cube[6][N][N], char* path);
void freeCube(miniCube cube[6][N][N]);
int isCompleteCube(miniCube cube[6][N][N]);

#endif /* __CUBE_H__ */
