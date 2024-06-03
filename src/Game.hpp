// Copyright (2024) ultralapse

#pragma once
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../lib/Board.hpp"

#define BOARD_ROWS 20
#define BOARD_COLS 10

using std::vector;

class Game: public sf::Drawable {
 private:
    Board b;

 public:
    explicit Game(int sq): b(sq) {}

 protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
