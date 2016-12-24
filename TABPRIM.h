#ifndef TABPRIM_H
#define TABPRIM_H
#include "ELTPRIM.H"
#include "LSTPRIM.H"
#include "TABSDD.H"
/*Cr�ation d'un tableau*/
ELEMENT_TAB tabCreer(void);
/*Dtruir un tableau*/
void tabDetruire(ELEMENT_TAB);
/*V�rifier si le tableau est vide*/
int estVide(ELEMENT_TAB);
/*V�rifier si le tableau est satur�*/
int estSaturee(ELEMENT_TAB);
/*R�cup�rer une liste d'uu tableau*/
LISTE recuperer(ELEMENT_TAB, int, int );
/*Inserer une liste dans un tableau*/
int inserer(ELEMENT_TAB,LISTE, int, int );
/*Supprimer une liste d'un tableau*/
int supprimer(ELEMENT_TAB, int,int);
/*Afficher le contenue d'un tableau*/
void tabAfficher(ELEMENT_TAB);
/*Copier le contenue d'un tableau dans un autre*/
ELEMENT_TAB tabCopier(ELEMENT_TAB);
/*Comparer deux tableau*/
int tabComparer(ELEMENT_TAB, ELEMENT_TAB);
#endif // TABPRIM_H
