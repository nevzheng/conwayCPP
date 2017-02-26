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
  // auto game = GameOfLife::GameOfLife(x, y);
  // create new game of life object
  ///
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
  auto game3 = GameOfLife::GameOfLife(4, 4);
  // auto game3 = GameOfLife::GameOfLife();
  game3.randomInit();

  auto gd3 = game3.get_conwayGrid();

  // this access pattern is weird
  std::cout << (int)gd3->at(0).at(0) << std::endl;

  std::cout << "Testing"
            << "\n";
  std::cout << game3 << std::endl;

  for (int i = 0; i < 1; ++i) {
    game3.iterateGrid();
    std::cout << game3 << std::endl;
  }

  char t = 0x15;
  std::cout << (int)GameOfLife::getNeighborCount(t) << '\n';
  GameOfLife::setNeighborCount(t, char(5));
  std::cout << (int)GameOfLife::getNeighborCount(t) << '\n';

  std::cout << "Working" << std::endl;
  conwayGrid test_grid{{0, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0},
                       {0, 0, 3, 0, 0},
                       {0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0}};

  for (auto &arr : test_grid) {
    for (auto &x : arr) {
      std::cout << x << "\n";
    }
  }

  auto gd5 = GameOfLife(test_grid);

  std::cout << "Working" << std::endl;
  std::cout << gd5 << std::endl;

  for (int i = 0; i < 10; ++i) {
    gd5.iterateGrid();
    std::cout << gd5 << std::endl;
  }

  return 0;
}
