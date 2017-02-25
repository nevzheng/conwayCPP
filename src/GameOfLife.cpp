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
  // out << inst.toString();
  auto dims = std::make_pair(inst.m_rows, inst.m_cols);

  for (int i = 0; i < dims.first; ++i) {
    for (int j = 0; j < dims.second; ++j) {
      char t = ((gd.at(i).at(j)) ? 'o' : 'x');
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

void ::GameOfLife::randomInit() {
  // CHANGE BY REFERENCE !!!!!!;
  // auto gd = &m_grid;
  // out << inst.toString();
  // auto dims = std::make_pair(m_rows, m_cols);

  for (auto it = m_grid.begin(); it != m_grid.end(); ++it) {
    it->resize(m_cols);
    std::for_each(it->begin(), it->end(),
                  [](char &n) { n = (char)(rand() % 2); });
  }
}
