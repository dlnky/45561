/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
const int CNVPERC = 100;
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float fValue1(float , float, int); //Power
float fValue2(float , float, int); //Exponential log
float fValue3(float , float, int); //For-loop
float fValue4(float , float, int); //Recursion
int  fValue5(float, float, int, float&); //Pass by Reference, also static
float fValue1(float , float, float); //Power Overridden using float years
float  fValue6(float, float, int=12); //Power Defaulted years

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float pv, //present value in dollars
            i; //interest rate percent/compounding period
    int n; //number of compounding periods(yrs)
    
    //Input or initialize values Here
    cout << "This is a savings account program" << endl;
    cout << "Input present value in dollars, " << endl;
    cout << "Interest rate in per cent / year, " << endl;
    cout << "the number of compounding periods in years." << endl;
    cin >> pv >> i >> n;
    
    //Map inputs
    i /= CNVPERC; //convert percentage interest to fraction
    
    
    //Process/Calculations Here
    //Initial output
    cout << fixed << setprecision(2) << showpoint;
    cout << endl;
    cout << "The present value= $" << setw(8) << pv << endl;
    cout << "The interest rate = " << setw(8)<< i << "%" << endl;
    cout << "Number of years =  " << setw(5) << n << endl;
    //Output Located Here
    
    cout << "Savings function 1 -> power = $" 
            << fValue1(pv, i, n) << endl;
    cout << "Savings function 1.2 -> Power Float = $" 
            << fValue1(pv, i,static_cast<float>(n) + 0.5f) << endl;
    cout << "Savings function 2 -> exponential = $" 
            << fValue2(pv, i, n) << endl;
    cout << "Savings function 3 -> for-loop = $" 
            << fValue3(pv, i, n) << endl;
    cout << "Savings function 4 -> recursion = $" 
            << fValue4(pv, i, n) << endl;
    
    float fv;
    int nTimes;
    for(int j = 1; j <= 5; j++){
        nTimes = fValue5(pv, i, n, fv);
    }
    
    cout << "Number of times function 5 called = " << nTimes << endl;
    cout << "Savings function 5 -> Reference/Static = $" 
            << fv << endl;
    cout << "Savings function 6 -> power = $" 
            << fValue6(pv, i, n) << endl;
    cout << "Savings function 6 -> power = $" 
            << fValue6(pv, i) << endl;
    
    
    //Exit
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//inputs:
//  pVal -> present value $'s
//  intRate -> Interest Rate as a fraction
//  nPds -> Number of compounding periods(years)
//output:
//  Future value -> units of $'s
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
float fValue1(float pVal,float intRate, int nPds){
    return pVal*pow((1+intRate),nPds);
}

float fValue2(float pVal,float intRate, int nPds){
    return pVal*exp(nPds * log(1+intRate));
}

float fValue3(float pVal,float intRate, int nPds){
    float fv = pVal;
    for(int i=1; i <= nPds; i++){
        fv *= (1 + intRate);
    }
    return fv;
}

float fValue4(float pVal,float intRate, int nPds){
    if(nPds <= 0) return pVal;
    return fValue4(pVal, intRate, nPds - 1) * (1 + intRate);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//inputs:
//  pVal -> present value $'s
//  intRate -> Interest Rate as a fraction
//  nPds -> Number of compounding periods(years)
//output:
//  nTimes -> Number of times the function was called
//  Future value -> units of $'s
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
int fValue5(float pVal, float intRate, int nPds, float &fv){
    //Static variable declaration for the count
    static int nTimes = 0;
    
    //Calculate the future value
    fv = pVal*pow((1 + intRate), nPds);
    return ++nTimes;
}

float fValue1(float pVal,float intRate, float nPds){
    return pVal*pow((1+intRate),nPds);
}
float fValue6(float pVal,float intRate, int nPds){
    return pVal*pow((1+intRate),nPds);
}