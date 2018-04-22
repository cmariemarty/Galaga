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

        //********************************************************************
        // description: This function constructs a player ship               *
        // return: none                                                      *
        // precondition: the PlayerShip class must exist                     *
        // postcondition: creates a player ship                              *
        //                                                                   *
        //********************************************************************
        PlayerShip();

        //********************************************************************
        // description: This function de-constructs the player ship          *
        // return: none                                                      *
        // precondition: the player ship must exist                          *
        // postcondition: destroys the player ship                           *
        //                                                                   *
        //********************************************************************
        ~PlayerShip();

        //********************************************************************
        // description: This function gets the player ship's x coordinate    *
        // return: int                                                       *
        // precondition: the player ship must exist                          *
        // postcondition: returns the x coordinate                           *
        //                                                                   *
        //********************************************************************
        int getxPos();

        //********************************************************************
        // description: This function gets the player ship's y coordinate    *
        // return: int                                                       *
        // precondition: the player ship must exist                          *
        // postcondition: returns the y coordinate                           *
        //                                                                   *
        //********************************************************************
        int getyPos();

        //********************************************************************
        // description: This function renders the player ship to the window  *
        // return: void                                                      *
        // precondition: the player ship must exist                          *
        // postcondition: renders the ship to the game window                *
        //                                                                   *
        //********************************************************************
        void renderShip(SDL_Renderer* field, SDL_Texture* space);

        //********************************************************************
        // description: This function moves the player ship                  *
        // return: void                                                      *
        // precondition: the player ship must exist                          *
        // postcondition: if the ship is within the boundaries, sets the x   *
        //                coordinate to newX                                 *
        //                                                                   *
        //********************************************************************
        void setxPos(int newX);
};

#endif // PLAYERSHIP_H_INCLUDED
