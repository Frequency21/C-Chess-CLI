cmake_minimum_required(VERSION 3.5.0)
project(Chess-CLI VERSION 1.0.0)

add_subdirectory(libs/cunit/CUnit)

enable_testing()
add_subdirectory(src)

add_test(NAME unit-tests COMMAND $<TARGET_FILE:unit-tests>)
