/*
* Author: PlayersX (Claire Williams, Lizette Martinez,
                    Christina Martinez, Taylor Robinett)
* Assignment Title: Galaga_Project
* Assignment Description: This program is a recreation of the
*       vintage shooter, Galaga.
* Due Date: 4/25/2018
* Date Created: 4/7/2018
* Date Last Modified: 4/21/2018
*/

#include <SDL.h>
#include "Enemy_Fire.h"

const int WIDTH = 500;
const int HEIGHT = 500;

// Basic enemy bullet constructor
Bullet::Bullet()
{
    x = 0;
    y = 0;
}

// Constructs bullet using enemy ship coordinates
Bullet::Bullet(EnemyShip enemy)
{
    x = enemy.getX() + 11;
    y = enemy.getY() + 25;
}

// De-constructs bullet
Bullet::~Bullet()
{

}

// Gets bullet x coordinate
int Bullet::getBulletX()
{
    return x;
}

// Gets bullet y coordinate
int Bullet::getBulletY()
{
    return y;
}

// Moves enemy bullet
void Bullet::moveBullet()
{
    y += 5;
}

// Renders bullet
void Bullet::renderBullet(SDL_Renderer* field, SDL_Texture* space)
{
    // Creating texture space for bullet
    SDL_Rect bulletSpace;
    bulletSpace.x = x;
    bulletSpace.y = y;
    bulletSpace.h = h;
    bulletSpace.w = w;

    // Rendering bullet
    SDL_RenderCopy(field, space, NULL, &bulletSpace);
}

// Checks for player ship bullet collision
void Bullet::detectPlayerCollision(PlayerShip ship, bool& defeat)
{
    if (ship.getxPos() <= x && (ship.getxPos() + 25) >= x
        && ship.getyPos() <= (y + h) && (ship.getyPos() + 25) >= y
        && active == true)
    {
        active = false;
        defeat = true;
    }
}

// Checks for range overflow
void checkOverflow(int& range, int maxVal)
{
    if (range < maxVal)
    {
        range++;
    }
    else
    {
        range = 0;
    }
}

