add_executable(main main.c)

add_subdirectory(chess)
add_subdirectory(tests/unit)

target_link_libraries(main PRIVATE chess)
