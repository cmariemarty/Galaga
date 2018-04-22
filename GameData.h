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

#ifndef GAMEDATA_H_INCLUDED
#define GAMEDATA_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

//********************************************************************
// description: This function determines the number of enemies per   *
//              level                                                *
// return: void                                                      *
// precondition: the level and numOfEnemies variables must exist     *
// postcondition: sets numOfEnemies for a given level                *
//                                                                   *
//********************************************************************
void enemiesPerLevel(int level, int& numOfEnemies);

//********************************************************************
// description: This function determines if the player has beaten    *
//              all enemies on all levels                            *
// return: void                                                      *
// precondition: the level, victory, and numOfDestroyed variables    *
//               must exist                                          *
// postcondition: determines if player has won the game              *
//                                                                   *
//********************************************************************
void victoryOrDefeat (bool& victory, int level, int numOfDestroyed);

//********************************************************************
// description: This function determines which score string to print *
//              to the game window                                   *
// return: string                                                    *
// precondition: the killCount variable must exist                   *
// postcondition: returns correct score string                       *
//                                                                   *
//********************************************************************
string score(int killCount);

//********************************************************************
// description: This function renders the final score to the game    *
//              window                                               *
// return: void                                                      *
// precondition: the finalScore, font, color, and field variables    *
//               must exist                                          *
// postcondition: renders the score to the game window               *
//                                                                   *
//********************************************************************
void renderScore(string finalScore, TTF_Font* font, SDL_Color color,
                 SDL_Renderer* field);

#endif // GAMEDATA_H_INCLUDED
