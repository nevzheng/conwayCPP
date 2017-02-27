add_executable(conwayCpp src/main.cpp)
target_link_libraries(conwayCPP ${SDL2_LIBRARY})
install(TARGETS conwayCPP RUNTIME DESTINATION ${BIN_DIR})
