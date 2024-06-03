// Copyright (2024) ultralapse

#include "Board.hpp"

sf::Color Board::color(Color c) const {
    switch (c) {
        case Y:
            return sf::Color(255, 255, 0);
        case C:
            return sf::Color(0, 255, 255);
        case B:
            return sf::Color(0, 0, 255);
        case O:
            return sf::Color(255, 127, 0);
        case G:
            return sf::Color(0, 255, 0);
        case R:
            return sf::Color(255, 0, 0);
        case P:
            return sf::Color(128, 0, 128);
        default:
            return sf::Color(0, 0, 0);
    }
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            sf::Vector2f pos(j * _sq, i * _sq);
            sf::RectangleShape rect(sf::Vector2f(_sq, _sq));

            sf::Color col = color(board[index(i, j)]);

            rect.setPosition(pos);
            rect.setFillColor(col);
            target.draw(rect);
        }
    }
}

unsigned int Board::index(const unsigned int &row, const unsigned int &col) const {
    if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS) {
        throw std::invalid_argument("Out of Bounds");
    }
    return (row * BOARD_COLS + col);
}
