#include <iostream>
#include <string>

using namespace std;


struct highScores
{
    int scores;
    string player;
    int highScore;
    int previousScores;
    int playersScores;
};

int main()
{

   int numOfPlayers;
   highScores playersScore[numOfPlayers];

   cout << "Enter number of players" << endl;

   for(int i = 0; i < numOfPlayers; i++)
   {
       cout << "Enter users name: "<< endl;
       cin >> playersScore[i].player;

       cout << "Enter score for player: " << endl;
       cin >> playersScore[i].scores;
   }

   cout << "HIGHSCORES" << endl;


   for(int i = 0; i < numOfPlayers; i++)
   {
       cout << playersScore[i].player << setw(7) << playersScore[i].scores << endl;
   }







    return 0;
}
