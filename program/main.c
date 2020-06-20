#include<stdlib.h>
#include<stdio.h>
#include<wchar.h>
#include<string.h>
#include<locale.h>
#include<graphics.h>
#include<logic.h>

char * user_input (int length);
void print_commands ();

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "");
#ifdef NDEBUG
    system("clear");
#endif
    init_table();

    int status = MOVE;
    do {
    #ifndef NDEBUG
        wprintf(L"\n");
    #endif
        print_table();
        switch (status)
        {
        case DRAW_OFFERED:
            wprintf(L"Your opponent offered a draw, do you accept it?\n"
                     "(type \"accept\" to accept, or anything else to decline it.)\n");
            break;
        case DRAW_ACCEPTED:
            wprintf(L"Draw by agreement.\n");
            destroy_table();
            return 0;
        case DRAW_DECLINED:
            wprintf(L"Draw was refused. Let's play on.\n");
            break;
        case ERR_BLACK_TURN:
            wprintf(L"Choose a black piece.\n");
            break;
        case ERR_WHITE_TURN:
            wprintf(L"Choose a white piece.\n");
            break;
        case ERR_WRONG_INPUT:
            wprintf(L"Wrong input, type \"\033[1;31mhelp\033[0m\" to display possible commands.\n");
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
        default:
            break;
        }
        wprintf(L"%s to move: ", white_move ? "White" : "Black");

        char * cmd = user_input(11);
        status = move(cmd);
        // handle "help"
        if (memcmp(cmd, "help\n", 5) == 0)
            print_commands ();
        free(cmd);

        if (status == PROMOTION) {
            char * choice;
            do {
                wprintf(L"\nYour pawn is about to promote, choose a figure (queen/rook/bishop/knight): ");
                choice = user_input (7);
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
                free(choice);
            } while (1);
            free(choice);
        }
    #ifdef NDEBUG
        system("clear");
    #endif
    } while (1);
    return 0;
}

char * user_input (int length) {
    char *flag, *result = (char*) malloc (sizeof(char) * (length + 2)); // length doesn't contain '\n' and '\0'
    memset(result, '\0', length+2);
    do {
    flag = fgets(result, length + 2, stdin);
            if(strchr(result, '\n') == NULL)
                scanf("%*[^\n]"),scanf("%*c");
            if (feof(stdin))
                clearerr(stdin);
    } while (flag == NULL);

    return result;
}

void print_commands () {
    system("clear");
    wprintf(L\
"Possible commands are:\n\n\
    [a-h][1-8] [a-h][1-8] --  move pieces.\n\
    draw                  --  offer draw.\n\
    resign                --  resign.\n\
    move back             --  take one move back.\n\
    exit                  --  exit the game.\n");
    wprintf(L"\nPress enter to move on.");
    getchar();
}
