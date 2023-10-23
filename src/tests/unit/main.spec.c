#include <CUnit/CUnit.h>

#include "CUnit/Basic.h"
#include "chess.spec.h"
#include "stack.spec.h"

CU_SuiteInfo chess_suites[] = {
    {"stack", NULL, NULL, NULL, NULL, stack_tests},
    {"chess", NULL, NULL, table_setup, table_teardown, logic_tests},
    CU_SUITE_INFO_NULL};

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    };
    if (CU_register_suites(chess_suites) != CUE_SUCCESS) {
        return CU_get_error();
    };
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
