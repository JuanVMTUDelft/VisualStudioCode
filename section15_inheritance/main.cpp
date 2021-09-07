#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Account_util.h"






int main(){

Account Juan_empty{};
Account Juan{"Juan", 10000};
Savings_Account Juan_savings{"Juan Savings", 10000, 1};
Checking_Account Juan_checking{"Juan Checking", 20000};

std::cout << Juan_empty << std::endl;
std::cout << Juan << std::endl;
std::cout << Juan_savings << std::endl;
std::cout << Juan_checking << std::endl;

std::vector<Account> accounts {Juan_empty, Juan, Juan_savings};




return 0;
}