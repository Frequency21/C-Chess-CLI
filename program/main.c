#include<stdlib.h>
#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<graphics.h>
#include<logic.h>

#include<string.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "");
    system("clear");
    init_table();

    int status = 1;
    char cmd [10];
    do {
        print_table();
        fgets(cmd, 10, stdin);
        status = move(cmd, 10);
        system("clear");
    } while (status);
    // char text[3] = "c4";
    // char oszlop;
    // char sor;

    // wprintf(L"size of '%s' is = %d\n", text, strlen(text));
    

    destroy_table();
    return 0;
}
