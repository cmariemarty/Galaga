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

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "PlayerShip.h"
#include "Arm_Photon_Torpedos.h"

using namespace std;

// Setting screen size
const int WIDTH = 500;
const int HEIGHT = 500;


int main(int game, char* games[])
{
    // Creating and defining SDL_Window
    SDL_Window* gameWindow = SDL_CreateWindow("Galaga_by_PlayersX",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
        HEIGHT, SDL_WINDOW_SHOWN);

    // Creating and directing window renderer
    SDL_Renderer* galagaField = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED |
                                                   SDL_RENDERER_PRESENTVSYNC);

    // Loading start screen
    SDL_Surface* homePic = IMG_Load("HomeScreen.png");
    SDL_Texture* homeScreen = SDL_CreateTextureFromSurface(galagaField, homePic);
    SDL_FreeSurface(homePic);
    bool startGame = true;

    // Creating background texture
    SDL_Surface* starPic = IMG_Load("starfield.png");
    SDL_Texture* starfield = SDL_CreateTextureFromSurface(galagaField, starPic);
    SDL_FreeSurface(starPic);

    // Creating player ship texture image
    SDL_Surface* shipPic = IMG_Load("Rogue1.png");
    SDL_SetColorKey(shipPic, SDL_TRUE, SDL_MapRGB(shipPic->format, 0xFF, 0xFF, 0xFF));
    SDL_Texture* shipSpace = SDL_CreateTextureFromSurface(galagaField, shipPic);
    SDL_FreeSurface(shipPic);

    // Creating enemy ship texture image
    SDL_Surface* enemyPic = IMG_Load("StrikeHawk.png");
    SDL_SetColorKey(enemyPic, SDL_TRUE, SDL_MapRGB(enemyPic->format, 0x00, 0x00, 0x00));
    SDL_Texture* enemySpace = SDL_CreateTextureFromSurface(galagaField, enemyPic);
    SDL_FreeSurface(enemyPic);

    // Creating player bullet texture image
    SDL_Surface* photonPic = IMG_Load("PhotonTorpedo.png");
    SDL_SetColorKey(photonPic, SDL_TRUE, SDL_MapRGB(photonPic->format, 0xFF, 0xFF, 0xFF));
    SDL_Texture* torpedoSpace = SDL_CreateTextureFromSurface(galagaField, photonPic);
    SDL_FreeSurface(photonPic);

    // Creating SDL_Events for game interface
    SDL_Event galacticKeys;

    // Creating base player ship
    PlayerShip MillenniumFalcon;

    // Creating enemy ship
    EnemyShip Borg;
    bool isSplosion = false;
    bool isDestroyed = false;

    // Creating bullets and bullet variable
    const int MAX_SHOT = 101;
    PhotonTorpedo shot[MAX_SHOT];
    bool collide[MAX_SHOT];
    PhotonTorpedo photon(MillenniumFalcon);
    int shotCount = 0;
    bool isShot = false;

    // Creating main game loop
    bool gameEnd = false;
    while (gameEnd == false)
    {
        // Creating an event queue for the game
        while (SDL_PollEvent(&galacticKeys) != 0)
        {
            // Determining if user quits
            if (galacticKeys.type == SDL_QUIT)
            {
                gameEnd = true;
            }

            // Determining if user uses keyboard
            else if (galacticKeys.type == SDL_KEYDOWN)
            {
                // Determines which key was pressed
                switch (galacticKeys.key.keysym.sym)
                {
                        // Start Screen activation key
                        case SDLK_RETURN:
                            startGame = true;
                        // User selects 'a' key
                        case SDLK_a:
                            MillenniumFalcon.setxPos(-10);
                            break;
                        // User selects 'd' key
                        case SDLK_d:
                            MillenniumFalcon.setxPos(10);
                            break;
                        // User fires photon shot (space bar)
                        case SDLK_SPACE:
                            isShot = true;
                            shot[shotCount] = photon;
                            shot[shotCount].setcurrX(MillenniumFalcon.getxPos() + 11);
                            collide[shotCount] = false;
                            shotCount++;
                            checkShotCount(shotCount);
                            break;
                }
            }
        }

        // Setting draw color
        SDL_SetRenderDrawColor(galagaField, 0x00, 0x00, 0x00, 0xFF);

        // Clearing window renderer
        SDL_RenderClear(galagaField);

        // Rending start screen
        if (startGame == false)
        {
            SDL_RenderCopy(galagaField, homeScreen, NULL, NULL);
        }

        else
        {

            // Rendering background texture
            SDL_RenderCopy(galagaField, starfield, NULL, NULL);

            // Rendering shots
            for (int i = 0; i < shotCount; i++)
            {
                shot[i].checkCollision(Borg, collide[i], isSplosion, isDestroyed);
                if (isShot == true && collide[i] == false)
                {
                    shot[i].renderTorpedo(galagaField, torpedoSpace);
                    shot[i].Move();
                    if (shot[i].getcurrY() <= 0)
                    {
                        shot[i].~PhotonTorpedo();
                    }
                }
            }

            if (isSplosion == false)
            {
                // Rendering enemy ship
                Borg.renderShip(galagaField, enemySpace);
                Borg.enemyMove();
            }
            else
            {
                isDestroyed = true;
            }

            // Rendering basic PlayerShip
            MillenniumFalcon.renderShip(galagaField, shipSpace);
        }

        // Updating window
        SDL_RenderPresent(galagaField);
    }

    // De-constructing player ship
    MillenniumFalcon.~PlayerShip();

    // De-constructing enemy ship
    Borg.~EnemyShip();

    // De-constructing photon torpedos
    for (int i = 0; i < MAX_SHOT; i++)
    {
        shot[i].~PhotonTorpedo();
    }

    // Destroying game texture
    SDL_DestroyTexture(starfield);

    // Destroying game renderer
    SDL_DestroyRenderer(galagaField);

    // Destroying game window
    SDL_DestroyWindow(gameWindow);

    return 0;
}










