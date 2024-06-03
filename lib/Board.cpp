// Copyright (2024) ultralapse

#include "Board.hpp"

unsigned int Board::index(const unsigned int &row, const unsigned int &col) {
    if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS) {
        throw std::invalid_argument("Out of Bounds");
    }
    return (row * BOARD_COLS + col);
}
