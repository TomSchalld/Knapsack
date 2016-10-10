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
static const int n=40; //not very elegant
struct result{
    int ID=0;
    int totalCost=0;
    int totalWeight=INT_MAX;
    std::bitset<n> bitset;
    double computationalTime;

    friend std::ostream &operator<<(std::ostream &os, const result &result1) {
        os << "ID: " << result1.ID << " totalCost: " << result1.totalCost << " totalWeight: "
           << result1.totalWeight << " bitset: " << result1.bitset << " computationalTime: "
           << result1.computationalTime;
        return os;
    }
    void setZero(){
         ID=0;
         totalCost=0;
         totalWeight=0;
         bitset=0;
         computationalTime=0;
    }
};
struct item{
    int id;
    int cost;
    int weight;
    float ratio;

    item(int id, int cost, int weight, float ratio) : id(id), cost(cost), weight(weight), ratio(ratio) {}
    static bool compareRatio(const item &a, const item &b){
        return a.ratio>b.ratio;
    }

    friend std::ostream &operator<<(std::ostream &os, const item &item1) {
        os << "id: " << item1.id << " cost: " << item1.cost << " weight: " << item1.weight << " ratio: " << item1.ratio;
        return os;
    }
};
/*** vars ***/
//static std::string path = "C:\\Users\\tscha\\ClionProjects\\Knapsack\\inst\\knap_"+std::to_string(n)+".inst.dat";
static std::string path = "/Users/Thomas/ClionProjects/Knapsack/inst/knap_"+std::to_string(n)+".inst.dat";

static std::ifstream file;
static std::vector<std::string> dataFromFile;
static std::vector<std::vector<int>> instances;
static unsigned long maxCombinations=0;
static std::vector<std::bitset<n>> combinations;
static std::vector<result> resultset;
static int multiplikator;

/*** functions ***/
void setMultiplikator();
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
void exportToDesktop();
void printResultSet();
void doGreedyOnInstance(std::vector<int> instance);
void greedy();
#endif //KNAPSACK_BRUTEFORCE_H
