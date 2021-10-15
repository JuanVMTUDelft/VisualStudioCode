#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Person{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age):
        name{name}, age{age}{};
    Person(const Person &p):
        name{p.name}, age{p.age}{};
    ~Person() = default;
    std::string get_name(){
        return name;
    }
    void set_name(std::string name){
        this->name = name;
    }
    int get_age(){
        return age;
    }
    void set_age(int age){
        this->age = age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs){
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;  
}

void test1(){
    std::cout << "\n================== Test 1 ==================" << std::endl;

    [] () {std::cout << "Hi!" << std::endl;} ();

    [] (int x) {std::cout << x << std::endl;} (100);

    [] (int x, int y) {std::cout << x+y << std::endl;} (100, 200);


}

void test2(){
    std::cout << "\n================== Test 2 ==================" << std::endl;

    auto i1 = [] () {std::cout << "Hi" << std::endl;};

    i1();

    int num1{200};
    int num2{100};

    auto i2 = [] (int x, int y) {std::cout << x << "+" << y << " is equal to " << x+y << std::endl;};

    i2(num1, num2);
    i2(100, 300);

    auto i3 = [] (int &x, int y) {
        std::cout << "x: " << x << ", y: " << y << std::endl;
        x = 1000;
        y = 2000;
        std::cout << "x: " << x << ", y: " << y << std::endl;
    };

    i3(num1, num2);
    std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;

 }

 void test3(){
    std::cout << "\n================== Test 3 ==================" << std::endl;
    Person stooge {"Larry", 25};
    std::cout << stooge << std::endl;

    auto i4 = [] (Person p) {
        std::cout << p << std::endl;
    };

    i4(stooge);

    auto i5 = [] (Person &p) {
        std::cout << p << std::endl;
        p.set_name("Larryto");
        p.set_age(12);
    };

    i5(stooge);

    std::cout << stooge << std::endl;
 }


void filter_vector (const std::vector<int> &vec, std::function<bool(int)> func){
    std::cout << "[";
    for (int i: vec){
        if (func(i)){
            std::cout << i << " ";
        }
    }
    std::cout << " ]";
}

void test4(){
    std::cout << "\n================== Test 4 ==================" << std::endl;
    std::vector<int> numbers {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};

    filter_vector(numbers, [] (int x) {return x > 50;});

}

int global_x {1000};

void test5(){
    std::cout << "\n================== Test 5 ==================" << std::endl;
    int local_x {50};

    auto i6 = [local_x] () {
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };

    i6();


}

void test6(){
    std::cout << "\n================== Test 6 ==================" << std::endl;
    int x {100};

    auto I = [x] () mutable {
        x += 100;
        std::cout << "Internal variable:" << x << std::endl;
    };

    I();

    std::cout <<  "External variable: " << x << std::endl;

    auto I2 = [&x] () mutable {
        x += 100;
        std::cout << "Internal variable:" << x << std::endl;
    };

    I2();
    std::cout <<  "External variable: " << x << std::endl;

}

int main(){

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

return 0;
}