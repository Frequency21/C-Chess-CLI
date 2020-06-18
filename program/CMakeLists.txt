# if($<CONFIG:DEBUG>)
#     MESSAGE("Adding Debug flag...")
#     MESSAGE("Build type is " ${CMAKE_BUILD_TYPE})
# endif($<CONFIG:DEBUG>)

# MESSAGE("Adding Debug flag...")
# MESSAGE("Build type is " ${CMAKE_BUILD_TYPE})

add_executable(sakk-exe main.c)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("debug mode")
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

target_link_libraries(sakk-exe PRIVATE sakk)

add_custom_target(test
    COMMAND bash -c "./sakk-exe < input.txt > output.txt"
    COMMENT "Creating output.txt in ${CMAKE_CURRENT_SOURCE_DIR} (integrity test)"
    VERBATIM
)

add_custom_command(TARGET sakk-exe
                   POST_BUILD
                   COMMAND bash -c "echo \"hello\""
                   VERBATIM)
