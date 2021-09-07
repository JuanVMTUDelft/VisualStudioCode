#include <string>
#include <iostream>
#include "Account.h"
#include "Savings_Account.h"





// Constructor
Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
:Account{name, balance}, int_rate{int_rate}{
};

bool Savings_Account::deposit(double amount){
    amount += amount*(int_rate/100.0);
    return Account::deposit(amount);
}

// Destructor

Savings_Account::~Savings_Account(){
};

// Overloaded operator
std::ostream &operator<<(std::ostream &os, const Savings_Account &rhs){
    os << "[Savings_Account: " << rhs.name << ": " << rhs.balance << ", " << rhs.int_rate << "%]";
    return os;
}


