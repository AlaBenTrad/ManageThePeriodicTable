#ifndef LSTATM_H
#define LSTATM_H
#include "ELTPRIM.H"

typedef struct structNoeud
{
    ELEMENT info;  //Info est de type ELEMENT
    struct structNoeud * suivant;// suivant est un pointeur sur un noeud (r�cursif)
}  structNoeud, * NOEUD; //NOEUD est un pointeur sur un n�ud

typedef struct
{
    NOEUD tete; //Un pointeur sur le n�ud tete
    int lg; // un entier indiquant le nombre d��l�ments dans la liste
} LISTE_ATM,*LISTE;
#endif // LSTATM_H
