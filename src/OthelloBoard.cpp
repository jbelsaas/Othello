#include <algorithm>

#include "../include/OthelloBoard.hpp"

namespace OthelloEngine {

  OthelloBoard::OthelloBoard() {
    std::fill(board.begin(), board.end(), DiskMarker::Empty);
  }

  void OthelloBoard::init() {
    board[27] = DiskMarker::Black;
    board[28] = DiskMarker::White;
    board[35] = DiskMarker::White;
    board[36] = DiskMarker::Black;
  }

  DiskMarker OthelloBoard::getPosition(int x, int y) {
    int position = (y * 8) + x;
    return board[position];
  }

  bool OthelloBoard::canMove() {
    for(int x = 0; x++; x < 8) {
      for(int y = 0; y++; y < 8) {
        if(isValidMove(x, y)) return true;
      } 
    }
    return false;
  }

  bool OthelloBoard::isValidMove(int x, int y) {
    return true;
  }
}
