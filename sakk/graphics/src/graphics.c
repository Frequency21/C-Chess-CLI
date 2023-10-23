/* Package drawing chessboard
 * if terminal support colors, then
 * background will be black, and
 * foreground will be white
 */
#include "graphics.h"

#include <stdbool.h>
#include <stdio.h>
#include <wchar.h>

int** table;

void print_figures(double num) {
    for (wchar_t i = 0x2654; i <= 0x265F; i++) wprintf(L"%lc\n", i);
}

void print_table() {
    int spaces = 4;

    // terminal background to black, and foreground to white
    wprintf(L"\033[1;37m\033[1;40m");

    // drawing column "letters"
    wprintf(L"%*c", spaces, ' ');
    for (int i = 0; i < 8; i++) wprintf(L" %c", 'a' + i);
    wprintf(L"    \n%*c", spaces, ' ');

    // drawing top of the board
    for (int i = 0; i < 17; i++) wprintf(L"_");
    wprintf(L"   \n");

    /* drawing figures (with side of the board and
       numbering rows.) */
    for (int i = 7; i >= 0; i--) {
        wprintf(L"%-*c%lc", spaces, '1' + i, 0x2502);
        for (int j = 0; j < 8; j++) {
            if (j < 7)
                wprintf(L"%lc ", table[i][j]);
            else
                wprintf(L"%lc", table[i][j]);  // no space after last figure
        }
        wprintf(L"%lc   ", 0x2502);
        wprintf(L"\n");
    }
    wprintf(L"%*c", spaces, ' ');
    // drawing bottom of the border
    for (int i = 0; i < 17; i++) wprintf(L"%lc", 0x203E);
    wprintf(L"   \n");

    // terminal background and foreground back to normal
    wprintf(L"\033[0;39m\033[0;49m");
}
