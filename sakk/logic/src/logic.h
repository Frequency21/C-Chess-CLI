#ifndef LOGIC_H
#define LOGIC_H

enum figures {EMPTY, B_KING = 0x2654, B_QUEEN, B_ROOK, B_BISHOP, B_KNIGHT,
              B_PAWN, W_KING, W_QUEEN, W_ROOK, W_BISHOP, W_KNIGHT, W_PAWN};

extern int ** table;

void init_table();

#endif