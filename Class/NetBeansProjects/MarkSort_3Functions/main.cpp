/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 20, 2017, 10:43 AM
 * Purpose:  Sorting in 3 functions
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void fillAr(int [], int);
void printAr(int [], int, int);
void swap(int &, int &);
void minPos(int [], int, int);
void markSrt(int [] , int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random number
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE = 100;
    int array[SIZE];
    //Input or initialize values Here
    fillAr(array, SIZE);
    printAr(array, SIZE, 10);
    //Process/Calculations Here
    minPos(array,SIZE, 0);
    
    markSrt(array, SIZE);
    //Output Located Here
    printAr(array, SIZE, 10);

    //Exit
    return 0;
}

void markSrt(int a[] , int n){
    for(int i = 0; i < n- 1;i++){
        minPos(a, n, i);
    }
}


void minPos(int a[], int n, int pos){
    for(int i = pos + 1; i < n; i++)
        if(a[pos]>a[i]) swap(a[pos], a[i]);
}


void swap(int &a, int &b){
    a = a^b;
    b = b^a;
    a = a^b;
}
void fillAr(int a[], int n){
    for(int i=0; i<n; i++){
        a[i] = rand()%90+10;
    }
}

void printAr(int a[], int n, int perLine){
    for(int i =0; i < n; i++){
        cout << a[i]<< " ";
        if(i%perLine ==(perLine - 1)){
            cout << endl;
        }
    }
    cout << endl;
}