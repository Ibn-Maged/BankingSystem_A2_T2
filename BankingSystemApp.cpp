/*
FCAI - Programming 2 - 2022 - Assignment 2 - Task 2
Program Name:           Banking System
Program Description:    This program is a bank system which -Creates clients and two types of bank accounts
                        -Stores data per run -Withdraw money -Deposit money
Last Modification Date: November 2, 2022
Version:                v1.4.0
Authors:                Youssef Moataz, Hassan Magdy,   Mohamed Maged
ID:                     20210488,       20210126,       20210352
Group:                  A
Labs:                   S9-S10
Purpose:                Master OOP by making such great banking system project
*/

#include "BankingSystemFunctions.cpp"

int main() {

//    printDashes();

    initializeSomeData();
    BankApplication bankApplication = BankApplication();


    return 0;
}
