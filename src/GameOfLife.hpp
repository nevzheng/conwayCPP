#pragma once

#include <string>
#include <utility>
#include <vector>

typedef std::vector<std::vector<char>> conwayGrid;

class GameOfLife {
private:
  int m_rows = 10;
  int m_cols = 10;
  conwayGrid m_grid;

public:
  // Constructors
  GameOfLife();
  GameOfLife(int m_rows, int m_cols);

  // destructor
  ~GameOfLife() = default;

  // getters
  conwayGrid *get_conwayGrid();
  std::pair<int, int> get_dimensions();

  // GameOfLife(const GameOfLife &other) = default;
  // GameOfLife(GameOfLife &&other) = default;
  // GameOfLife &operator=(const GameOfLife &other) = default;
  // GameOfLife &operator=(GameOfLife &&other) = default;

  // printing
  friend std::ostream &operator<<(std::ostream &out, GameOfLife const &inst);

  void randomInit();

  void iterateGrid();

  // bitwise operators
  // to do think about inlining these
  static void setCell(char &cell);
  static void unsetCell(char &cell);
  static char getState(char &cell);
  static char getNeighborCount(char &cell);
  static char countNeighbors(conwayGrid m_grid, int x, int y);
  static void setNeighborCount(char &cell, char count);
};
