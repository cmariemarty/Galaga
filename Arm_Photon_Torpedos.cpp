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

#include "Arm_Photon_Torpedos.h"
#include "PlayerShip.h"
#include <SDL.h>
#include "EnemyShip.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int START_X = (WIDTH / 2) - 12;
const int START_Y = (HEIGHT - 50);

// Constructs basic player torpedo
PhotonTorpedo::PhotonTorpedo()
{
    currX = START_X + 11;
    currY = START_Y - 15;

}

// Constructs player bullet
PhotonTorpedo::PhotonTorpedo(PlayerShip ship)
{
    currX = ship.getxPos() + 11;
    currY = ship.getyPos() - 15;
}

// De-constructs player bullet
PhotonTorpedo::~PhotonTorpedo()
{

}

// Sets torpedo x coordinate
void PhotonTorpedo::setcurrX(int newX)
{
    currX = newX;
}

// Moves photon torpedo
void PhotonTorpedo::Move()
{
    currY -= 10;
}

// Gets Torpedo y coordinate
int PhotonTorpedo::getcurrX()
{
    return currX;
}

// Gets torpedo x coordinate
int PhotonTorpedo::getcurrY()
{
    return currY;
}

// Renders bullet to game window
void PhotonTorpedo::renderTorpedo(SDL_Renderer* field, SDL_Texture* space)
{
    // Creating texture space for bullet
    SDL_Rect torpedoSpace;
    torpedoSpace.x = currX;
    torpedoSpace.y = currY;
    torpedoSpace.h = shotHeight;
    torpedoSpace.w = shotWidth;

    // Rendering bullet
    SDL_RenderCopy(field, space, NULL, &torpedoSpace);
}

// Checking for collisions
void PhotonTorpedo::checkCollision(EnemyShip ship[], bool& collide,
                                   int numOfEnemies, int& numOfDestroyed,
                                   int& killCount)
{
    for (int i = 0; i < numOfEnemies; i++)
    {
        if (ship[i].getX() <= currX && (ship[i].getX() + 25) >= currX
            && (ship[i].getY() + 25) > currY && ship[i].getY() < currY
            && ship[i].isDestroyed == false && active == true)
        {
            collide = true;
            ship[i].isSplosion = true;
            active = false;
            numOfDestroyed++;
            killCount++;
        }
    }
}

// Checking for overcapacity of shot array
void checkShotCount(int& shotCount)
{
    if (shotCount == 500)
    {
        shotCount = 0;
    }
}
