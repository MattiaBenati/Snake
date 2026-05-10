#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "gioco.h"
#include "input.h"
#include "grafica.h"
#include "mappa.h"
#include "serpente.h"

void InizializzazioneGioco(int ***mappa, Coordinate **serpente, int *lunghezza, int *cibi) {
    *mappa = CreazioneMappa();
    *serpente = CreazioneSerpente(*mappa, *lunghezza);
    GenerazioneCibo(*mappa, cibi, *lunghezza);
}

void LoopGioco(Coordinate *serpente, int *lunghezza, int *direzione, int **mappa, int *cibi) {
    do {
        AggiornamentoSerpente(serpente, lunghezza, direzione, input, mappa, &oggetto);

        if (*lunghezza >= CELLE_GIOCABILI)
            break;

        if (oggetto == CIBO)
            GenerazioneCibo(mappa, cibi, *lunghezza);

    } while (oggetto >= 0 && input != EXIT);
}

void FineGioco(int lunghezza) {
    giocoAttivo = 0;
    Sleep(100);

    BordiPannelloEsito();

    GoToXY(X_PANNELLO / 2 - 10, Y_PANNELLO / 2 + 1);
    printf("Il tuo punteggio e' %d", lunghezza - 1);

    GoToXY(X_PANNELLO / 2 - 5, Y_PANNELLO / 2 - 1);

    if (lunghezza >= CELLE_GIOCABILI)
        printf("HAI VINTO!");
    else
        printf("GAME OVER!");

    _getch();
}