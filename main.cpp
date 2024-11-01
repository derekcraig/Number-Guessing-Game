/* 
CS10A - Professor Harden

Number Guessing Game

Description: Demonstrates the use of functions through a number guessing
             game. User is asked if they would like to play a game with a
             'y/n' prompt. The program will then make a guess by finding
             the midpoint between globally declared constants LOWER_LIMIT
             and UPPER_LIMIT rounding down. The user is then prompted to
             provide feedback on the programs guess by asking if the guess
             is too high, too low or correct. It it is too high, the current
             guess replaces the lower value and the midpoint is found again
             and vica versa until the correct number is found and confirmed.
             Afterwards the user is asked if they would like to play again.

 Date: 9/11/2023
 
 Programmer: Derek Craig
*/
#include <iostream>
using namespace std;

void playOneGame();
void getUserResponseToGuess( int, char& );
int getMidpoint( int, int );

const int LOWER_LIMIT = 1;
const int UPPER_LIMIT = 100;

int main() {
    char response;
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}






    void playOneGame(){
    int lowerGuess = LOWER_LIMIT;
    int higherGuess = UPPER_LIMIT;
    int currentGuess;
    char result = 'h';
  
    cout << "Think of a number between " << LOWER_LIMIT << " and " 
         << UPPER_LIMIT << "." << endl;
    
    while( result != 'c' ) {
    
    getUserResponseToGuess(getMidpoint( lowerGuess, higherGuess), result );
    
    currentGuess = getMidpoint( lowerGuess, higherGuess );
       
      if( result == 'l' ) {
          higherGuess = currentGuess - 1;
       
      } else if ( result == 'h' ) {
          lowerGuess = currentGuess + 1;
       
      } else if ( result == 'c' ) {
          return;
       
      } else {
          cout << "Invalid input. Please Enter 'l' if your number is lower, "
               << "'h' if it is higher, 'c' if it is correct: ";
          cin >> result;
      }
    }
    }






    void getUserResponseToGuess(int guess, char& result) {
    cout << "My guess is " << guess 
         << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c'"
         << " if it is correct: ";
    cin >> result;
    }

  




    int getMidpoint(int low, int high) {

    int midpoint;
    int numberOfDigits = (high - low) + 1 ;

    if( numberOfDigits % 2 != 0 ) {
    midpoint = (numberOfDigits / 2) + (low);
    
    } else {
       midpoint = (numberOfDigits / 2) + (low - 1);
    }

    return midpoint;
    }

/*
    Example Output
    
Ready to play (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if 
it is correct: h
My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if 
it is correct: h
My guess is 88. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if 
it is correct: l
My guess is 81. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if 
it is correct: c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if 
it is correct: l
My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if 
it is correct: h
My guess is 37. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if 
it is correct: c
Great! Do you want to play again (y/n)? n
*/