#include "../include/renderer.hpp"

Renderer::Renderer(sf::RenderWindow* renderWindow)
    : renderWindow(renderWindow){
    currentFPS = 0;
    lastFPS = 0;

    deltaTimeClock = sf::Clock();
    deltaTime = sf::milliseconds(0);
    currentDeltaTime = sf::milliseconds(0);
}

void Renderer::drawFrame(){
        // Clear window, reset deltatime clock
        deltaTimeClock.reset();
        Renderer::renderWindow->clear(sf::Color::Black);

        // Draw

        // End render frame, capture delta time
        renderWindow->display();
        deltaTime = deltaTimeClock.reset();
        currentDeltaTime += deltaTime;
        currentFPS++;

        // FPS Calc
        if(currentDeltaTime >= sf::seconds(1)){
            currentDeltaTime = sf::Time::Zero;
            lastFPS = currentFPS;
            currentFPS = 0;
        }
}
