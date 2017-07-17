/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 16, 2017, 9:16 PM
 * Purpose:  Estimate the perimeter of a triangle using 3 sides.
 */

//System Libraries Here
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void calc(int, int, int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int side1, side2, side3;
    //Input or initialize values Here
    cout << "Enter 3 values, one per side: " << endl;
    cin >> side1 >> side2 >> side3;
    //Process/Calculations Here
    calc(side1, side2, side3);
    //Output Located Here
    
    //Exit
    return 0;
}

void calc(int s1, int s2, int s3){
    float semiPer, perim, area;
    semiPer = (s1 + s2 + s3) / 2.0f;
    area = sqrt(semiPer * (semiPer - s1) * (semiPer - s2) * (semiPer - s3));
    perim = s1 + s2 + s3;
    cout << "Length of side one:   " << s1 << endl;
    cout << "Length of side two:   " << s2 << endl;
    cout << "Length of side three: " << s3 << endl;
    cout << "Semiperemter:         " << semiPer << endl;
    cout << "Perimeter:            " << perim << endl;
    cout << "Area:                 " << area << endl;
}