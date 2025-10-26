#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>		// Sleep()
#include "serpente.h"
#include "grafica.h"
#include "mappa.h"

// creazione del serpente
extern Coordinate *CreazioneSerpente(int **mappa, int lunghezza) {
    Coordinate *serpente = calloc(X_PANNELLO * Y_PANNELLO, sizeof(Coordinate));

    serpente[0].x = X_PANNELLO / 2;
    serpente[0].y = Y_PANNELLO / 2;

    serpente[1].x = serpente[0].x + 1;
    serpente[1].y = serpente[0].y;

    GoToXY(serpente[0].x, serpente[0].y);
    printf("O");

    GoToXY(serpente[1].x, serpente[1].y);
    printf("+");

    // far sapere alla mappa la posizione del serpente
    for (int i = 0; i < lunghezza; ++i)
        mappa[serpente[i].y][serpente[i].x] = SERPENTE;

    return serpente;
}

// verifica se due direzioni sono opposte tra loro
static int DirezioneOpposta(int input1, int input2) {
    if (input1 == SINISTRA && input2 == DESTRA)
        return 1;
    if (input1 == DESTRA && input2 == SINISTRA)
        return 1;
    if (input1 == SU && input2 == GIU)
        return 1;
    if (input1 == GIU && input2 == SU)
        return 1;

    return 0;
}

// aggiornamento della direzione del serpente
static void AggiornamentoDirezione(Coordinate *serpente, Coordinate *precedente, int direzione) {
    // direzione verso l'altro
    if (direzione == SU) {
        serpente[0].x = precedente[0].x;
        serpente[0].y = precedente[0].y - 1;
    }

    // direzione verso il basso
    else if (direzione == GIU) {
        serpente[0].x = precedente[0].x;
        serpente[0].y = precedente[0].y + 1;
    }

    // direzione verso destra
    else if (direzione == DESTRA) {
        serpente[0].x = precedente[0].x + 1;
        serpente[0].y = precedente[0].y;
    }

    // direzione verso sinistra
    else if (direzione == SINISTRA) {
        serpente[0].x = precedente[0].x - 1;
        serpente[0].y = precedente[0].y;
    }
}

// aggiornamento del serpente
extern void AggiornamentoSerpente(Coordinate *serpente, int *lunghezza, int *direzione, int input,
                                  int **mappa, int *oggetto) {
    Coordinate precedente[X_PANNELLO * Y_PANNELLO];

    for (int i = 0; i < *lunghezza; ++i) {
        precedente[i].x = serpente[i].x;
        precedente[i].y = serpente[i].y;
    }

    if (input != EXIT && DirezioneOpposta(*direzione, input) == false)
        *direzione = input;

    AggiornamentoDirezione(serpente, precedente, *direzione);

    // posizione occupata dal muro o coda del serpente
    if (mappa[serpente[0].y][serpente[0].x] < LIBERO) {
        *oggetto = -1;
        return;
    }

    // posizione occupata dal cibo
    if (mappa[serpente[0].y][serpente[0].x] == CIBO) {
        *lunghezza += 1;
        *oggetto = CIBO;
    }

    // posizione libera
    else {
        mappa[serpente[*lunghezza - 1].y][serpente[*lunghezza - 1].x] = LIBERO;
        *oggetto = LIBERO;

        GoToXY(serpente[*lunghezza - 1].x, serpente[*lunghezza - 1].y);
        printf(" ");
    }

    // aggiornamento delle posizioni del serpente
    for (int i = 1; i < *lunghezza; ++i) {
        serpente[i].x = precedente[i - 1].x;
        serpente[i].y = precedente[i - 1].y;
    }

    GoToXY(serpente[1].x, serpente[1].y);
    printf("+");

    GoToXY(serpente[0].x, serpente[0].y);
    printf("O");

    // far sapere alla mappa la posizione del serpente
    for (int i = 0; i < *lunghezza; ++i)
        mappa[serpente[i].y][serpente[i].x] = SERPENTE;

    Sleep(65);
}

// generazione posizione casuale del cibo
extern void GenerazioneCibo(int **mappa, int *cibi) {
    int x, y;

    do {
        x = rand() % X_PANNELLO;
        y = rand() % Y_PANNELLO;
    } while (mappa[y][x] != LIBERO);

    mappa[y][x] = CIBO;
    *cibi += 1;

    GoToXY(x, y);
    printf("%c", 5);
}
