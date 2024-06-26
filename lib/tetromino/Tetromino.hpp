// Copyright (2024) ultralapse
#pragma once
#include <tuple>

/*
O Piece - yellow: RGB(255, 255, 0)
I Piece - cyan: RGB(0, 255, 255)
L piece - blue: RGB(0, 0, 255)
J piece - orange: RGB(255, 127, 0)
S piece - green: RGB(0, 255, 0)
Z piece - red: RGB(255, 0, 0)
T piece - purple: RGB(128, 0, 128)
*/
enum Color {
    Y = 1, C, B, O, G, R, P
};

class Tetromino {
 public:
    virtual bool down() {return false;}
    virtual bool lRotate() {return false;}
    virtual bool rRotate() {return false;}
};
