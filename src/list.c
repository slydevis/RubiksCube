#include <stdio.h> // NULL
#include <stdlib.h> // malloc()

#include "list.h"

/**
 * \fn pList addList(pList head, pTree t)
 * \brief Crée une liste chainée avec la liste des frêres d'un élément
 * \param head Adresse de la tête de la liste
 * \param t Adresse de l'arbre à ajouter dans la liste chainée
 * \return Renvoie l'adresse du premier frêre à rajouter
 */
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

/**
 * \fn pList supprimerListe(pList l)
 * \brief Supprime un élément de la liste et libère la mémoire
 * \param l Element de la liste à supprimer
 * \return Renvoie l'adresse de l'élément suivant
 */
pList supprimerListe(pList l) {
    pList tmp = l->next;
    free(l);
    return tmp;
}
