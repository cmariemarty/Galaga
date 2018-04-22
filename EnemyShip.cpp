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
#include "EnemyShip.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int STARTING_X = (WIDTH / 2) - 40;

// Basic enemy ship constructor
EnemyShip::EnemyShip()
{
    x = STARTING_X;
    y = 100;
}

// Constructs enemy ships with different coordinates
EnemyShip::EnemyShip(int position)
{
    if (position < 5)
    {
        x = (STARTING_X) + (position * 40);
        y = 100;
    }
    else if (position >= 5 && position < 7)
    {
        x = (STARTING_X) + ((position - 5) * 160);
        y = 150;
    }
    else if (position >= 7 && position < 10)
    {
        x = (STARTING_X) + ((position - 6) * 40);
        y = 150;
    }
    else if (position == 10)
    {
        x = (STARTING_X) + (80);
        y = 50;
    }
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
    if (moveFrame >= 0 && moveFrame < 100)
    {
        x -= 1;
    }
    else if (moveFrame >= 100 && moveFrame < 200)
    {
        x += 1;
    }
    if (moveFrame < 200)
    {
        moveFrame++;
    }
    else
    {
        moveFrame = 0;
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
