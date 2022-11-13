// Casino Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

void rules() {
    cout << "\t\t======WELCOME TO CASINO NUMBER GUESSING GAME!======" << endl;
    cout << "\t\t===========CASINO NUMBER GUESSING RULES!===========" << endl;
    cout << "\t1. You have to choose a number between 1 to 10." << endl;
    cout << "\t2. Winner gets 10 times of the money bet." << endl;
    cout << "\t3. Wrong bet, and you lose the amount you bet." << endl << endl;
}

int main()
{
    string playerName;                              //Stores player name.
    int dice;                                       //Stores random number.
    int balance;                                    //Stores balance of the player.
    int bettingAmount;                              //Stores betting amount.
    int guess;                                      //Stores number guessed by player.
    char choice;                                    //Stores if player wants to play again or not.
    srand(time(0));                                 //Seeds the function rand().

    cout<< "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nPlease enter your name to proceed : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play the game : $";
    cin >> balance;
    do {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
        do {
            cout << "Hello, " << playerName << ", enter the amount to be bet : $";
            cin >> bettingAmount;
            if (bettingAmount > balance) {
                cout << "Betting balance can't be more than current balance!\n"
                    << "\nRe-enter balance\n ";
            }
        } while (bettingAmount > balance);
        do {
            cout << "Guess any number between 1 and 10 : ";
            cin >> guess;
            if (guess <= 0 || guess > 10) {
                cout << "\nNumber should be between 1 and 10!\n"
                     << "Re-enter number :\n ";
            }
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess) {
            cout << "\n\nYou are in luck!! You have won $" << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else {
            cout << "Oops, better luck next time !! You lost $" << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n" << playerName << ", You have balance of $" << balance << "\n";
        if (balance == 0) {
            cout << "You have no money to play the game again.";
            break;
        }
        cout << "\n\nDo you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $" << balance << "\n\n";
    return 0;
}

