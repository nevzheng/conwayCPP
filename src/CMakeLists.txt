add_executable (conwayCPP main.cpp GameOfLife.cpp)
install(TARGETS conwayCPP RUNTIME DESTINATION ${BIN_DIR})