// Move and shot code - PRESTART SCREEN
/*#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "PlayerShip.h"
#include "Arm_Photon_Torpedos.h"

using namespace std;

// Setting screen size
const int WIDTH = 500;
const int HEIGHT = 500;


int main(int game, char* games[])
{
    // Creating and defining SDL_Window
    SDL_Window* gameWindow = SDL_CreateWindow("Galaga_by_PlayersX",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
        HEIGHT, SDL_WINDOW_SHOWN);

    // Creating and directing window renderer
    SDL_Renderer* galagaField = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED |
                                                   SDL_RENDERER_PRESENTVSYNC);

    // Creating background texture;
    SDL_Surface* starPic = IMG_Load("starfield.png");
    SDL_Texture* starfield = SDL_CreateTextureFromSurface(galagaField, starPic);
    SDL_FreeSurface(starPic);

    // Creating player ship texture image
    SDL_Surface* shipPic = IMG_Load("Rogue1.png");
    SDL_SetColorKey(shipPic, SDL_TRUE, SDL_MapRGB(shipPic->format, 0xFF, 0xFF, 0xFF));
    SDL_Texture* shipSpace = SDL_CreateTextureFromSurface(galagaField, shipPic);
    SDL_FreeSurface(shipPic);

    // Creating player bullet texture image
    SDL_Surface* photonPic = IMG_Load("PhotonTorpedo.png");
    SDL_SetColorKey(photonPic, SDL_TRUE, SDL_MapRGB(photonPic->format, 0xFF, 0xFF, 0xFF));
    SDL_Texture* torpedoSpace = SDL_CreateTextureFromSurface(galagaField, photonPic);
    SDL_FreeSurface(photonPic);

    // Creating SDL_Events for game interface
    SDL_Event galacticKeys;

    // Creating base player ship
    PlayerShip MillenniumFalcon;

    // Creating bullets and bullet variable
    PhotonTorpedo shot[101];
    PhotonTorpedo photon(MillenniumFalcon);
    int shotCount = 0;
    bool isShot = false;

    // Creating main game loop
    bool gameEnd = false;
    while (gameEnd == false)
    {
        // Creating an event queue for the game
        while (SDL_PollEvent(&galacticKeys) != 0)
        {
            // Determining if user quits
            if (galacticKeys.type == SDL_QUIT)
            {
                gameEnd = true;
            }

            // Determining if user uses keyboard
            else if (galacticKeys.type == SDL_KEYDOWN)
            {
                // Determines which key was pressed
                switch (galacticKeys.key.keysym.sym)
                {
                        // User selects 'a' key
                        case SDLK_a:
                            MillenniumFalcon.setxPos(-10);
                            break;
                        // User selects 'd' key
                        case SDLK_d:
                            MillenniumFalcon.setxPos(10);
                            break;
                        // User fires photon shot (space bar)
                        case SDLK_SPACE:
                            isShot = true;
                            shot[shotCount] = photon;
                            shot[shotCount].setcurrX(MillenniumFalcon.getxPos() + 11);
                            shotCount++;
                            checkShotCount(shotCount);
                            break;
                }
            }
        }

        // Setting draw color
        SDL_SetRenderDrawColor(galagaField, 0x00, 0x00, 0x00, 0xFF);

        // Clearing window renderer
        SDL_RenderClear(galagaField);

        // Rendering background texture
        SDL_RenderCopy(galagaField, starfield, NULL, NULL);

        // Rendering shots
        for (int i = 0; i < shotCount; i++)
        {
            if (isShot == true)
            {
                shot[i].renderTorpedo(galagaField, torpedoSpace);
                shot[i].Move();
                if (shot[i].getcurrY() <= 0)
                {
                    shot[i].~PhotonTorpedo();
                }
            }
        }

        // Rendering basic PlayerShip
        MillenniumFalcon.renderShip(galagaField, shipSpace);

        // Updating window
        SDL_RenderPresent(galagaField);
    }

    // De-constructing player ship
    MillenniumFalcon.~PlayerShip();

    // Destroying game texture
    SDL_DestroyTexture(starfield);

    // Destroying game renderer
    SDL_DestroyRenderer(galagaField);

    // Destroying game window
    SDL_DestroyWindow(gameWindow);

    return 0;
}*/

















