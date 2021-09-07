#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"

// Functions for Account class

void display (const std::vector<Account> accounts){
    std::cout << "\n=== Current accounts ====================================" << std::endl;
    std::cout << "|" << std::setw(10) << "Name" 
              << "|" << std::setw(10) << "Balance" << "|" << std::endl;
    
    std::cout << "----------------------" << std::endl;

    
    for (auto &acc:accounts){
        std::cout << "|" << acc << std::endl; 
    }


};


void deposit (std::vector<Account> &accounts, double val){
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:accounts){
        if (acc.deposit(val))
            std::cout << "Deposited " << val << " to " << acc << std::endl;
        else    
            std::cout << "Failed deposit of " << val << " to " << acc << std::endl;
    }
};

template <typename T>
void withdraw (std::vector<T> &accounts, double val){
};

void deposit_ptr(std::vector<Account*> pointers, double val){
 std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:pointers){
        if (acc->deposit(val))
            std::cout << "Deposited " << val << " to " << *acc << std::endl;
        else    
            std::cout << "Failed deposit of " << val << " to " << *acc << std::endl;
    }
};