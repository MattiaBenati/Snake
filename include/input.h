#ifndef INPUT_H
#define INPUT_H

extern volatile int input;
extern volatile int oggetto;
extern volatile int giocoAttivo;

void InputUtente(void *param);

#endif //INPUT_H