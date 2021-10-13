#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;

int totalBalance;
string nickname;

void rules();
void game();
void options();

int main() {
    cout << "What's Your Name?\n";
    cin >> nickname;
    cout << "Welcome " << nickname;
    cout << "\nWhat's your limit to spent today?\t$";
    cin >> totalBalance;
    cout << "\n Before we start the bet, I'll talk about the rules!\n";

    cout << "\n\n\t\t==============RULES!==============\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";

    cout << "\nLet's play, Good Luck";
    game();
}

void rules() {
    cout << "\n\n\t\t==============RULES!==============\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";

    options();
}

void game() {
    int bettingAmount, dice, guess;
    srand(time(0));
    cout << "\nHow many do you want to start bet?\t $";
    cin >> bettingAmount;
    if(bettingAmount > totalBalance || bettingAmount < 0){
        cout << "This amount is invalid, please put a valid amount!";
        cin >> bettingAmount;
    }
    cout << "\nChoose 1 number between 1 to 10!\n";
    cin >> guess;
    dice = rand()%10 + 1;
    if(guess == dice){
        cout << "You're in Luck, you have Won\t$" << bettingAmount * 10;
        totalBalance = totalBalance + bettingAmount * 10;
    }else{
        cout << "It's bad, you Lost, better luck next time";
        totalBalance = totalBalance - bettingAmount;
    }
    cout << "\nThe win number was\t" << dice << "\n";
    cout << nickname << " Your balance is\t$" << totalBalance;
    options();
}

void options() {
    char choice;
    cout << "\nDo you want to play again?\t [y] Yes, [n] No or [r] rules\n";
    cin >> choice;

    switch (choice) {
        case 'y':
            cout << "\nThanks for playing the game. Your balance is $ " << totalBalance << "\n";
            game();
            break;
        case 'n':
            cout << "\nThanks for playing our game, have a good day!";
            return;
        case 'r':
            rules();
            break;

//Uppercase letters

        case 'Y':
            game();
            break;
        case 'N':
            cout << "\nThanks for playing our game, have a good day!";
            return;
        case 'R':
            rules();
            break;
    }
}