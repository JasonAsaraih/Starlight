#include "Constellation.h"
#include <random>
#include <cmath>

Constellation::Constellation(
    int startX,
    int startY,
    int gridX,
    int gridY,
    float spacingX,
    float spacingY,
    float starWidth,
    float starHeight,
    float noise
)

{
    this->startX = startX;
    this->startY = startY;
    this->gridX = gridX;
    this->gridY = gridY;
    this->spacingX = spacingX;
    this->spacingY = spacingY;
    this->starWidth = starWidth;
    this->starHeight = starHeight;
    this->noise = noise;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-noise, noise);

    for (int x = 0; x < gridX; x++)
    {
        for (int y = 0; y < gridY; y++)
        {
            float posX = x * spacingX + dist(gen) + startX;
            float posY = y * spacingY + dist(gen) + startY;

            stars.emplace_back(posX, posY, starWidth, starHeight);
        }
    }
}

void Constellation::draw(sf::RenderWindow& window)
{
    for (auto& star : stars)
    {
        window.draw(star.getShape());
    }
}

void Constellation::updateZoom(int x, int y, float speed){
    for (Star& star : stars)
    {
        float dx = x-star.getX();
        float dy = y-star.getY();

        float theta = std::atan2(dy, dx);

        float newX = speed * cos(theta);
        float newY = speed * sin(theta);

        float sizeScaler = 0.1;

        star.updatePosition(-newX, -newY);
        if(star.getWidth()+speed*sizeScaler <= 0){
            star.setSize(0, 0);
        }else{
            star.setSize(star.getWidth()+speed*sizeScaler, star.getHeight()+speed*sizeScaler);
        }

    }
}

std::vector<Star>& Constellation::getStars()
{
    return stars;
}