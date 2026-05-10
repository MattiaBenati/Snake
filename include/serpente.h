#ifndef SERPENTE_H
#define SERPENTE_H
#define DESTRA 0
#define SU 1
#define SINISTRA 2
#define GIU 3
#define EXIT -1
#define CELLE_GIOCABILI ((X_PANNELLO - 2) * (Y_PANNELLO - 2))

typedef struct {
    int x;
    int y;
} Coordinate;

Coordinate *CreazioneSerpente(int **mappa, int lunghezza);

void AggiornamentoSerpente(Coordinate *serpente, int *lunghezza, int *direzione, int input,
                                  int **mappa, int *oggetto);

void GenerazioneCibo(int **mappa, int *cibi, int lunghezza);

#endif //SERPENTE_H
