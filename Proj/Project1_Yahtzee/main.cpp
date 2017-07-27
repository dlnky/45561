/* 
 * File:   main.cpp
 * Author: Cole Greenwood
 * Created on July 20, 2017, 12:01 AM
 * Purpose:  Create a yahtzee game that can get the highest scores on its own
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
short yatzy(char [], int);  //check if a yahtzee has been scored
short fullHs(char[], int);  // check if a full house has been scored
short lStrt(char[], int);   //check if a large straight has been scored
short sStrt(char[], int);   // check if a small straight has been scored
short fourOK(char [], int); //check the score for a four of a kind
short thrOK(char [], int);  //check the score for a three of a kind
short chance(char [], int); // check the score for a chance
short aces(char [], int);   //check the score for the aces
short twos(char [], int);   //check the score for the twos
short threes(char [], int); //check the score for the threes
short fours(char [], int);  //check the scores for the fours
short fives(char [], int);  //check the scores for the fives
short sixes(char [], int);  //check the scores for the sixes
short play(int);            //run the full games
void roll(char [], int);    //roll the dice for a hand
void sort(char [], int);    //sort the hand of dice
void keep(char [], int);    //decide which dice to keep
void printAr(char [], int); //print the dice
void prntRun(bool [], int); //print the menu of options

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE = 5; //size of hand
    
    char arr[SIZE] = {}; //array to rep dice
    short score, win;    //final score and score needed for win
    score = 0;
    
    //Input or initialize values Here
    cout << "Input the score you want to win(100-200)" << endl;
    cin >> win;
    
    roll(arr, SIZE);
    score = play(SIZE);
    
    cout << "A score of " << win << " is needed to win." << endl;
    if(score >= win){
        cout << "You won with a score of " << score << endl;
    } else{
        cout << "You lost with a score of " << score << endl;
    }
    
    //Exit
    return 0;
}
//        Rolls the dice
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  Basically a replacement for fillArray. So a full array
void roll(char dice[], int n){
    for(int i = 0; i < n; i++){
        dice[i] = rand()% 6 + 49;
    }
}

//        Prints the array
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The array of dice printed out in a little format
void printAr(char a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//        Prints the menu
//Inputs:
//  run[] -> the boolean array of runs
//  n -> the size of said array
//Outputs:
//  Prints each score type and whether or not they are available
void prntRun(bool run[], int n){
    cout << "Yahtzee:         ";
    if(!run[0])cout << "Open" << endl;
    else cout << "Closed" << endl;
    cout << "Large Straight:  ";
    if(!run[1])cout << "Open ";
    else cout << "Closed ";
    cout << "Small Straight:  ";
    if(!run[2])cout << "Open" << endl;
    else cout << "Closed" << endl;
    cout << "Full House:      ";
    if(!run[3])cout << "Open ";
    else cout << "Closed ";
    cout << "Four of a Kind:  ";
    if(!run[4])cout << "Open" << endl;
    else cout << "Closed" << endl;
    cout << "Three of a Kind: ";
    if(!run[5])cout << "Open ";
    else cout << "Closed ";
    cout << "Chance:          ";
    if(!run[6])cout << "Open" << endl;
    else cout << "Closed" << endl;
    cout << "Sixes:           ";
    if(!run[7])cout << "Open ";
    else cout << "Closed ";
    cout << "Fives:           ";
    if(!run[8])cout << "Open" << endl;
    else cout << "Closed" << endl;
    cout << "Fours:           ";
    if(!run[9])cout << "Open ";
    else cout << "Closed ";
    cout << "Threes:          ";
    if(!run[10])cout << "Open" << endl;
    else cout << "Closed" << endl;
    cout << "Twos:            ";
    if(!run[11])cout << "Open ";
    else cout << "Closed ";
    cout << "Aces:            ";
    if(!run[12])cout << "Open" << endl;
    else cout << "Closed" << endl;
}

//        User says which dice they want to hold
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  a new array where some values stayed the same and others changed
void keep(char dice[], int n){
    char in1, in2, in3, in4, in5;
    char kept[n] = {};
    printAr(dice, n);
    cout << "Enter a y in the positions of the numbers to keep: " << endl;
    cout << "Enter an n in the positions of the numbers to replace: " << endl;
    cin >> in1 >> in2 >> in3 >> in4 >> in5;
    if(in1 == 'n'){
        dice[0] = '0';
    }
    if(in2 == 'n'){
        dice[1] = '0';
    }
    if(in3 == 'n'){
        dice[2] = '0';
    }
    if(in4 == 'n'){
        dice[3] = '0';
    }
    if(in5 == 'n'){
        dice[4] = '0';
    }
    roll(kept, n);
    for(int i = 0; i < n; i++){
        if(dice[i] == '0'){
            dice[i] = kept[i];
        }
    }
}

//        Runs the entire game
//Inputs:
//  n -> The number of dice in a hand
//Outputs:
//  the total sum of all scores
short play(int n){
    short sums[13] = {};
    short rolls = 3;
    char dice[n];
    bool runs[13] = {};
    bool ran1, ran2, ran3, ran4, ran5, ran6, ran7, ran8, ran9,
            ran10, ran11, ran12, ran13;
    ran1 = ran2 = ran3 = ran4 = ran5 = ran6 = ran7 = ran8
            = ran9 = ran10 = ran11 = ran12 = ran13 = false;
    for(int i = 0; i < 13; i++){
        roll(dice, n);
        for(int j = 1; j <= rolls; j++){
            prntRun(runs, 13);
            if(yatzy(dice, n) > 0 && runs[0] == false){
                cout << "YAHTZEE! + 50" << endl;
                sums[0] = 50;
                runs[0] = true;
                break;
            } else if(lStrt(dice, n) > 0 && runs[1] == false){
                cout << "Large Straight! + 40" << endl;
                sums[1] = 40;
                runs[1] = true;
                break;
            } else if(sStrt(dice, n) > 0 && runs[2] == false){
                cout << "Small Straight! + 30" << endl;
                sums[2] = 30;
                runs[2] = true;
                break;
            } else if(fullHs(dice, n) > 0 && runs[3] == false){
                cout << "Full House! + 25" << endl;
                sums[3] = 25;
                runs[3] = true;
                break;
            } else if(fourOK(dice, n) >= 20 && runs[4] == false){
                cout << "Four of a kind! + " << fourOK(dice, n) << endl;
                sums[4] = fourOK(dice, n);
                runs[4] = true;
                break;
            } else if(thrOK(dice, n) >= 20 && runs[5] == false){
                cout << "Three of a kind! + " << thrOK(dice, n) << endl;
                sums[5] = thrOK(dice, n);
                runs[5] = true;
                break;
            } else if(chance(dice, n) > 22 && runs[6] == false){
                cout << "Chance! + " << chance(dice, n) << endl;
                sums[6] = chance(dice, n);
                runs[6] = true;
                break;
            } else if(sixes(dice, n) >= 18 && runs[7] == false){
                cout << "Sixes = " << sixes(dice, n) << endl;
                sums[7] = sixes(dice, n);
                runs[7] == true;
                break;
            } else if(fives(dice, n) >= 15 && runs[8] == false){
                cout << "Fives = " << fives(dice, n) << endl;
                sums[8] = fives(dice, n);
                runs[8] = true;
                break;
            } else if(fours(dice, n) >= 12 && runs[9] == false){
                cout << "Fours = " << fours(dice, n) << endl;;
                sums[9] = fours(dice, n);
                runs[9] = true;
                break;
            } else if(threes(dice, n) >= 9 && runs[10] == false){
                cout << "Threes = " << threes(dice, n) << endl;
                sums[10] = threes(dice, n);
                runs[10] = true;
                break;
            } else if(twos(dice, n) >= 6 && runs[11] == false){
                cout << "Twos = " << twos(dice, n) << endl;
                sums[11] = twos(dice, n);
                runs[11] = true;
                break;
            } else if(aces(dice, n) >= 3 && runs[12] == false){
                cout << "Aces = " << aces(dice, n) << endl;
                sums[12] = aces(dice, n);
                runs[12] = true;
                break;
            } else if(aces(dice, n) > 0 && runs[12] == false){
                if(j > 2){
                    cout << "Aces = " << aces(dice, n) << endl;
                    sums[12] = aces(dice, n);
                    runs[12] = true;
                } else{
                    cout << "Aces re-roll" << endl;
                    keep(dice, n);
                }
            } else if(twos(dice, n) > 0 && runs[11] == false){
                if(j > 2){
                    cout << "Twos = " << twos(dice, n) << endl;
                    sums[11] = twos(dice, n);
                    runs[11] = true;
                } else{
                    cout << "Twos re-roll" << endl;
                    keep(dice, n);
                }
            } else if(threes(dice, n) > 0 && runs[10] == false){
                if(j > 2){
                    cout << "Threes = " << threes(dice, n) << endl;
                    sums[10] = threes(dice, n);
                    runs[10] = true;
                } else{
                    cout << "Threes re-roll" << endl;
                    keep(dice, n);
                }
            } else if(chance(dice, n) > 15 && runs[6] == false){
                cout << "Chance = " << chance(dice, n) << endl;
                sums[6] = chance(dice, n);
                runs[6] = true;
                break;
            } else if(fours(dice, n) > 0 && runs[9] == false){
                if(j > 2){
                    cout << "Fours = " << fours(dice, n) << endl;
                    sums[9] = fours(dice, n);
                    runs[9] = true;
                } else{
                    keep(dice, n);
                }          
            } else if(fourOK(dice, n) > 15 && runs[4] == false){
                cout << "Four of a Kind = " << fourOK(dice, n) << endl;
                sums[4] = fourOK(dice, n);
                runs[4] = true;
                break;
            } else if(thrOK(dice, n) > 12 && runs[5] == false){
                cout << "Three of a Kind = " << thrOK(dice, n) << endl;
                sums[5] = thrOK(dice, n);
                runs[5] = true;
                break;
            } else if(fives(dice,n) > 0 && runs[8] == false){
                if(j > 2){
                    cout << "Fives = " << fives(dice, n) << endl;
                    sums[8] = fives(dice, n);
                    runs[8] = true;
                } else{
                    cout << "Fives re-roll" << endl;
                    keep(dice, n);
                }
            } else if(sixes(dice, n) > 0 && runs[7] == false){
                if(j > 2){
                    cout << "Sixes = " << sixes(dice, n) << endl;
                    sums[7] = sixes(dice, n);
                    runs[7] = true;
                } else{
                    cout << "Sixes re-roll" << endl;
                    keep(dice, n);
                }
            } else{
                cout << "No Points." << endl;
                for(int j = 12; j >= 7; j--){
                    if(runs[j] == false){
                        sums[j] = 0;
                        runs[j] = true;
                        break;
                    }
                }
            }
        }
    }
    short total = 0;
    for(short val:sums){
        total += val;
    }
    return total;
}

//        Sorts the array
//Inputs:
//  a[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  A new array that has been sorted in ascending order
void sort(char a[], int n){
    for(int i = 0; i < n- 1;i++){
        for(int j = i + 1; j < n; j++){
            if(a[i]>a[j]){
                a[i] = a[i]^a[j];
                a[j] = a[j]^a[i];
                a[i] = a[i]^a[j];
            }
        }
    }
}

//        Checks if there was a yahtzee
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  Whether or not all dice were the same
short yatzy(char dice[], int n){
    char check = dice[0];
    for(int i = 0; i < n; i++){
        if(dice[i] != check){
            return 0;
        }
    } return 50;
}

//        Checks if there was a Full house
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  Whether or not there was a full house
short fullHs(char dice[], int n){
    char check1, check2;
    short count1, count2;
    check1 = dice[0];
    check2 = '0';
    count1 = count2 = 0;
    for(int i = 0; i < n; i++){
        if(dice[i] == check1){
            count1++;
        } else if(dice[i] == check2){
            count2++;
        } else if(check2 == '0' && dice[i] != check1){
            check2 = dice[i];
            count2++;
        }
    }
    if((count2 == 3 && count1 == 2) || ((count2 == 2 && count1 == 3))){
        return 25;
    } else {
        return 0;
    }
}

//        Checks if there was a large straight
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  Whether or not there was a large straight
short lStrt(char dice[], int n){
    short count = 1;
    sort(dice,n);
    for(int i = 1; i < n; i++){
        if(dice[i - 1] + 1 == dice[i]){
            count++;
        }
    } if(count >= 5){
        return 40;
    } else {
        return 0;
    }
}

//        Checks if there was a small straight
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  Whether or not there was a small straight
short sStrt(char dice[], int n){
    short count = 1;
    sort(dice,n);
    for(int i = 1; i < n; i++){
        if(dice[i - 1] + 1 == dice[i]){
            count++;
        }
    } if(count >= 4){
        return 30;
    } else {
        return 0;
    }
}

//        Checks if there was four of a kind
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  Whether or not four dice were the same
short fourOK(char dice[], int n){
    short count1, count2, sum;
    char check1, check2;
    count1 = count2  = 1;
    sum = 0;
    check1 = dice[0];
    check2 = '0';
    for(int i = 0; i < n; i++){
        if(dice[i] == check1){
            count1++;
            sum += dice[i] - 48;
        } else if(dice[i] == check2){
            count2++;
            sum += dice[i] - 48;
        } else if(check2 == '0' && dice[i] != check1){
            check2 = dice[i];
            sum += dice[i] - 48;
        }
    }
    if(count1 >= 4){
        return sum;
    } else if(count2 >= 4){
        return sum;
    } else{
        return 0;
    }
}

//        Checks if there was three of a kind
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  Whether or not three dice were the same
short thrOK(char dice[], int n){
    short count1, count2, count3, sum;
    char check1, check2, check3;
    count1 = count2 = count3 = 0;
    sum = 0;
    check1 = dice[0];
    check2 = check3 = '0';
    for(int i = 0; i < n; i++){
        if(dice[i] == check1){
            count1++;
            sum += dice[i] - 48;
        } else if(dice[i] == check2){
            count2++;
            sum += dice[i] - 48;
        } else if(dice[i] == check3){
            count3++;
            sum += dice[i] - 48;
        } else if(check2 == '0' && dice[i] != check1){
            check2 = dice[i];
            sum += dice[i] - 48;
            count2++;
        } else if(check3 == '0' && dice[i] != check1 && dice[i] != check2){
            check3 = dice[i];
            sum += dice[i] - 48;
            count3++;
        }
    }
    if(count1 >= 3){
        return sum;
    } else if(count2 >= 3){
        return sum;
    } else if(count3 >= 3){
        return sum;
    } else{
        return 0;
    }
}

//        Scores the total of all dice
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The total when all dice are added up
short chance(char dice[], int n){
    short sum = 0;
    for(int i = 0; i < n; i++){
        sum += dice[i] - 48;
    }
    return sum;
}

//        Scores the total of all aces
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The total of all ones in the hand
short aces(char dice[], int n){
    short sum = 0;
    for(int i = 0; i < n; i++){
        if(dice[i] == '1') sum += 1; 
    }
    return sum;
}

//        Scores the total of all twos
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The total of all twos in the hand
short twos(char dice[], int n){
    short sum = 0;
    for(int i = 0; i < n; i++){
        if(dice[i] == '2') sum += 2; 
    }
    return sum;
}

//        Scores the total of all threes
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The total of all threes in the hand
short threes(char dice[], int n){
    short sum = 0;
    for(int i = 0; i < n; i++){
        if(dice[i] == '3') sum += 3; 
    }
    return sum;
}

//        Scores the total of all fours
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The total of all fours in the hand
short fours(char dice[], int n){
    short sum = 0;
    for(int i = 0; i < n; i++){
        if(dice[i] == '4') sum += 4; 
    }
    return sum;
}

//        Scores the total of all fives
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The total of all fives in the hand
short fives(char dice[], int n){
    short sum = 0;
    for(int i = 0; i < n; i++){
        if(dice[i] == '5') sum += 5; 
    }
    return sum;
}

//        Scores the total of all sixes
//Inputs:
//  dice[] -> the character array of dice
//  n -> the size of said array
//Outputs:
//  The total of all sixes in the hand
short sixes(char dice[], int n){
    short sum = 0;
    for(int i = 0; i < n; i++){
        if(dice[i] == '6') sum += 6; 
    }
    return sum;
}