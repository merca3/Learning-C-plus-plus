/* 
 My imagination is quite poor, but I decided to write a code for Rock-Paper-Scissors 
 game using knowledge and code examples from our semester :) Specifically - linked list.

 User should enter amount of rounds he/she wants to play (or 0 to quit), so depending on that 
 computer game options will be already created and stored in linked list. Once user enters 
 his value for the game round, linked list is being updated, and computer option values (r/p/s/) 
 are rewritten to winner values (c/u/t).
 After all rounds are over, all 't' values are removed from linked list, and results are 
 calculated and printed.
*/

#include <iostream>

using namespace std;

struct elem {
    char info;
    elem *next;
};

void push_back(elem*&first, elem*&last, char val) { // for adding values to linked list
    elem *p = new elem;
    p->info = val;
    p->next = NULL;
    if (first == NULL) {
        first = p;
        last = p;
    } else {
        last->next = p;
        last = p;
    }
}

void printLinkedList(elem*first) { // added here for testing purposes
    elem *p = first;
    if (p == NULL) {
        cout << "*** List is empty ***" << endl;
        return;
    }
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteLinkedList(elem*&first) {
    elem *p=first;
    while(first!=NULL) {
        p=first->next;
        delete first;
        first=p;
    }
}

void introTexts() {
    cout << "--------------- Welcome to SDF bonus task by Katrina ---------------" << endl;
    cout << "----------------     Rock  -  Paper  -  Scissors    ----------------" << endl;
    cout << endl;
    cout << "--- How many rounds do you want to play?" << endl;
    cout << "Enter amount of rounds (or 0 to quit): ";
}

char generateRandomComputerOption() {
    int randomNumber = rand() % 3 + 1;
    
    if (randomNumber == 1) return 'r';
    if (randomNumber == 2) return 'p';
    if (randomNumber == 3) return 's';
    
    return 'n'; // in case if something goes wrong...
}

string findRoundWinner(char computerOption, char userOption) {
    bool computerWin = (computerOption == 'r' && userOption == 's') 
        || (computerOption == 'p' && userOption == 'r') 
        || (computerOption == 's' && userOption == 'p');

    bool userWin = (userOption == 'r' && computerOption == 's') 
        || (userOption == 'p' && computerOption == 'r') 
        || (userOption == 's' && computerOption == 'p');
    
    if (computerOption == 'n') {
        cout << "Something went wrong in computer option generation..." << endl;
        return "";
    }
    if (computerWin) return "computer";
    if (userWin) return "user";
    return "tie";
}

void updateResults(elem*&first, char userOption, int roundNr) {
    elem *p = first;
    
    // getting to element of specific round
    if (roundNr != 0) {
        for (int i = 0; i < roundNr; i++) {
            p = p->next;
        }
    }
    
    // changing the value to the winner value, to be counted later
    char computerOption = p->info;
    string winner = findRoundWinner(computerOption, userOption);
    if (winner == "computer") {
        cout << "Oops - you lost this round... Try again!" << endl;
        p->info = 'c';
    } else if (winner == "user") {
        cout << "Congrats - you won this round!" << endl;
        p->info = 'u';
    } else {
        cout << "Oh, it's a tie!" << endl;
        p->info = 't';
    }
}

void cleanUpAndPrintResults(elem*&first) {
    elem *p = first;

    // removing tie values for easier calculation of results (and simply more interesting code)
    elem* prev = nullptr;   // empty header
    elem* current = first;  // the first valid node
    
    while (current != nullptr) {
        if (current->info == 't') {     // in case if we need to remove current element
            if (current == first) first = current->next;    // in case if it's first element
            else prev->next = current->next;

            // delete the element and move on to the next element.
            elem *temp = current;
            current = current->next;
            delete temp;
        } else {                        // in case we don't want to remove current element
            prev = current;
            current = current->next;
        }
    }

    cout << "-------------------------- !!! Results !!! -------------------------" << endl;
    cout << endl;
    
    // printing results
    p = first;
    if (p == NULL) {
        cout << "---- It's a tie! Both you and random generator are quite lucky! ----" << endl;
        return;
    }
    
    int sizeCounter = 0, userWins = 0;
    while (p != NULL) {
        if (p->info == 'u') userWins++;
        p = p->next;
        sizeCounter++;
    }
    
    if (userWins > sizeCounter - userWins) cout << "--------------- You won this game - congratulations! ---------------" << endl;
    else if (userWins < sizeCounter - userWins) cout << "- You were close... but you lost this game... Good luck next time! -" << endl;
    else cout << "---- It's a tie! Both you and random generator are quite lucky! ----" << endl;
}


int main()
{
    char playAgain = 'y';
    while (playAgain == 'y') { // for repeated game option
    
        introTexts();
        
        int roundAmount;
        while (true) {
            cin >> roundAmount;
        
            // Check if the input was a valid number.
            if (cin.fail()) {
                cout << "!!! Please enter a valid number or 0 to quit !!!" << std::endl;
                cout << "Enter your amount of rounds again: ";
        
                // Clear the error flag and discard the invalid input.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        }
        
        if (roundAmount == 0) {
            cout << endl;
            cout << "--- You've decided to quit the game..." << endl;
            cout << "--- Sad, but hope to see you next time!" << endl;
            break;
        }
        
        elem *first = NULL, *last = NULL;
        for (int i = 0; i < roundAmount; i++) {
            push_back(first, last, generateRandomComputerOption());
        }
    
        cout << endl;
        cout << "--- And now let's start the game..." << endl;
        cout << "--- Enter 'r' for Rock, 'p' for Paper and 's' for Scissors" << endl;
        cout << endl;
        
        for (int i = 0; i < roundAmount; i++) {
            if (i == roundAmount - 1) {
                cout << "Last round - enter your option: ";
            } else cout << "Round " << i+1 << " - enter your option: ";
            
            char userOption;
            cin >> userOption;
            if (userOption != 's' && userOption != 'r' && userOption != 'p') {
                cout << "!!! Please enter only 'r', 'p' or 's' !!!" << endl;
                cout << "Enter your option again: ";
                cin >> userOption;
            }
            updateResults(first, userOption, i);
            cout << endl;
        }
    
        cleanUpAndPrintResults(first);  // removes unnecessary tie values in the list and prints final game result
        // printLinkedList(first);      // seeing changed list for testing purposes
        deleteLinkedList(first);        // cleans up the memory
        
        cout << endl;
        cout << "--- Want to play again?" << endl;
        cout << "--- Enter 'y' for Yes or any other key for No" << endl;
        cin >> playAgain;
        cout << endl;
    }
    
    cout << endl;
    cout << "------------------------- Have a nice day! -------------------------" << endl;
}

