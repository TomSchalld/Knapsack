//
// Created by tscha on 06/11/2016.
//

#ifndef KNAPSACK_BRANCHANDBOUND_H
#define KNAPSACK_BRANCHANDBOUND_H


#include "Instance.h"
#include "Instances.h"
#include "DataImport.h"
#include <queue>

class BranchAndBound {

private:
    Instances* instances;
    void pushBitSetToQ(const int capacity, std::queue<std::vector<bool>> &queue) const;

public:
    BranchAndBound();
    void solveAndPrintInstance(Instance * instance);
    void solveAndPrintInstances();
    int calculateCurrentCost(std::vector<bool, std::allocator<bool>> *bitSet, Instance *inst);

    int calculateRemainingCost(std::vector<bool, std::allocator<bool>> *bitSet, Instance *pInstance);

    int calculatePosition(std::vector<bool> *items);

    int calculateCurrentWeight(std::vector<bool> *items, Instance *pInstance);

    std::vector<bool> generateNextBit(std::vector<bool> *items, int position);
};


#endif //KNAPSACK_BRANCHANDBOUND_H
