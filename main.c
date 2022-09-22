#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
/******************structures************************************/

//Nous allons commencer par créer nos types de données pour les médicaments
struct Medicine{
       char Code[100];
       char Nom[100];
       int Quantite;
       float Prix;
};
/******************global variables*****************************/
   //struct Achat Achat[100];
   struct Medicine medicine[100];
   struct Medicine m[1];
   int comp=0;
   /*******************Fonctions***********************************/
   void cleanConsole()
    {
    system("cls");
    }
//fonction permet d'ajouter un nouveau médicament: un médicament est identifié par : son code, son nom, sa quantité, et son prix
   void AddNewMedicine(){
      int nbr;
      printf("entrer le nombre des medicaments :\t");
      scanf("%d",&nbr);
    for(int i=0;i<nbr;i++){
        printf("entrer les donnees du medicament %d\n\n",i+1);
        printf("entrer le Code du medicament:\t");
        scanf("%s",medicine[i].Code);
        printf("entrer le Nom du medicament:\t");
        scanf("%s",medicine[i].Nom);
        printf("entrer la Quantite du medicament:\t");
        scanf("%d",&medicine[i].Quantite);
        printf("entrer le Prix du medicament:\t");
        scanf("%f",&medicine[i].Prix);
        comp++;
   }
        MENU();
}

//cette fonction permet de lister tous les médicaments selon l’ordre alphabétique  croissant du nom.
  void TriMedicineAlphabetique(){
    int i,j;

      for(int i=0;i<comp;i++){
        for(int j=i+1;j<comp;j++){
        if(strcmp(medicine[i].Nom,medicine[j].Nom)>0){
             m[0]=medicine[i];
             medicine[i]=medicine[j];
             medicine[j]=m[0];

        }
       }
      }
       printf("____________liste de tous les produits selon l’ordre alphabetique  croissant du nom :_________\n");
       for(int i=0;i<comp;i++){
      AfficherNewMedicine(i);}
}
// cette fonction permet de lister tous les médicaments selon l’ordre  décroissant du prix.
  void TriMedicinePrix(){
    int i,j;

      for(int i=0;i<comp;i++){
        for(int j=i+1;j<comp;j++){
        if(medicine[i].Prix < medicine[j].Prix){
             m[0]=medicine[i];
             medicine[i]=medicine[j];
             medicine[j]=m[0];

        }
      }
    }
      printf("_________liste de tous les produits selon l’ordre  decroissant du prix :__________\n");
      for(int i=0;i<comp;i++){
      AfficherNewMedicine(i);}
}
//cette fonction permet d'afficher les nouveaux médicaments qui sont identifié par : son code, son nom, sa quantité, et son prix
    void AfficherNewMedicine(int i){

        printf(" Code du medicament: %s\n",medicine[i].Code);
        printf("Nom du medicament: %s\n",medicine[i].Nom);
        printf("Quantite du medicament: %d\n",medicine[i].Quantite);
        printf("Prix du medicament: %.2f\n",medicine[i].Prix);

}
//cette fonction permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à déduire
void BuyMedicine(){
    char code[100];
    int quantite;
    printf("entrer le code du medicament: \t");
    scanf("%s",code);
     for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            printf("le Nom du medicament est : %s\n",medicine[i].Nom);
            printf("la Quantite du medicament est : %d\n",medicine[i].Quantite);
            printf("le Prix du medicament est : %d\n",medicine[i].Prix);
        printf("entrer la quantite a deduire du medicament: \t");
        scanf("%d",&quantite);
          if(medicine[i].Quantite>quantite){
        medicine[i].Quantite = medicine[i].Quantite - quantite;
          }
        printf("la quantite a deduire est : %d\n");
        printf("le prix TTC du medicament est : %f \n",medicine[i].Prix*1,15);
    }else{
        printf("ce code n'existe pas\n");
     }
    }
}
//cette fonction permet de rechercher les produits Par :Code et Quantité.
void SearchMedicine(){
    char code[20];
    int quantite;
    int trouve = 0;
    printf("entrer le Code du medicament: \t");
    scanf("%s",code);
    printf("%d\n", comp);
    for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            printf("le Nom du medicament est : %s\n",medicine[i].Nom);
            printf("la Quantite du medicament est : %d\n",medicine[i].Prix);
            printf("le Prix du medicament est : %d\n",medicine[i].Quantite);
            trouve = 1;
            break;
        }
    }
    if(trouve == 0) {
        printf("ce Code n'existe pas\n");
    }
    trouve = 0;
    printf("entrer la Quantite du medicament: \t");
    scanf("%d",&quantite);
    for(int i=0;i<comp;i++){
        if(medicine[i].Quantite == &quantite){
           printf("les produits qui ont la meme quantite sont : %d\n", medicine[i].Nom);
           trouve++;
        }
    }
    if(trouve == 0) {
        printf("cette quantite n'existe pas\n");
    }
}
//cette fonction (etat des stocks) permet d’afficher les produits dont la quantité est inférieure à 3.
void StockStatus(){
     for(int i=0;i<comp;i++){
        if(medicine[i].Quantite<3){
            printf("le Nom du medicament est : %s\n",medicine[100].Nom);
            printf("le Code du medicament est : %d\n",medicine[100].Code);
            printf("le Prix du medicament est : %d\n",medicine[100].Prix);
     }else{
         printf("tout les produits ont des quantite superieur a 3\n");
     }
     }

}
//cette fonction (Alimenter le stock) permet de mettre à jour la quantité après avoir introduit
//le code du produit et la quantité à ajouter.
void AddToStock(){
    char code[80];
    int quantite;
    int trouve = 0;
    printf("entrer le code du medicament: \t");
    scanf("%s",code);
     for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            trouve = 1;
            printf("le Nom du medicament est : %s\n",medicine[i].Nom);
            printf("la Quantite du medicament est : %d\n",medicine[i].Quantite);
            printf("le Prix du medicament est : %d\n",medicine[i].Prix);
            printf("entrer la quantite ajouter du medicament: \t");
            scanf("%d",&quantite);
            medicine[i].Quantite = medicine[i].Quantite + quantite;
            printf("nouvel quantite: %d\n", medicine[i].Quantite);
   }
   }
   if(trouve == 0){
        printf("ce code n'existe pas \n");
    }
 }
