/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 10, 2017, 3:06 PM
 * Purpose:  Calculate the annual mortgage of a house post-tax
 */

//System Libraries Here
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float calcAll(int, int, int, int, int);
float calcAvg(int, int, int, int, int);
float calcDev(int, int, int, int, float, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int s1, s2, s3, s4, numScr;
    float avg, stDev;
    
    //Input or initialize values Here
    cout << "Enter 4 integer scores: " << endl;
    cin >> s1 >> s2 >> s3 >> s4;
    numScr = 4;
    
    //Process/Calculations Here
    stDev = calcAll(s1, s2, s3, s4, numScr);
    
    //Output Located Here
    
    //Exit
    return 0;
}

float calcAll(int s1, int s2, int s3, int s4, int nScore){
    float average, stdDev;
    average = calcAvg(s1, s2, s3, s4, nScore);
    stdDev = calcDev(s1, s2, s3, s4, average, nScore);
    return stdDev;
}

float calcAvg(int s1, int s2, int s3, int s4, int nScor){
    float a, sum;
    sum = s1 + s2 + s3 + s4;
    a = sum/nScor;
    cout << "Average Score: " << a << endl;
    return a;
}

float calcDev(int s1, int s2, int s3, int s4, float av, int nScr){
    float dev, total;
    total = 0;
    total += pow(s1-av, 2);
    total += pow(s2-av, 2);
    total += pow(s3-av, 2);
    total += pow(s4-av, 2);
    dev = sqrt(total);
    cout << "Standard Deviation: " << dev << endl;
    return dev;
}