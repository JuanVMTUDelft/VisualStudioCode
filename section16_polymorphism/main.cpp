// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "I_Printable.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   

    vector<std::shared_ptr<Account>> sav_accounts;
    sav_accounts.push_back(std::make_shared<Savings_Account>());
    sav_accounts.push_back(std::make_shared<Savings_Account>("Superman"));
    sav_accounts.push_back(std::make_shared<Savings_Account>("Batman", 2000));
    sav_accounts.push_back(std::make_shared<Savings_Account>("Wonderwoman", 5000, 5.0));

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
    
    return 0;
}

