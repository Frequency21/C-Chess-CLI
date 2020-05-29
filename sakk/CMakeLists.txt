add_library(
    sakkLib
    logic/src/logic.c
    logic/src/logic.h
    graphics/src/graphics.c
    graphics/src/graphics.h
)

target_include_directories(sakkLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/graphics/src/")
target_include_directories(sakkLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/logic/src/")
