#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "LSTPRIM.H"
/*Création d'un noeud*/
NOEUD noeudCreer(ELEMENT e){
    NOEUD n;
//Alloction mémpor car il s'agit d'un stockage direct
n=(NOEUD)malloc(sizeof(structNoeud));
if(!n)
    //Pas assez de mémoire
    printf ("\nPlus d'espace!");
else {
//creation du noeud
    elementAffecter(&n->info, e);
    n->suivant = NULL;
}
return n;
}
/*Detruir un neodu*/
void noeudDetruire(NOEUD n)
{  //détruir l'éléménet
    elementDetruire(n->info);
 // Libération de mémoire
    free(n);
}
/*Creaton d'une liste*/
LISTE listeCreer(void)
{
    LISTE L;
    //Alloction mémpor car il s'agit d'un stockage direct
    L = (LISTE)malloc(sizeof(LISTE_ATM));
    if(!L){
            //Pas asseez de mémoire
        printf("\nProbl%cme de m%cmoire!",138,130) ;
		exit(0) ;
    }
    else {
            L->lg = 0;
            L->tete = NULL; /* initialiser la tête */
    }
   return(L);
}
/*Detruire une liste */
void listeDetruire(LISTE L){
int i;
NOEUD  p, q; //Noeuds temporelles pour nous aide à a la destrcution des éléments de la liste
q= L->tete;
   for(i = 1;i <= L->lg; i++)
   {
        p=q;
        q=q->suivant;
        noeudDetruire(p);
   }
    free(L);
}
/*Vérifier si la liste est vide*/
int estVide(LISTE L) {
	return (L->lg == 0);//retourne 1 si la liste est vide 0 si non
}
/*Retoune la taille de la liste*/
int listeTaille(LISTE L) {
   return (L->lg);
}
/*Vérifier si la liste est saturée*/
int estSaturee(LISTE L)
{
    NOEUD temp;
    int saturee=1;
    //On crée un noeud de test
    temp=(NOEUD)malloc(sizeof(structNoeud));
    //si la noeud à été crée donc la liste n'est pas saturée
    if(temp!=NULL){
        saturee=0;
        free(temp);
    }
    return saturee;//retourne 1 si la liste est saturée 0 si non
}
/*Insertion d'un élémnets dans uns liste*/
int inserer (LISTE L, ELEMENT e, int pos){
   NOEUD n,p,q;
   int succee=1,i;
   //si la liste est saturée on ne peux pas insere un élément de plus
  if (estSaturee(L))
    {   printf ("\nListe saturée");
  succee=0;}
  else {
        //Controle du position
    if  ((pos < 1) || (pos > L->lg + 1))  {
            printf ("\nPosition invalide");
            succee=0;
  }
  else {
    n=noeudCreer (e);
   //insertion en tête de liste
    if (pos == 1) {
        n->suivant=L->tete;
        L->tete = n;
    }
    else {
    //cas général (pos > 1)
        q= L->tete;
        for (i=1; i<pos; i++) {
                p = q;
        q = q->suivant;
    }
    p->suivant=n;
    n->suivant=q;
  }
  (L->lg)++; //Incrémentation de taille de la liste
}}
return succee;//retourn 1 si l'opération a été effectué 0 si non
}
/*Supprimer un élément d'une liste */
int supprimer (LISTE L, int pos ){
int i;  int succee=1;  NOEUD  p,  q;//Noeuds d'aide
	 if (estVide(L)) {
             //si la liste estvide on ne peux pas supprimer un élément
            printf ("\nListe vide!");
            succee=0; }
            else {
                   //Controle du position
                if   ((pos < 1) || (pos > L->lg)) {
                    printf ("\nPosition invalide!");
                    succee=0;
                }
            else {
                 q = L->tete;
                 //suppression en tête de liste
                 if (pos == 1)
                     L->tete=L->tete->suivant;
                 else {
                        //cas général (pos > 1)
                     for (i=1; i<pos; i++) {
                      p = q;
                     q = q->suivant;
                 }
                  p->suivant=q->suivant;
            }
            noeudDetruire(q);
            (L->lg)--; //décréméntaion de la taille de la liste
            }}
return succee; //retourn 1 si l'opération a été effectué 0 si non
}
/*Récuperer un élément d'une liste*/
ELEMENT recuperer(LISTE L, int pos) {
    /*  s'il ya une erreur on affiche un message et on retourne un element vide */
	ELEMENT elt= elementCreer();//création de l'élements quand va le retourner
	int i;
	NOEUD p;
       //si la liste estvide on ne peux pas récuperer un élément
	if (estVide(L))
		printf ("");
	else		{
            //Control du position
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide!");

				else{
                    p= L->tete;
                    for (i=1; i<pos; i++)
                    p = p->suivant;
                    elementAffecter(&elt,p->info);
				}
			}
	return(elt);
}
/*Affichage d'une liste*/
void listeAfficher(LISTE L){
	int i;
	NOEUD p;
	p=L->tete;
   for(i = 1;i <= L->lg; i++)
		{elementAfficher(p->info);
		p=p->suivant;}
}
/*Faire un copier d'une liste*/
LISTE listeCopier(LISTE L){
//Création de la liste quand va le retourner
LISTE LR = listeCreer();
int i;
ELEMENT elt;
   for(i = 1;i <= L->lg; i++) {
     //Chaque itération on crée un élément
	    elt=elementCreer();
	    //On copier l'éléments récupérer
		elementCopier(&elt, recuperer(L,i));
        //Insertion de élément copiée dans notre liste
		inserer(LR,elt, i);
	}
 return LR;
}
/*Comparer deux liste*/
int  listeComparer (LISTE L1,LISTE L2)
{
int test= 1;
int i=1;
//Si les tailles sont différnets dans les liste n'est pas identiques
if (listeTaille(L1) != listeTaille(L2)) test= 0;
//si non on vérifier élément par élément
while ((i<=listeTaille(L1)) && (test)) {
	   if (elementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
		test=0;
	i++;
}
return test;//retourn 1 si l'opération a été effectué 0 si non
}




