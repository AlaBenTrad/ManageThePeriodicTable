#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include<windows.h>
#include <ctype.h>
#include "ELTPRIM.H"
#include "LSTPRIM.H"
#include "TABPRIM.H"
using namespace std;
ELEMENT_TAB E;
LISTE L;
/*Retourne une liste contient les atomes gazeux*/
LISTE Gaz(ELEMENT_TAB E){
int i,j,k,p=1;
LISTE LG=listeCreer();//Création de la liste des atomes gazeux
//Parcour du tableau
for(i=0;i<7;i++){
        for(j=0;j<18;j++){

                if(estVide(E->T[i][j])==0){ //si la liste est vide ne faire pas les testes
                for(k=1;k<=listeTaille(E->T[i][j]);k++){
                     if (recuperer(E->T[i][j],k)->Etat=='G')
                    //Si l'atome est en etat gazeux il va l'inserer dans la liste
                {inserer(LG,recuperer(E->T[i][j],k),p);
                p++;}//toutfois on ajout un atome on incrémente la position
               }}}}
return LG;//retourne la liste des atomes gazeux
}
/*Retourne une liste qui contient les atomes lourds*/
LISTE Lourds(ELEMENT_TAB E)
{
    int i,j,k,p=1;
LISTE LL=listeCreer();//Création de la liste des atomes lourds
for(i=0;i<7;i++){
        for(j=0;j<18;j++){
                if(estVide(E->T[i][j])==0){//si la liste est vide ne faire pas les testes
                for(k=1;k<=listeTaille(E->T[i][j]);k++){//Copier l'élément aprés avoir le récuperer
                    //Si la numereau atomique est supérieur à 104.
                        if (recuperer(E->T[i][j],k)->NumAtom>104)
                  //Si la consition est vérirfié on l'insére dans la liste.
                        {inserer(LL,recuperer(E->T[i][j],k),p);
                //toutfois on ajout un atome on incrémente la position
                         p++;}}}}}
                return LL;//retourne la liste qui contient les atomes lourds
}
/*Retourne une liste qui contient les atomes radioactifs*/
LISTE Radioactifs(ELEMENT_TAB E)
{
    int i,j,k,p=1;
    LISTE LRadio = listeCreer();//Création de la liste des atomes radioactifs.
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
                if(estVide(E->T[i][j])==0){//si la liste est vide ne faire pas les testes
        for(k=1;k<=listeTaille(E->T[i][j]);k++){
    //Si les atomes sont radio cad l'atome 'Tc' et l'atome 'Pm' et tous les atomes qui ont un numero atomique suéprieur ou égale 84
     if ((strcmp(recuperer(E->T[i][j],k)->Symb,"Tc")==0 &&(recuperer(E->T[i][j],k)->NumAtom==43))||
         (strcmp(recuperer(E->T[i][j],k)->Symb,"Pm")==0 &&(recuperer(E->T[i][j],k)->NumAtom==61))||
         (recuperer(E->T[i][j],k)->NumAtom>=84)){
   //On l'insere dans la liste des atome radioactifs
          inserer(LRadio,recuperer(E->T[i][j],k),p);
          //toutfois on ajout un atome on incrémente la position
          p++;}
}}}}
return LRadio;}
/*Retourne une liste qui contient les atomes instable*/
LISTE Instables(ELEMENT_TAB E)
{
    int i,j,k,p=1;
     LISTE LInstable = listeCreer();//Création de la liste des atomes instables
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
      //si la liste est vide ne faire pas les testes
                if(estVide(E->T[i][j])==0){
        for(k=1;k<=listeTaille(E->T[i][j]);k++){
 //Si la masse atomiqu d'une atome est un entier donc il s'agit d'un atome instable
     if((recuperer(E->T[i][j],k)->MassAtom)-(floor(recuperer(E->T[i][j],k)->MassAtom))==0)/*Dans ce cas on utilise la focntion floor qui retourne la partie entier
    il suffit de faire la soustraction de la masse atomique de l'atome et la floor de sa masse si
    la différence est 0 donc il s'agit d'un nombre entier si non il admet des entier aprés la virgule*/
        {inserer(LInstable,recuperer(E->T[i][j],k),p);
   //toutfois on ajout un atome on incrémente la position
        p++;}
     }}}}
