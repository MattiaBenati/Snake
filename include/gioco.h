#ifndef GIOCO_H
#define GIOCO_H

#include "serpente.h"

void InizializzazioneGioco(int ***mappa, Coordinate **serpente, int *lunghezza, int *cibi);
void LoopGioco(Coordinate *serpente, int *lunghezza, int *direzione, int **mappa, int *cibi);
void FineGioco(int lunghezza);

#endif //GIOCO_H