/* PRESHOT CODE
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "PlayerShip.h"

using namespace std;

// Setting screen size
const int WIDTH = 500;
const int HEIGHT = 500;


int main(int game, char* games[])
{
    // Creating and defining SDL_Window
    SDL_Window* gameWindow = SDL_CreateWindow("Galaga_by_PlayersX",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
        HEIGHT, SDL_WINDOW_SHOWN);

    // Creating and directing window renderer
    SDL_Renderer* galagaField = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED |
                                                   SDL_RENDERER_PRESENTVSYNC);

    // Creating background texture;
    SDL_Surface* starPic = IMG_Load("starfield.png");
    SDL_Texture* starfield = SDL_CreateTextureFromSurface(galagaField, starPic);
    SDL_FreeSurface(starPic);

    // Creating player ship texture image
    SDL_Surface* shipPic = IMG_Load("Rogue1.png");
    SDL_SetColorKey(shipPic, SDL_TRUE, SDL_MapRGB(shipPic->format, 0xFF, 0xFF, 0xFF));
    SDL_Texture* shipSpace = SDL_CreateTextureFromSurface(galagaField, shipPic);
    SDL_FreeSurface(shipPic);

    // Creating SDL_Events for game interface
    SDL_Event galacticKeys;

    // Creating base player ship
    PlayerShip MillenniumFalcon;

    // Creating main game loop
    bool gameEnd = false;
    while (gameEnd == false)
    {
        // Creating an event queue for the game
        while (SDL_PollEvent(&galacticKeys) != 0)
        {
            // Determining if user quits
            if (galacticKeys.type == SDL_QUIT)
            {
                gameEnd = true;
            }

            // Determining if user uses keyboard
            else if (galacticKeys.type == SDL_KEYDOWN)
            {
                // Determines which key was pressed
                switch (galacticKeys.key.keysym.sym)
                {
                        // User selects 'a' key
                        case SDLK_a:
                            MillenniumFalcon.setxPos(-10);
                            break;
                        case SDLK_d:
                            MillenniumFalcon.setxPos(10);
                            break;
                        /*case SDLK_SPACE:
                            break;*/
/*                }
            }
        }

        // Setting draw color
        SDL_SetRenderDrawColor(galagaField, 0x00, 0x00, 0x00, 0xFF);

        // Clearing window renderer
        SDL_RenderClear(galagaField);

        // Rendering background texture
        SDL_RenderCopy(galagaField, starfield, NULL, NULL);

        // Rendering basic PlayerShip
        MillenniumFalcon.renderShip(galagaField, shipSpace);

        // Updating window
        SDL_RenderPresent(galagaField);
    }

    // De-constructing player ship
    MillenniumFalcon.~PlayerShip();

    // Destroying game texture
    SDL_DestroyTexture(starfield);

    // Destroying game renderer
    SDL_DestroyRenderer(galagaField);

    // Destroying game window
    SDL_DestroyWindow(gameWindow);

    return 0;
}*/
