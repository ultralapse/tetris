// Copyright (2024) ultralapse

#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <memory>

#include "tetromino/Tetromino.hpp"
#include "tetromino/I.hpp"
#include "tetromino/J.hpp"
#include "tetromino/L.hpp"
#include "tetromino/O.hpp"
#include "tetromino/S.hpp"
#include "tetromino/T.hpp"
#include "tetromino/Z.hpp"


#define BOARD_ROWS 20
#define BOARD_COLS 10


using std::vector;
using std::stack;
using std::unique_ptr;

class Board {
 private:
    vector<Color> board;
    stack<unique_ptr<Tetromino>> next;
    unique_ptr<Tetromino> cur;
    unique_ptr<Tetromino> hold;
    

    unsigned int index(const unsigned int &row, const unsigned int &col);
    void write();

 public:
    Board() : board(BOARD_ROWS * BOARD_COLS) {}

    // Makes pieces fall
    bool update();

    // Makes piece move left
    bool left();

    // Makes piece move right
    bool right();
};
