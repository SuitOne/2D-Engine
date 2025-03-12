#pragma once

#include "renderer.hpp"

class Engine{
    public:
        Renderer* renderer;
        sf::RenderWindow renderWindow;

        Engine();
        void boot();
        void mainLoop();
};
