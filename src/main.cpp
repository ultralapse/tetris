// Copyright (2024) ultralapse

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Game.hpp"

#define HEIGHT 800
#define WIDTH 600

int main(int argc, char **argv) {
    sf::Window window(sf::VideoMode(HEIGHT, WIDTH), "Tetris");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
    }
    return 0;
}
