add_library(
    gyok
    src/gyok/gyok.h
    src/gyok/gyok.c
)

target_include_directories(gyok PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
