//
// Created by tscha on 05/10/2016.
//


#include <ctime>
#include "bruteforce.h"


void printFileContent() {

    for (auto it = dataFromFile.cbegin(); it != dataFromFile.cend(); ++it) {
        std::cout << *it << std::endl;
    }
}

void printOutInstance() {
    for (auto it = instances.cbegin(); it != instances.cend(); ++it) {
        for (auto iter = it->cbegin(); iter != it->cend(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;

    }
}

void readIn() {
    std::string line;

    file.open(path);
    if (file.is_open()) {
        while (getline(file, line)) {
            dataFromFile.push_back(line);
            //std::cout << line << std::endl;
        }
        file.close();
        //printFileContent();
        convertDataToInstances();
    } else {
        std::cout << "Error while opening" << std::endl;
    }
}

void convertDataToInstances() {
    for (auto it = dataFromFile.cbegin(); it != dataFromFile.cend(); ++it) {
        convertLineToInstance(*it);
    }
}

void convertLineToInstance(std::string line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};
    std::vector<int> instance;
    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
        instance.push_back((std::stoi(*it)));
    }
    instances.push_back(instance);
}

void generateCombinations() {
    std::bitset<n> countSet;
    countSet.set();
    maxCombinations = countSet.to_ulong();
    //std::cout << "Max Combinations = " << maxCombinations << std::endl;

    for (unsigned long i = 1; i < maxCombinations + 1; i++) {
        combinations.push_back(std::bitset<n>(i));
    }

}

void printCombinations() {
    for (auto it = combinations.cbegin(); it != combinations.cend(); ++it) {
        std::cout << *it << std::endl;
    }
}

void doTheComputation(std::vector<int> instance) {
    result tempResult;
    result best;
    clock_t time;
    int multiplikator = 1;
    double computationalTime;
    int capacity = instance.at(2);
    tempResult.ID = instance.at(0);
    tempResult.totalWeight = 0;
    best.ID = instance.at(0);
    printCombinations();
    //TODO take time here
    time = clock();
    for (int k = 0; k < multiplikator; ++k) {


        for (auto it = combinations.cbegin(); it != combinations.cend(); ++it) {
        //for (int l = 0; l < combinations.size(); ++l) {


            std::bitset<n> temp(it->to_string());
            tempResult.totalWeight=0;
            tempResult.totalCost =0;
            tempResult.bitset = temp;
            //temp = combinations.at(l);
            for (unsigned int i = 0, j = 3; i < n; i++) {
                if (temp[i] == 1) {
                    tempResult.totalWeight += instance.at(j);
                    tempResult.totalCost += instance.at(j + 1);
                    //tempResult.bitset = temp;

                }
                j += 2;
            }
            if (betterResult(tempResult, best)) {
                if (tempResult.totalWeight <= capacity) {
                    best = tempResult;
                }
            }
        }


    }
    //TODO take time here
    time = clock() - time;
    std::cout << "|Best Result: " << best.ID << " total weight " << best.totalWeight << " total cost: "
              << best.totalCost << " bitset: " << best.bitset << "|" << std::endl;

    computationalTime = ((double) time / CLOCKS_PER_SEC) / multiplikator;
    std::cout << time << " CPU-Clicks needed" << std::endl;
    std::cout << computationalTime << "micro seconds CPU-Time needed" << std::endl;

}

/*** returns if first param better result then second ***/
bool betterResult(result a, result b) {
    return  a.totalCost >= b.totalCost;
}

void bruteForce() {
    readIn();
    generateCombinations();
    for (auto it = instances.cbegin(); it != instances.cend(); ++it) {
        doTheComputation(*it);
    }

}
