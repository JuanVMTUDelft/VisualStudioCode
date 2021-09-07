#include <string>
#include <iostream>
#include "Account.h"
#include "Savings_Account.h"



double Savings_Account::get_interest(){
    return int_rate;
}

// Constructor
Savings_Account::Savings_Account(std::string name_val, double balance_val, double int_val)
:Account{name_val, balance_val}, int_rate{int_val}{
};

Savings_Account::

// Destructor

Savings_Account::~Savings_Account(){
};


