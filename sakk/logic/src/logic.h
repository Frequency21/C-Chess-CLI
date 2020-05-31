#ifndef LOGIC_H
#define LOGIC_H
enum figures {EMPTY_SQUARE = L' ', B_KING = 0x2654, B_QUEEN, B_ROOK, B_BISHOP, B_KNIGHT,
              B_PAWN, W_KING, W_QUEEN, W_ROOK, W_BISHOP, W_KNIGHT, W_PAWN};

extern int ** table;

void init_table();

void destroy_table();

int move (char * cmd, int length);

_Bool white_move;
#define             RESIGN 0
#define               DRAW 1
#define               MOVE 2
#define         MOVED_BACK 3
#define          PROMOTION 4
#define NO_MORE_PREV_MOVES 5
#define     ERR_BLACK_TURN 6
#define     ERR_WHITE_TURN 7
#define    ERR_WRONG_INPUT 8
#define     ERR_WRONG_MOVE 9
#endif