//cette fonction permet de supprimer le médicament par son code
void RemoveMedicine(){
    char code[100];
    int indice;
    bool trouve = false;
    printf("entrer le code du medicament: \t");
    scanf("%s",code);
     for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            printf("le Nom du medicament est : %s\n",medicine[i].Nom);
            printf("la Quantite du medicament est : %d\n",medicine[i].Quantite);
            printf("le Prix du medicament est : %d\n",medicine[i].Prix);
     indice=i;
            trouve = true;
    }
     }
     if(trouve == true) {
        for(int i=indice;i<comp;i++){
            strcpy(medicine[indice].Code,medicine[indice+1].Code);
            strcpy(medicine[indice].Nom,medicine[indice+1].Nom);
            (medicine[indice].Quantite,medicine[indice+1].Quantite);
            (medicine[indice].Prix,medicine[indice+1].Prix);
        }
        comp--;
     }
}

void backToMenu(){
   int l;
   printf("Appuyer sur un nombre pour retourner au menu : ");scanf("%d",&l);
   system("cls");
   MENU();
}

void MENU(){
        int choix;
        do
       {
            printf("\n            ********************MENU********************");
            printf("\n                      1-/ Ajouter un nouveau medicament");
            printf("\n                      2-/ Lister les medicament");
            printf("\n                      3-/ Ajouter un medicament vendu");
            printf("\n                      4-/ Rechercher les medicament");
            printf("\n                      5-/ Etat du stock");
            printf("\n                      6-/ Alimenter le stock");
            printf("\n                      7-/ Supprimer un medicament");
            printf("\n                      8-/ Statistiques des medicaments");
            printf("\n \t\t\t\tEntrer votre choix :");
            scanf("%d",&choix);
            system("cls");


            printf("\n");


        switch(choix)
        {
            case 1:
            {
                AddNewMedicine();
                backToMenu();
                break;
            }
            case 2:
                Operationlister();
                backToMenu();
                break;
          case 3:
             BuyMedicine();
             backToMenu();
             break;

          case 4:
               SearchMedicine();
               backToMenu();
               break;

          case 5:
              StockStatus();
              backToMenu();
              break;

          case 6:
              AddToStock();
              backToMenu();
              break;

          case 7:
              RemoveMedicine();
              backToMenu();
              break;

        }
        }while(choix>8 || choix<0);
    }

void Operationlister(){
        int choix;
        do
       {
            printf("liste des medicaments : \n");
            printf("\t1--selon le nom : \n");
            printf("\t2--selon l'ordre decroissant du prix : \n");
            printf("\n Entrer votre choix :");
            scanf("%d",&choix);
            system("cls");


            printf("\n");


        switch(choix)
        {
               case 1:
                       TriMedicineAlphabetique();
                       printf("liste des medicaments selon le nom : \n");
                       break;

               case 2:
                       printf("liste des medicaments selon le prix : \n");
                       TriMedicinePrix();
                       break;

}
        }while(choix>2 || choix<1);
    }

    /*
    struct Medicine{
       char Code[100];
       char Nom[100];
       int Quantite;
       float Prix;
};
    struct Medicine medicine[100];

struct Date{int j; int m; int a};
 struct Date date[100];
 */

void main()//Début du main()
{       strcpy(medicine[0].Code, "1");
        strcpy(medicine[0].Nom, "aaa");
        medicine[0].Quantite = 30;
        medicine[0].Prix = 20;

        strcpy(medicine[1].Code, "2");
        strcpy(medicine[1].Nom, "bbb");
        medicine[1].Quantite = 30;
        medicine[1].Prix = 20;

        strcpy(medicine[2].Code, "3");
        strcpy(medicine[2].Nom, "ccc");
        medicine[2].Quantite = 100;
        medicine[2].Prix = 40;
        comp = 3;
        MENU();
}//Fin du main()
