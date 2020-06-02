#ifndef LOGIC_H
#define LOGIC_H
enum figures {EMPTY_SQUARE = L' ', B_KING = 0x2654, B_QUEEN, B_ROOK, B_BISHOP, B_KNIGHT,
              B_PAWN, W_KING, W_QUEEN, W_ROOK, W_BISHOP, W_KNIGHT, W_PAWN};

extern int ** table;

void init_table();
void destroy_table();
int move (char * cmd);
static int move_back (char * cmd);
_Bool white_move;
#define             RESIGN 0
#define               EXIT 1
#define               DRAW 2
#define               MOVE 3
#define         MOVED_BACK 4
#define          PROMOTION 5
#define NO_MORE_PREV_MOVES 6
#define     ERR_BLACK_TURN 7
#define     ERR_WHITE_TURN 8
#define    ERR_WRONG_INPUT 9
#define     ERR_WRONG_MOVE 10
#define    ERR_CANT_CASTLE 11

void promotion (int figure);
#define PROMOTE_TO_QUEEN  0
#define PROMOTE_TO_ROOK   1
#define PROMOTE_TO_BISHOP 2
#define PROMOTE_TO_KNIGHT 3

#endif