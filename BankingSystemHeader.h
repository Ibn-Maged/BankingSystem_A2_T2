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

    map<string, BankAccount> Accounts;

public:
    inline Client(string name, string address, string phone);

};


class BankAccount {
protected:
    string AccountID;
    double Balance;

public:
    inline BankAccount();

    inline virtual int withdraw(double amount);

    inline virtual int deposit(double amount);

};


class SavingBankAccount : public BankAccount {
private:
    double MinimumBalance;

public:
    inline SavingBankAccount();

    inline virtual int withdraw(double amount);

    inline virtual int deposit(double amount);

    inline virtual void setMinimumBalance();
};

inline void printDashes();

// End of the file