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

#ifndef ARM_PHOTON_TORPEDOS_H_INCLUDED
#define ARM_PHOTON_TORPEDOS_H_INCLUDED

#include <SDL.h>
#include "PlayerShip.h"
#include "EnemyShip.h"

class PhotonTorpedo
{
    private:
        int currX, currY;
        int shotWidth = 3;
        int shotHeight = 15;

    public:
        PhotonTorpedo();
        PhotonTorpedo(PlayerShip);
        ~PhotonTorpedo();
        void setcurrX(int newX);
        int getcurrX();
        int getcurrY();
        void Move();
        void renderTorpedo(SDL_Renderer* field, SDL_Texture* space);
        void checkCollision(EnemyShip, bool& collide, bool& enemyCollision,
                            bool isDestroyed);
};

void checkShotCount(int& shotCount);

#endif // ARM_PHOTON_TORPEDOS_H_INCLUDED
