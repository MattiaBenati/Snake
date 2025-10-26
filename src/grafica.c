#include <stdio.h>
#include <windows.h>
#include "grafica.h"

// posizione specifica nello schermo
extern void GoToXY(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// stampa del pannello
extern void BordiPannelloGioco() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_PANNELLO - 4; ++i)
        printf("%c", 205);

    GoToXY(X_PANNELLO - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_PANNELLO - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_PANNELLO - 2, i + 2);
        printf("%c", 186);
    }

    // ultima riga
    GoToXY(1, Y_PANNELLO - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_PANNELLO - 4; ++i)
        printf("%c", 205);

    GoToXY(X_PANNELLO - 2, Y_PANNELLO - 2);
    printf("%c", 188);
}

// liberazione dello spazio indicato all'interno del pannello
static void LiberazioneSpazioPennello() {
    // righe
    for (size_t i = 0; i < 9; ++i) {
        // colonne
        for (size_t j = 0; j < 35; ++j) {
            GoToXY(j + 25, i + 9);
            printf(" ");
        }
    }
}

// stampa del pannello risultato
extern void BordiPannelloEsito() {
    LiberazioneSpazioPennello();

    // prima riga
    GoToXY(26, 9);
    printf("%c", 201);

    for (size_t i = 0; i < 31; ++i)
        printf("%c", 205);

    GoToXY(58, 9);
    printf("%c", 187);

    // ultima riga
    GoToXY(26, 15);
    printf("%c", 200);

    for (size_t i = 0; i < 31; ++i)
        printf("%c", 205);

    GoToXY(58, 15);
    printf("%c", 188);
}
