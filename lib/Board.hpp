// Copyright (2024) ultralapse

#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

class Board: public sf::Drawable {
 private:
    vector<Color> board;
    stack<unique_ptr<Tetromino>> next;
    unique_ptr<Tetromino> cur;
    unique_ptr<Tetromino> hold;
    int _sq;

    unsigned int index(const unsigned int &row, const unsigned int &col) const;
    sf::Color color(Color c) const;


    void write();

 public:
    Board(int sq) : board(BOARD_ROWS * BOARD_COLS), _sq(sq) {}

    // Makes pieces fall
    bool update();

    // Makes piece move left
    bool left();

    // Makes piece move right
    bool right();

 protected:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
