#include <cstdlib>
#include <ctime>
#include <iostream>

#include "GameOfLife.hpp"

GameOfLife::GameOfLife() {
  m_grid.resize(m_rows);
  std::vector<std::vector<char>>::iterator it;
  // con_rowIterator it;

  for (it = m_grid.begin(); it != m_grid.end(); ++it) {
    it->resize(m_cols);
    std::for_each(it->begin(), it->end(), [](char &n) { n = (char)0; });
  }
}

GameOfLife::GameOfLife(int rows, int cols) {
  m_rows = rows;
  m_cols = cols;
  m_grid.resize(m_rows);
  std::vector<std::vector<char>>::iterator it;
  for (it = m_grid.begin(); it != m_grid.end(); ++it) {
    it->resize(m_cols);
    std::for_each(it->begin(), it->end(), [](char &n) { n = (char)0; });
  }
}

std::ostream &operator<<(std::ostream &out, GameOfLife const &inst) {
  auto gd = inst.m_grid;
  auto dims = std::make_pair(inst.m_rows, inst.m_cols);

  for (int i = 0; i < dims.first; ++i) {
    for (int j = 0; j < dims.second; ++j) {
      char t = (GameOfLife::getState((gd[i][j])) ? 'i' : '.');
      //   std::cout << (int)t << "\n";
      out << t << " ";
    }
    out << "\n";
  }
  return out;
}

conwayGrid *GameOfLife::get_conwayGrid() { return &m_grid; }

std::pair<int, int> GameOfLife::get_dimensions() {
  return std::make_pair(m_cols, m_rows);
}

void GameOfLife::randomInit() {

  for (auto it = m_grid.begin(); it != m_grid.end(); ++it) {
    for (auto x = it->begin(); x != it->end(); ++x) {
      if (rand() % 2) {
        GameOfLife::setCell(*x);
      }
    }
    for (int i = 1; i < m_rows - 1; ++i) {
      for (int j = 1; j < m_cols - 1; ++j) {
        char count = GameOfLife::getState(m_grid[i + 1][j]) +
                     GameOfLife::getState(m_grid[i][j + 1]) +
                     GameOfLife::getState(m_grid[i - 1][j]) +
                     GameOfLife::getState(m_grid[i][j - 1]);
        GameOfLife::setNeighborCount(m_grid[i][j], count);
        // std::cout << (int)count << "\n";
      }
    }
    // std::for_each(it->begin(), it->end(),
    //   [](char &n) { n = (char)(rand() % 2); });
  }
}

void GameOfLife::iterateGrid() {
  conwayGrid n_grid = m_grid;
  for (int i = 01; i < m_rows - 1; ++i) {
    for (int j = 1; j < m_cols - 1; ++j) {
      char count = GameOfLife::getNeighborCount(m_grid[i + 1][j]) +
                   GameOfLife::getNeighborCount(m_grid[i][j + 1]) +
                   GameOfLife::getNeighborCount(m_grid[i - 1][j]) +
                   GameOfLife::getNeighborCount(m_grid[i][j - 1]);
      GameOfLife::setNeighborCount(n_grid[i][j], count);
      if (GameOfLife::getState(m_grid[i][j])) {
        if (count < 2 || count > 3) {
          GameOfLife::unsetCell(n_grid[i][j]);
        } else if (count == 2 || count == 3) {
          GameOfLife::setCell(n_grid[i][j]);
        }
      } else {
        if (count == 3) {
          GameOfLife::setCell(n_grid[i][j]);
        }
      }
      // std::cout << (int)count << "\n";
    }
  }
  m_grid = n_grid;
}

// bitwise operators
inline void GameOfLife::setCell(char &cell) { cell |= 1; }
inline void GameOfLife::unsetCell(char &cell) { cell &= ~1; }
inline char GameOfLife::getState(char &cell) { return cell & 1; };

inline char GameOfLife::getNeighborCount(char &cell) {
  char copy = cell;
  return (copy >> 1) & (0x0F);
}
inline void GameOfLife::setNeighborCount(char &cell, char count) {
  cell |= (count << 1) | (cell | 1);
}
