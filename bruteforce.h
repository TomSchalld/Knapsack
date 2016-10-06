//
// Created by tscha on 05/10/2016.
//

#ifndef KNAPSACK_BRUTEFORCE_H
#define KNAPSACK_BRUTEFORCE_H

/*** includes ***/
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <bitset>
#include <climits>

/*** define ***/
static const int n=25; //not very elegant
struct result{
    int ID=0;
    int k=0;
    int totalCost=0;
    int totalWeight=INT_MAX;
    std::bitset<n> bitset;
};
/*** vars ***/
static std::string path = "C:\\Users\\tscha\\ClionProjects\\Knapsack\\inst\\knap_"+std::to_string(n)+".inst.dat";
static std::ifstream file;
static std::vector<std::string> dataFromFile;
static std::vector<std::vector<int>> instances;
static unsigned long maxCombinations=0;
static std::vector<std::bitset<n>> combinations;
/*** functions ***/
void convertLineToInstance(std::string line);
void printFileContent();
void readIn();
void printOutInstance();
void convertDataToInstances();
void generateCombinations();
void doTheComputation(std::vector<int> instance);
void bruteForce();
bool betterResult(result a, result b);
void printCombinations();
#endif //KNAPSACK_BRUTEFORCE_H
