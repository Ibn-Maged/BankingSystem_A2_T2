//
// Created by Youssef Moataz on 10/27/2022.
//

#ifndef BANKINGSYSTEM_A2_T2_BANKINGSYSTEMHEADER_H
#define BANKINGSYSTEM_A2_T2_BANKINGSYSTEMHEADER_H

#endif //BANKINGSYSTEM_A2_T2_BANKINGSYSTEMHEADER_H

#include <iostream>
#include <map>

using namespace std;

class BankAccount;

class Client;

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

//    map<string, BankAccount> Accounts;

public:
    inline Client(string name, string address, string phone);

    inline string getClientID();

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
    inline virtual int withdraw(double amount);

    inline virtual int deposit(double amount);

    // getters and setters
    inline double getBalance();

    inline string getID();

    inline void setBalance(double Balance);
};


class SavingBankAccount : public BankAccount {
private:
    double MinimumBalance = 1000;

public:
    inline SavingBankAccount(double Balance);

    inline virtual int withdraw(double amount);

    inline virtual int deposit(double amount);

    inline virtual void setMinimumBalance();
};

inline void printDashes();

inline map<string, BankAccount &> DATA;

// End of the file