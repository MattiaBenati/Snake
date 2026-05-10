#include <windows.h>
#include <process.h>	// _beginthread()
#include <conio.h>		// _getch()
#include <time.h>		// srand(time(NULL));
#include "serpente.h"
#include "console.h"
#include "mappa.h"
#include "grafica.h"
#include "input.h"
#include "gioco.h"

volatile int input = SINISTRA;
volatile int oggetto = LIBERO;
volatile int giocoAttivo = 1;

int main(void) {
    ImpostaTitoloFinestraConsole("Snake");
    system("MODE 85, 25");	// DIMENSIONE pannello
    CentraEBloccaFinestraConsole();	// pannello CENTRALE e NON CLICCABILE

    BordiPannelloGioco();

    srand(time(NULL));

    int lunghezza = 2;
    int cibi = 0;
    int direzione = SINISTRA;

    int **mappa;
    Coordinate *serpente;

    InizializzazioneGioco(&mappa, &serpente, &lunghezza, &cibi);

    _getch();
    _beginthread(InputUtente, 0, (void *) 0);

    LoopGioco(serpente, &lunghezza, &direzione, mappa, &cibi);

    FineGioco(lunghezza);

    EliminazioneMappa(mappa);
    free(serpente);

    return 0;
}
