#ifndef LIST_H_
#define LIST_H_

#include "tree.h"

typedef struct list {
    pTree tree;
    struct list* next;
} list;

typedef list* pList;

pList addList(pList head, pTree t);
pList supprimerListe(pList l);

#endif /* LIST_H_ */
