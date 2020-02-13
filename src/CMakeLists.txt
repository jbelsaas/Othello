set(TARGET_NAME othello_board)

add_library(${TARGET_NAME}
  OthelloBoard.cpp
)

target_include_directories(${TARGET_NAME}
  INTERFACE ./)

file(GLOB SOURCES "*.cpp")

add_executable(othello ${SOURCES})

install(TARGETS ${TARGET_NAME}
  ARCHIVE DESTINATION lib/)
