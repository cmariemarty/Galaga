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

#ifndef ENEMYSHIP_H_INCLUDED
#define ENEMYSHIP_H_INCLUDED

#include <SDL.h>

class EnemyShip
{
    private:
        int x, y;
        int ShipH = 25;
        int ShipW = 25;

    public:
        EnemyShip();
        ~EnemyShip();
        int getX();
        int getY();
        void enemyMove();
        void renderShip(SDL_Renderer* field, SDL_Texture* space);
        void checkCollision();
};

#endif // ENEMYSHIP_H_INCLUDED
