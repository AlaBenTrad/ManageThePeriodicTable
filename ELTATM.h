#ifndef _ELTATM_H
#define _ELTATM_H
//Definition du strucutre d'un atome.
typedef struct
{
    int NumAtom; //Numéreo atomique.
    char Symb[4]; //Symbole de l'atome.
    float MassAtom; // Mass atomique.
    char Etat; //Etat : (solide/liquide/gaz/synthétique)
}ELEMENT_ATM,*ELEMENT;

#endif // ELTATM_H
