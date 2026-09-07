#include "matrix.h"

Matrice* creaMatrice(int righe, int colonne){
    Matrice* matPtr= malloc(sizeof(Matrice));
    //alloca le righe
    matPtr->data= malloc(righe*sizeof(double*)); 

    // alloca le colonne
    for(int i=0; i<righe; i++){
        matPtr->data[i]= malloc(colonne*sizeof(double));
    }
    matPtr->num_colonne=colonne;
    matPtr->num_righe=righe;
    return matPtr;
}

int popolaDaFile(FILE* fin, Matrice* mat){
    if(fin==NULL){
        return 1;
    }
    for(int i=0; i< mat->num_righe;i++){
        for(int j=0; j<mat->num_colonne; j++){
            fscanf(fin, "%lf", &mat->data[i][j]);
        }
    }
    return 0;
}

void distruggiMatrice(Matrice* mat){
    if(mat==NULL){
        return;
    }
    for(int i=0; i<mat->num_righe; i++){
        free(mat->data[i]);
    }

    free(mat->data);
    free(mat);
}

void stampaMatrice(Matrice* mat){
    for(int i=0; i< mat->num_righe; i++){
        for(int j=0; j<mat->num_colonne; j++){
            printf("%8.3lf", mat->data[i][j]);
        }
        printf("\n");
    }
}