#ifndef CONSTELLATION_H
#define CONSTELLATION_H

#include <vector>
#include "Star.h"

class Constellation
{
private:
    std::vector<Star> stars;

    int gridX;
    int gridY;

    float spacingX;
    float spacingY;

    float starWidth;
    float starHeight;

    float startX;
    float startY;

    float noise;

public:
    Constellation(
        int startX,
        int startY,
        int gridX,
        int gridY,
        float spacingX,
        float spacingY,
        float starWidth,
        float starHeight,
        float noise
    );

    void updateZoom(int x, int y, float speed);
    void draw(sf::RenderWindow& window);

    std::vector<Star>& getStars();
};

#endif