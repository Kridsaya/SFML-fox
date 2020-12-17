#include "sun.h"
#include<iostream>
sun::sun(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
	animation(texture, imageCount, switchTime)
{
	Csun = 0;
	collide = 0;
	row = 0;
	body.setSize(sf::Vector2f(45.0f, 45.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

sun::~sun()
{
}

void sun::update(float deltaTime)
{
	animation.updatestar(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void sun::draw(sf::RenderWindow& window)
{
	window.draw(body);
}