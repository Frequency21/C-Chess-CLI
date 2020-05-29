#include<stdlib.h>
#include"logic.h"

// enum figures {EMPTY, B_KING = 0x2654, B_QUEEN, B_ROOK, B_BISHOP, B_KNIGHT,
//               B_PAWN, W_KING, W_QUEEN, W_ROOK, W_BISHOP, W_KNIGHT, W_PAWN};

void init_table () {
    table = (int**) malloc (sizeof(int*)*8);
    for (int i = 0; i < 8; i++)
        table[i] = (int*) malloc (sizeof(int)*8);
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
        int figure = EMPTY;
        if (i == 1)
            figure = W_PAWN;
        else if (i == 6)
            figure = B_PAWN;
        
        for (int j = 0; j < 8; j++) {
            table[i][j] = figure;
        }
    }
}