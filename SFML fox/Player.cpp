#include "Player.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation(texture, imageCount, switchTime)
{
    this->numStar = 0;
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    //this->buffX10 = false;
    this->sound = false;
    //this->buffTimer = 0;
    this->checkjump = 0;

    row = 0;
    canJump = true;
    slide = false;
    bullet = false;
    faceRight = true;

    body.setSize(sf::Vector2f(120.0f, 120.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(200.0f, 520.0f);
    body.setTexture(texture);

}

Player::~Player()
{
}


void Player::update(float deltaTime, std::vector<sun*>& stars)
{
    velocity.x = 0.0f;
    //slide = false;
    bullet = false;

   // if (slide == false) {
   //     body.setSize(sf::Vector2f(120.0f, 150.0f));
   // }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        bullet = true;
        row = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = speed * 2.5f; slide = false; bullet = false;
        this->check = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -speed * 2.5f;
        this->check = 2;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && canJump == true) {
        canJump = false;
        velocity.y = -sqrtf(2.0f * 1500.0f * jumpHeight); //¡ÃÐâ´´
        this->checkjump++;
    }
    velocity.y += 1500.0f * deltaTime; //¡ÃÐâ´´
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocity.x = speed * 3.0f;
        slide = true;
        if (slide == true) {
            body.setSize(sf::Vector2f(120.0f, 130.0f));
        }
    } */
    if (velocity.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 1;

        if (velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
        velocity.x = speed * 4.0f;
    }
    if (velocity.x == 0 && bullet == false) {
        row = 0;
    }
    else {
        if (velocity.x > 0.0f) {
            if (slide == true) {
                row = 3;
            }
            else {
                row = 1;
            }
        }
        if (velocity.x < 0.0f) {
            row = 1;
        }
    }
    animation.update(row, deltaTime, bullet, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
    this->updateNumstar(deltaTime, stars);
} 

void Player::updateNumstar(float deltaTime, std::vector<sun*>& stars) {
 /*   for (int i = 0; i < X2Vector.size(); i++) {
        if (this->GetCollider().CheckCollision(X2Vector[i].GetCollider())) {
            this->buffX10 = true;
            X2Vector[i].setPosition(-100.0f, 30.0f);
        }
    }
    if (this->buffX10 == true) {
        buffTimer += deltaTime;
        if (buffTimer >= 10) {
            buffTimer = 0;
            this->buffX10 = false;
        }
    } */
    for (int i = 0; i < stars.size(); i++) {
        if (this->GetCollider().CheckCollision(stars[i]->GetCollider())) {
            soundstar.loadFromFile("arts/item.ogg");
            Soundss.setBuffer(soundstar);
            Soundss.play();
           Soundss.setVolume(5.0f);
            if (this->buffX10 == true) {
                this->numStar += 10;
            }
            else {
                this->numStar += 1;
            }
            this->sound = true;
            delete stars[i];
            stars.erase(stars.begin() + i);
            stars.shrink_to_fit();
        }
        else {
            this->sound = false;
        }
    }
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f) {
        //left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f) {
        //right
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f) {
        //bottom
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f) {
        //top
        velocity.y = 0.0f;
    }
}
void Player::HPbar(float deltaTime, Player player, sf::Vector2f pos)
{
    body.setPosition(pos.x, pos.y - 50.0f);
    //animation.updatedog(row, deltaTime);
    body.setTextureRect(animation.uvRect);
}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
void Player::SetPosition(float x, float y)
{
    body.setPosition(x, y);
}
void Player::RESET() {
    if (body.getPosition().y >= 600) {
        body.setPosition(200, 520);
    }
}
void Player::ResetNumstar() {
    this->numStar = 0;
    this->buffX10 = false;
}