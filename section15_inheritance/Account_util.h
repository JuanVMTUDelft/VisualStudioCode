#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_


#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"

// Functions for Account class

void display (const std::vector<Account>);


void deposit (std::vector<Account> & , double);


void withdraw (std::vector<Account> &, double);

void deposit_ptr(std::vector<Account*>, double);




#endif