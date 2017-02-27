add_executable (conwayCPP main.cpp GameOfLife.cpp )
target_link_libraries(conwayCPP ${SDL2_LIBRARY})
install(TARGETS conwayCPP RUNTIME DESTINATION ${BIN_DIR})

add_library(GameOfLife GameOfLife.cpp ../include/GameOfLife.hpp ../include/res_path.hpp ../include/cleanup.hpp)
