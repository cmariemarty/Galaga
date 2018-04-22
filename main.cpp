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

/*
* Data Abstraction:
*           An SDL window and renderer is initialized for game
*               play
* Input:
*           The program reads in movement input with the 'a' and
*               'd' keys, and accepts a 'fire' command with the
*               space bar
* Process:
*           The program renders a player ship and enemy ships to
*               the game window and simulates a battle
* Output:
*           The final score is printed to the game window
* Assumptions:
*           It is assumed that the necessary dll and image
*               files will be present in the executable directory
*           It is assumed that the user will run the program only
*               once at a time
*/

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "PlayerShip.h"
#include "Arm_Photon_Torpedos.h"
#include "Enemy_Fire.h"
#include "GameData.h"

using namespace std;

// Setting screen size
const int WIDTH = 500;
const int HEIGHT = 500;


int main(int game, char* games[])
{
    // Initializing TTF
    TTF_Init();

    // Creating and defining SDL_Window
    SDL_Window* gameWindow = SDL_CreateWindow("Galaga_by_PlayersX",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
        HEIGHT, SDL_WINDOW_SHOWN);

    // Creating and directing window renderer
    SDL_Renderer* galagaField = SDL_CreateRenderer(gameWindow, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Loading start screen
    SDL_Surface* homePic = IMG_Load("HomeScreen.png");
    SDL_Texture* homeScreen = SDL_CreateTextureFromSurface(galagaField,
                              homePic);
    SDL_FreeSurface(homePic);
    bool startGame = false;

    // Creating background texture
    SDL_Surface* starPic = IMG_Load("starfield2.png");
    SDL_Texture* starfield = SDL_CreateTextureFromSurface(galagaField,
                             starPic);
    SDL_FreeSurface(starPic);

    // Creating player ship texture image
    SDL_Surface* shipPic = IMG_Load("Rogue1.png");
    SDL_SetColorKey(shipPic, SDL_TRUE, SDL_MapRGB(shipPic->format,
        0xFF, 0xFF, 0xFF));
    SDL_Texture* shipSpace = SDL_CreateTextureFromSurface(galagaField,
                             shipPic);
    SDL_FreeSurface(shipPic);

    // Creating enemy ship texture image
    SDL_Surface* enemyPic = IMG_Load("StrikeHawk.png");
    SDL_SetColorKey(enemyPic, SDL_TRUE, SDL_MapRGB(enemyPic->format,
        0x00, 0x00, 0x00));
    SDL_Texture* enemySpace = SDL_CreateTextureFromSurface(galagaField,
                              enemyPic);
    SDL_FreeSurface(enemyPic);

    // Creating player bullet texture image
    SDL_Surface* photonPic = IMG_Load("PhotonTorpedo.png");
    SDL_SetColorKey(photonPic, SDL_TRUE, SDL_MapRGB(photonPic->format,
        0xFF, 0xFF, 0xFF));
    SDL_Texture* torpedoSpace = SDL_CreateTextureFromSurface(galagaField,
                                photonPic);
    SDL_FreeSurface(photonPic);

    // Creating enemy bullet texture image
    SDL_Surface* bulletPic = IMG_Load("BloodBullet.png");
    SDL_SetColorKey(bulletPic, SDL_TRUE, SDL_MapRGB(bulletPic->format,
        0xFF, 0xFF, 0xFF));
    SDL_Texture* bulletSpace = SDL_CreateTextureFromSurface(galagaField,
                               bulletPic);
    SDL_FreeSurface(bulletPic);

    // Creating and loading defeat texture image
    SDL_Surface* defeatPic = IMG_Load("GameOver.png");
    SDL_Texture* defeatScape = SDL_CreateTextureFromSurface(galagaField,
                               defeatPic);
    SDL_FreeSurface(defeatPic);

    // Loading victory texture image
    SDL_Surface* victoryPic = IMG_Load("victory.png");
    SDL_Texture* victoryScape = SDL_CreateTextureFromSurface(galagaField,
                                victoryPic);
    SDL_FreeSurface(victoryPic);

    // Creating game font
    TTF_Font* galaFont = TTF_OpenFont("GOTHIC.ttf", 24);
    SDL_Color scoreColor = {0xFF, 0xFF, 0xFF};

    // Creating SDL_Events for game interface
    SDL_Event galacticKeys;

    // Setting game data and level
    int level = 1;
    bool victory = false;
    bool defeat = false;
    int killCount = 0;
    string finalScore;

    // Creating base player ship
    PlayerShip MillenniumFalcon;

    // Creating enemy ships
    EnemyShip Borg[12];
    int numOfBorg;
    int numOfDestroyed = 0;
    enemiesPerLevel(level, numOfBorg);
    for (int b = 0; b < numOfBorg; b++)
    {
        EnemyShip assimulationVictim(b);
        Borg[b] = assimulationVictim;
    }

    // Creating player bullets and bullet variables
    const int MAX_SHOT = 501;
    PhotonTorpedo shot[MAX_SHOT];
    bool collide[MAX_SHOT];
    PhotonTorpedo photon(MillenniumFalcon);
    int shotCount = 0;
    bool isShot = false;

    // Creating enemy bullets and bullet variables
    const int MAX_DARK_SHOTS = 1000;
    Bullet darkShot[MAX_DARK_SHOTS];
    int darkShotCount = 0;
    int darkShotDelay = 0;
    int firingPosition = 0;

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

        // Running main game
        else if (victory == false && defeat == false)
        {

            // Rendering background texture
            SDL_RenderCopy(galagaField, starfield, NULL, NULL);

            // Rendering shots
            for (int i = 0; i < shotCount; i++)
            {
                shot[i].checkCollision(Borg, collide[i], numOfBorg,
                                       numOfDestroyed, killCount);
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

            // Firing dark shots
            checkOverflow(darkShotDelay, 61);
            if (darkShotDelay == 60)
            {
                if (Borg[firingPosition].isDestroyed == false)
                {
                    Bullet newShot(Borg[firingPosition]);
                    darkShot[darkShotCount] = newShot;
                    darkShot[darkShotCount].active = true;
                    checkOverflow(darkShotCount, MAX_DARK_SHOTS);
                }
                checkOverflow(firingPosition, (numOfBorg - 1));
            }

            // Rendering dark shots
            for (int b = 0; b < darkShotCount; b++)
            {
                if (darkShot[b].active == true)
                {
                    darkShot[b].detectPlayerCollision(MillenniumFalcon,
                                                      defeat);
                    darkShot[b].renderBullet(galagaField, bulletSpace);
                    darkShot[b].moveBullet();
                }
                if (darkShot[b].getBulletY() > 500)
                {
                    darkShot[b].active = false;
                    darkShot[b].~Bullet();
                }
            }

            // Rendering enemy ships
            for (int e = 0; e < numOfBorg; e++)
            {
                if (Borg[e].isSplosion == false)
                {
                    // Rendering enemy ship
                    Borg[e].renderShip(galagaField, enemySpace);
                    Borg[e].enemyMove();
                }
                else
                {
                    Borg[e].isDestroyed = true;
                }
            }

            // Checking for victory
            victoryOrDefeat(victory, level, numOfDestroyed);

            // Checking for level complete
            if (numOfDestroyed == numOfBorg && victory == false)
            {
                level++;
                enemiesPerLevel(level, numOfBorg);
                for (int b = 0; b < numOfBorg; b++)
                {
                    EnemyShip assimulationVictim(b);
                    Borg[b] = assimulationVictim;
                }
                numOfDestroyed = 0;
            }

            // Rendering basic PlayerShip
            if (defeat == false)
            {
                MillenniumFalcon.renderShip(galagaField, shipSpace);
            }
        }

        // Rendering defeat screen and final score
        else if (defeat == true)
        {
            SDL_RenderCopy(galagaField, defeatScape, NULL, NULL);
            finalScore = score(killCount);
            renderScore(finalScore, galaFont, scoreColor, galagaField);
        }

        //Rendering victory screen and final score
        else
        {
            SDL_RenderCopy(galagaField, victoryScape, NULL, NULL);
            finalScore = score(killCount);
            renderScore(finalScore, galaFont, scoreColor, galagaField);
        }

        // Updating window
        SDL_RenderPresent(galagaField);
    }

    // De-constructing player ship
    MillenniumFalcon.~PlayerShip();

    // De-constructing enemy ship
    for (int i = 0; i < 12; i++)
    {
        Borg[i].~EnemyShip();
    }

    // De-constructing photon torpedos
    for (int i = 0; i < MAX_SHOT; i++)
    {
        shot[i].~PhotonTorpedo();
    }

    // De-constructing enemy bullets
    for (int i = 0; i < MAX_DARK_SHOTS; i++)
    {
        darkShot[i].~Bullet();
    }

    // Destroying game textures
    SDL_DestroyTexture(homeScreen);
    SDL_DestroyTexture(shipSpace);
    SDL_DestroyTexture(torpedoSpace);
    SDL_DestroyTexture(enemySpace);
    SDL_DestroyTexture(bulletSpace);
    SDL_DestroyTexture(victoryScape);
    SDL_DestroyTexture(defeatScape);
    SDL_DestroyTexture(starfield);

    // Destroying game renderer
    SDL_DestroyRenderer(galagaField);

    // Destroying game window
    SDL_DestroyWindow(gameWindow);

    // Closing TTF
    TTF_Quit();

    return 0;
}

