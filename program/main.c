#include<stdlib.h>
#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<graphics.h>
#include<logic.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "");
    system("clear");
    // wprintf(L"asd\n");
    // print_figures();
    // wprintf(L"\n");
    init_table();
    print_table();
    return 0;
}