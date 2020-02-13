#ifndef OTHELLO_BOARD_HPP
#define OTHELLO_BOARD_HPP

#include <array>

#include "../include/IOthelloBoard.hpp"
namespace OthelloEngine {
  class OthelloBoard : public IOthelloBoard {
    public:
      OthelloBoard();
      void init();
      DiskMarker getPosition(int x, int y);
      bool canMove();
      bool isValidMove(int x, int y);
    private:
     std::array<DiskMarker, 64> board;
  };
}

#endif
