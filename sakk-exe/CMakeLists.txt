add_executable(sakk asd.c)

IF(UNIX)
	target_link_libraries(sakk PUBLIC m)
ENDIF(UNIX)

target_link_libraries(sakk PRIVATE gyok)
