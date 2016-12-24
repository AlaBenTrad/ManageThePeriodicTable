#include <stdlib.h>
#include <stdio.h>
#include<malloc.h>
#include "TABPRIM.H"
/*Creation d'un tableau*/
ELEMENT_TAB tabCreer(void)
{
    ELEMENT_TAB Tab;
    //Allocation mémoire car il s'agit d'un stockage indirect
    Tab = (ELEMENT_TAB)malloc(sizeof(TAB));
    if(!Tab) {
            //Pas assez de mémoire
        printf("\nProbl%cme de m%cmoire!",138,130) ;
		exit(0) ;
    }
    else
        return Tab;
}
/*Dtruire un tableau*/
void tabDetruire(ELEMENT_TAB Tab)
{
    int i,j;
    //On parcour le tableau est chaque fois on detruire une liste
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
            listeDetruire(Tab->T[i][j]);
        }
    }
    //Libération de mémoire
    free(Tab);
}
/*Vérifier si le tableau est vide*/
int estVide(ELEMENT_TAB Tab)
{
    int test=0,i,j;
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
//Chaque foix on trouve une liste vide on incrémente le compteur test
            if(estVide(Tab->T[i][j]))
                test++;}}
//si test == 126 donc tous les cases du tableau sont vide donc le tableau est vide
   if(test==126)
         return 1;
   else return 0;
}
/*Vérifier si le tableua est saturé*/
int estSaturee(ELEMENT_TAB Tab)
{
    int test=0,i,j;
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
//Chaque foix on trouve une liste saturée on incrémente le compteur test
            if(estSaturee(Tab->T[i][j]))
                test++;
        }
    }
//si test == 126 donc tous les cases du tableau sont saturés donc le tableau est saturé
   if(test==126)
         return 1;
   else return 0;
}
/*Récupére une liste d'un tableau*/
LISTE recuperer(ELEMENT_TAB Tab, int posl, int posc)
{ //Creation de la liste quand va retourner
    LISTE L=listeCreer();
    //  s'il ya une erreur on affiche un message et on retourne une liste vide */
    if(estVide(Tab))
        printf("\nTableau vide!");
        //Control de position
    else if((posl<0 || posl>7)&&(posc<0 && posc>18))
         printf ("\nPosition invalide!");
    else
        L=(Tab->T[posl][posc]);
    return(L);
}
/*Inserer une liste dans un tableau*/
int inserer(ELEMENT_TAB Tab, LISTE L, int posl, int posc)
{  int succee=1;
 //Si le liste est saturé on ne peux pas insere une liste de plus
    if(estSaturee(Tab)){
        {
		printf ("\nListe satur%ce",130);
		succee=0;}
    }
       //Controle du position
    else if((posl<0 || posl>7)&&(posc<0 && posc>18)){
         printf ("\nPosition invalide!");
         succee=0;}
         //Si la case est saturée on ne peux insere une liste dedant
    else if (estSaturee(Tab->T[posl][posc])){
      printf("\nCase occupe!");
      succee=0;}
      else Tab->T[posl][posc]=L;
      return succee;
}
/*Supprimer une liste d'un tableau*/
int supprimer(ELEMENT_TAB Tab, int posl, int posc)
{
    int succee=1;
      //si le tableau est vide on ne peux pas supprimer une liste
    if(estVide(Tab)){
        printf ("\nTableau vide");
		succee=0;}
  //Controle du position
    else if((posl<0 || posl>7)&&(posc<0 && posc>18)){
         printf ("\nPosition invalide");
         succee=0;}
         //Si la case est vide on ne peux pas supprimer une liste
    else if (estVide(Tab->T[posl][posc]))
        printf("\nCase vide!");
    else listeDetruire(Tab->T[posl][posc]);
    return succee; //retourn 1 si l'opération a été effectué 0 si non
}
/*Affichage d'un tableau*/
void tabAfficher(ELEMENT_TAB Tab)
{
    int i,j;
    printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
        //Chaque itération on affiche une liste
                listeAfficher(Tab->T[i][j]);}}
}
/*Faire une copier d'un tableau*/
ELEMENT_TAB tabCopier(ELEMENT_TAB Tab)
{ ELEMENT_TAB tab = tabCreer();
    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
//Chaque itération on faire une copier d'une liste et l'insére dans le tableau
            inserer(tab,listeCopier(Tab->T[i][j]),i,j);
        }}
        return tab;
}
/*Comparer deux tableau*/
int tabComparer(ELEMENT_TAB Tab1, ELEMENT_TAB Tab2)
{
    int i=0,j=0,test=1;
    while(i<7 && j<18 && test){
            //On vérifie la taille des listes d meme case du tableau
        if(listeTaille(Tab1->T[i][j]) != listeTaille(Tab2->T[i][j]))
              test=0;
    //si les taille sont égaux on campare les listes une par une
              else if (listeComparer(Tab1->T[i][j],Tab2->T[i][j])!=0)
                    {test=0;
                      i++;
                      j++;}
    }
   return test;//retourn 1 si l'opération a été effectué 0 si non
}
