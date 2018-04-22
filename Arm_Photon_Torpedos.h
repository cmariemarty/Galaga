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
        bool active = true;

    public:
        //********************************************************************
        // description: This function constructs a photon torpedo            *
        // return: none                                                      *
        // precondition: the photon torpedo class must exist                 *
        // postcondition: creates a torpedo                                  *
        //                                                                   *
        //********************************************************************
        PhotonTorpedo();

        //********************************************************************
        // description: This function constructs a photon torpedo with the   *
        //              player ship's coordinates                            *
        // return: none                                                      *
        // precondition: the photon torpedo class must exist                 *
        // postcondition: creates a torpedo with player ship coordinates     *
        //                                                                   *
        //********************************************************************
        PhotonTorpedo(PlayerShip);

        //********************************************************************
        // description: This function de-constructs a photon torpedo         *
        // return: none                                                      *
        // precondition: the photon torpedo must exist                       *
        // postcondition: destroys the torpedo                               *
        //                                                                   *
        //********************************************************************
        ~PhotonTorpedo();

        //********************************************************************
        // description: This function sets the torpedo's x coordinate        *
        // return: void                                                      *
        // precondition: the torpedo must exist                              *
        // postcondition: set the x coordinate to newX                       *
        //                                                                   *
        //********************************************************************
        void setcurrX(int newX);

        //********************************************************************
        // description: This function gets a torpedo's x coordinate          *
        // return: int                                                       *
        // precondition: the torpedo must exist                              *
        // postcondition: returns the x coordinate                           *
        //                                                                   *
        //********************************************************************
        int getcurrX();

        //********************************************************************
        // description: This function gets a torpedo's y coordinate          *
        // return: int                                                       *
        // precondition: the torpedo must exist                              *
        // postcondition: returns the y coordinate                           *
        //                                                                   *
        //********************************************************************
        int getcurrY();

        //********************************************************************
        // description: This function moves a torpedo's y coordinate         *
        // return: void                                                      *
        // precondition: the torpedo must exist                              *
        // postcondition: decreases the y coordinate by 10                   *
        //                                                                   *
        //********************************************************************
        void Move();

        //********************************************************************
        // description: This function renders a photon torpedo to the window *
        // return: void                                                      *
        // precondition: the torpedo must exist                              *
        // postcondition: renders the torpedo to the game window             *
        //                                                                   *
        //********************************************************************
        void renderTorpedo(SDL_Renderer* field, SDL_Texture* space);

        //********************************************************************
        // description: This function checks for a collision between a       *
        //              torpedo and an enemy ship                            *
        // return: void                                                      *
        // precondition: the torpedo and enemy ship array must exist         *
        // postcondition: sets collide equal to true if a collision occurs   *
        //                                                                   *
        //********************************************************************
        void checkCollision(EnemyShip ship[], bool& collide, int numOfEnemies,
                            int& numOfDestroyed, int& killCount);
};

//********************************************************************
// description: This function checks overcapacity for the shot array *
// return: void                                                      *
// precondition: the shotCount variable must exist                   *
// postcondition: if the shot array exceeds capacity, sets the       *
//                shotCount to zero                                  *
//                                                                   *
//********************************************************************
void checkShotCount(int& shotCount);

#endif // ARM_PHOTON_TORPEDOS_H_INCLUDED
