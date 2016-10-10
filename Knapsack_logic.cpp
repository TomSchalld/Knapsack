//
// Created by tscha on 05/10/2016.
//


#include <ctime>
#include <algorithm>
#include "Knapsack_logic.h"



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
    std::bitset<n> temp;
    result best;
    clock_t time;
    int capacity = instance.at(2);
    tempResult.ID = instance.at(0);
    tempResult.totalWeight = 0;
    best.ID = instance.at(0);
    setMultiplikator();

    //printCombinations();
    //TODO take time here
    time = clock();
    for (int k = 0; k < multiplikator; ++k) {


        for (auto it = combinations.cbegin(); it != combinations.cend(); ++it) {
            temp = *it;
            tempResult.totalWeight = 0;
            tempResult.totalCost = 0;
            tempResult.bitset = temp;
            unsigned int j = 3;
            for (int i = n - 1; i > -1; i--) {
                if (temp[i] == 1) {
                    tempResult.totalWeight += instance.at(j);
                    tempResult.totalCost += instance.at(j + 1);
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
    best.computationalTime = ((double) time / CLOCKS_PER_SEC) / multiplikator;

    resultset.push_back(best);

}

void setMultiplikator() {
    switch (n) {
        case 4:
            multiplikator = 100000;
            break;
        case 10:
            multiplikator = 1000;
            break;
        case 15:
            multiplikator = 10;
            break;
        default:
            multiplikator = 1;
            break;
    }
}

/*** returns if first param better result then second ***/
bool betterResult(result a, result b) {
    return a.totalCost >= b.totalCost;
}

void bruteForce() {
    readIn();
    generateCombinations();
    for (auto it = instances.cbegin(); it != instances.cend(); ++it) {
        doTheComputation(*it);
    }

}

void exportToDesktop() {
    std::string path;
    std::string home;
#ifdef _WIN32
    home = getenv("HOMEPATH");
#else
    home= getenv("HOME");
#endif
    path = home + "/Desktop/result_" + std::to_string(n) + ".csv";
    std::ofstream results;
    results.open(path);
    for (auto it = resultset.cbegin(); it != resultset.cend(); ++it) {
        results << "Instance ID," << it->ID << ",Total Wieght," << it->totalWeight << ",Total Cost," << it->totalCost
                << ",BitSet,'" << it->bitset << "' ,Computational Time in seconds," << it->computationalTime << "\n";
    }
    results.close();
}

void printResultSet() {
    result best;
    for (auto it = resultset.cbegin(); it != resultset.cend(); ++it) {
        best = *it;
        std::cout << "|Best Result: " << best.ID << " total weight " << best.totalWeight << " total cost: "
                  << best.totalCost << " bitset: " << best.bitset << "|" << std::endl;
        std::cout << time << " CPU-Clicks needed" << std::endl;
        std::cout << best.computationalTime << "micro seconds CPU-Time needed" << std::endl;
    }
}

void greedy() {
    readIn();
    for (auto it = instances.cbegin(); it != instances.cend(); ++it) {
        doGreedyOnInstance(*it);
    }

}

void doGreedyOnInstance(std::vector<int> instance) {
    int capacity = instance.at(2);
    result bestCombo;
    std::vector<item>items;
    setMultiplikator();
    time_t time;
    for (int i = 3, j = 0; i < instance.size(); i += 2) {
        items.push_back(
                item(j++, instance.at(i + 1), instance.at(i), ((float) instance.at(i + 1) / instance.at(i))));
    }
    //TODO take time here
    time = clock();
    for (int k = 0; k < multiplikator; ++k) {
        bestCombo.setZero();
        std::sort(items.begin(), items.end(), item::compareRatio);
        for (auto it = items.cbegin(); it != items.cend(); ++it) {
            if (bestCombo.totalWeight + it->weight <= capacity) {
                bestCombo.totalWeight += it->weight;
                bestCombo.totalCost += it->cost;
                bestCombo.bitset[it->id] = 1;
            } else {
                bestCombo.bitset[it->id] = 0;
            }

        }
    }
    //TODO take time here
    time = clock() - time;
    bestCombo.ID=instance.at(0);
    bestCombo.computationalTime = ((double) time / CLOCKS_PER_SEC) / multiplikator;
    resultset.push_back(bestCombo);
}

