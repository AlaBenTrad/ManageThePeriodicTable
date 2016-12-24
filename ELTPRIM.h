#ifndef _ELTPRIM_H
#define _ELTPRIM_H
#include "ELTSDD.H"
/*Creation d'un �lements */
ELEMENT elementCreer(void) ;
/* Lecture d'un �l�ment*/
void elementLire(ELEMENT*);
/* Lib�ration de m�moire */
void elementDetruire (ELEMENT);
/* Affichage d'un �l�ment*/
void elementAfficher(ELEMENT);
/* Copie  du contenu du  deuxi�me argument dans le premier*/
void elementAffecter(ELEMENT*, ELEMENT);
/*Copier le conteurn d'un �lement dans un autre*/
void elementCopier(ELEMENT *, ELEMENT) ;
/*Comparaison de deux �lements*/
int elementComparer(ELEMENT, ELEMENT);

#endif // ELTPRIM_H
