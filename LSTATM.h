#ifndef LSTATM_H
#define LSTATM_H
#include "ELTPRIM.H"

typedef struct structNoeud
{
    ELEMENT info;  //Info est de type ELEMENT
    struct structNoeud * suivant;// suivant est un pointeur sur un noeud (récursif)
}  structNoeud, * NOEUD; //NOEUD est un pointeur sur un nœud

typedef struct
{
    NOEUD tete; //Un pointeur sur le nœud tete
    int lg; // un entier indiquant le nombre d’éléments dans la liste
} LISTE_ATM,*LISTE;
#endif // LSTATM_H
