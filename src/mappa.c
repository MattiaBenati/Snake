#include <stdlib.h>
#include "mappa.h"
#include "grafica.h"

// creazione della mappa di gioco
extern int **CreazioneMappa() {
    int righe = Y_PANNELLO;
    int colonne = X_PANNELLO;

    int **mappa = calloc(righe, sizeof(int *));

    for (int i = 0; i < righe; ++i)
        mappa[i] = calloc(colonne, sizeof(int));

    // muro il alto e in basso
    for (int i = 0; i < colonne; ++i) {
        mappa[0][i] = MURO;
        mappa[1][i] = MURO;

        mappa[righe - 1][i] = MURO;
        mappa[righe - 2][i] = MURO;
    }

    // muro a sinistra e a destra
    for (int i = 0; i < righe; ++i) {
        mappa[i][0] = MURO;
        mappa[i][1] = MURO;

        mappa[i][colonne - 1] = MURO;
        mappa[i][colonne - 2] = MURO;
    }

    return mappa;
}

// eliminazione della mappa di gioco
extern void EliminazioneMappa(int **mappa) {
    int righe = Y_PANNELLO;

    for (int i = 0; i < righe; ++i)
        free(mappa[i]);

    free(mappa);
}
