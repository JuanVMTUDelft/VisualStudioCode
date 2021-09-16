// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main() {

    std::fstream in_file;
    std::ofstream out_file;
    std::string filename_in{".//romeoandjuliet"};
    std::string filename_out {".//romeoandjuliet_num.txt"};
    std::string line{};

    in_file.open(filename_in);
    out_file.open(filename_out);

    if (in_file.is_open()){
        std::cout << "File open" << std::endl;
    }else{
        std::cout << "Could not open file" << std::endl;
    }
    
    double numLine {1};
    if (in_file){
        while (std::getline(in_file, line)){
            if (!line.empty()){
                out_file << std::left << std::setw(7) << numLine
                     << line << std::endl;
                ++numLine;
            }else{
                out_file << line << std::endl;
            }
        }
    }

    if (out_file.is_open()){
        std::cout << "File open" << std::endl;
    }else{
        std::cout << "Could not open file" << std::endl;
    }

    in_file.close();
    out_file.close();

    return 0;
}

