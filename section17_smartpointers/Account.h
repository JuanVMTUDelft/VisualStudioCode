#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>
class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
private:
    // Account class atributes
    std::string name;
    double balance;
public:
    const std::string get_name() const;
    void change_name(std::string);
    const double get_balance() const;
    bool deposit(double);
    bool withdraw(double);

    // Account class constructors
    Account(std::string, double);
    Account();

    // Account class destructors
    ~Account();


};

#endif