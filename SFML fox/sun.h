#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class sun
{
public:

    sun(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~sun();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    int iscollide()
    {
        if (Csun == 1) {
            Csun--;
            return 1;
        }
    }

    Collision GetCollider() { return Collision(body); }

private:
    int row;
    int Csun;
    int collide;
    sf::RectangleShape body;
    Animation animation;
};

