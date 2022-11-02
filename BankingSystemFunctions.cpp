//
// Created by Youssef Moataz on 10/27/2022.
//
#include "BankingSystemHeader.h"

// Youssef
BankApplication::BankApplication() {

    string selectedMenuOption;

    while (true) {

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

            string clientName;
            string clientAddress;
            string clientPhone;
            string clientAccountType;
            string clientStartingBalance;

            cout << "Please Enter Client Name =========> ";
            cin >> clientName;

            cout << "Please Enter Client Address =======> ";
            cin >> clientAddress;

            cout << "Please Enter Client Phone =======> ";
            cin >> clientPhone;

//            do {
//                cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========> ";
//                cin >> clientAccountType;
//            } while (clientAccountType != "1" || clientAccountType != "2");

            cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========> ";
            cin >> clientAccountType;

            cout << "Please Enter the Starting Balance =========> ";
            cin >> clientStartingBalance;

            // to prevent object slicing
            SavingBankAccount savingBankAccount;
            BankAccount *bankAccount = &savingBankAccount;

            // create account
            if (clientAccountType == "1") {

                clientAccountType = Basic;

                (*bankAccount) = BankAccount(stod(clientStartingBalance));

                bankAccount->increaseIDCounter();

            } else if (clientAccountType == "2") {

                clientAccountType = Saving;

                (*bankAccount) = SavingBankAccount(stod(clientStartingBalance));

                bankAccount->increaseIDCounter();
            }

            // create client
            Client client = Client(clientName, clientAddress, clientPhone, clientAccountType);

            // add to dataset
            DATA[client.getClientID()] = (*bankAccount).getID();
            CLIENTS[client.getClientID()] = client;
            ACCOUNTS[(*bankAccount).getID()] = (*bankAccount);

            cout << "An account was created with ID " << (*bankAccount).getID() <<
                 " and Starting Balance " << (*bankAccount).getBalance() << " L.E." << endl;


        } else if (selectedMenuOption == "2") {
            // show all clients and accounts

            for (int i = 1; i <= DATA.size(); ++i) {

                cout << setw(20) << setfill('-') << CLIENTS["CID-" + to_string(i)].getName() << endl;
                cout << "Address : " << CLIENTS["CID-" + to_string(i)].getAddress() << endl;
                cout << "Phone : " << CLIENTS["CID-" + to_string(i)].getPhone() << endl;
                cout << "Account ID : " << DATA["CID-" + to_string(i)] << " ("
                     << CLIENTS["CID-" + to_string(i)].getAccountType() << ")" << endl;
                cout << "Balance : " << ACCOUNTS["FCAI-" + to_string(i)].getBalance() << endl;


            }
            printDashes();
            cout << endl;

        } else if (selectedMenuOption == "3") {
            // withdraw

            string accID;
            string accType;
            double accBalance;
            double withdrawAmount = -1.0;

            cout << "Please Enter Account ID (e.g., FCAI-015) =========>";
            cin >> accID;

            // get account data
            accType = CLIENTS["CID-" + accID.substr(5)].getAccountType();
            accBalance = ACCOUNTS[accID].getBalance();

            // print some account data
            cout << "Account ID : " << accID << endl;
            cout << "Account Type : " << accType << endl;
            cout << "Balance : " << accBalance << endl;

            // to prevent object slicing
            SavingBankAccount savingBankAccount;
            BankAccount *bankAccount = &savingBankAccount;

            // get account data
            bankAccount = &ACCOUNTS[accID];

            // get amount and withdraw
            cout << "Please Enter The Amount to Withdraw =========>";
            cin >> withdrawAmount;
            bankAccount->withdraw(withdrawAmount);

            // get the updated data
            ACCOUNTS[accID] = (*bankAccount);

            // print the updated data
            cout << "Account ID : " << accID << endl;
            cout << "New Balance : " << ACCOUNTS[accID].getBalance() << endl;

            printDashes();
            cout << endl;

        } else if (selectedMenuOption == "4") {
            // deposit

            string accID;
            string accType;
            double accBalance;
            double depositAmount = -1.0;

            cout << "Please Enter Account ID (e.g., FCAI-015) =========>";
            cin >> accID;

            // get account data
            accType = CLIENTS["CID-" + accID.substr(5)].getAccountType();
            accBalance = ACCOUNTS[accID].getBalance();

            // print some account data
            cout << "Account ID : " << accID << endl;
            cout << "Account Type : " << accType << endl;
            cout << "Balance : " << accBalance << endl;

            // to prevent object slicing
            SavingBankAccount savingBankAccount;
            BankAccount *bankAccount = &savingBankAccount;

            // get account data
            bankAccount = &ACCOUNTS[accID];

            // get amount and deposit
            cout << "Please Enter The Amount to Deposit =========>";
            cin >> depositAmount;

            if(accType == Saving){
                if (depositAmount >= MinimumDeposit)
                bankAccount->deposit(depositAmount);
            } else{
                bankAccount->deposit(depositAmount);
            }


            // get the updated data
            ACCOUNTS[accID] = (*bankAccount);

            // print the updated data
            cout << "Account ID : " << accID << endl;
            cout << "New Balance : " << ACCOUNTS[accID].getBalance() << endl;

            printDashes();
            cout << endl;

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
Client::Client(string name, string address, string phone, string accountType) {

    this->Name = name;
    this->Address = address;
    this->Phone = phone;
    this->AccountType = accountType;

    clientCounter++;
    ClientID = "CID-" + to_string(clientCounter);

}

string Client::getClientID() {
    return ClientID;
}

string Client::getName() {
    return Name;
}

string Client::getAddress() {
    return Address;
}

string Client::getPhone() {
    return Phone;
}

string Client::getAccountType() {
    return AccountType;
}

// mohamed 
// constructors
BankAccount::BankAccount() {
    counter++;
    AccountID = "FCAI-" + to_string(counter);
    Balance = 0;
}

BankAccount::BankAccount(double Balance) {
    AccountID = "FCAI-" + to_string(counter);
    this->Balance = Balance;
}

// withdraw and deposit
bool BankAccount::withdraw(double amount) {
    if (Balance >= amount) {
        Balance -= amount;
        cout << "Thank you." << endl;
        return 1;
    } else {
        return 0;
    }
}

bool BankAccount::deposit(double amount) {
    Balance += amount;
    return 1;
}

// getters and setters
double BankAccount::getBalance() {
    return Balance;
}

string BankAccount::getID() {
    return AccountID;
}

void BankAccount::setBalance(double Balance) {
    this->Balance = Balance;
}

void BankAccount::increaseIDCounter() {
    counter++;
}

SavingBankAccount::SavingBankAccount(double Balance) : BankAccount(Balance) {
    while (Balance < MinimumBalance) {
        cout << "saving accounts require a minimum starting balance of" << MinimumBalance << endl;
        cout << "Please enter valid starting balance:";
        cin >> Balance;
    }
    this->Balance = Balance;

}

bool SavingBankAccount::withdraw(double amount) {
    if ((amount - Balance) < MinimumBalance) {
        return 0;
    } else {
        Balance -= amount;
        cout << "Thank you." << endl;
        return 1;
    }

}

bool SavingBankAccount::deposit(double amount) {
    if (amount >= 100) {
        Balance += amount;
        return 1;
    } else {
        return 0;
    }
}

void SavingBankAccount::setMinimumBalance() {

}

// Youssef
void printDashes() {
    cout << string(20, '-') << endl;
}

void initializeSomeData() {

    DATA["CID-1"] = "FCAI-1";
    DATA["CID-2"] = "FCAI-2";
    DATA["CID-3"] = "FCAI-3";
//
    CLIENTS["CID-1"] = Client("Youssef", "Haram", "01011", Basic);
    CLIENTS["CID-2"] = Client("Hassan", "Dokki", "01112", Saving);
    CLIENTS["CID-3"] = Client("Mohamed", "Cairo", "01213", Basic);
//
    ACCOUNTS["FCAI-1"] = BankAccount(50.5);
    ACCOUNTS["FCAI-2"] = BankAccount(1250);
    ACCOUNTS["FCAI-3"] = BankAccount(400);

}

// End of the file