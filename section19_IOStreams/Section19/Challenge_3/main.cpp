// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void clean(std::string){
    
}

int main() {
    std::fstream in_file;
    std::string filename {".//romeoandjuliet.txt"};

    std::vector<std::string> words;
    std::string currentWord;
    
    in_file.open(filename);

    if (in_file.is_open()){
        while (!in_file.eof()){
            in_file >> currentWord;
            if (currentWord != "|"){
                words.push_back(currentWord);
            }
        }
    }else{
        std::cout << "File not found" << std::endl;
    }
    
    for (size_t i{0}; i < 20; ++i){
            std::cout << words.at(i) << std::endl;
    }

    

    return 0;
}