return LInstable;
}
/*Retourne la masse atomique d'un symbole donnée*/
double Ar(ELEMENT_TAB E, char * s)
{int i,trouve,j,k;
double n;
    i=0;
    trouve=0;
    n=0.0;
 //Parcour du tableau
    while((i<7)&&((!trouve)))
    {j=0;
        while(j<18)
        {
            k=1;
        //parcour des listes
            while((k<=listeTaille(E->T[i][j]))&&(!trouve))
            {
        //Création d'un élément
                ELEMENT e=elementCreer();
        //Copier l'élément aprés avoir le récuperer
                elementCopier(&e,recuperer(E->T[i][j],k));
      //Si le symbole donnée est le symbole trouvée sont identique alors le recherhe va étre arréter
                if(strcmp(e->Symb,s)==0)
                {
                    trouve=1;
                //On affecte la masse molaire du élément trouvée
                    n=e->MassAtom;
                }
                else
                {
              //Si non on le detruire
                    elementDetruire(e);
                    k++;
                }
            }
            j++;
        }
        i++;
    }

    return n;//retourne la masse atomque trouvée
}
/*les coleurs*/
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
//Fonction qui affiche le num atomique, le symbole et la masse atomiqueli
void affichage(ELEMENT_TAB E)
{
    int i,j;
    //Parcour du tableau
    printf("\n--------                                                                                                                                --------\n");
    for(i=0;i<2;i++){
        //On chaque ligne on va afficher le num atomique le symbole est le masse atomique
        for(j=0;j<18;j++){
            //si la case du tableau ne continet des atomes on affiches 7 espace car on résérve pour chaque atome dans l'affichage 7 espace
                if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
                else
     //Au premier temps on affiche le num atomique de l'atome
          printf("%7d|",recuperer(E->T[i][j],1)->NumAtom);}
          printf("\n");
    //puis on affiche le symbole
           for(j=0;j<18;j++){
                if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
                else
          printf("%7s|",recuperer(E->T[i][j],1)->Symb);}
           printf("\n");
        //et finalement on affiche la masse atomique
          for(j=0;j<18;j++){
               if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
          else
          printf(" %6.2f|",recuperer(E->T[i][j],1)->MassAtom);}
           printf("\n");
          for(j=0;j<18;j++){
               if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
          else
          printf("%7.c|",recuperer(E->T[i][j],1)->Etat);}
          printf("\n---------------                                                                                 -----------------------------------------------\n");
           }
           for(i=2;i<7;i++){
        //On chaque ligne on va afficher le num atomique le symbole est le masse atomique
        for(j=0;j<18;j++){
            //si la case du tableau ne continet des atomes on affiches 7 espace car on résérve pour chaque atome dans l'affichage 7 espace
                if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
                else
     //Au premier temps on affiche le num atomique de l'atome
          printf("%7d|",recuperer(E->T[i][j],1)->NumAtom);}
          printf("\n");
    //puis on affiche le symbole
           for(j=0;j<18;j++){
                if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
                else
          printf("%7s|",recuperer(E->T[i][j],1)->Symb);}
           printf("\n");
        //et finalement on affiche la masse atomique
          for(j=0;j<18;j++){
               if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
          else
          printf(" %6.2f|",recuperer(E->T[i][j],1)->MassAtom);}
           printf("\n");
          for(j=0;j<18;j++){
               if(listeTaille(recuperer(E,i,j))==0)
                printf("        ");
          else
          printf("%7.c|",recuperer(E->T[i][j],1)->Etat);}
           printf("\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
           }
   //Ici on affiche les liste qui contient 15 atomes
         printf("\nLanthanides : ");
         for(i=1;i<=15;i++){
          printf("%8d",recuperer(E->T[5][2],i)->NumAtom);}
          printf("\n              ");
          for(i=1;i<=15;i++){
         printf("%8s",recuperer(E->T[5][2],i)->Symb);}
         printf("\n                  ");
                   for(i=1;i<=15;i++){
         printf("%6.2f  ",recuperer(E->T[5][2],i)->MassAtom);}
         printf("\n              ");
          for(i=1;i<=15;i++){
         printf("%8.c",recuperer(E->T[5][2],i)->Etat);}
        printf("\n\nAnticides : ");
        for(i=1;i<=15;i++){
          printf("%8d",recuperer(E->T[6][2],i)->NumAtom);}
          printf("\n            ");
          for(i=1;i<=15;i++){
         printf("%8s",recuperer(E->T[6][2],i)->Symb);}
         printf("\n               ");
          for(i=1;i<=15;i++){
         printf("%6.2f  ",recuperer(E->T[6][2],i)->MassAtom);}
          printf("\n            ");
          for(i=1;i<=15;i++){
         printf("%8.c",recuperer(E->T[6][2],i)->Etat);}
}

/*Retourne la masse atomiue du molecule de caféine*/
double M_C8H10N4O2 (ELEMENT_TAB E)
{ //chaque fois on calcue le mass atomique de chaque atome du caféine puis on la multiple avec sa coifficient
  return ((Ar(E,"C")*8)+(Ar(E,"H")*10)+(Ar(E,"N")*4)+(Ar(E,"O")*2));
}
/*Retoune le nombre du mole de caféine dans 10g de caféine*/
 double n_C8H10N4O2()
 { /*Aprés avoir calculer la masse atomique de caférine on le dévise sure 10 pour avoir le nombre du mole car n=m/M avec
     n:nombre de mole , m:masse, M:masse molaire*/
   return (10/M_C8H10N4O2(E));
 }
/*Retourne la masse molaire d'une molecule donnée*/
  double M (ELEMENT_TAB E, char * molecule)
  { int x=0,h=0;
  char *p=molecule,S[50];
   float z=0,w=0,y=0;
      strcpy(S, "\0");// On fixe tous les champs de la chaine à '\0'
        while(molecule[h]){
        if(isalpha(molecule[h]))/*on vérifie si le caractére est une caractére alphabétique à l'aide de fonction isalpha qui retourne 1
        si la caractére est alphabétique*/
         {
             strncat(S,p,1);}//on faire la concaténation de ce caractére alphabétique avec
          else if(isdigit(molecule[h]))//si non si le caractére est numérique
          {  //On calule la masse molaire de symbole dans le tableau précédent
              w=Ar(E,S);
          strcpy(S, "\0");// On fixe tous les champs de la chaine à '\0' encore une fois
           x=atoi(p);/*ici on transforme le nombre déja trouve on un entier à l'aide du focntion prédéfinis atoi qui transforme un
           chaine de caractére en un entier*/
           z=w*x;
           y+=z;
           }
           *p++;//on incrémente le pointeur d'aide sur la chaine donnée
           h++;}
         return y;
  }
/*Menu qui affiche les foncions de notre programme*/
 int Menu()
{ Color(11, 0);
int Choix;
printf("\n                                                *********************MENU*************************\n\n");
printf("                                                  1- Remplissage du tableau automatique : \n\n");
printf("                                                  2- Remplissage du tableau manuelle : \n\n");
printf("                                                  3- Affichage de tableau periodique :\n\n");
printf("                                                  4- Affichage simple des atomes du tableau :\n\n");
printf("                                                  5- Affichage des atomes Liquide :\n\n");
printf("                                                  6- Affichage des atomes solide :\n\n");
printf("                                                  7- Affichage des atomes gazeux :\n\n");
printf("                                                  8- Affichage des atomes lourdes :\n\n");
printf("                                                  9- Affichage des atomes Radioactifs :\n\n");
printf("                                                  10- Affichage des atomes instables :\n\n");
printf("                                                  11- La masse atomique d'un atome :\n\n");
printf("                                                  12- La masse molaire de la molecule de cafeine :\n\n");
printf("                                                  13- le nombre de moles de cafeine dans 10,0 g de cafein :\n\n");
printf("                                                  14- La masse atomique d'une molecule :\n\n");
printf("                                                  15- Radioactivite :\n\n");
printf("                                                  16- Verifier l'appartenance d'un atome:\n\n");
printf("                                                  0- Quitter\n");
do
{  //lecture du choix
    printf("Votre choix : ");
    scanf("%d",&Choix);
    fflush(stdin);
}
while(Choix<0 || Choix>16);
    return Choix;
}

//Partie 2//


/*Recherche l'atome coreespend à l'élement donné*/
ELEMENT ar2( int m)
 {
int i=0,j=0,trouve=0;
/*Parcour du tableau*/
while ((i<=6)&&(trouve==0))
{
   j=0;
    while ((j<=17)&&(trouve==0))
    {
        if (recuperer(E->T[i][j],1)->NumAtom==m)
            {trouve=1;//si on trouve l'atome correspendante
          return(recuperer(E->T[i][j],1));}//on retoune l'atome
        else
            j++;
    }
    i++;
}
if (trouve==0)
{ //si on le trouve pas dans les case des matrice d'un seul atome on cherche dans les listes de 15 atomes
    i=1;
    while ((i<=15)&&(trouve==0))
    {
        if (recuperer(E->T[5][2],i)->NumAtom==m)
            {trouve=1;
          return(recuperer(E->T[5][2],i));
             }
        else
            i++;
    }
}
if (trouve==0)
{
     i=1;
    while ((i<=15)&&(trouve==0))
    {
        if (recuperer(E->T[6][2],i)->NumAtom==m)
           {
                trouve=1;
return(recuperer(E->T[6][2],i));
           }
        else
            i++;
    }
}
if (trouve==0)
return (elementCreer());//si non on retounrne un atome vide
 }
/*Vérifier le type de radeio donnée */
ELEMENT noyauFils (ELEMENT x ,ELEMENT_TAB E, int type_radio)
{
 if (type_radio==1)//alpha
 {
     return (ar2(x->NumAtom-2));
 }
 else if (type_radio==2)//Beta +
    return (ar2(x->NumAtom+1));
 else
    return (ar2(x->NumAtom-1));//Beta -
}
/*Vérifier l'appartenance d'un atome dans une liste*/
int appartien(ELEMENT e, LISTE L)
{
    int i=1,trouve=0;
    while(i<= listeTaille(L) && !trouve)
    {
        if(elementComparer(e,recuperer(L,i))==1)
        trouve=1;
        else i++;
    }
    return trouve;//retourne 1 si l'atome donnée est dans la liste 0 si non
}

/*Retourne une liste contient les atomes liquide*/
LISTE Liquide(ELEMENT_TAB E){
int i,j,k,p=1;
LISTE Ll=listeCreer();//Création de la liste des atomes gazeux
//Parcour du tableau
for(i=0;i<7;i++){
        for(j=0;j<18;j++){

                if(estVide(E->T[i][j])==0){ //si la liste est vide ne faire pas les testes
                for(k=1;k<=listeTaille(E->T[i][j]);k++){
                     if (recuperer(E->T[i][j],k)->Etat=='L')
                    //Si l'atome est en etat liquide il va l'inserer dans la liste
                {inserer(Ll,recuperer(E->T[i][j],k),p);
                p++;}//toutfois on ajout un atome on incrémente la position
               }}}}
return Ll;//retourne la liste des atomes liquide
}
/*Retourne une liste contient les atomes solide*/
LISTE Solide(ELEMENT_TAB E){
int i,j,k,p=1;
LISTE Ls=listeCreer();//Création de la liste des atomes solides
//Parcour du tableau
for(i=0;i<7;i++){
        for(j=0;j<18;j++){

                if(estVide(E->T[i][j])==0){ //si la liste est vide ne faire pas les testes
                for(k=1;k<=listeTaille(E->T[i][j]);k++){
                     if (recuperer(E->T[i][j],k)->Etat=='S')
                    //Si l'atome est en etat gazeux il va l'inserer dans la liste
                {inserer(Ls,recuperer(E->T[i][j],k),p);
                p++;}//toutfois on ajout un atome on incrémente la position
               }}}}
return Ls;//retourne la liste des atomes solide
}
int  main()
{   Color(15, 0);
    printf("                                                  ***PROJET ALGORITHMIQUE ET PROGRAMMATION II***\n");
    int n,i,j,k;
     char s[5],C[5],Choix;
     ELEMENT e;
     FILE *F=NULL;
     //création du tableau
     E=tabCreer();
     LISTE LT=listeCreer();
     inserer(E,LT,0,0);
     do
    { Choix=Menu();
    fflush(stdin);
    switch(Choix)
    {  case 1:
        Color(15, 0);
          F=fopen("Atomes.txt","r");
         if(F != NULL){
             for(i=0;i<7;i++){
        for(j=0;j<18;j++){
            L=listeCreer();
            fscanf(F,"%d",&n);
            for(k=1;k<=n;k++){
        e=elementCreer();
        fscanf(F,"%d %s %f %c",&e->NumAtom,&e->Symb,&e->MassAtom,&e->Etat);
        inserer(L,e,k);
    }
       inserer(E,L,i,j);
        }
    }}
    printf("\nRemplissage automatique terminee.\n");
    break;
        case 2 :
            Color(15, 0);
    for(i=0;i<7;i++){
        for(j=0;j<18;j++){
            L=listeCreer();
            printf("T[%d][%d] : ",i+1,j+1);
            do{
            printf("Donner la taille de la liste :\n");

            scanf("%i",&n);
            }
            while(n<0);
        for(k=1;k<=n;k++){
        e=elementCreer();
        elementLire(&e);
        inserer(L,e,k);
    }
       inserer(E,L,i,j);
        }
    }
     break;
        case 3:
    if(listeTaille(E->T[0][0])!=0)
    {Color(15, 0);
    printf("\nLes atomes dans le tableau :\n\n");
    affichage(E);}
    else
    printf("\nil faut remplir le tableau d'abord!!!");
    break;
        case 4:
    if(listeTaille(E->T[0][0])!=0)
    {  Color(15, 0);
        printf("Les atomes sont les tableau :\n");
        tabAfficher(E);}
      else
        printf("\nil faut remplir le tableau d'abord!!!");
        break;
    case 5 :
    if(listeTaille(E->T[0][0])!=0)
    {Color(15, 0);
    printf("\n\nLes atomes liquide : \n\n");
    if(listeTaille(Liquide(E))==0)
        printf("NULL\n");
    else {printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
        listeAfficher(Liquide(E));}}
       else printf("\nil faut remplir le tableau d'abord!!!");
        break;
        case 6 :
    if(listeTaille(E->T[0][0])!=0)
    { Color(15, 0);
    printf("les atomes Solide : \n");
    if(listeTaille(Solide(E))==0)
         printf("NULL\n");
    else{ printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
        listeAfficher(Solide(E));}}
    else printf("\nil faut remplir le tableau d'abord!!!");
        break;
        case 7 :
    if(listeTaille(E->T[0][0])!=0)
    {Color(15, 0);
    printf("Les atomes gazeux :\n");
     if(listeTaille(Gaz(E))==0)
         printf("NULL\n");
    else {printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
    listeAfficher(Gaz(E));}}
 else printf("\nil faut remplir le tableau d'abord!!!");
    break;
    case 8 :
        if(listeTaille(E->T[0][0])!=0)
    {Color(15, 0);
    printf("Les atomes lourdes :\n");
     if(listeTaille(Lourds(E))==0)
         printf("NULL\n");
    else {printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
    listeAfficher(Lourds(E));}}
 else printf("\nil faut remplir le tableau d'abord!!!");
    break;
    case 9 :
        if(listeTaille(E->T[0][0])!=0)
    {Color(15, 0);
    printf("Les atomes Radioactifs :\n");
     if(listeTaille(Radioactifs(E))==0)
         printf("NULL\n");
    else {printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
    listeAfficher(Radioactifs(E));}}
 else printf("\nil faut remplir le tableau d'abord!!!");
    break;
    case 10 :
        if(listeTaille(E->T[0][0])!=0)
    {Color(15, 0);
    printf("Les atomes instables :\n");
     if(listeTaille(Instables(E))==0)
         printf("NULL\n");
    else {printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
    listeAfficher(Instables(E));}}
 else printf("\nil faut remplir le tableau d'abord!!!");
    break;
    case 11 :
        if(listeTaille(E->T[0][0])!=0)
    {Color(15, 0);
    printf("\nSaisie un symbole : ");
    scanf("%s",s);
    if(Ar(E,s)==0)
        printf("\nCe symbole n'exite pas dans le tableau periodique!\n");
    else
    printf("\nLa masse atomique de '%s' est : %.4f\n",s,Ar(E,s));}
   else printf("\nil faut remplir le tableau d'abord!!!");
    break;
    case 12:
        Color(15, 0);
  if(listeTaille(E->T[0][0])!=0)
    printf("\nLa masse molaire de la molecule de cafeine : %.4f g/mol.\n",M_C8H10N4O2(E));
   else printf("\nil faut remplir le tableau d'abord!!!");
    break;
    case 13 :
if(listeTaille(E->T[0][0])!=0)
{Color(15, 0);
    printf("\nle nombre de moles de cafeine dans 10,0 g de cafeine : %.4f mol.\n",n_C8H10N4O2());}
 else printf("\nil faut remplir le tableau d'abord!!!");
    break;
    case 14 :
    if(listeTaille(E->T[0][0])!=0){
            Color(15, 0);
     printf("\n\nsaisie une molcule : ");
     scanf("%s",C);
     if(M(E,C)==0)
        printf("\nCette molecule n'exite pas!");
        else
     printf("\nLa masse molaire de '%s'  est : %.4f g/mol.\n",C,M(E,C));
         }
  else printf("\nil faut remplir le tableau d'abord!!!");
         break;
     case 15 :
      {  if(listeTaille(E->T[0][0])!=0){
          Color(15, 0);
          ELEMENT a=elementCreer();
      int type_radio;
      elementLire(&a);
      if(appartien(a,Radioactifs(E))==0)
        printf("\ncette atome n'est pas une atome radioactife!\n");
      else {
      do{
      printf("Saisie le type de radio :\n");
      printf("\n1-Radioactivite alpha :\n2-Radioactivite beta- :\n3-Radioactivite beta+ :\n");
      scanf("%d",&type_radio);}
      while(type_radio<0 && type_radio>3);
      printf("\n");
      printf(" le noyau fils issu de la desintegration du noyau pere '%s' :\n",a->Symb);
     printf("\n Num atomique             Symbole         Mass atomique        Etat\n");
      elementAfficher(noyauFils(a,E,type_radio));}}
     else printf("\nil faut remplir le tableau d'abord!!!");}
        break;
        case 16 :
      {  if(listeTaille(E->T[0][0])!=0){
          Color(15, 0);
          e=elementCreer();
        elementLire(&e);
        if(appartien(e,Gaz(E))==1)
        printf("\nCet atome est un atome gazeux!\n");
        else if(appartien(e,Lourds(E)))
            printf("\nCet atome est un atome lourde!\n");
        else if(appartien(e,Radioactifs(E)))
            printf("\nCet atome est un atome radioactif!\n");
            else if (appartien(e,Instables(E)))
        printf("\nCet atome est un atome instable!\n");
        else if(appartien(e,Liquide(E)))
            printf("\nCet atome est un atome liquide!\n");
         else if(appartien(e,Solide(E)))
            printf("\nCet atome est un atome solide!\n");
        else printf("\nCet atome n'existe pas!");}
    else printf("\nil faut remplir le tableau d'abord!!!");}
        break;
    }}
        while(Choix !=0);
    Color(15, 0);
    printf("                             Merci! :3");
return 0 ;
}
