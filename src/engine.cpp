#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/engine.hpp"

Engine::Engine()
    : renderer(nullptr), 
    deltaTime(sf::Time::Zero),
    fps(1000) {}

void Engine::mainLoop(){
    // Create the window, initialize renderer
    renderWindow = sf::RenderWindow(sf::VideoMode({1280, 720}), "SFML_Test");
    renderWindow.setVerticalSyncEnabled(true);
    renderWindow.setKeyRepeatEnabled(false);
    renderer = new Renderer(&renderWindow);

    // Create deltaTime clock
    sf::Clock deltaTimeClock;
    
    // Run the program as long as the window is open
    while (Engine::renderWindow.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = renderWindow.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()){
                renderWindow.close();
            }   

            // Key presses
            if(const auto& keyPressed = event->getIf<sf::Event::KeyPressed>()){
                std::cout << "Key pressed: " << static_cast<int>(keyPressed->scancode) << std::endl;
            }
        }

        // Rendering
        renderer->drawFrame();

        // Clock deltatime
        deltaTime = deltaTimeClock.restart();
        deltaTime.asMilliseconds() == 0 ? fps = 1000 : fps = 1000 / deltaTime.asMilliseconds();
        std::cout << "DeltaTime: " << deltaTime.asMilliseconds() << " FPS: " << fps << std::endl;
    }
}
