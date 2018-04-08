/*
* Author: PlayersX (Claire Williams, Lizette Martinez,
                    Christina Martinez, Taylor Robinett)
* Assignment Title: Galaga_Project
* Assignment Description: This program is a recreation of the
*       vintage shooter, Galaga. This file dictates the
*       creation and movement of the player ship
* Due Date: 4/25/2018
* Date Created: 4/7/2018
* Date Last Modified: 4/7/2018
*/

#include "PlayerShip.h"
#include <SDL.h>

const int WIDTH = 500;
const int HEIGHT = 500;
const int START_X = (WIDTH / 2) - 12;
const int START_Y = (HEIGHT - 50);

// Creating player ship
PlayerShip::PlayerShip()
{
    xPos = START_X;
    yPos = START_Y;
}

// De-constructs player ship
PlayerShip::~PlayerShip()
{

}

// Creates twin ship
PlayerShip::PlayerShip(int startX)
{
    xPos = startX;
}

// Gets the ships x coordinate
int PlayerShip::getxPos()
{
    return xPos;
}

// Gets the ships y coordinate
int PlayerShip::getyPos()
{
    return yPos;
}

/*int PlayerShip::getShipH()
{
    return ShipH;
}

int PlayerShip::getShipW()
{
    return ShipW;
}*/

// Renders player ship to screen
void PlayerShip::renderShip(SDL_Renderer* field, SDL_Texture* space)
{
    // Creating texture space for ship
    SDL_Rect shipSpace;
    shipSpace.x = xPos;
    shipSpace.y = yPos;
    shipSpace.h = ShipH;
    shipSpace.w = ShipW;

    // Rendering ship
    SDL_RenderCopy(field, space, NULL, &shipSpace);
}

// Moves the ship around
void PlayerShip::setxPos(int newX)
{
    if (xPos < 10)
    {
        xPos = 11;
    }
    else if (xPos > (WIDTH - ShipW) -10)
    {
        xPos = (WIDTH - ShipW) -11;
    }
    else
    {
        xPos += newX;
    }
}
