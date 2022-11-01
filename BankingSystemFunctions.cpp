//
// Created by Youssef Moataz on 10/27/2022.
//
#include "BankingSystemHeader.h"

// Youssef
BankApplication::BankApplication() {

    bool validMenuOption = false;

    string selectedMenuOption;

    while (!validMenuOption) {

        cout << "Welcome to FCAI Banking Application " << endl <<
             "1. Create a New Account " << endl <<
             "2. List Clients and Accounts " << endl <<
             "3. Withdraw Money " << endl <<
             "4. Deposit Money" << endl <<
             "5. Exit" << endl <<
             "Please Enter Choice =========> ";

        cin >> selectedMenuOption;

        if (selectedMenuOption == "1") {
            // create new account

        } else if (selectedMenuOption == "2") {
            // show all clients and accounts

        } else if (selectedMenuOption == "3") {
            // withdraw

        } else if (selectedMenuOption == "4") {
            // deposit

        } else if (selectedMenuOption == "5") {
            // exit
            exit(0);
        } else {
            // invalid option
            cout << endl << "Enter a valid option !" << endl;
        }

    }


}

// Youssef
bool BankApplication::addClient() {

}

// Youssef
Client::Client(string name, string address, string phone) {

}

BankAccount::BankAccount() {

}

int BankAccount::withdraw(double amount) {

}

int BankAccount::deposit(double amount) {

}

SavingBankAccount::SavingBankAccount() {

}

int SavingBankAccount::withdraw(double amount) {

}

int SavingBankAccount::deposit(double amount) {

}

// Youssef
void printDashes() {
    cout << string(20, '-') << endl;
}

// End of the file