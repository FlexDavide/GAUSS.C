#include "solver.h"
#include <math.h>

int solve_gaussian(Matrice* mat, double* solution){
    int n=mat->num_righe;
    // Metto l'elemento maggiore sulla diagonale
    for(int k=0; k< n; k++){
        int max_row=k;
        for(int i=k; i< n; i++){
            //Trova l'indice della riga con il valore massimo in modulo nella colonna k
            if(fabs(mat->data[i][k]) > fabs(mat->data[max_row][k])){
                max_row=i;
            }
        }
        //Scambio delle righe (se necessario)
        if (max_row != k) {
            double *temp = mat->data[k];
            mat->data[k] = mat->data[max_row];
            mat->data[max_row] = temp;
        }

        // Azzerro sotto i pivot
        for(int i=k+1; i<n;i++){
            double fatt= mat->data[i][k]/mat->data[k][k];
            for(int j=k; j<mat->num_colonne; j++){
                mat->data[i][j]-= mat->data[k][j]*fatt;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
            double sum = mat->data[i][n]; // Termine noto della riga i
            
            // Sottrai i contributi delle incognite già note
            for (int j = i + 1; j < n; j++) {
                sum -= mat->data[i][j] * solution[j];
            }
            
            // Ricava l'incognita corrente dividendo per il pivot sulla diagonale
            solution[i] = sum / mat->data[i][i];
        }
    return 0;
}