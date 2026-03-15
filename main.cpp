#include <SFML/Graphics.hpp>
#include "Constellation.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1200, 1000}), "Constellation");
    window.setFramerateLimit(60);

    Constellation midStars(
        0,    // startX
        0,    // startY
        15,     // gridX
        15,     // gridY
        100,     // spacingX
        100,     // spacingY
        3,      // star width
        3,      // star height
        50       // noise
    );

    Constellation largeStars(
        0,    // startX
        0,    // startY
        7,     // gridX
        7,     // gridY
        200,     // spacingX
        200,     // spacingY
        5,      // star width
        5,      // star height
        50       // noise
    );

    Constellation smallStars(
        0,    // startX
        0,    // startY
        7,     // gridX
        7,     // gridY
        200,     // spacingX
        200,     // spacingY
        1,      // star width
        1,      // star height
        50       // noise
    );

    sf::Clock clock;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

        window.clear();

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            smallStars.updateZoom(mousePos.x, mousePos.y, 0.5);
            midStars.updateZoom(mousePos.x, mousePos.y, 0.5);
            largeStars.updateZoom(mousePos.x, mousePos.y, 0.5);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            smallStars.updateZoom(mousePos.x, mousePos.y, -0.5);
            midStars.updateZoom(mousePos.x, mousePos.y, -0.5);
            largeStars.updateZoom(mousePos.x, mousePos.y, -0.5);
        }
        
        smallStars.draw(window);
        midStars.draw(window);
        largeStars.draw(window);



        window.display();
    }
}