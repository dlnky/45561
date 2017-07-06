/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 6, 2017, 10:47 AM
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
    ifstream in;
    ofstream out;
    int nGames, wins, losses, nThrows, mxThrGm, fGames;
    int win12, win11, win10, win9, win8, win7, win6, win5, win4, win3 ,win2;
    int loss12,loss11,loss10,loss9,loss8,loss7,loss6,loss5,loss4,loss3,loss2;
    
    //Loop and take statistics
    nGames = 3600000, wins = 0, losses = 0, mxThrGm = 0;
    win12=win11=win10=win9=win8=win7=win6=win5=win4=win3=win2 = 0;
    loss12=loss11=loss10=loss9=loss8=loss7=loss6=loss5=loss4=loss3=loss2 = 0;
    //Open the file and read in the number of games to play
    //from the file
    in.open("fGames.dat");
    out.open("stats.dat");
    while(in>>fGames);
    nGames = fGames < nGames?fGames:nGames;
    
    
    //Play craps
    for(int game = 1; game <= nGames; game++){
        char die1=rand()%6 + 1;
        char die2 = rand()%6 + 1;
        char sum1 = die1 + die2;
        bool win = false;
        unsigned short gmThrws = 1;
        nThrows++;
        if(sum1 == 2 || sum1 == 3 || sum1 == 12) losses ++;
        else if(sum1 == 7||sum1 == 11){
            wins++;
            win = true;
        }
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
                    win = true;
                } else if(sum2 == 7){
                    losses++;
                    stpGame = true;
                    win = false;
                }
            } while(!stpGame);
        } if(gmThrws > mxThrGm)mxThrGm=gmThrws;
        switch(sum1){
            case 12:win?win12++:loss12++;break;
            case 11:win?win11++:loss11++;break;
            case 10:win?win10++:loss10++;break;
            case 9:win?win9++:loss9++;break;
            case 8:win?win8++:loss8++;break;
            case 7:win?win7++:loss7++;break;
            case 6:win?win6++:loss6++;break;
            case 5:win?win5++:loss5++;break;
            case 4:win?win4++:loss4++;break;
            case 3:win?win3++:loss3++;break;
            default:win?win2++:loss2++;
        }
            
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
    cout << "Throw   Wins    Losses   Total" << endl;
    cout << " 2" << setw(8)<< win2 <<setw(12) << loss2 <<setw(9) <<win2 + loss2 << endl;
    cout << " 3" << setw(8)<< win3 <<setw(12) << loss3 <<setw(9) <<win3 + loss3 << endl;
    cout << " 4" << setw(8)<< win4 <<setw(12) << loss4 <<setw(9) <<win4 + loss4 << endl;
    cout << " 5" << setw(8)<< win5 <<setw(12) << loss5 <<setw(9) <<win5 + loss5 << endl;
    cout << " 6" << setw(8)<< win6 <<setw(12) << loss6 <<setw(9) <<win6 + loss6 << endl;
    cout << " 7" << setw(8)<< win7 <<setw(12) << loss7 <<setw(9) <<win7 + loss7 << endl;
    cout << " 8" << setw(8)<< win8 <<setw(12) << loss8 <<setw(9) <<win8 + loss8 << endl;
    cout << " 9" << setw(8)<< win9 <<setw(12) << loss9 <<setw(9) <<win9 + loss9 << endl;
    cout << " 10" << setw(7)<< win10 <<setw(12) << loss10 <<setw(9) <<win10 + loss10 << endl;
    cout << " 11" << setw(7)<< win11 <<setw(12) << loss11 <<setw(9) <<win11 + loss11 << endl;
    cout << " 12" << setw(7)<< win12 <<setw(12) << loss12 <<setw(9) <<win12 + loss12 << endl;
    cout << "Total number of all wins and losses: " << win12 + win11 + win10 +
            win9 + win8 + win7 + win6 + win5 + win4 + win3 + win2 +
            loss12 + loss11 + loss10 + loss9 + loss8 + loss7 + loss6 + loss5 + 
            loss4 + loss3 + loss2 << endl;
    //To file
    out << "Number of games played = " << nGames << endl;
    out << "Number of games played = " << wins + losses << endl;
    out << "Number of wins =         " << wins << endl;
    out << "Number of losses =       " << losses << endl;
    out << "Percentage wins =        " << CNVPERC*wins/nGames << endl;
    out << "Percentage losses =      " << CNVPERC*losses/nGames << endl;
    out << "Average throws/game =    " << static_cast<float>(nThrows)/nGames << endl;
    out << "Max throws/game =        " << mxThrGm << endl;
    out << "Throw   Wins    Losses   Total" << endl;
    out << " 2" << setw(8)<< win2 <<setw(12) << loss2 <<setw(9) <<win2 + loss2 << endl;
    out << " 3" << setw(8)<< win3 <<setw(12) << loss3 <<setw(9) <<win3 + loss3 << endl;
    out << " 4" << setw(8)<< win4 <<setw(12) << loss4 <<setw(9) <<win4 + loss4 << endl;
    out << " 5" << setw(8)<< win5 <<setw(12) << loss5 <<setw(9) <<win5 + loss5 << endl;
    out << " 6" << setw(8)<< win6 <<setw(12) << loss6 <<setw(9) <<win6 + loss6 << endl;
    out << " 7" << setw(8)<< win7 <<setw(12) << loss7 <<setw(9) <<win7 + loss7 << endl;
    out << " 8" << setw(8)<< win8 <<setw(12) << loss8 <<setw(9) <<win8 + loss8 << endl;
    out << " 9" << setw(8)<< win9 <<setw(12) << loss9 <<setw(9) <<win9 + loss9 << endl;
    out << " 10" << setw(7)<< win10 <<setw(12) << loss10 <<setw(9) <<win10 + loss10 << endl;
    out << " 11" << setw(7)<< win11 <<setw(12) << loss11 <<setw(9) <<win11 + loss11 << endl;
    out << " 12" << setw(7)<< win12 <<setw(12) << loss12 <<setw(9) <<win12 + loss12 << endl;
    out << "Total number of all wins and losses: " << win12 + win11 + win10 +
            win9 + win8 + win7 + win6 + win5 + win4 + win3 + win2 +
            loss12 + loss11 + loss10 + loss9 + loss8 + loss7 + loss6 + loss5 + 
            loss4 + loss3 + loss2 << endl;
    
    //Exit
    in.close();
    out.close();
    return 0;
}

