#include <windows.h>
#include "console.h"

void ImpostaTitoloFinestraConsole(const char* titolo) {
    if(titolo != NULL)
        SetConsoleTitleA(titolo);
}

void CentraEBloccaFinestraConsole(void) {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    HWND hWnd = GetConsoleWindow();
    if(hInput == INVALID_HANDLE_VALUE || hWnd == NULL) return;

    DWORD mode = 0;
    if(GetConsoleMode(hInput, &mode)) {
        mode &= ~ENABLE_QUICK_EDIT_MODE;
        mode &= ~ENABLE_INSERT_MODE;
        mode &= ~ENABLE_MOUSE_INPUT;
        mode |= ENABLE_EXTENDED_FLAGS;
        SetConsoleMode(hInput, mode);
    }

    LONG_PTR style = GetWindowLongPtr(hWnd, GWL_STYLE);
    style &= ~WS_SIZEBOX;
    style &= ~WS_MAXIMIZEBOX;
    SetWindowLongPtr(hWnd, GWL_STYLE, style);

    HMENU hMenu = GetSystemMenu(hWnd, FALSE);
    if(hMenu != NULL) {
        DeleteMenu(hMenu, SC_SIZE, MF_BYCOMMAND);
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }

    SetWindowPos(hWnd, NULL, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    RECT rect;
    if(GetWindowRect(hWnd, &rect)) {
        int windowWidth = rect.right - rect.left;
        int windowHeight = rect.bottom - rect.top;

        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);

        int posX = (screenWidth - windowWidth) / 2;
        int posY = (screenHeight - windowHeight) / 2;

        MoveWindow(hWnd, posX, posY, windowWidth, windowHeight, TRUE);
    }
}