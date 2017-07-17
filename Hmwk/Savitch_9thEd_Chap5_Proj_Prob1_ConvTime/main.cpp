/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 16, 2017, 9:56 PM
 * Purpose:  Take the time in 24 hours and convert to 12.
 */

//System Libraries Here
#include <iostream>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void input();
int newTime(int, int, char);
void output(int, int, char);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char cont;
    //Input or initialize values Here
    cont = 'y';
    while(cont == 'y'){
        input();
        cout << "Press y to run, or anything else to quit: " << endl;
        cin >> cont;
    }
    //Process/Calculations Here
   
    //Output Located Here
    
    //Exit
    return 0;
}

void input(){
    int hour, min;
    cout << "Enter the hour followed by the minute: " << endl;
    cin >> hour >> min;
    if(hour > 12){
        newTime(hour, min, 'p');
    } else {
        newTime(hour, min, 'a');
    }
}

int newTime(int hr, int min, char zone){
    int nHour;
    if (zone == 'a'){
        output(hr, min, 'a');
        return hr + min/100.0f;
    } else {
        nHour = hr % 12;
        output(nHour, min, 'p');
        return nHour + min/100.0f;
    }
}

void output(int hr, int min, char zone){
    if (zone == 'a'){
        cout << "The time is: " << hr << ":" << min << " AM" << endl;
    } else {
        cout << "The time is: " << hr << ":" << min << " PM" << endl;
    }
}
