#pragma once

#include <string>
#include <utility>
#include <vector>

typedef std::vector<std::vector<char>> conwayGrid;
// typedef std::vector<std::vector<char>>::iterator con_rowIterator;
// typedef std::vector<char>::iterator con_colIterator;

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

  friend std::ostream &operator<<(std::ostream &out, GameOfLife const &inst);
};
