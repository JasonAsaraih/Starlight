#include "Star.h"

// Constructor
Star::Star(float x, float y, float width, float height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    shape.setSize({width, height});
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color::White);
}

// Getters
float Star::getX() const
{
    return x;
}

float Star::getY() const
{
    return y;
}

float Star::getWidth() const
{
    return width;
}

float Star::getHeight() const
{
    return height;
}

// Setters
void Star::setX(float newX)
{
    x = newX;
    shape.setPosition({x, y});
}

void Star::setY(float newY)
{
    y = newY;
    shape.setPosition({x, y});
}

void Star::setWidth(float newWidth)
{
    width = newWidth;
    shape.setSize({width, height});
}

void Star::setHeight(float newHeight)
{
    height = newHeight;
    shape.setSize({width, height});
}

// Update position
void Star::updatePosition(float dx, float dy)
{
    x += dx;
    y += dy;
    shape.move({dx, dy});
}

void Star::setSize(float width, float height)
{
    this->width = width;
    this->height = height;
    shape.setOrigin({width / 2.0f, height / 2.0f});
    shape.setSize({width, height});
}

// Get shape for drawing
sf::RectangleShape& Star::getShape()
{
    return shape;
}