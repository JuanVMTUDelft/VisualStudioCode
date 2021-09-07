#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#include <iomanip>

std::string clean_string(const std::string &s){
    std::string result;
    for (char letter: s){
        if (letter == ';' || letter == ':' || letter == ',' || letter == ' ' || letter == '.')
            continue;
        else 
            result += std::toupper(letter);
    }
return result;
}


bool is_a_palindrome(const std::string &s){
    std::stack<char> front_s;
    std::stack<char> back_s;

    std::string clean {clean_string(s)};

    bool palindrome;


    for (size_t i {0}; i < s.length(); i++){
        front_s.emplace(clean.at(i));
        back_s.emplace(clean.at(s.length()-1-i));

        if (front_s.top()==back_s.top())
            palindrome = true;
        else 
            palindrome = false;
    }


return palindrome;
}



int main(){

    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::string current_string {clean_string(test_strings.at(11))};
    std::cout << current_string << std::endl;

    for (size_t i{0}; i < current_string.length(); i++){
        std::cout << current_string.at(i) << std::endl;
    }

    std::cout << std::boolalpha;
    std::cout << is_a_palindrome(current_string);

    

return 0;   
}