#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/engine.hpp"

Engine::Engine()
    : renderer(nullptr) {
    
}

void Engine::mainLoop(){
    // Create the window, initialize renderer
    renderWindow = sf::RenderWindow(sf::VideoMode({1280, 720}), "SFML_Test");
    renderWindow.setVerticalSyncEnabled(true);
    renderWindow.setKeyRepeatEnabled(false);
    renderer = new Renderer(&renderWindow);
    
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

        renderer->drawFrame();
    }
}
