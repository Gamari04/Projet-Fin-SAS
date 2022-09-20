#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//Nous allons commencer par créer nos types de données pour les médicaments
struct Medicine{
       char Code;
       char Nom[100];
       int Quantite;
       float Prix;
};
//fonction permet d'ajouter un nouveau médicament: un médicament est identifié par : son code, son nom, sa quantité, et son prix
int comp=0;
void AddNewMedicine(struct Medicine medicine[100]){
        printf("entrer le Code du medicament:\t");
        scanf("%s",&medicine[comp].Code);
        printf("entrer le Nom du medicament:\t");
        scanf("%s",medicine[comp].Nom);
        printf("entrer la Quantite du medicament:\t");
        scanf("%d",&medicine[comp].Quantite);
        printf("entrer le Prix du medicament:\t");
        scanf("%f",&medicine[comp].Prix);
        comp++;
}
//cette fonction permet de lister tous les médicaments selon l’ordre alphabétique  croissant du nom.
void TriMedicineAlphabetique(struct Medicine medicine[100], int n){
    int i,j;
    struct Medicine m;
      for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
        if(strcmp(medicine[i].Nom,medicine[j].Nom)>0){
             m=medicine[i];
             medicine[i]=medicine[j];
             medicine[j]=m;
             break;
        }
       }
      }
       printf("____________liste de tous les produits selon l’ordre alphabetique  croissant du nom :_________\n");
       AfficherNewMedicine(medicine);
}
// cette fonction permet de lister tous les médicaments selon l’ordre  décroissant du prix.
void TriMedicinePrix(struct Medicine medicine[100],int y){
    int i,j;
    struct Medicine a;
      for(int i=0;i<y-1;i++){
        for(int j=i+1;j<y;j++){
        if(medicine[i].Prix < medicine[j].Prix){
            a=medicine[i];
            medicine[i]=medicine[j];
            medicine[j]=a;
            break;
        }
      }
    }
      printf("_________liste de tous les produits selon l’ordre  decroissant du prix :__________\n");
      AfficherNewMedicine(medicine);
}
//cette fonction permet d'afficher les nouveaux médicaments qui sont identifié par : son code, son nom, sa quantité, et son prix
void AfficherNewMedicine(struct Medicine medicine[100]){
    for(int i=0;i<comp;i++){
        printf("entrer le Code du medicament: %s\n",medicine[i].Code);
        printf("entrer le Nom du medicament: %s\n",medicine[i].Nom);
        printf("entrer la Quantite du medicament: %d\n",medicine[i].Quantite);
        printf("entrer le Prix du medicament: %.2f\n",medicine[i].Prix);

        }
}
//cette fonction permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à déduire
void BuyMedicine(struct Medicine medicine[100]){
    char code[100];
    int quantite;
    printf("entrer le code du medicament: \t");
    scanf("%s",code);
     for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            printf("le Nom du medicament est : %s\n");
            printf("la Quantite du medicament est : %d\n");
            printf("le Prix du medicament est : %d\n");
        printf("entrer la quantite a deduire du medicament: \t");
        scanf("%d",&quantite);
        medicine[i].Quantite = medicine[i].Quantite - quantite;
        printf("la quantite a deduire est : %d\n");
        printf("le prix TTC du medicament est : %f \n",medicine[i].Prix*1,15);
    }else{
        printf("ce code n'existe pas\n");
     }
    }
}
//cette fonction permet de rechercher les produits Par :Code et Quantité.
void SearchMedicine(struct Medicine medicine [100]){
    char code[20];
    int quantite;
    printf("entrer le Code du medicament: \t");
    scanf("%s",code);
    for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            printf("le Nom du medicament est : %s\n");
            printf("la Quantite du medicament est : %d\n");
            printf("le Prix du medicament est : %d\n");
    }else{
         printf("ce Code n'existe pas\n");
    }
    }
    printf("entrer la Quantite du medicament: \t");
    scanf("%d",&quantite);
    for(int i=0;i<comp;i++){
        if(medicine[i].Quantite == &quantite){
           printf("les produits qui ont la meme quantite sont : %d\n");
     }else{
         printf("cette quantite n'existe pas\n");
     }
    }
}
//cette fonction (etat des stocks) permet d’afficher les produits dont la quantité est inférieure à 3.
void DisplayStockStatus(struct Medicine medicine [100]){
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
void AddToStock(struct Medicine medicine [100]){
    char code[80];
    int quantite;
    printf("entrer le code du medicament: \t");
    scanf("%s",code);
     for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            printf("le Nom du medicament est : %s\n");
            printf("la Quantite du medicament est : %d\n");
            printf("le Prix du medicament est : %d\n");
        printf("entrer la quantite ajouter du medicament: \t");
        scanf("%d",&quantite);
        medicine[i].Quantite = medicine[i].Quantite + quantite;
        printf("le Nom du medicament est : %s\n");
        printf("la Quantite du medicament est : %d\n");
        printf("le Prix du medicament est : %d\n");

   }else{
      printf("ce code n'existe pas \n");
   }
 }
}
//cette fonction permet de supprimer le médicament par son code
void RemoveMedicine(struct Medicine medicine [100]){
    char code[100];
    int indice;
    printf("entrer le code du medicament: \t");
    scanf("%s",code);
     for(int i=0;i<comp;i++){
        if(strcmp(medicine[i].Code,code)==0){
            printf("le Nom du medicament est : %s\n");
            printf("la Quantite du medicament est : %d\n");
            printf("le Prix du medicament est : %d\n");
     indice=i;
    }
     }
     for(int i=indice;i<comp;i++){
            strcpy(medicine[indice].Code,medicine[indice+1].Code);
            strcpy(medicine[indice].Nom,medicine[indice+1].Nom);
            (medicine[indice].Quantite,medicine[indice+1].Quantite);
            (medicine[indice].Prix,medicine[indice+1].Prix);
            comp--;
     }
}
int main()//Début du main()
{
    struct Medicine medicine[100];
    int nbr;
    printf("entrer le nombre des medicaments :\t");
    scanf("%d",&nbr);
     printf("______________________________\n");
    for(int i=0;i<nbr;i++){
        AddNewMedicine(medicine);
         printf("______________________________\n");
    }
        TriMedicineAlphabetique(medicine, nbr);
        printf("____________________________\n");
        TriMedicinePrix(medicine, nbr);
        printf("____________________________\n");

    return 0;
}//Fin du main()
