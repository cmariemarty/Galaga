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

#ifndef PLAYERSHIP_H_INCLUDED
#define PLAYERSHIP_H_INCLUDED

#include <SDL.h>

class PlayerShip
{
    private:
        int xPos, yPos;
        int ShipH = 25;
        int ShipW = 25;

    public:
        PlayerShip();
        ~PlayerShip();
        PlayerShip(int startX);
        int getxPos();
        int getyPos();
        /*int getShipH();
        int getShipW();*/
        void renderShip(SDL_Renderer* field, SDL_Texture* space);
        void setxPos(int newX);

};

#endif // PLAYERSHIP_H_INCLUDED
