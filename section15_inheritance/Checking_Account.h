#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <string>
#include <iostream>
#include "Account.h"

class Checking_Account: public Account{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &rhs);

private:
    static constexpr const char *def_name = "Unnamed Chacking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double fee = 0.0;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
};


#endif