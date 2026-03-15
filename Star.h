#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>

class Star
{
private:
    float x;
    float y;
    float width;
    float height;

    sf::RectangleShape shape;

public:
    // Constructor
    Star(float x, float y, float width, float height);

    // Getters
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

    // Setters
    void setX(float newX);
    void setY(float newY);
    void setWidth(float newWidth);
    void setHeight(float newHeight);

    // Update
    void updatePosition(float dx, float dy);
    void setSize(float width, float height);

    // Access the shape for drawing
    sf::RectangleShape& getShape();
};

#endif