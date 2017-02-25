#include <iostream>

#include "GameOfLife.hpp"

int main(int argc, char *argv[]) {
  std::cout << "Hello World" << std::endl;

  // create new game of life object
  auto game = GameOfLife::GameOfLife();

  auto gd = game.get_conwayGrid();

  // this access pattern is weird
  std::cout << (int)gd->at(0).at(0) << std::endl;

  std::cout << game << std::endl;
  return 0;
}
