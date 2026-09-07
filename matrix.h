#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int num_righe;
    int num_colonne;
    double **data;
}Matrice;



Matrice* creaMatrice( int righe, int colonne);

int popolaDaFile(FILE* fin, Matrice* mat);

void distruggiMatrice(Matrice* mat);

void stampaMatrice(Matrice* mat);

#endif