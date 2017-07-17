/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 16, 2017, 8:46 PM
 * Purpose:  Convert a weight in pounds and ounces into kilograms and grams.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
float const CONVKTP = 2.2046;
float const CONVPTO = 16;

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void input();
float calc(int);
void output(int, int, int, int);

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
    int lbs, oz, kg, g , nOz;
    
    cout << "Input the weight in pounds, ounces: " << endl;
    cin >> lbs >> oz;
    nOz = lbs * CONVPTO;
    g = calc(nOz);
    kg = g / 1000.0f;
    g %= 1000;
    output(lbs, oz, kg, g);
}

float calc(int ounce){
    float gram;
    gram = (ounce * 1000.0f)/(16 * CONVKTP);
    cout << "Grams: " << gram << endl;
    return gram;
}

void output(int lbs, int oz, int kg, int g){
    oz %= 16;
    cout << "Number of pounds:    " << lbs << endl;
    cout << "Number of ounces:    " << oz << endl;
    cout << "Number of kilograms: " << kg << endl;
    cout << "Number of grams:     " << g << endl;
}