#include <iostream>
#include <vector>
#include <memory>

#include "Account.h"
#include "Savings_Account.h"


class Test {
private:
    int data;

public:
    Test():data{0} {std::cout << "Test constructor (" << data << ")" << std::endl;}
    Test(int data): data{data} {std::cout << "Test constructor (" << data << ")" << std::endl;}
    int get_data() const {
        return data;}
    ~Test(){std::cout << "Test destructor (" << data <<")" << std::endl; }
};


void func(std::shared_ptr<Test> &p){
    std::cout << "Use count: " << p.use_count() << std::endl;
}


// Challenge functions
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(){
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::unique_ptr<std::vector<std::shared_ptr<Test>>> &vec, int num){
    vec->push_back(std::make_shared<Test>(num));
}

void display(std::unique_ptr<std::vector<std::shared_ptr<Test>>> &vec){
    std::cout << "[ " << std::endl;
    for (auto current_test: *vec){
        std::cout << current_test->get_data() << std::endl;
    }
    std::cout << " ]" << std::endl;
}





int main(){

// Unique pointers

std::cout << "\n====== Unique pointers ======================================== \n" << std::endl;

std::unique_ptr<Test> t1 {new Test{100}};

std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

std::unique_ptr<Account> a1 = std::make_unique<Savings_Account>("Juan", 100, 1);

std::cout << a1->get_name() << ": " << a1->get_balance() << std::endl;

std::vector<std::unique_ptr<Account>> accounts;

accounts.push_back(std::make_unique<Account>("Juan", 2000));
accounts.push_back(std::make_unique<Account>("Pipo", 3000));
accounts.push_back(std::make_unique<Savings_Account>("Alba", 5000, 2));

for (const auto &acc: accounts){
    std::cout << acc->get_name() << ": " << acc->get_balance() << std::endl;
}


// Shared pointers

std::cout << "\n====== Shared pointers ======================================== \n" << std::endl;


std::shared_ptr<Test> s_p1 = std::make_shared<Test>(10000);
func(s_p1);

std::vector<std::shared_ptr<Test>> shared_pointers;

shared_pointers.push_back(std::make_shared<Test>(1));
shared_pointers.push_back(std::make_shared<Test>(2));
shared_pointers.push_back(std::make_shared<Test>(3));

for (auto &poin: shared_pointers){
    func(poin);
}


// ==================== Challenge =======================================

std::cout << "\n====== Challenge ======================================== \n" << std::endl;

std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;

vec_ptr = make();

fill(vec_ptr, 1);
fill(vec_ptr, 2);
fill(vec_ptr, 3);
display(vec_ptr);


return 0;

}


