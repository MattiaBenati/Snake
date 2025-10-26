#ifndef SERPENTE_H
#define SERPENTE_H
#define DESTRA 0
#define SU 1
#define SINISTRA 2
#define GIU 3
#define EXIT -1

typedef struct {
    int x;
    int y;
} Coordinate;

extern Coordinate *CreazioneSerpente(int **mappa, int lunghezza);

extern void AggiornamentoSerpente(Coordinate *serpente, int *lunghezza, int *direzione, int input,
                                  int **mappa, int *oggetto);

extern void GenerazioneCibo(int **mappa, int *cibi);

#endif //SERPENTE_H
