// Copyright (2024) ultralapse

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Game.hpp"

#define HEIGHT 20
#define WIDTH 10

int main(int argc, char **argv) {


    int square_size = std::stoi(argv[1]);

    int height = HEIGHT * square_size;
    int width = WIDTH * square_size;

    sf::RenderWindow window(sf::VideoMode(width, height), "Tetris");
    Game g(square_size);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.draw(g);
        window.display();
    }
    return 0;
}
