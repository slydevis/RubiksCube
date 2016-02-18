#include <stdio.h> // NULL
#include <stdlib.h> // malloc()
#include <string.h> // strcmp()

#include "define.h"
#include "tree.h"
#include "util.h"
#include "rotations.h"

/**
 * \fn pTree creeNode(pTree father, miniCube cube[6][N][N])
 * \brief Crée un nouvel élément dans l'arbre de recherche
 * \param father l'adresse de l'élément précédant
 * \param cube L'état courant du Rubik's cube
 * \return Renvoie l'adresse du nouvelle élément
 */
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

        if(strcmp(father->rotation, "U'") == 0) {
            newTree->rotation = "U'";
        }
        else {
            newTree->rotation = "U";
        }

        cubeRotation(newTree->cubeState, newTree->rotation);

        newTree->step = concatStr(father->step, newTree->rotation);
        newTree->step = concatStr(newTree->step, ", ");
        newTree->brother = createBrothers(father);
    }

    return newTree;
}

/**
 * \fn pTree createBrothers(pTree father)
 * \brief Crée une liste chainée avec la liste des frêres d'un élément
 * \param father l'adresse de l'élément précédant
 * \return Renvoie l'adresse du premier frêre à rajouter
 */
pTree createBrothers(pTree father) {
    pTree uPrim = NULL;
    if(strcmp(father->rotation, "U'") != 0) {
        uPrim = (pTree) malloc(sizeof(tree));
        uPrim->children = NULL;
        uPrim->rotation = "U'";
        uPrim->step = concatStr(father->step, uPrim->rotation);
        uPrim->step = concatStr(uPrim->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    uPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(uPrim->cubeState, uPrim->rotation);
    }

    pTree l = NULL;
    if(strcmp(father->rotation, "L'") != 0) {
        l = (pTree) malloc(sizeof(tree));
        l->children = NULL;
        l->rotation = "L";
        l->step = concatStr(father->step, l->rotation);
        l->step = concatStr(l->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    l->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(l->cubeState, l->rotation);
    }

    pTree lPrim = NULL;
    if(strcmp(father->rotation, "L") != 0) {
        lPrim = (pTree) malloc(sizeof(tree));
        lPrim->children = NULL;
        lPrim->rotation = "L'";
        lPrim->step = concatStr(father->step, lPrim->rotation);
        lPrim->step = concatStr(lPrim->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    lPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(lPrim->cubeState, lPrim->rotation);
    }

    pTree f = NULL;
    if(strcmp(father->rotation, "F'") != 0) {
        f = (pTree) malloc(sizeof(tree));
        f->children = NULL;
        f->rotation = "F";
        f->step = concatStr(father->step, f->rotation);
        f->step = concatStr(f->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    f->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(f->cubeState, f->rotation);
    }

    pTree fPrim = NULL;
    if(strcmp(father->rotation, "F") != 0) {
        fPrim = (pTree) malloc(sizeof(tree));
        fPrim->children = NULL;
        fPrim->rotation = "F'";
        fPrim->step = concatStr(father->step, fPrim->rotation);
        fPrim->step = concatStr(fPrim->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    fPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(fPrim->cubeState, fPrim->rotation);
    }

    pTree r = NULL;
    if(strcmp(father->rotation, "R'") != 0) {
        r = (pTree) malloc(sizeof(tree));
        r->children = NULL;
        r->rotation = "R";
        r->step = concatStr(father->step, r->rotation);
        r->step = concatStr(r->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    r->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(r->cubeState, r->rotation);
    }

    pTree rPrim = NULL;
    if(strcmp(father->rotation, "R") != 0) {
        rPrim = (pTree) malloc(sizeof(tree));
        rPrim->children = NULL;
        rPrim->rotation = "R'";
        rPrim->step = concatStr(father->step, rPrim->rotation);
        rPrim->step = concatStr(rPrim->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    rPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(rPrim->cubeState, rPrim->rotation);
    }

    pTree d = NULL;
    if(strcmp(father->rotation, "D'") != 0) {
        d = (pTree) malloc(sizeof(tree));
        d->children = NULL;
        d->rotation = "D";
        d->step = concatStr(father->step, d->rotation);
        d->step = concatStr(d->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    d->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(d->cubeState, d->rotation);
    }

    pTree dPrim = NULL;
    if(strcmp(father->rotation, "D") != 0) {
        dPrim = (pTree) malloc(sizeof(tree));
        dPrim->children = NULL;
        dPrim->rotation = "D'";
        dPrim->step = concatStr(father->step, dPrim->rotation);
        dPrim->step = concatStr(dPrim->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    dPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(dPrim->cubeState, dPrim->rotation);
    }

    pTree x = NULL;
    if(strcmp(father->rotation, "X'") != 0) {
        x = (pTree) malloc(sizeof(tree));
        x->children = NULL;
        x->rotation = "X";
        x->step = concatStr(father->step, x->rotation);
        x->step = concatStr(x->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    x->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(x->cubeState, x->rotation);
    }

    pTree xPrim = NULL;
    if(strcmp(father->rotation, "X") != 0) {
        xPrim = (pTree) malloc(sizeof(tree));
        xPrim->children = NULL;
        xPrim->rotation = "X'";
        xPrim->step = concatStr(father->step, xPrim->rotation);
        xPrim->step = concatStr(xPrim->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    xPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(xPrim->cubeState, xPrim->rotation);
    }

    pTree y = NULL;
    if(strcmp(father->rotation, "Y'") != 0) {
        y = (pTree) malloc(sizeof(tree));
        y->children = NULL;
        y->rotation = "Y";
        y->step = concatStr(father->step, y->rotation);
        y->step = concatStr(y->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    y->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(y->cubeState, y->rotation);
    }

    pTree yPrim = NULL;
    if(strcmp(father->rotation, "Y") != 0) {
        yPrim = (pTree) malloc(sizeof(tree));
        yPrim->children = NULL;
        yPrim->rotation = "Y'";
        yPrim->step = concatStr(father->step, yPrim->rotation);
        yPrim->step = concatStr(yPrim->step, ", ");
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    yPrim->cubeState[i][j][k] = father->cubeState[i][j][k];
        cubeRotation(yPrim->cubeState, yPrim->rotation);
    }

    // Linked list creation
    if(yPrim != NULL)
        yPrim->brother = NULL;

    if(y != NULL && yPrim != NULL)
        y->brother = yPrim;
    else if(y != NULL)
        y->brother = NULL;

    if(xPrim != NULL && y != NULL)
        xPrim->brother = y;
    else if(xPrim != NULL)
        xPrim->brother = yPrim;

    if(x != NULL && xPrim != NULL)
        x->brother = xPrim;
    else if(x != NULL)
        x->brother = y;

    if(dPrim != NULL && x != NULL)
        dPrim->brother = x;
    else if(dPrim != NULL)
        dPrim->brother = xPrim;

    if(d != NULL && dPrim != NULL)
        d->brother = dPrim;
    else if(d != NULL)
        d->brother = x;

    if(rPrim != NULL && d != NULL)
        rPrim->brother = d;
    else if(rPrim != NULL)
        rPrim->brother = dPrim;

    if(r != NULL && rPrim != NULL)
        r->brother = rPrim;
    else if(r != NULL)
        r->brother = d;

    if(fPrim != NULL && r != NULL)
        fPrim->brother = r;
    else if(fPrim != NULL)
        fPrim->brother = rPrim;

    if(f != NULL && fPrim != NULL)
        f->brother = fPrim;
    else if(f != NULL)
        f->brother = r;

    if(lPrim != NULL && f != NULL)
        lPrim->brother = f;
    else if(lPrim != NULL)
        lPrim->brother = fPrim;

    if(l != NULL && lPrim != NULL)
        l->brother = lPrim;
    else if(l != NULL)
        l->brother = f;

    if(uPrim != NULL && l != NULL) {
        uPrim->brother = l;
    }
    else if(uPrim != NULL)
        uPrim->brother = lPrim;

    if(uPrim == NULL)
        return l;
    else
        return uPrim;
}
