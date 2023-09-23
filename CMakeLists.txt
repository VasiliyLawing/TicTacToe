cmake_minimum_required(VERSION 3.26)

project(TickTackToeRevision)
set(CMAKE_CXX_STANDARD 17)

add_executable(TickTackToeRevision src/main.cc
        src/Board.hh
        src/Board.cc
        src/Game.cpp
        src/Game.h
        src/minimax.cpp
        src/minimax.h
        src/alphaBeta.cpp
        src/alphaBeta.h)

