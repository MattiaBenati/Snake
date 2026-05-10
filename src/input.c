#include <windows.h>
#include <conio.h>
#include <process.h>
#include "input.h"
#include "serpente.h"

void InputUtente(void *param) {
    (void)param;
    while (giocoAttivo) {
        if (_kbhit()) {
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
        }
        Sleep(10);
    }

    _endthread();
}