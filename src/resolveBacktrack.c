#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>// sleep()
#include <string.h> // strlen()
#include "resolveBacktrack.h"
#include "rotations.h"
#include "util.h"

typedef struct tree {
	char* rotation;
	miniCube cubeState[6][N][N];
	char* step;
	struct tree* brother;
	struct tree* children;
} tree	;

typedef tree* pTree;

typedef struct list {
	pTree tree;
	struct list* next;
} list;

typedef list* pList;

pList addList(pList head, pTree t) {
	pList newElem = malloc(sizeof(list));
	newElem->tree = t;
	newElem->next = NULL;

	if(head == NULL)
		return newElem;

	pList cur = head;
	while(cur->next)
		cur = cur->next;

	cur->next = newElem;
	return head;
}

pList supprimerListe(pList l) {
    pList tmp = l->next;
    free(l);
    return tmp;
}

pTree createBrothers(pTree father) {
    pTree uPrim = (pTree) malloc(sizeof(tree));
    uPrim->children = NULL;
    uPrim->rotation = "U'";
    uPrim->step = concatStr(father->step, uPrim->rotation);
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                uPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
    up_rotation_reverse(uPrim->cubeState);

    pTree l = (pTree) malloc(sizeof(tree));
    l->children = NULL;
    l->rotation = "L";
    l->step = concatStr(father->step, l->rotation);
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                l->cubeState[i][j][k] = father->cubeState[i][j][k];
    left_rotation_reverse(l->cubeState);

    pTree lPrim = (pTree) malloc(sizeof(tree));
    lPrim->children = NULL;
    lPrim->rotation = "L'";
    lPrim->step = concatStr(father->step, lPrim->rotation);
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                lPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
    left_rotation(lPrim->cubeState);

    pTree f = (pTree) malloc(sizeof(tree));
    f->children = NULL;
    f->rotation = "F";
    f->step = concatStr(father->step, f->rotation);
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                f->cubeState[i][j][k] = father->cubeState[i][j][k];
    front_rotation(f->cubeState);

    pTree fPrim = (pTree) malloc(sizeof(tree));
    fPrim->children = NULL;
    fPrim->rotation = "F'";
    fPrim->step = concatStr(father->step, fPrim->rotation);
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                fPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
    front_rotation_reverse(fPrim->cubeState);

    pTree r = (pTree) malloc(sizeof(tree));
    r->children = NULL;
    r->rotation = "R";
    r->step = concatStr(father->step, r->rotation);
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                r->cubeState[i][j][k] = father->cubeState[i][j][k];
    right_rotation(r->cubeState);

    pTree rPrim = (pTree) malloc(sizeof(tree));
    rPrim->children = NULL;
    rPrim->rotation = "R'";
    rPrim->step = concatStr(father->step, rPrim->rotation);
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                rPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
    right_rotation_reverse(rPrim->cubeState);

    pTree d = (pTree) malloc(sizeof(tree));
    d->children = NULL;
    d->rotation = "D";
    d->step = concatStr(father->step, d->rotation);

    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                d->cubeState[i][j][k] = father->cubeState[i][j][k];
    down_rotation_reverse(d->cubeState);

    pTree dPrim = (pTree) malloc(sizeof(tree));
    dPrim->children = NULL;
    dPrim->rotation = "D'";
    dPrim->step = concatStr(father->step, dPrim->rotation);

    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                dPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
    down_rotation(dPrim->cubeState);

    pTree x = (pTree) malloc(sizeof(tree));
    x->children = NULL;
    x->rotation = "X";
    x->step = concatStr(father->step, x->rotation);

    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                x->cubeState[i][j][k] = father->cubeState[i][j][k];
    cube_rotation_upside_down(x->cubeState);

    pTree xPrim = (pTree) malloc(sizeof(tree));
    xPrim->children = NULL;
    xPrim->rotation = "X'";
    xPrim->step = concatStr(father->step, xPrim->rotation);

    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                xPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
    cube_rotation_upside_down(xPrim->cubeState);
    cube_rotation_upside_down(xPrim->cubeState);
    cube_rotation_upside_down(xPrim->cubeState);

    pTree y = (pTree) malloc(sizeof(tree));
    y->children = NULL;
    y->rotation = "Y";
    y->step = concatStr(father->step, y->rotation);

    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                y->cubeState[i][j][k] = father->cubeState[i][j][k];
    cube_rotation_side(y->cubeState);


    pTree yPrim = (pTree) malloc(sizeof(tree));
    yPrim->children = NULL;
    yPrim->rotation = "Y'";
    yPrim->step = concatStr(father->step, yPrim->rotation);

    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                yPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
    cube_rotation_side(yPrim->cubeState);
    cube_rotation_side(yPrim->cubeState);
    cube_rotation_side(yPrim->cubeState);

    // Creation de la liste chainée
    yPrim->brother = NULL;
    y->brother = yPrim;
    xPrim->brother = y;
    x->brother = xPrim;
    dPrim->brother = x;
    d->brother = dPrim;
    rPrim->brother = d;
    r->brother = rPrim;
    fPrim->brother = r;
    f->brother = fPrim;
    lPrim->brother = f;
    l->brother = lPrim;
    uPrim->brother = l;
    return uPrim;
}

pTree creeNode(pTree father, miniCube cube[6][N][N]) {
    pTree newTree = (pTree) malloc(sizeof(tree));
    if(father != NULL)
        father->children = newTree;
    newTree->children = NULL;
    newTree->step = "";
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                newTree->cubeState[i][j][k] = cube[i][j][k];

    if(father == NULL) {
        newTree->rotation = "N"; // N = None
        newTree->brother = NULL;
    }
    else {
        newTree->rotation = "U";
        newTree->step = concatStr(father->step, newTree->rotation);
        up_rotation(newTree->cubeState);
        newTree->brother = createBrothers(father);
    }

    return newTree;
}

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

	 pTree tmp = tree;
	 l = addList(l, tmp);

	 int cpt = 0;
	 int pred = 0;
	 while(l != NULL) {
		 tmp = l->tree;
		 l = supprimerListe(l);

		 if(strlen(tmp->step) == 99)
			 break;

		 if(strlen(tmp->step) > pred) {
			 printf("profondeur = %d\n", strlen(tmp->step));
			 pred = strlen(tmp->step);
		 }

		 if(isCompleteCube(tmp->cubeState)) {
		     printf("Solution trouvé (%s) !!!\n", tmp->step);
			 exit(0);
		 }

		 tmp = creeNode(tmp, tmp->cubeState);
		 l = addList(l, tmp);
		 while(tmp->brother != NULL) {
			 tmp = tmp->brother;
			 l = addList(l, tmp);
		 }

		 cpt++;
	 }

	 printf("Pas encore trouvé \n");
     printf("\nFIN\n");
	 exit(0);

}
