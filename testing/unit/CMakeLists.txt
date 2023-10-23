set(SOURCES
    utest-logic.c
    utest-logic.h
    utest-stack.c
    utest-stack.h
)

enable_testing()

add_executable (test_sakk test_sakk.c ${SOURCES})
target_link_libraries(test_sakk PRIVATE cunit)
target_link_libraries(test_sakk PRIVATE sakk)

add_test (test_sakk ${EXECUTABLE_OUTPUT_PATH}/test)
