#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include <string>
#include <iostream>
#include "Account.h"


class Savings_Account: public Account{
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &rhs);

private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:
    // Class attributes
    double int_rate; 

public:
    // Class constructor
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // Class methods 
    bool deposit(double amount);

    // Destructor
    ~Savings_Account();

};







#endif