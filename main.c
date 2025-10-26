#include <stdio.h>
#include <windows.h>
#include <process.h>	// _beginthread()
#include <conio.h>		// _getch()
#include <time.h>		// srand(time(NULL));
#include "serpente.h"
#include "mappa.h"
#include "grafica.h"

int input = SINISTRA;
int oggetto = LIBERO;

// input utente per l'avvio del gioco
void InputUtente() {
    do {
        int c = _getch();

        switch (c) {
            case 'W':
            case 'w':
                input = SU;
                break;

            case 'S':
            case 's':
                input = GIU;
                break;

            case 'D':
            case 'd':
                input = DESTRA;
                break;

            case 'A':
            case 'a':
                input = SINISTRA;
                break;

            case 27:
                input = EXIT;
                break;
        }
    } while (input != EXIT && oggetto >= 0);

    _endthread();
}

int main(void) {
    // dimensione pannello FISSA
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    // dimensione pannello del gioco
    system("MODE 85, 25");
    BordiPannelloGioco();

    srand(time(NULL));

    // variabili del serpente
    int lunghezza = 2;
    int cibi = 0;
    int direzione = SINISTRA;

    // generazione della mappa
    int **mappa = CreazioneMappa();
    Coordinate *serpente = CreazioneSerpente(mappa, lunghezza);
    GenerazioneCibo(mappa, &cibi);

    _beginthread(InputUtente, 0, (void *) 0);
    _getch();

    do {
        AggiornamentoSerpente(serpente, &lunghezza, &direzione, input, mappa, &oggetto);

        if (oggetto == CIBO)
            GenerazioneCibo(mappa, &cibi);
    } while (oggetto >= 0 && input != EXIT);

    // stampa esito del gioco
    BordiPannelloEsito();

    GoToXY(X_PANNELLO / 2 - 10, Y_PANNELLO / 2 + 1);
    printf("Il tuo punteggio e' %d", lunghezza - 1);

    GoToXY(X_PANNELLO / 2 - 5, Y_PANNELLO / 2 - 1);
    printf("GAME OVER!");

    _getch();

    // eliminazione memoria
    EliminazioneMappa(mappa);
    free(serpente);

    return 0;
}
