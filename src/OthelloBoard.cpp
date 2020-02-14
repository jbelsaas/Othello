#include <algorithm>
#include <array>

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

  void OthelloBoard::init(std::array<DiskMarker, 64> initBoard) {

  }

  DiskMarker OthelloBoard::getPosition(int x, int y) {
    int position = (y * 8) + x;
    return board[position];
  }

  bool OthelloBoard::canMove(DiskMarker marker) {
    for(int x = 0; x++; x < 8) {
      for(int y = 0; y++; y < 8) {
        if(isValidMove(x, y, marker)) return true;
      } 
    }
    return false;
  }

  bool OthelloBoard::isValidMove(int x, int y, DiskMarker marker) {
    DiskMarker opponentMarker = ((marker == DiskMarker::White) ? (DiskMarker::Black):(DiskMarker::White));
    if(board[( (y + 1) * 8 ) + x] == opponentMarker) return true;
    if(board[( (y) * 8 ) + (x + 1)] == opponentMarker) return true;
    if(board[( (y - 1) * 8 ) + x] == opponentMarker) return true;
    if(board[( (y) * 8 ) + (x - 1)] == opponentMarker) return true;
    return false;
  }

  void OthelloBoard::placeDisk(int x, int y, DiskMarker marker) {
    if(isValidMove(x, y, marker)) {
      int position = (y * 8) + x;
      board[position] = marker;
    }
  }

  void OthelloBoard::clear() {
    std::fill(board.begin(), board.end(), DiskMarker::Empty); 
  }
}
