#pragma once

#include "renderer.hpp"

class Engine{
    public:
        Renderer* renderer;
        sf::RenderWindow renderWindow;
        sf::Time deltaTime;
        int fps;

        Engine();
        void mainLoop();
};
