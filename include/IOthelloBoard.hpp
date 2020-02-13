#ifndef IOthelloBoard_Interface_HPP
#define IOthelloBoard_Interface_HPP
#include "../include/OthelloUtils.hpp"

namespace OthelloEngine {
  class IOthelloBoard {
    public:
      IOthelloBoard() {};
      virtual void init() = 0;
      virtual DiskMarker getPosition(int x, int y) = 0;
      virtual bool canMove() = 0;
      virtual bool isValidMove(int x, int y) = 0;
  };
}
#endif
