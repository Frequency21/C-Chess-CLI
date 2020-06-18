#include "../../sakk/logic/src/logic.h"  // figures
#include "../../sakk/logic/stack/src/stack.h"
#include "utest-stack.h"

#include <CUnit/CUnit.h>

static void test_stack_push_pop () {
    StackNode * root = ROOT;
    Data move1, move2;
    move1.figure = W_PAWN;
    move1.from_to = 5254;
    move1.flag = ORDINARY;
    move2.figure = B_PAWN;
    move2.from_to = 5755;
    move2.flag = ORDINARY;
    push(&root, move1);
    push(&root, move2);
    Data popped1, popped2;
    popped1 = pop(&root);
    popped2 = pop(&root);
    CU_ASSERT_EQUAL(popped1.figure,  B_PAWN);
    CU_ASSERT_EQUAL(popped1.flag,    ORDINARY);
    CU_ASSERT_EQUAL(popped1.from_to, 5755);
    CU_ASSERT_EQUAL(popped2.figure,  W_PAWN);
    CU_ASSERT_EQUAL(popped2.flag,    ORDINARY);
    CU_ASSERT_EQUAL(popped2.from_to, 5254);
    destroy_stack(&root);
    CU_ASSERT_PTR_NULL(root);
}

static void test_stack_destroy () {}

CU_TestInfo stack_tests[] = {
    {"push pop",    test_stack_push_pop},
    // {"destroy",     test_stack_destroy},
    CU_TEST_INFO_NULL
};
