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
                }
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
}
