cmake_minimum_required(VERSION 3.26)

project(TickTackToeRevision)
set(CMAKE_CXX_STANDARD 17)

add_executable(TickTackToeRevision src/main.cc
        src/Board.hh
        src/Board.cc
        src/Minimax.hh
        src/Minimax.cc)

