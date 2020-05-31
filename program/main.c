#include<stdlib.h>
#include<stdio.h>
#include<wchar.h>
#include<string.h>
#include<locale.h>
#include<graphics.h>
#include<logic.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "");
    system("clear");
    init_table();

    int status = MOVE;
    char cmd [10];
    do {
        print_table();
        switch (status)
        {
        case ERR_BLACK_TURN:
            wprintf(L"Choose a black piece.\n");
            break;
        case ERR_WHITE_TURN:
            wprintf(L"Choose a white piece.\n");
            break;
        case ERR_WRONG_INPUT:
            wprintf(L"Wrong input.\n");
            break;
        case ERR_WRONG_MOVE:
            wprintf(L"Illegal, or non-sense move.\n");
            break;
        case RESIGN:
            wprintf(L"Your opponent resigned. You win!\n");
            return 0;
            break;
        case MOVED_BACK:
            wprintf(L"Last move is taken back.\n");
            break;
        case NO_MORE_PREV_MOVES:
            wprintf(L"There are no more previous moves.\n");
            break;
        default:
            break;
        }
        wprintf(L"%s to move: ", white_move ? "White" : "Black");
        if (fgets(cmd, 10, stdin) != NULL) {
            int length = strlen(cmd);
            if (length > 0 && cmd[length-1] != '\n') {
                int c;
                while ((c = getchar())!= '\n' && c != EOF)
                    ;
            }
            status = move(cmd, 10);
        } else {  // EOF, vagy error
            return 1;
        }
        system("clear");
    } while (1);
    // char text[3] = "c4";
    // char oszlop;
    // char sor;

    // wprintf(L"size of '%s' is = %d\n", text, strlen(text));
    

    destroy_table();
    return 0;
}
