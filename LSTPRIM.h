#ifndef _LSTPRIM_H
#define _LSTPRIM_H
#include "ELTPRIM.H"
#include "LSTSDD.H"
/*création d'un noeud*/
NOEUD noeudCreer(ELEMENT);
/*Detruir un noeud*/
void noeudDetruire(NOEUD);
/*Création d'une liste*/
LISTE listeCreer(void);
/*Detruire une liste*/
void listeDetruire(LISTE);
/*Vérifier si la liste est vide*/
int estVide(LISTE);
/*Vérifier si la liste est saturée*/
int estSaturee(LISTE);
/*retourne la taille de la liste*/
int listeTaille(LISTE);
/*récupérer un éléments d'une liste*/
ELEMENT recuperer(LISTE, int);
/*Insere un éléments dans un liste*/
int inserer(LISTE, ELEMENT,int);
/*Supprimer un éléments d'une liste*/
int supprimer(LISTE, int);
/*Afficher le contenue d'une liste*/
void listeAfficher(LISTE);
/*Copier une liste dans une autre liste*/
LISTE listeCopier(LISTE);
/*Comparer deux listes */
int  listeComparer(LISTE, LISTE);
#endif // LSTPRIM_H
