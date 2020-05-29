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
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      wprintf(L"%lc ", table[i][j]);
    } wprintf(L"\n");
  }
  
}