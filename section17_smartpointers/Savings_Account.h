#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include <string>
#include <iostream>
#include "Account.h"


class Savings_Account: public Account{



private:
    // Class attributes
    double int_rate; 

public:
    // Class methods 
    double get_interest();

    // Constructor
    Savings_Account(std::string, double, double);

    // Destructor
    ~Savings_Account();

};







#endif