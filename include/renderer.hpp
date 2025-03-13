#pragma once

#include <SFML/Graphics.hpp>

class Renderer{
    private:
        sf::RenderWindow* renderWindow;

    public:
        Renderer(sf::RenderWindow* renderWindow);

        void drawFrame();
};
