#ifndef CHESS_H
#define CHESS_H

enum figures {
    EMPTY_SQUARE = L' ',
    B_KING = 0x2654,
    B_QUEEN,
    B_ROOK,
    B_BISHOP,
    B_KNIGHT,
    B_PAWN,
    W_KING,
    W_QUEEN,
    W_ROOK,
    W_BISHOP,
    W_KNIGHT,
    W_PAWN
};

extern int** table;

void init_table();
void destroy_table();
int move(char* cmd);
static int move_back(char* cmd);
_Bool white_move;
#define RESIGN 0
#define EXIT 1
#define DRAW_OFFERED 2
#define DRAW_ACCEPTED 3
#define DRAW_DECLINED 4
#define MOVE 5
#define MOVED_BACK 6
#define PROMOTION 7
#define NO_MORE_PREV_MOVES 8
#define ERR_BLACK_TURN 9
#define ERR_WHITE_TURN 10
#define ERR_WRONG_INPUT 11
#define ERR_WRONG_MOVE 12
#define ERR_CANT_CASTLE 13

void promotion(int figure);
#define PROMOTE_TO_QUEEN 0
#define PROMOTE_TO_ROOK 1
#define PROMOTE_TO_BISHOP 2
#define PROMOTE_TO_KNIGHT 3

#endif
