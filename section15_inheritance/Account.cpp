#include <string>
#include <iostream>
#include "Account.h"



// Account class constructors

Account::Account(std::string name, double balance)
:name{name}, balance{balance}{
}

// Account class methods

bool Account::deposit(double amount){
    if (amount < 0.0){
        return false;
    }
    else{
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount){
    if (balance - amount <0.0){
        return false;
    }
    else{
        balance -= amount;
        return true;
    }
}

// Account class destructors 

Account::~Account(){
}

std::ostream &operator<<(std::ostream &os, const Account &rhs){
    os << "[Account-> " << rhs.name << ": " << rhs.balance << "]"; 
    return os;
}


