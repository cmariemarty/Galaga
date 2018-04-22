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

#include "GameData.h"

// Determines enemies based on level
void enemiesPerLevel(int level, int& numOfEnemies)
{
    switch (level)
    {
        case 1:
            numOfEnemies = 3;
            break;
        case 2:
            numOfEnemies = 5;
            break;
        case 3:
            numOfEnemies = 7;
            break;
        case 4:
            numOfEnemies = 10;
            break;
        case  5:
            numOfEnemies = 11;
            break;
    }
}

// Checks for player victory
void victoryOrDefeat (bool& victory, int level, int numOfDestroyed)
{
    if (level == 5 && numOfDestroyed == 11)
    {
        victory = true;
    }
}

// Determines score to print to screen
string score(int killCount)
{
    string killTally;
    switch (killCount)
    {
        // Level 1 kills
        case 0:
            killTally = "Score: 0";
            break;
        case 1:
            killTally = "Score: 1000";
            break;
        case 2:
            killTally = "Score: 2000";
            break;
        case 3:
            killTally = "Score: 3000";
            break;

        // Level 2 kills
        case 4:
            killTally = "Score: 4000";
            break;
        case 5:
            killTally = "Score: 5000";
            break;
        case 6:
            killTally = "Score: 6000";
            break;
        case 7:
            killTally = "Score: 7000";
            break;
        case 8:
            killTally = "Score: 8000";
            break;

        // Level 3 kills
        case 9:
            killTally = "Score: 9000";
            break;
        case 10:
            killTally = "Score: 10000";
            break;
        case 11:
            killTally = "Score: 11000";
            break;
        case 12:
            killTally = "Score: 12000";
            break;
        case 13:
            killTally = "Score: 13000";
            break;
        case 14:
            killTally = "Score: 14000";
            break;
        case 15:
            killTally = "Score: 15000";
            break;

        // Level 4 kills
        case 16:
            killTally = "Score: 16000";
            break;
        case 17:
            killTally = "Score: 17000";
            break;
        case 18:
            killTally = "Score: 18000";
            break;
        case 19:
            killTally = "Score: 19000";
            break;
        case 20:
            killTally = "Score: 20000";
            break;
        case 21:
            killTally = "Score: 21000";
            break;
        case 22:
            killTally = "Score: 22000";
            break;
        case 23:
            killTally = "Score: 23000";
            break;
        case 24:
            killTally = "Score: 24000";
            break;
        case 25:
            killTally = "Score: 25000";
            break;

        // Level 5 kills
        case 26:
            killTally = "Score: 26000";
            break;
        case 27:
            killTally = "Score: 27000";
            break;
        case 28:
            killTally = "Score: 28000";
            break;
        case 29:
            killTally = "Score: 29000";
            break;
        case 30:
            killTally = "Score: 30000";
            break;
        case 31:
            killTally = "Score: 31000";
            break;
        case 32:
            killTally = "Score: 32000";
            break;
        case 33:
            killTally = "Score: 33000";
            break;
        case 34:
            killTally = "Score: 34000";
            break;
        case 35:
            killTally = "Score: 35000";
            break;
        case 36:
            killTally = "Score: 36000";
            break;
    }
    return killTally;
}

// Creating and rendering score texture
void renderScore(string finalScore, TTF_Font* font, SDL_Color color,
                 SDL_Renderer* field)
{
    // Loading proper string to texture
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font,
                                finalScore.c_str(), color);
    SDL_Texture* scoreSpace = SDL_CreateTextureFromSurface(field,
                              scoreSurface);
    SDL_FreeSurface(scoreSurface);

    // Creating texture rectangle
    SDL_Rect scoreArea;
    scoreArea.x = 175;
    scoreArea.y = 300;
    scoreArea.h = 35;
    scoreArea.w = 140;

    // Rendering score texture
    SDL_RenderCopy(field, scoreSpace, NULL, &scoreArea);
}
