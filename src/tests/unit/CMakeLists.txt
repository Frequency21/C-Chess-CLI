set(SOURCES
    chess.spec.c
    chess.spec.h
    stack.spec.c
    stack.spec.h
)

add_executable(unit-tests main.spec.c ${SOURCES})
target_link_libraries(unit-tests PRIVATE cunit)
target_link_libraries(unit-tests PRIVATE chess)
