//
// Created by Thomas Schalldach on 03/10/2016.
//

#ifndef KNAPSACK_KNAP_INST_H
#define KNAPSACK_KNAP_INST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "knap_Item.h"
class knap_Inst {

    int ID;
    int numberOfItems;
    int capacity;
    std::vector<knap_Item> items;
    struct weightCostValues{
        int totalWeight;
        int totalCost;
    };
    struct bestCombination{
        weightCostValues best;
        int combination[];
    };
    bestCombination result;
public:
    knap_Inst(int ID, int numberOfItems, int capacity);
     ~knap_Inst();
    void dataToInstance(std::vector<std::string> &data);
    void print() const;
    void bruteForce() const;
    void printResult();

    void setResult(const bestCombination &result);

};


#endif //KNAPSACK_KNAP_INST_H
