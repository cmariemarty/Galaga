//#include "PlayerShip.h"
    #include <iostream>
    #include <string>
    #include <fstream>



   // highscores[i] = 0;

   // highscores[0] = x;

    struct highScore
    {
        int highScore;
        string highscoreNames;
        const int NUM_SCORES;
    };


    using namespace std;

    int main()
    {






        //MAKE HIGHSCORE ARRAY


    //ifstream inputFile;
    //inputFile.open("highscores.txt");

    //ofstream ouputFile;
   // outputFile.open("highscores.txt")


   // if(!in.fail())
  //  {
    //    inputFile >> highScores;
  //  }

  //  outputFile << highScores;


    //for(int i = 0; i < num)
      //  {

  //      }





    const int NUM_SCORES = 10;

    int highscores[NUM_SCORES] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};

    string highscoreNames[NUM_SCORES] = {"DES", "AAA", "ABC", "XYZ", "ILM", "ILY", "BOB", "SAM", "SUE", "WAT"};


    for(int score = 0; score < NUM_SCORES; score++)
    {
        highscores[score] == 0;




   // cout << highscoreNames[score] << " has a highscore of "
  //   << highscores[0] << endl;





   }


   //inputFile.close();
   //outputFile.close();


    return 0;

    }
