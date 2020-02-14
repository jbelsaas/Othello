#ifndef IOthelloBoard_Interface_HPP
#define IOthelloBoard_Interface_HPP

#include <array>

#include "../include/OthelloUtils.hpp"

namespace OthelloEngine {
  class IOthelloBoard {
    public:
      IOthelloBoard() {};
      virtual void init() = 0;
      virtual void init(std::array<DiskMarker, 64> initBoard) = 0;
      virtual DiskMarker getPosition(int x, int y) = 0;
      virtual bool canMove(DiskMarker marker) = 0;
      virtual bool isValidMove(int x, int y, DiskMarker marker) = 0;
      virtual void placeDisk(int x, int y, DiskMarker marker) = 0;
      virtual void clear() = 0;
  };
}
#endif
