#include "utest-logic.h"

#include <CUnit/CUnit.h>
#include <stdbool.h>

#include "../../sakk/logic/src/logic.h"  // figures
#include "../../sakk/logic/stack/src/stack.h"

static void test_wrong_inp() {
    CU_ASSERT_EQUAL(move("`1 a1"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("a1 `1"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("a0 a1"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("a1 a0"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("a9 a1"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("a1 a9"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("h0 h1"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("h1 h0"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("h9 h1"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("h1 h9"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("h1 i1"), ERR_WRONG_INPUT);
    CU_ASSERT_EQUAL(move("i1 h1"), ERR_WRONG_INPUT);
}

static void test_white_with_black_fig() {
    int status = move("e7 e5");
    CU_ASSERT_EQUAL(status, ERR_WHITE_TURN);
}

static void test_black_with_white_fig() {
    white_move = false;
    int status = move("e2 e4");
    CU_ASSERT_EQUAL(status, ERR_BLACK_TURN);
}

static void test_promotion() {
    CU_ASSERT_EQUAL(move("a2 a8"), PROMOTION);
    promotion(PROMOTE_TO_ROOK);
    CU_ASSERT_EQUAL(table[7][0], W_ROOK);
    CU_ASSERT_EQUAL(table[2][0], EMPTY_SQUARE);
    CU_ASSERT_TRUE(!white_move);
}

static void test_promotion_move_back() {
    move("a2 a8");
    promotion(PROMOTE_TO_ROOK);
    move("move back\n");
    CU_ASSERT_EQUAL(table[1][0], W_PAWN);
    CU_ASSERT_EQUAL(table[7][0], B_ROOK);
    CU_ASSERT_TRUE(white_move);
}

static void test_W_KS_castle() {
    table[0][5] = table[0][6] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e1 g1"), MOVE);
    CU_ASSERT_EQUAL(table[0][6], W_KING);
    CU_ASSERT_EQUAL(table[0][5], W_ROOK);
    CU_ASSERT_TRUE(!white_move);
}

static void test_B_KS_castle() {
    white_move = false;
    table[7][5] = table[7][6] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e8 g8"), MOVE);
    CU_ASSERT_EQUAL(table[7][6], B_KING);
    CU_ASSERT_EQUAL(table[7][5], B_ROOK);
    CU_ASSERT_TRUE(white_move);
}

static void test_W_QS_castle() {
    table[0][1] = table[0][2] = table[0][3] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e1 c1"), MOVE);
    CU_ASSERT_EQUAL(table[0][2], W_KING);
    CU_ASSERT_EQUAL(table[0][3], W_ROOK);
    CU_ASSERT_TRUE(!white_move);
}

static void test_B_QS_castle() {
    white_move = false;
    table[7][1] = table[7][2] = table[7][3] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e8 c8"), MOVE);
    CU_ASSERT_EQUAL(table[7][2], B_KING);
    CU_ASSERT_EQUAL(table[7][3], B_ROOK);
    CU_ASSERT_TRUE(white_move);
}

static void test_W_KS_castle_ERR() {
    table[0][5] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e1 g1"), ERR_WRONG_MOVE);
    CU_ASSERT_EQUAL(table[0][4], W_KING);
    CU_ASSERT_EQUAL(table[0][7], W_ROOK);
    CU_ASSERT_TRUE(white_move);

    table[0][5] = W_PAWN;
    table[0][6] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e1 g1"), ERR_CANT_CASTLE);
    CU_ASSERT_EQUAL(table[0][4], W_KING);
    CU_ASSERT_EQUAL(table[0][7], W_ROOK);
    CU_ASSERT_TRUE(white_move);
}

static void test_W_QS_castle_ERR() {
    table[0][1] = table[0][2] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e1 c1"), ERR_CANT_CASTLE);
    CU_ASSERT_EQUAL(table[0][4], W_KING);
    CU_ASSERT_EQUAL(table[0][0], W_ROOK);
    CU_ASSERT_TRUE(white_move);

    table[0][2] = W_PAWN;
    table[0][1] = table[0][3] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e1 c1"), ERR_WRONG_MOVE);
    CU_ASSERT_EQUAL(table[0][4], W_KING);
    CU_ASSERT_EQUAL(table[0][0], W_ROOK);
    CU_ASSERT_TRUE(white_move);
}

static void test_B_KS_castle_ERR() {
    white_move = false;
    table[7][5] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e8 g8"), ERR_WRONG_MOVE);
    CU_ASSERT_EQUAL(table[7][4], B_KING);
    CU_ASSERT_EQUAL(table[7][7], B_ROOK);
    CU_ASSERT_TRUE(!white_move);

    table[7][5] = B_PAWN;
    table[7][6] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e8 g8"), ERR_CANT_CASTLE);
    CU_ASSERT_EQUAL(table[7][4], B_KING);
    CU_ASSERT_EQUAL(table[7][7], B_ROOK);
    CU_ASSERT_TRUE(!white_move);
}

static void test_B_QS_castle_ERR() {
    white_move = false;
    table[7][1] = table[7][2] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e8 c8"), ERR_CANT_CASTLE);
    CU_ASSERT_EQUAL(table[7][4], B_KING);
    CU_ASSERT_EQUAL(table[7][0], B_ROOK);
    CU_ASSERT_TRUE(!white_move);

    table[7][2] = B_PAWN;
    table[7][1] = table[7][3] = EMPTY_SQUARE;
    CU_ASSERT_EQUAL(move("e8 c8"), ERR_WRONG_MOVE);
    CU_ASSERT_EQUAL(table[7][4], B_KING);
    CU_ASSERT_EQUAL(table[7][0], B_ROOK);
    CU_ASSERT_TRUE(!white_move);
}

CU_TestInfo logic_tests[] = {
    {"move out of board", test_wrong_inp},
    {"white tries to move with black figure", test_white_with_black_fig},
    {"black tries to move with white figure", test_black_with_white_fig},
    {"promotion", test_promotion},
    {"promotion move back", test_promotion_move_back},
    {"white kingside castle", test_W_KS_castle},
    {"black kingside castle", test_B_KS_castle},
    {"white queenside castle", test_W_QS_castle},
    {"black queenside castle", test_B_QS_castle},
    {"white can't castle kingside", test_W_KS_castle_ERR},
    {"white can't castle queenside", test_W_QS_castle_ERR},
    {"black can't castle kingside", test_B_KS_castle_ERR},
    {"black can't castle queenside", test_B_QS_castle_ERR},
    CU_TEST_INFO_NULL};

void table_setup() { init_table(); }

void table_teardown() { destroy_table(); }
