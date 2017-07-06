/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
const float CONVLTG = .264179;
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float findMPG(int liter, int mile) {
    float mpg = mile/(liter * CONVLTG);
    cout << "Your mileage is " << mpg << " miles per gallon." << endl;
    return mpg;
}


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int lit, mile;
    //Input or initialize values Here
    
    cout << "Please input the liters in your tank and " << endl;
    cout << "the distance you have driven in miles." << endl;
    cin >> lit >> mile;
    //Process/Calculations Here
    findMPG(lit, mile);
    
    //Output Located Here
    
    //Exit
    return 0;
}

