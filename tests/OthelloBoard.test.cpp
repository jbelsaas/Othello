#include <catch2/catch.hpp>

#include "../include/OthelloBoard.hpp"

SCENARIO( "Board can be created and initialized", "[board]") {
  using namespace OthelloEngine;
  GIVEN ("An Empty board") {
    IOthelloBoard* board = new OthelloBoard;
    
    for(int x = 0; x < 8; x++) {
      for(int y = 0; y < 8; y++) {
        REQUIRE(board->getPosition(x, y) == DiskMarker::Empty);
      }
    }
    WHEN( "Initializing" ) {
      board->init();

      for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
          if( (x == 3 && y == 3) || (x == 4 && y == 4)) {
            REQUIRE(board->getPosition(x, y) == DiskMarker::Black);
          }
          else if( (x == 3 && y == 4) || (x == 4 && y == 3)) {
            REQUIRE(board->getPosition(x, y) == DiskMarker::White);
	  }
          else {
            REQUIRE(board->getPosition(x, y) == DiskMarker::Empty);
          }
        }
      }

    }
  }
}

SCENARIO( "Players can move", "[board]") {
  using namespace OthelloEngine;
  GIVEN( "An Empty board" ) {
    IOthelloBoard* board = new OthelloBoard();

    REQUIRE(board->canMove() == false);
  }
}
