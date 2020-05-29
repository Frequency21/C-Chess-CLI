#include<stdio.h>
#include<wchar.h>
#include"graphics.h"

int ** table;

void print_figures (double num) {
  for (wchar_t i = 0x2654; i <= 0x265F; i++)
  {
      wprintf(L"%lc\n", i);
  }
}

void print_table () {
  int spaces = 4;
  wprintf(L"%*c", spaces, ' ');
  for (int i = 1; i < 9; i++)
    wprintf(L" %d", i);
  wprintf(L"\n%*c", spaces, ' ');
  for (int i = 0; i < 17; i++)
    wprintf(L"_");
  wprintf(L"\n");
  for (int i = 7; i >= 0; i--) {
    wprintf(L"%-*c|", spaces, 'a' + i);
    for (int j = 0; j < 8; j++) {
      if (j < 7)
        wprintf(L"%lc ", table[i][j]);
      else
        wprintf(L"%lc", table[i][j]);
    } wprintf(L"|");
    wprintf(L"\n");
  }
  wprintf(L"%*c", spaces, ' ');
  for (int i = 0; i < 17; i++)
    wprintf(L"%lc", 0x203E);
  wprintf(L"\n");
}