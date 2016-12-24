#ifndef _ELTPRIM_H
#define _ELTPRIM_H
#include "ELTSDD.H"
/*Creation d'un élements */
ELEMENT elementCreer(void) ;
/* Lecture d'un élément*/
void elementLire(ELEMENT*);
/* Libération de mémoire */
void elementDetruire (ELEMENT);
/* Affichage d'un élément*/
void elementAfficher(ELEMENT);
/* Copie  du contenu du  deuxième argument dans le premier*/
void elementAffecter(ELEMENT*, ELEMENT);
/*Copier le conteurn d'un élement dans un autre*/
void elementCopier(ELEMENT *, ELEMENT) ;
/*Comparaison de deux élements*/
int elementComparer(ELEMENT, ELEMENT);

#endif // ELTPRIM_H
