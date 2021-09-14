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
   
    // Accounts
    // vector<Account> accounts;
    // accounts.push_back(Account {});
    // accounts.push_back(Account {"Larry"});
    // accounts.push_back(Account {"Moe", 2000} );
    // accounts.push_back(Account {"Curly", 5000} );
    
    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts,2000);
    
    // Savings 

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

