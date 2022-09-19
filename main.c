#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Ajouter un nouveau médicament: un médicament est identifié par : son code, son nom, sa quantité, et son prix.
struct Medicine{
       int Code;
       char Nom[100];
       int Quantite;
       float Prix;
};
int comp=0;
void AddNewMedicine(struct Medicine medicine[100]){
        printf("entrer le Code du medicament:\t");
        scanf("%d",&medicine[comp].Code);
        printf("entrer le Nom du medicament:\t");
        scanf("%s",medicine[comp].Nom);
        printf("entrer la Quantite du medicament:\t");
        scanf("%d",&medicine[comp].Quantite);
        printf("entrer le Prix du medicament:\t");
        scanf("%f",&medicine[comp].Prix);
        comp++;
}
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
      AfficherNewMedicine(medicine);
}
void TriMedicinePrix(struct Medicine medicine[100]){

}
void AfficherNewMedicine(struct Medicine medicine[100]){
    for(int i=0;i<comp;i++){
            printf("entrer le Code du medicament: %d\n",medicine[i].Code);
        printf("entrer le Nom du medicament: %s\n",medicine[i].Nom);
        printf("entrer la Quantite du medicament: %d\n",medicine[i].Quantite);
        printf("entrer le Prix du medicament: %.2f\n",medicine[i].Prix);

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
     AfficherNewMedicine(medicine);
    return 0;

}//Fin du main()
