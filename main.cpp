#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>

#include "bruteforce.h"
int main() {

    /*ops *o = new ops();
    o->readInFile();
    std::cout << "Read in completed \n\n\n\n" << std::endl;
    o->print();
    delete(o);*/
    /*readIn();
    printOutInstance();
    generateCombinations();*/
    /*const int n = 4;
    unsigned long maxCombinations=0;
    std::bitset<n> countSet;
    std::vector<std::bitset<n>> combinations;
    countSet.set();
    maxCombinations = countSet.to_ulong();
    std::cout<<"Max Combinations = "<< maxCombinations << std::endl;

    for (unsigned long i = 1; i < maxCombinations+1; i++) {
        combinations.push_back(std::bitset<n>(i));
    }
    for (auto it = combinations.cbegin(); it != combinations.cend(); ++it) {
        std::cout<<*it<<std::endl;
    }*/
    bruteForce();


    /*std::cout<< combinations.count() << " ones and ";
    std::cout << (combinations.size()-combinations.count()) << " zeros.\n";*/
    return 0;
}