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

#ifndef ENEMY_FIRE_H_INCLUDED
#define ENEMY_FIRE_H_INCLUDED

#include <SDL.h>
#include "EnemyShip.h"
#include "PlayerShip.h"

class Bullet
{
    private:
        int x, y;
        int h = 15;
        int w = 3;

    public:
        bool active = false;

        //********************************************************************
        // description: This constructs a basic enemy bullet                 *
        // return: none                                                      *
        // precondition: the bullet class must exist                         *
        // postcondition: creates an enemy bullet                            *
        //                                                                   *
        //********************************************************************
        Bullet();

        //********************************************************************
        // description: This constructs a bullet based on an enemy ship      *
        //              position                                             *
        // return: none                                                      *
        // precondition: the bullet and enemy ship class must exist          *
        // postcondition: creates a bullet for a specific enemy ship         *
        //                                                                   *
        //********************************************************************
        Bullet(EnemyShip);

        //********************************************************************
        // description: This function de-constructs an enemy bullet          *
        // return: none                                                      *
        // precondition: the bullet must exist                               *
        // postcondition: destroys the bullet                                *
        //                                                                   *
        //********************************************************************
        ~Bullet();

        //********************************************************************
        // description: This function gets a bullet's x coordinate           *
        // return: int                                                       *
        // precondition: the bullet must exist                               *
        // postcondition: returns x coordinate                               *
        //                                                                   *
        //********************************************************************
        int getBulletX();

        //********************************************************************
        // description: This function gets a bullet's y coordinate           *
        // return: int                                                       *
        // precondition: the bullet must exist                               *
        // postcondition: returns y coordinate                               *
        //                                                                   *
        //********************************************************************
        int getBulletY();

        //********************************************************************
        // description: This function moves the bullet                       *
        // return: void                                                      *
        // precondition: the bullet must exist                               *
        // postcondition: increases y coordinate by 5                        *
        //                                                                   *
        //********************************************************************
        void moveBullet();

        //********************************************************************
        // description: This function renders a bullet to the game window    *
        // return: void                                                      *
        // precondition: the bullet, renderer, and bullet texture must exist *
        // postcondition: renders the bullet                                 *
        //                                                                   *
        //********************************************************************
        void renderBullet(SDL_Renderer* field, SDL_Texture* space);

        //********************************************************************
        // description: This function determines if a collision occurred     *
        //              with the player ship                                 *
        // return: void                                                      *
        // precondition: the player ship and defeat variable must exist      *
        // postcondition: if a collision occurred, sets defeat to true       *
        //                                                                   *
        //********************************************************************
        void detectPlayerCollision(PlayerShip, bool& defeat);

};

//********************************************************************
// description: This function checks for overflow of a range         *
//              capacity                                             *
// return: void                                                      *
// precondition: the range and the max value must exist              *
// postcondition: if the maxVal is exceeded, set the range to zero   *
//                                                                   *
//********************************************************************
void checkOverflow(int& range, int maxVal);

#endif // ENEMY_FIRE_H_INCLUDED
