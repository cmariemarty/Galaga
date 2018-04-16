/*
* Author: PlayersX (Claire Williams, Lizette Martinez,
                    Christina Martinez, Taylor Robinett)
* Assignment Title: Galaga_Project
* Assignment Description: This program is a recreation of the
*       vintage shooter, Galaga. This file dictates the
*       creation and movement of the player ship
* Due Date: 4/25/2018
* Date Created: 4/7/2018
* Date Last Modified: 4/12/2018
*/

#include <SDL.h>
#include "EnemyShip.h"

const int WIDTH = 500;
const int HEIGHT = 500;

// Basic enemy ship constructor
EnemyShip::EnemyShip()
{
    x = (WIDTH / 2) + 25;
    y = 100;
}

// Enemy ship de-constructor
EnemyShip::~EnemyShip()
{

}

// Gets enemy ship x position
int EnemyShip::getX()
{
    return x;
}

// Gets enemy ship y position
int EnemyShip::getY()
{
    return y;
}

// Moving enemy ship
void EnemyShip::enemyMove()
{
    static int frames = 0;
    if (frames >= 0 && frames < 100)
    {
        x -= 1;
    }
    else if (frames >= 100 && frames < 200)
    {
        x += 1;
    }
    if (frames < 200)
    {
        frames++;
    }
    else
    {
        frames = 0;
    }
}

// Renders enemy ship
void EnemyShip::renderShip(SDL_Renderer* field, SDL_Texture* space)
{
    SDL_Rect enemyShip;
    enemyShip.x = x;
    enemyShip.y = y;
    enemyShip.h = ShipH;
    enemyShip.w = ShipW;
    SDL_RenderCopy(field, space, NULL, &enemyShip);
}

// Checks if enemy ship is shot
/*void EnemyShip::checkCollision()
{

}*/
