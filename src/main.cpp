#include <cstdlib>
#include <ctime>
#include <iostream>

#include "GameOfLife.hpp"

int main(int argc, char *argv[]) {
  std::srand(std::time(NULL));

  //
  // int x, y, iters;
  // std::cout << "Welcome to Conway's" << std::endl;
  // std::cout << "Please enter (x,y,iterations)" << std::endl;
  // std::cin >> x;
  // std::cin >> y;
  // std::cin >> iters;

  // create new game of life object
  // auto game = GameOfLife::GameOfLife(x,y);
  // create new game of life object
  /////
  auto game = GameOfLife::GameOfLife();

  auto gd = game.get_conwayGrid();

  // this access pattern is weird
  std::cout << (int)gd->at(0).at(0) << std::endl;

  std::cout << game << std::endl;
  ////

  ///// non default grid size
  auto game2 = GameOfLife::GameOfLife(5, 5);

  auto gd2 = game2.get_conwayGrid();

  // this access pattern is weird
  std::cout << (int)gd2->at(0).at(0) << std::endl;

  std::cout << game2 << std::endl;
  ////

  // Test randomInit
  auto game3 = GameOfLife::GameOfLife();
  game3.randomInit();

  auto gd3 = game3.get_conwayGrid();

  // this access pattern is weird
  std::cout << (int)gd3->at(0).at(0) << std::endl;

  std::cout << game3 << std::endl;

  return 0;
}
