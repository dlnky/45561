/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 16, 2017, 9:16 PM
 * Purpose:  Calculate the time that it will be after a wait
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int calTime(int, int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int wTime, cTime, nTime;
    //Input or initialize values Here
    cout << "Input the current time(1234): " << endl;
    cin >> cTime;
    cout << "Input the estimated wait time(1512) " << endl;
    cin >> wTime;
    //Process/Calculations Here
    nTime = calTime(cTime, wTime);
    //Output Located Here
    cout << "Time at start of wait: " << cTime << endl;
    cout << "Time until wait ends:  " << wTime << endl;
    cout << "Time at end of wait:   " << nTime << endl;
    
    //Exit
    return 0;
}

int calTime(int curr, int wait){
    int nTime, minWait;
    nTime = curr + (wait/100) * 100;
    nTime += wait % 100;
    if(nTime % 100 >= 60){
        nTime += 40;
    }
    if(nTime >= 2400){
        nTime -= 2400;
    }
    return nTime;
}