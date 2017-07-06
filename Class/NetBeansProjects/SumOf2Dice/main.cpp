/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 5, 2017, 10:38 AM
 * Purpose:  Randomly throw dice and observe results
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare all Variables Here and initialize some
    char die1, die2, sum;
    unsigned int nThrows = 36000, frq2=0, frq3=0, frq4=0, frq5=0, frq6=0, 
            frq7 = 0, frq8 = 0, frq9 = 0, frq10 = 0, frq11 = 0, frq12 = 0;
    
    //Loop and take statistics
    for(int thrw = 1; thrw <= nThrows; thrw++){
        die1 = rand()%6+1;
        die2 = rand()%6+1;
        sum = die1 + die2;
        switch(sum){
            case 12:frq12++;break;
            case 11:frq11++;break;
            case 10:frq10++;break;
            case 9:frq9++;break;
            case 8:frq8++;break;
            case 7:frq7++;break;
            case 6:frq6++;break;
            case 5:frq5++;break;
            case 4:frq4++;break;
            case 3:frq3++;break;
            default:frq2++;
        }
        
    }
    //Input or initialize values Here
    
    //Process/Calculations Here
    
    //Output Located Here
    cout<<"Number of throws = " << nThrows <<endl;
    cout<<"Number of throws = " << frq12+frq11+frq10+frq9+frq8+frq7+frq6+
            frq5+frq4+frq3+frq2 << endl;
    cout<<"12 was thrown " << setw(5) << frq12 << " times" << endl;
    cout<<"11 was thrown " << setw(5) << frq11 << " times" << endl;
    cout<<"10 was thrown " << setw(5) << frq10 << " times" << endl;
    cout<<"9 was thrown " << setw(5) << frq9 << " times" << endl;
    cout<<"8 was thrown " << setw(5) << frq8 << " times" << endl;
    cout<<"7 was thrown " << setw(5) << frq7 << " times" << endl;
    cout<<"6 was thrown " << setw(5) << frq6 << " times" << endl;
    cout<<"5 was thrown " << setw(5) << frq5 << " times" << endl;
    cout<<"4 was thrown " << setw(5) << frq4 << " times" << endl;
    cout<<"3 was thrown " << setw(5) << frq3 << " times" << endl;
    cout<<"2 was thrown " << setw(5) << frq2 << " times" << endl;

    //Exit
    return 0;
}

