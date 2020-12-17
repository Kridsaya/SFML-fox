#include "Bloodup.h"
#include<iostream>

Bloodup::Bloodup(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    row = 0;
    this->Bup = 0;
    this->Bdown = 0;
    this->X2 = 0;
    body.setSize(sf::Vector2f(55.0f, 55.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Bloodup::~Bloodup()
{
}

void Bloodup::update(float deltaTime, Player player)
{
    animation.updateItemBloodup(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        this->Bup++;
        this->Bdown += 10;
        this->X2 += 20;
        body.setPosition(-3000.0f, 350.0f);
    }
}

void Bloodup::draw(sf::RenderWindow& window)
{
    window.draw(body);
}