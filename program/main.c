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
    init_table();
    print_table();

    destroy_table();
    return 0;
}
