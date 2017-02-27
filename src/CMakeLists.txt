project(conwayCPP)
add_executable(conway main.cpp)
target_link_libraries(conway ${SDL2_LIBRARY})
install(TARGETS conway RUNTIME DESTINATION ${BIN_DIR})
