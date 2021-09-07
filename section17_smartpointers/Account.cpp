#include <string>
#include <iostream>
#include "Account.h"
using namespace std;

// Account class methods

const std::string Account::get_name() const{
    return name;
}

const double Account::get_balance() const {
    return balance;
}

void Account::change_name(std::string input_name){
    name = input_name;
}

bool Account::deposit(double input_balance){
    balance += input_balance;
    return true;
}

bool Account::withdraw(double input_balance){
    balance -= input_balance;
    return true;
}

// Account class constructors

Account::Account(std::string input_name, double input_balance)
:name{input_name}, balance{input_balance}{
}

Account::Account()
:name{"None"}, balance{0}{
}

// Account class destructors 

Account::~Account(){
}

std::ostream &operator<<(std::ostream &os, const Account &rhs){
    os << "[Account-> " << rhs.name << ": " << rhs.balance << "]"; 
    return os;
}


