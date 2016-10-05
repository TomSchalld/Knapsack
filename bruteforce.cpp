//
// Created by tscha on 05/10/2016.
//


#include <sstream>
#include <iterator>
#include "bruteforce.h"

/*** vars ***/
std::string path = "C:\\Users\\tscha\\ClionProjects\\Knapsack\\inst\\knap_4.inst.dat";
std::ifstream file;
static std::vector<std::string> dataFromFile;
std::vector<int> instance;
void printFileContent() {

    for (auto it = dataFromFile.cbegin(); it != dataFromFile.cend(); ++it) {
        std::cout<< *it <<std::endl;
    }
}

void printOutInstance() {
    for (auto it = instance.cbegin(); it != instance.cend(); ++it) {
        std::cout<< *it <<std::endl;
    }
}

void readIn() {
   std::string line;

    file.open (path);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            dataFromFile.push_back(line);
             //std::cout << line << std::endl;
        }
        file.close();
        printFileContent();
        convertLineToInstance(dataFromFile[0]);
    } else{
        std::cout << "Error while opening" << std::endl;
    }
}
void convertLineToInstance(std::string &line) {
    instance.clear();
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
        instance.push_back(std::stoi(*it));
    }


}