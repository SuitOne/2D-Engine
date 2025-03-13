#include "../include/renderer.hpp"

Renderer::Renderer(sf::RenderWindow* renderWindow)
    : renderWindow(renderWindow){

}

void Renderer::drawFrame(){
        // Clear window
        Renderer::renderWindow->clear(sf::Color::Black);

        // Draw

        // End render frame
        renderWindow->display();
}
