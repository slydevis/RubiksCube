#include <stdio.h> // NULL
#include <unistd.h>// sleep()
#include <string.h> // strlen()

#include "tree.h"
#include "list.h"
#include "resolveBacktrack.h"
#include "util.h"
#include "cube.h"
#include "rotations.h"
#include "display.h"

/**
 * \fn void resolveBacktrack(miniCube c[6][N][N])
 * \brief Lance la résolution avec l'algorithme de Backtrack afin de trouver une solution optimal
 * \param c Rubik's cube initialisé
 */
void resolveBacktrack(miniCube c[6][N][N]) {
    printf("BACKTRACK : \n");

    miniCube cube[6][N][N];

    // Init temporary cube
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                cube[i][j][k] = c[i][j][k];

    pTree tree = creeNode(NULL, cube);
    pList l = NULL;

    l = addList(l, tree);

    while(l != NULL) {
        tree = l->tree;
        l = supprimerListe(l);

        if(strlen(tree->step) == MAX_BACKTRACK)
            break;

        if(isCompleteCube(tree->cubeState))
            break;

        tree = creeNode(tree, tree->cubeState);
        l = addList(l, tree);
        while(tree->brother != NULL) {
            tree = tree->brother;
            l = addList(l, tree);
        }
    }

    if(isCompleteCube(tree->cubeState)) {
        printInfo("Une solution a été trouvé");
        printf("(%s)\n", tree->step);
        char* buff = strtok (tree->step, ", ");

        do {
            if(buff != NULL) {
                cubeRotation(c, buff);
                buff = strtok (NULL, ", ");
            }
        } while(buff != NULL);
    }
    else
        printf("Pas trouvé il s'agit peut être d'une configuration impossible\n");

    printf("\nFIN\n");
}
