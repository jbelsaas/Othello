#ifndef OTHELLO_BOARD_HPP
#define OTHELLO_BOARD_HPP

#include <array>

#include "../include/IOthelloBoard.hpp"
namespace OthelloEngine {
  class OthelloBoard : public IOthelloBoard {
    public:
      OthelloBoard();
      void init();
      void init(std::array<DiskMarker, 64> initBoard);
      DiskMarker getPosition(int x, int y);
      bool canMove(DiskMarker marker);
      bool isValidMove(int x, int y, DiskMarker marker);
      void placeDisk(int x, int y, DiskMarker marker);
      void clear();
    private:
      std::array<DiskMarker, 64> board;
  };
}

#endif
