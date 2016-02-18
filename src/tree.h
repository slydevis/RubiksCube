#ifndef __TREE_H__
#define __TREE_H__

#include "define.h"

typedef struct tree {
    char* rotation;
    miniCube cubeState[6][N][N];
    char* step;
    struct tree* brother;
    struct tree* children;
} tree;

typedef tree* pTree;

pTree creeNode(pTree father, miniCube cube[6][N][N]);
pTree createBrothers(pTree father);

#endif /* __TREE_H__ */
