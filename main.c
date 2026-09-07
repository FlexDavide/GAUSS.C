#include "solver.h"
#include "matrix.h"

int main(int argc, char* argv[]){
    if(argc<2){
        printf("Mancante file d'ingresso");
        return 1;
    }

    FILE* fin= fopen(argv[1], "r");
    
    char buffer[256]; // La dimensione non importa 
    int contatore_righe = 0;
    int nuova_riga = 1; // Flag per capire se stiamo iniziando una nuova riga

    while (fgets(buffer, sizeof(buffer), fin) != NULL) {
        // Se il flag è a 1, questa è una nuova riga effettiva nel file
        if (nuova_riga) {
            contatore_righe++;
            nuova_riga = 0; // Resetta il flag per i pezzi successivi della stessa riga
        }
        // Se il pezzo appena letto contiene '\n'
        if (strchr(buffer, '\n') != NULL) {
            nuova_riga = 1;
        }
    }
    rewind(fin);
    int righe=contatore_righe;
    int colonne= righe+1;

    Matrice* mat= creaMatrice(righe, colonne);
    int control=popolaDaFile(fin,mat);
    if(control==1){
        printf("Errore compilazione matrice");
        return 2;
    }
    fclose(fin);

    // Risolviamo il sistema lineare
    double* solution = (double*)malloc(righe * sizeof(double));
    if (!solution) {
        printf("Errore di allocazione memoria per la soluzione\n");
        distruggiMatrice(mat);
        return 4;
    }

    int res = solve_gaussian(mat, solution);
    if (res != 0) {
        printf("Errore: la matrice è singolare o quasi-singolare.\n");
        distruggiMatrice(mat);
        free(solution);
        return 5;
    }

    // Stampiamo il vettore delle soluzioni
    printf("Soluzione del sistema:\n");
    for (int i = 0; i < righe; i++) {
        printf("x[%d] = %lf\n", i, solution[i]);
    }

    char action;
    printf("\nInserire azione:\n D (distruggi matrice), \n S (stampa matrice): ");
    scanf(" %c", &action);

    if(action == 'D'){
        distruggiMatrice(mat);
    } else if(action == 'S'){
        stampaMatrice(mat);
        distruggiMatrice(mat);
    } else {
        printf("Errore, azione non disponibile\n");
        distruggiMatrice(mat);
        free(solution);
        return 3;
    }

    free(solution);
    return 0;
}