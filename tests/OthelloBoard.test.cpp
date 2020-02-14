#include <catch2/catch.hpp>

#include "../include/OthelloBoard.hpp"

SCENARIO( "Board can be created and initialized", "[board]") {
  using namespace OthelloEngine;
  IOthelloBoard* board = new OthelloBoard;

  GIVEN ("An Empty board") {
    
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

SCENARIO( "Players can move", "[empty-board-init]") {
  using namespace OthelloEngine;
  IOthelloBoard* board = new OthelloBoard();

  GIVEN( "An Empty board" ) {
    REQUIRE(board->canMove(DiskMarker::White) == false);
    REQUIRE(board->canMove(DiskMarker::Black) == false);
    REQUIRE(board->canMove(DiskMarker::Empty) == false);


    WHEN("Newly Initialized x = 3, y = 2") {
      board->init();
      int x = 3; 
      int y = 2;

      REQUIRE(board->isValidMove(x, y, DiskMarker::White) == true);
      board->placeDisk(x, y, DiskMarker::White);
      REQUIRE(board->getPosition(x, y) == DiskMarker::White);

      board->clear();
      board->init();

      REQUIRE(board->isValidMove(x, y, DiskMarker::Black) == false);
      board->placeDisk(x, y, DiskMarker::Black);
      REQUIRE(board->getPosition(x, y) == DiskMarker::Empty);
    }

    WHEN("Newly Initialized x = 2, y = 3") {
      board->init();
      int x = 2; 
      int y = 3;

      REQUIRE(board->isValidMove(x, y, DiskMarker::White) == true);
      board->placeDisk(x, y, DiskMarker::White);
      REQUIRE(board->getPosition(x, y) == DiskMarker::White);

      board->clear();
      board->init();

      REQUIRE(board->isValidMove(x, y, DiskMarker::Black) == false);
      board->placeDisk(x, y, DiskMarker::Black);
      REQUIRE(board->getPosition(x, y) == DiskMarker::Empty);
    }

    WHEN("Newly Initialized x = 4, y = 5") {
      board->init();
      int x = 4; 
      int y = 5;
      REQUIRE(board->isValidMove(x, y, DiskMarker::White) == true);
      board->placeDisk(x, y, DiskMarker::White);
      REQUIRE(board->getPosition(x, y) == DiskMarker::White);

      board->clear();
      board->init();

      REQUIRE(board->isValidMove(x, y, DiskMarker::Black) == false);
      board->placeDisk(x, y, DiskMarker::Black);
      REQUIRE(board->getPosition(x, y) == DiskMarker::Empty);
    }

    WHEN("Newly Initialized x = 5, y = 4") {
      board->init();
      int x = 5; 
      int y = 4;
      REQUIRE(board->isValidMove(x, y, DiskMarker::White) == true);
      board->placeDisk(x, y, DiskMarker::White);
      REQUIRE(board->getPosition(x, y) == DiskMarker::White);

      board->clear();
      board->init();

      REQUIRE(board->isValidMove(x, y, DiskMarker::Black) == false);
      board->placeDisk(x, y, DiskMarker::Black);
      REQUIRE(board->getPosition(x, y) == DiskMarker::Empty);
    }
  }

  GIVEN("An empty board") {
    WHEN("Ingame and can place -x +y of disk") {
      
    }
  }
}

