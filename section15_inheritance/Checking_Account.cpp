#include <string>
#include <iostream>
#include "Account.h"
#include "Checking_Account.h"

// Class constructor

Checking_Account::Checking_Account(std::string name, double balance):
Account{name, balance}{
}

// Class methods

bool Checking_Account::withdraw(double amount){
    amount += fee;
    return Account::withdraw(amount);
};

std::ostream &operator<<(std::ostream &os, const Checking_Account &rhs){
    os << "[Checking_Account: " << rhs.name << ": " << rhs.balance << ", " << rhs.fee << "$ fee]";
    return os;
}