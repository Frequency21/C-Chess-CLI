#include<stdbool.h>
#include<stdio.h>
#include<wchar.h>
#include"graphics.h"

int ** table;

void print_figures (double num) {
  for (wchar_t i = 0x2654; i <= 0x265F; i++)
      wprintf(L"%lc\n", i);
}

void print_table () {
  int spaces = 4;
  
  // oszlop számok kiíratása
  wprintf(L"%*c", spaces, ' ');
  for (int i = 0; i < 8; i++)
    wprintf(L" %c", 'a' + i);
  wprintf(L"\n%*c", spaces, ' ');

  // tábla tetejének kirajzolása
  for (int i = 0; i < 17; i++)
    wprintf(L"_");
  wprintf(L"\n");

  /* figurák kirajzolása (tábla szélével,
     és sorok számozásával) */
  for (int i = 7; i >= 0; i--) {
    wprintf(L"%-*c%lc", spaces, '1' + i, 0x2502);
    for (int j = 0; j < 8; j++) {
      if (j < 7)
        wprintf(L"%lc ", table[i][j]);
      else
        wprintf(L"%lc", table[i][j]);   // utolsó bábú után ne legyen space
    } wprintf(L"%lc", 0x2502);
    wprintf(L"\n");
  }
  wprintf(L"%*c", spaces, ' ');
  // tábla alsó felének kirajzolása
  for (int i = 0; i < 17; i++)
    wprintf(L"%lc", 0x203E);
  wprintf(L"\n");
}