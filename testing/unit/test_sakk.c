#include "CUnit/Basic.h" 
#include <CUnit/CUnit.h>

// #include "../../sakk/graphics/src/graphics.h"
// #include "../../sakk/logic/src/logic.h"
// #include "../../sakk/logic/stack/src/stack.h"

#include "utest-logic.h"
#include "utest-stack.h"
 
CU_SuiteInfo pnm_suites[] = {
    { "stack", NULL, NULL, NULL, NULL, stack_tests },
    // { "manipulation", NULL, NULL, manip_test_setup, manip_test_teardown, manipulation_tests },
    CU_SUITE_INFO_NULL
};
 
int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return -1;
    };
    if (CU_register_suites(pnm_suites) != CUE_SUCCESS) {
        return -1;
    };
    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}

// int main (int argc, char** argv) {
 
//     CU_pSuite pSuite = NULL;
 
//    /* initialize the CUnit test registry */ 
//    if (CUE_SUCCESS != CU_initialize_registry())
//       return CU_get_error();
 
//    /* add a suite to the registry */ 
//    pSuite = CU_add_suite("Suite_1", NULL, NULL);
//    if (NULL == pSuite) {
//       CU_cleanup_registry();
//       return CU_get_error();
//    }
 
//    /* add the tests to the suite */ 
//    if (NULL == CU_add_test(pSuite, "Simple Addition Test", simpleTest)) {
//       CU_cleanup_registry();
//       return CU_get_error();
//    }
 
//    /* Run all tests using the CUnit Basic interface */ 
//    CU_basic_set_mode(CU_BRM_VERBOSE);
//    CU_basic_run_tests();
//    CU_cleanup_registry();
//    return CU_get_error();
// }