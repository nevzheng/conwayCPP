#include <iostream>

#include "GameOfLife.hpp"

GameOfLife::GameOfLife() {
  m_grid.resize(m_rows);
  std::vector<std::vector<char>>::iterator it;
  // con_rowIterator it;
  for (it = m_grid.begin(); it != m_grid.end(); ++it) {
    it->resize(m_cols);
  }
}

GameOfLife::GameOfLife(int rows, int cols) {}

std::ostream &operator<<(std::ostream &out, GameOfLife const &inst) {
  auto gd = inst.m_grid;
  // out << inst.toString();
  auto dims = std::make_pair(inst.m_rows, inst.m_cols);

  for (int i = 0; i < dims.first; ++i) {
    for (int j = 0; j < dims.second; ++j) {
      out << gd.at(0).at(0) << " ";
    }
    out << "\n";
  }
  return out;
}

conwayGrid *GameOfLife::get_conwayGrid() { return &m_grid; }

std::pair<int, int> GameOfLife::get_dimensions() {
  return std::make_pair(m_cols, m_rows);
}
