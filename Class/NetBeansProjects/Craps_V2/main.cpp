/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 6, 2017, 10:04 AM
 * Purpose:  Randomly throw dice and observe results
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
float const CNVPERC = 100.0f; // conversion to percentage

//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare all Variables Here and initialize some
    fstream in;
    int nGames, wins, losses, nThrows, mxThrGm, fGames;
    
    //Loop and take statistics
    nGames = 1000000, wins = 0, losses = 0, mxThrGm = 0;
    
    //Open the file and read in the number of games to play
    //from the file
    in.open("fGames.dat");
    while(in>>fGames);
    nGames = fGames < nGames?fGames:nGames;
    
    
    //Play craps
    for(int game = 1; game <= nGames; game++){
        char die1=rand()%6 + 1;
        char die2 = rand()%6 + 1;
        char sum1 = die1 + die2;
        unsigned short gmThrws = 1;
        nThrows++;
        if(sum1 == 2 || sum1 == 3 || sum1 == 12) losses ++;
        else if(sum1 == 7||sum1 == 11)wins++;
        else{
            bool stpGame = false;
            do{
                die1=rand()%6 + 1;
                die2 = rand()%6 + 1;
                char sum2 = die1 + die2;
                nThrows++;
                gmThrws++;
                if(sum1 == sum2) {
                    wins++;
                    stpGame = true;
                } else if(sum2 == 7){
                    losses++;
                    stpGame = true;
                }
            } while(!stpGame);
        } if(gmThrws > mxThrGm)mxThrGm=gmThrws;
    }
    
    //Input or initialize values Here
    
    //Process/Calculations Here
    
    //Output Located Here
    cout << "Number of games played = " << nGames << endl;
    cout << "Number of games played = " << wins + losses << endl;
    cout << "Number of wins =         " << wins << endl;
    cout << "Number of losses =       " << losses << endl;
    cout << "Percentage wins =        " << CNVPERC*wins/nGames << endl;
    cout << "Percentage losses =      " << CNVPERC*losses/nGames << endl;
    cout << "Average throws/game =    " << static_cast<float>(nThrows)/nGames << endl;
    cout << "Max throws/game =        " << mxThrGm << endl;
    //Exit
    in.close();
    return 0;
}

