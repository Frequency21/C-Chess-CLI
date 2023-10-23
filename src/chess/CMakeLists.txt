add_library(
    chess
    graphics/graphics.c
    graphics/graphics.h
    stack/stack.c
    stack/stack.h
    chess.c
    chess.h
)

target_include_directories(chess PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
target_include_directories(chess PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/graphics/")
target_include_directories(chess PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/stack/")
