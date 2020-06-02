#include<stdlib.h>
#include<stdio.h>
#include<wchar.h>
#include<string.h>
#include<locale.h>
#include<graphics.h>
#include<logic.h>

char * user_input (int length);

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
        case ERR_CANT_CASTLE:
            wprintf(L"Can't castle.\n");
            break;
        case RESIGN:
            wprintf(L"Your opponent resigned. You win!\n");
            destroy_table ();
            return 0;
            break;
        case MOVED_BACK:
            wprintf(L"Last move is taken back.\n");
            break;
        case NO_MORE_PREV_MOVES:
            wprintf(L"There are no more previous moves.\n");
            break;
        case EXIT:
            wprintf(L"\n");
            destroy_table();
            return 0;
            break;
        default:
            break;
        }
        wprintf(L"%s to move: ", white_move ? "White" : "Black");

        char * cmd = user_input(10);
        status = move(cmd);

        if (status == PROMOTION) {
            char * choice;
            do {
                wprintf(L"\nYour pawn is about to promote, choose a figure (queen/rook/bishop/knight): ");
                choice = user_input (8);
                // fgets(choice, 8, stdin);
                // if(strchr(choice, '\n') == NULL)
                //     scanf("%*[^\n]"),scanf("%*c");
                // if (feof(stdin))
                //     clearerr(stdin);
                if (memcmp(choice, "queen\n", 6)  == 0) {
                    promotion(PROMOTE_TO_QUEEN);
                    break;
                }
                if (memcmp(choice, "rook\n", 5)   == 0) {
                    promotion(PROMOTE_TO_ROOK);
                    break;
                }
                if (memcmp(choice, "bishop\n", 7) == 0) {
                    promotion(PROMOTE_TO_BISHOP);
                    break;
                }
                if (memcmp(choice, "knight\n", 7) == 0) {
                    promotion(PROMOTE_TO_KNIGHT);
                    break;
                }
            } while (1);
        }

        system("clear");
    } while (1);
    return 0;
}

char * user_input (int length) {
    char *flag, *result = (char*) malloc (sizeof(char) * length);
    do {
    flag = fgets(result, 10, stdin);
            if(strchr(result, '\n') == NULL)
                scanf("%*[^\n]"),scanf("%*c");
            if (feof(stdin))
                clearerr(stdin);
    } while (flag == NULL);

    return result;
}