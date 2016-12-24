#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include "ELTPRIM.H"

/*création d'un éléments*/
ELEMENT elementCreer()
{ /*Allocation mémoire car il s'agit de stockage indirect*/
    ELEMENT e=(ELEMENT)malloc(sizeof(ELEMENT_ATM));
    e->NumAtom=0; //Initilisation
    strcpy(e->Symb,"\0");//Initilisation
    e->MassAtom=0.0;//Initilisation
    e->Etat='\0'; //Initilisation
    return e;
}
/*Lecture d'un élément*/
void elementLire(ELEMENT* e)
{   do{
    printf("\nDonnez numereau d'atomique = ");
    scanf("%d",&((*e)->NumAtom));//lecture de Numereau d'atome
    fflush(stdin);}
    while((*e)->NumAtom <= 0 || (*e)->NumAtom >118); //Le num atomique est toujour positive
    printf("Donnez le symbole de l'atome = ");
    scanf("%s",&((*e)->Symb));//lecture de la symbole
    fflush(stdin);
    do{
    printf("Donnez la mass atomique de l'atome = ");
    scanf("%f",&((*e)->MassAtom)); //lecture de mass atomique
    fflush(stdin);}
    while((*e)->MassAtom < 0);//le Mass atomique est toujours positives
    do{
    printf("Donnez l'etat de l'atome = ");
    scanf("%c",&((*e)->Etat));//lecture de l'etat
    fflush(stdin);}
    while((*e)->Etat !='S' && (*e)->Etat !='G' && (*e)->Etat!='L' && (*e)->Etat!='Y');
    //Etat : (solide/liquide/gaz/synthétique)
}
//affichage d'un élément*/
void elementAfficher(ELEMENT e)
{
printf("      %3d\t           %3s\t            %.4f\t         %c\t\n",e->NumAtom,e->Symb,e->MassAtom,e->Etat);
}
/*Detruir un élément*/
void elementDetruire(ELEMENT e)
{
   free(e);
}
/*affecter le contenue d'un élémnets dans un autre*/
void elementAffecter(ELEMENT* e1, ELEMENT e2)
{
*e1=e2;
}
/*Copier le contenue d'un élémnets dans un autre*/
void elementCopier(ELEMENT * e1, ELEMENT e2)
{
    memcpy(*e1,e2,sizeof(ELEMENT_ATM));
}
/*Ici on campare le symbole car chaque atome a sa propores symbole unique*/
int elementComparer(ELEMENT e1,ELEMENT e2)
{
    if(e1->NumAtom==e2->NumAtom&&(strcmp(e1->Symb,e2->Symb)==0)&&(e1->MassAtom==e2->MassAtom)&&(e1->Etat==e2->Etat))
        return 1;
    else return 0;
}







