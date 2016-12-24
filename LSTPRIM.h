#ifndef _LSTPRIM_H
#define _LSTPRIM_H
#include "ELTPRIM.H"
#include "LSTSDD.H"
/*cr�ation d'un noeud*/
NOEUD noeudCreer(ELEMENT);
/*Detruir un noeud*/
void noeudDetruire(NOEUD);
/*Cr�ation d'une liste*/
LISTE listeCreer(void);
/*Detruire une liste*/
void listeDetruire(LISTE);
/*V�rifier si la liste est vide*/
int estVide(LISTE);
/*V�rifier si la liste est satur�e*/
int estSaturee(LISTE);
/*retourne la taille de la liste*/
int listeTaille(LISTE);
/*r�cup�rer un �l�ments d'une liste*/
ELEMENT recuperer(LISTE, int);
/*Insere un �l�ments dans un liste*/
int inserer(LISTE, ELEMENT,int);
/*Supprimer un �l�ments d'une liste*/
int supprimer(LISTE, int);
/*Afficher le contenue d'une liste*/
void listeAfficher(LISTE);
/*Copier une liste dans une autre liste*/
LISTE listeCopier(LISTE);
/*Comparer deux listes */
int  listeComparer(LISTE, LISTE);
#endif // LSTPRIM_H
