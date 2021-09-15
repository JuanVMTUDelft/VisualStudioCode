// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <map>



int main() {

    // Open file with filename
    std::fstream in_file;
    std::string filename{".//responses.txt"};

    in_file.open(filename);
    
    // Check if file is correctly open
    if (in_file.is_open()){
        std::cout << filename << " is open" << std::endl;
    }
    else{
        std::cout << "Not possible to open" << std::endl;
    }

    // Load reference answers 

    std::string correctAnswers;
    in_file >> correctAnswers;

    // Load names of the students and answers
    std::map<std::string, std::string> students;
    std::string currentName;
    std::string currentAnswers;

    while(!in_file.eof()){
        in_file >> currentName;
        in_file >> currentAnswers;
        students[currentName] = currentAnswers;
    }
    
    // Print names alphabetically and their answers
    for(std::map<std::string, std::string>::const_iterator it = students.begin();
    it != students.end(); ++it){
        std::cout << it->first << ": " << it->second << "\n";
    }

    // Close file
    in_file.close();

    // Check scores

    std::map<std::string, double> scores;
    double currentScore {0};

    for(std::map<std::string, std::string>::const_iterator it = students.begin();
    it != students.end(); ++it){
        currentScore = 0;
        for (size_t i_char{0}; i_char < correctAnswers.length(); ++i_char){
            if (it->second[i_char] == correctAnswers[i_char]){
                ++currentScore;
            }
        }
        scores[it->first] = currentScore;
    }

    double totalScore {0};
    // Print scores
    for(std::map<std::string, double>::const_iterator it = scores.begin();
    it != scores.end(); ++it){
        std::cout << it->first << ": " << it->second << "\n";
        totalScore += it->second;
    }

    double averageScore {totalScore/scores.size()};

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Average score: " << averageScore << std::endl;




    return 0;
    std::cout << "Hello world" << std::endl;
}

