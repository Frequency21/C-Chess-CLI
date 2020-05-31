add_library(
    sakk
    logic/stack/src/stack.c
    logic/stack/src/stack.h
    logic/src/logic.c
    logic/src/logic.h
    graphics/src/graphics.c
    graphics/src/graphics.h
)

target_include_directories(sakk PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/graphics/src/")
target_include_directories(sakk PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/logic/src/")
target_include_directories(sakk PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/logic/stack/src/")
