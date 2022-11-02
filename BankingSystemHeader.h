//
// Created by Youssef Moataz on 10/27/2022.
//

#ifndef BANKINGSYSTEM_A2_T2_BANKINGSYSTEMHEADER_H
#define BANKINGSYSTEM_A2_T2_BANKINGSYSTEMHEADER_H

#endif //BANKINGSYSTEM_A2_T2_BANKINGSYSTEMHEADER_H

#include <iostream>
#include <map>
#include <iomanip>

#define Basic "Basic"
#define Saving "Saving"

using namespace std;

class BankAccount;

class SavingBankAccount;

class Client;

inline map<string, string> DATA;
inline map<string, Client> CLIENTS;
inline map<string, BankAccount> ACCOUNTS;

class BankApplication {
public:
    inline BankApplication();

    inline bool addClient();

};


class Client {
private:
    string Name;
    string Address;
    string Phone;
    string AccountType;
    string ClientID;
    inline static int clientCounter = 0;

//    map<string, BankAccount> Accounts;

public:
    inline Client() {};

    inline Client(string name, string address, string phone, string accountType);

    inline string getClientID();

    inline string getName();

    inline string getAddress();

    inline string getPhone();

    inline string getAccountType();
};


class BankAccount {
protected:
    string AccountID, AccountType = "Basic";
    double Balance;
    inline static int counter = 0;

public:
    // constructors
    inline BankAccount();

    inline BankAccount(double Balance);

    // withdraw and deposit
    inline virtual bool withdraw(double amount);

    inline virtual bool deposit(double amount);

    // getters and setters
    inline double getBalance();

    inline string getID();

    inline void setBalance(double Balance);
};


class SavingBankAccount : public BankAccount {
private:
    double MinimumBalance = 1000;
    double minimumDeposit = 100;

public:
    // to overcome object creation to avoid object slicing
    inline SavingBankAccount() { counter--; }

    inline SavingBankAccount(double Balance);

    inline virtual bool withdraw(double amount);

    inline virtual bool deposit(double amount);

    inline virtual void setMinimumBalance();
};

inline void printDashes();

inline void initializeSomeData();

// End of the file