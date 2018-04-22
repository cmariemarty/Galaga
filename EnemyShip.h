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
        bool isSplosion = false;
        bool isDestroyed = false;
        int moveFrame = 0;

        //********************************************************************
        // description: This function constructs an enemy ship               *
        // return: none                                                      *
        // precondition: the enemy ship class must exist                     *
        // postcondition: creates an enemy ship                              *
        //                                                                   *
        //********************************************************************
        EnemyShip();

        //********************************************************************
        // description: This function constructs an enemy ship in a line up  *
        // return: none                                                      *
        // precondition: the enemy ship class must exist                     *
        // postcondition: creates an enemy ship with proper formation        *
        //                placement                                          *
        //                                                                   *
        //********************************************************************
        EnemyShip(int numOfEnemies);

        //********************************************************************
        // description: This function de-constructs an enemy ship            *
        // return: none                                                      *
        // precondition: the enemy ship must exist                           *
        // postcondition: destroys enemy ship                                *
        //                                                                   *
        //********************************************************************
        ~EnemyShip();

        //********************************************************************
        // description: This function gets an enemy ship's x coordinate      *
        // return: int                                                       *
        // precondition: the enemy ship must exist                           *
        // postcondition: returns the x coordinate                           *
        //                                                                   *
        //********************************************************************
        int getX();

        //********************************************************************
        // description: This function gets an enemy ship's y coordinate      *
        // return: int                                                       *
        // precondition: the enemy ship must exist                           *
        // postcondition: returns the y coordinate                           *
        //                                                                   *
        //********************************************************************
        int getY();

        //********************************************************************
        // description: This function moves an enemy ship's x coordinate     *
        // return: void                                                      *
        // precondition: the enemy ship must exist                           *
        // postcondition: moves the ship to the left and the right           *
        //                                                                   *
        //********************************************************************
        void enemyMove();

        //********************************************************************
        // description: This function renders an enemy ship to the window    *
        // return: void                                                      *
        // precondition: the enemy ship must exist                           *
        // postcondition: renders the ship to the game window                *
        //                                                                   *
        //********************************************************************
        void renderShip(SDL_Renderer* field, SDL_Texture* space);
};

#endif // ENEMYSHIP_H_INCLUDED
