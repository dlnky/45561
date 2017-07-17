/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 16, 2017, 8:36 PM
 * Purpose:  Convert feet and inches into meters and centimeters.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float CONVMTF = .3048;
const float CONVFTI = 12;

//Function Prototypes Here
void input();
void output(int, int, int, int);
float calc(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    
    //Input or initialize values Here
    input();
    //Process/Calculations Here
    
    //Output Located Here
    
    //Exit
    return 0;
}

void input(){
    int inch, feet, meter, cent;
    cout << "Input a length in feet, inches: " << endl;
    cin >> feet >> inch;
    inch += feet * CONVFTI;
    cent = calc(inch);
    meter = cent / 100;
    cent = cent % 100;
    output(meter, cent, inch, feet);

}

float calc(int inches){
    float meter, cent;
    cent = (inches * CONVMTF * 100.0f)/12;
    return cent;
}

void output(int met, int cent, int in, int ft){
    in %= 12;
    cout << "Number of feet:       " << ft << endl;
    cout << "Number of inches:     " << in << endl;
    cout << "Number of meters:     " << met << endl;
    cout << "Number of cenimeters: " << cent << endl;
}