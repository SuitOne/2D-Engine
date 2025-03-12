#pragma once

#include <SFML/Graphics.hpp>

class Renderer{
    private:
        int currentFPS; // Shows frame count for this 1000ms
        int lastFPS; // Shows latest FPS count

        sf::Clock deltaTimeClock; // Used to count render time
        sf::Time deltaTime; // Shows latest delta time for full frame
        sf::Time currentDeltaTime; // Shows delta time count for this frame so far 

        sf::RenderWindow* renderWindow;

    public:
        Renderer(sf::RenderWindow* renderWindow);

        void drawFrame();

        int getFPS() { return lastFPS; }
        sf::Time getDeltaTime() {return deltaTime; }
};
