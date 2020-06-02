#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"logic.h"
#include"../stack/src/stack.h"

#define RESIGN_CMD "resign\n"
#define DRAW_CMD "draw\n"
#define MOVE_BACK_CMD "move back"
static StackNode * root = ROOT;

#define TABLE(i,j) table[i][j]

void init_table () {
    table = (int**) malloc (sizeof(int*)*8);
    for (int i = 0; i < 8; i++)
        table[i] = (int*) malloc (sizeof(int)*8);

    // the column coordinates of figures in the order
    // of enum figures.
    int coordinates[] = {4, 3, 0, 2, 1};

    for (int i = 0, figure = W_KING; i < 5; i++, figure++) {
        table[0][coordinates[i]] = figure;
        if (coordinates[i] != 3 && coordinates[i] != 4)
            table[0][7 - coordinates[i]] = figure;
    }
    for (int i = 0, figure = B_KING; i < 5; i++, figure++) {
        table[7][coordinates[i]] = figure;
        if (coordinates[i] != 3 && coordinates[i] != 4)
            table[7][7 - coordinates[i]] = figure;
    }
    for (int i = 1, figure; i < 7; i++) {
        int figure = EMPTY_SQUARE;
        if (i == 1)
            figure = W_PAWN;
        else if (i == 6)
            figure = B_PAWN;
        for (int j = 0; j < 8; j++)
            TABLE(i,j) = figure;
    }
    white_move = true;
}

int move (char * cmd) {
    if (memcmp(cmd, "exit\n", 5) == 0)
        return EXIT;
    if (memcmp(cmd, RESIGN_CMD, 7) == 0)
        return RESIGN;
    if (memcmp(cmd, DRAW_CMD, 5) == 0)
        return DRAW;
    if (memcmp(cmd, MOVE_BACK_CMD, 9) == 0)
        return move_back(cmd);
    
    char from_row, to_row,
         from_col, to_col;
    if (sscanf(cmd, "%c%c %c%c\n", &from_col, &from_row, &to_col, &to_row) == 4) {
        Data move_d;
        from_col = from_col - 'a' + '1';  // 'a'->'1', 'b'->'2' ..., 'h'->'8'
        to_col   = to_col   - 'a' + '1';
        if (from_col > '0' && from_col < '9' && from_row > '0' && from_row < '9' &&
              to_col > '0' &&   to_col < '9' &&   to_row > '0' &&   to_row < '9'    )
        {  // format is acceptable
            int from_row_index = from_row - '1', from_col_index = from_col - '1',
                to_row_index   = to_row   - '1', to_col_index   = to_col   - '1';
            int figure_in_move  = table[from_row_index][from_col_index],
                figure_attacked = table[to_row_index][to_col_index];
            if (figure_in_move == EMPTY_SQUARE)
                return ERR_WRONG_MOVE;
            if (white_move) {
                if (figure_in_move >= B_KING && figure_in_move <= B_PAWN)
                    return ERR_WHITE_TURN;
                if (figure_attacked >= W_KING && figure_attacked <= W_PAWN)
                    return ERR_WRONG_MOVE;
            } else {
                if (figure_in_move >= W_KING && figure_in_move <= W_PAWN)
                    return ERR_BLACK_TURN;
                if (figure_attacked >= B_KING && figure_attacked <= B_PAWN)
                    return ERR_WRONG_MOVE;
            }
            char from_to[] = {from_row, from_col, to_row, to_col, 0};
            move_d.from_to = atoi(from_to);
            move_d.figure  = figure_attacked;
            move_d.flag    = ORDINARY;
            table[to_row_index][to_col_index] = figure_in_move;
            table[from_row_index][from_col_index] = EMPTY_SQUARE;

            // handle promotion
            if ((figure_in_move == B_PAWN && to_row_index == 0) || 
                (figure_in_move == W_PAWN && to_row_index == 7)) {
                move_d.flag = PROMOTE;
                push(&root, move_d);
                return PROMOTION;
            }
            // handle castle
            if (figure_in_move == W_KING && from_row_index == 0 && from_col_index == 4 && to_row_index == 0) {
                if (to_col_index == 6) {
                    if (TABLE(0,5) == EMPTY_SQUARE && TABLE(0,7) == W_ROOK) {
                        move_d.flag = W_KING_SIDE_CASTLE;
                        TABLE(0,5) = W_ROOK;
                        TABLE(0,7) = EMPTY_SQUARE;
                    } else
                        return ERR_CANT_CASTLE;
                } else if (to_col_index == 2) {
                    if (TABLE(0,3) == EMPTY_SQUARE && TABLE(0,0) == W_ROOK) {
                        move_d.flag = W_QUEEN_SIDE_CASTLE;
                        TABLE(0,0) = EMPTY_SQUARE;
                        TABLE(0,3) = W_ROOK;
                    } else
                        return ERR_CANT_CASTLE;
                }  
            } else if (figure_in_move == B_KING && from_row_index == 7 && from_col_index == 4 && to_row_index == 7) {
                if (to_col_index == 6) {
                    if (TABLE(7,5) == EMPTY_SQUARE && TABLE(7,7) == B_ROOK) {
                        move_d.flag = B_KING_SIDE_CASTLE;
                        TABLE(7,5) = B_ROOK;
                        TABLE(7,7) = EMPTY_SQUARE;
                    } else
                        return ERR_CANT_CASTLE;
                } else if (to_col_index == 2) {
                    if (TABLE(7,3) == EMPTY_SQUARE && TABLE(7,0) == B_ROOK) {
                        move_d.flag = B_QUEEN_SIDE_CASTLE;
                        TABLE(7,0) = EMPTY_SQUARE;
                        TABLE(7,3) = B_ROOK;
                    } else
                        return ERR_CANT_CASTLE;
                }  
            } 

            white_move = !white_move;
            push(&root, move_d);
            return MOVE;
        }
    }
    return ERR_WRONG_INPUT;
}

