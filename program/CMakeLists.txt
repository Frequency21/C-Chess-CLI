add_executable(sakk-exe main.c)

target_link_libraries(sakk-exe PRIVATE sakk)

# Robert James Fischer vs Lev Polugaevsky
# Palma de Mallorca Interzonal (1970), Palma de Mallorca ESP, rd 11, Nov-23 
# English Opening: Anglo-Indian Defense. Mikenas-Carls Variation (A15)

add_custom_target(integrity-test-Fischer
    DEPENDS sakk-exe
    COMMAND bash -c "./sakk-exe < ${CMAKE_SOURCE_DIR}/testing/integrity/Fischer-game.txt > ${CMAKE_SOURCE_DIR}/testing/integrity/Fischer-game-output.txt"
    COMMENT "Creating Fischer-game-output.txt in ${CMAKE_SOURCE_DIR}/testing/integrity (integrity test)"
    VERBATIM
)

add_custom_target(integrity-test-castle
    DEPENDS sakk-exe
    COMMAND bash -c "./sakk-exe < ${CMAKE_SOURCE_DIR}/testing/integrity/castle.txt > ${CMAKE_SOURCE_DIR}/testing/integrity/castle-output.txt"
    COMMENT "Creating castle-output.txt in ${CMAKE_SOURCE_DIR}/testing/integrity (integrity test)"
    VERBATIM
)

add_custom_target(integrity-test-promotion
    DEPENDS sakk-exe
    COMMAND bash -c "./sakk-exe < ${CMAKE_SOURCE_DIR}/testing/integrity/promotion.txt > ${CMAKE_SOURCE_DIR}/testing/integrity/promotion-output.txt"
    COMMENT "Creating promotion-output.txt in ${CMAKE_SOURCE_DIR}/testing/integrity (integrity test)"
    VERBATIM
)
