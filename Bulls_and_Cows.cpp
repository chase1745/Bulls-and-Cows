//
//  main.cpp
//  HW 3
//
//  Created by Chase McDermott on 9/16/16.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int rseed = 5, numDigits, randNum, userCode, userLength, tempNum, userGuess, bulls = 0, cows = 0, RANGE = 10;
    srand(rseed);
    vector<int> code;
    
    
    cout << "Enter number of digits in code (3, 4, or 5): " << endl;
    cin >> numDigits;  // 1) Get the number of digits to guess
    
    userLength = numDigits;
    
    if (numDigits == 3 || numDigits == 4 || numDigits == 5) {
        for (int i = 0; i < numDigits; i++) {  // Create vector with size of user input
            randNum = rand() % RANGE;
            if (i > 0) {  // dont check on first iteraton because vector is empty
                for (int j = 0; j <= code.size(); j++) {
                    while (randNum == code[j]) {  // check to see if number is already in code.
                        randNum = rand() % RANGE;
                    }
                }
            }
            code.push_back(randNum);  // place the number into the vector
        }
        
        cout << "Number to guess: ";
        
        for (int i = 0; i < code.size(); i++) {
            cout << code[i];
        }
        
    } else if (numDigits == 0) {
        cout << "Enter code: " << endl;
        cin >> userCode;
        
        cout << "Enter number of digits in code: " << endl;
        cin >> userLength;
        
        for (int i = pow(10, userLength-1); i >= 1; i /= 10) {  // loop through int, putting digits into vector
            tempNum = userCode / i;
            code.push_back(tempNum);
            userCode %= i;
        }
        
        cout << "Number to guess: ";
        
        for (int i = 0; i < code.size(); i++) {
            cout << code[i];
        }
        
    } else {  // if the input is not 0, 3, 4, or 6
        cout << "ERROR: Please enter 3, 4, or 5." << endl;
    }
    cout << endl;
    
    
    // guessing section
    do {
        vector<int> guess;  // create vector for guess
        
        bulls = 0, cows = 0;
        // input the guess
        cout << "Enter guess: " << endl;
        cin >> userGuess;
        
        while (userGuess >= pow(10,userLength)) {  // make sure code is correct length
            cout << "You can only enter " << userLength << " digits." << endl;
            cin >> userGuess;
        }
        
        for (int i = pow(10, userLength-1); i >= 1; i /= 10) {  // loop through int, putting digits into vector
            tempNum = userGuess / i;
            guess.push_back(tempNum);
            userGuess %= i;
        }
        
        bool repeatNum = false;
        for (int i = 0; i < userLength; i++) {  
            for (int j = i+1; j < userLength; j++) {
                if (guess[i] == guess[j]) repeatNum = true;
            }
        }
        if (repeatNum) {
            cout << "Each number must be different." << endl;
            continue;
        }
        
        for (int i = 0; i < userLength; i++) {  // find bulls
            if (code[i] == guess[i]) {
                bulls++;
            }
        }
        
        for (int i = 0; i < userLength; i++) {  // find cows
            for (int j = 0; j < userLength; j++) {
                if (guess[i] == code[j]) {
                    if (i != j) {  // cannot be both a bull and cow
                        cows++;
                    }
                }
            }
        }
        if (bulls == userLength) break;
        cout << bulls << " bulls" << endl << cows << " cows" << endl;
    } while (bulls != userLength);  // runs until guess  is the same as the code.
    
    cout << bulls << " bulls - ";
    for (int i = 0; i < code.size(); i++) {
        cout << code[i];
    }
    cout << " is correct!" << endl;
    
    
    
    return 0;
}