static void test () {
    printf("Static function test.\n");
}

void promotion (int figure_code) {
    int figure;
    switch (figure_code) {
    case PROMOTE_TO_QUEEN:
        figure = white_move ? W_QUEEN : B_QUEEN;
        break;
    case PROMOTE_TO_ROOK:
        figure = white_move ? W_ROOK : B_ROOK;
        break;
    case PROMOTE_TO_BISHOP:
        figure = white_move ? W_BISHOP : B_BISHOP;
        break;
    case PROMOTE_TO_KNIGHT:
        figure = white_move ? W_KNIGHT : B_KNIGHT;
        break;
    default:
        white_move = !white_move;
        return;
        break;
    }

    int row, pawn;

    if (white_move) {
        row = 7;
        pawn = W_PAWN;
    } else {
        row = 0;
        pawn = B_PAWN;
    }

    for (int j = 0; j < 8; j++)
        if (table[row][j] == pawn)
            table[row][j] = figure;

    white_move = !white_move;
}

void destroy_table () {
    destroy_stack(&root);
    for (int i = 0; i < 8; i++)
        free(table[i]);
    free(table);
}

static int move_back (char * cmd) {
    if (isEmpty(root))
        return NO_MORE_PREV_MOVES;
    Data last_move = pop(&root);
    int from = last_move.from_to / 100;
    int   to = last_move.from_to % 100;
    int from_row = from / 10 - 1, from_col = from % 10 - 1,
            to_row =   to / 10 - 1,   to_col =   to % 10 - 1;
    int attacked_figure = last_move.figure,
        figure          = last_move.flag == PROMOTE ? (white_move ? W_PAWN : B_PAWN) : table[to_row][to_col];
    table[from_row][from_col] = figure;
    table[to_row][to_col] = attacked_figure;

    // handle castle
    if (last_move.flag == W_KING_SIDE_CASTLE) {
        TABLE(0,5) = EMPTY_SQUARE;
        TABLE(0,7) = W_ROOK;
    } else if (last_move.flag == W_QUEEN_SIDE_CASTLE) {
        TABLE(0,3) = EMPTY_SQUARE;
        TABLE(0,0) = W_ROOK;
    } else if (last_move.flag == B_KING_SIDE_CASTLE) {
        TABLE(7,5) = EMPTY_SQUARE;
        TABLE(7,7) = B_ROOK;
    } else if (last_move.flag == B_QUEEN_SIDE_CASTLE) {
        TABLE(7,3) = EMPTY_SQUARE;
        TABLE(7,0) = B_ROOK;
    }

    white_move = !white_move;
    return MOVED_BACK;
}