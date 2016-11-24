//
// Created by tscha on 06/11/2016.
//

#include <ctime>
#include "BranchAndBound.h"

BranchAndBound::BranchAndBound() {
    DataImport dataImport;
    dataImport.readIn();
    this->instances = dataImport.createInstances();
}
void BranchAndBound::solvePrintAndExportToDesktop(){
    solveAndPrintInstances();
    this->instances->exportToDesktop();
}
void BranchAndBound::solveAndPrintInstances() {
    Instances *instances = this->instances;
    Instance *tmp = instances->getNextInstance();

    while (tmp != nullptr) {
        solveAndPrintInstance(tmp);
        tmp = instances->getNextInstance();
    }

}

void BranchAndBound::solveAndPrintInstance(Instance *instance) {
    const int capacity = instance->getCapacity();
    const int amountOfItems = instance->getAmountOfItems();
    int currentPosition, bestCostSoFar, currentCost, remainingCost, currentWeight;
    std::vector<bool> currentItemSet, currentBestSolution;
    std::queue<std::vector<bool>> queue;
    time_t time;
    //
    time = clock();
    for (int j = 0; j < instance->getMULTIPLIKATOR(); ++j) {
        currentPosition = 0;
        bestCostSoFar = 0;
        currentCost = 0;
        remainingCost = 0;
        currentWeight = 0;
        clear(currentItemSet);
        clear(currentBestSolution);
        clear(queue);

        pushBitSetToQ(amountOfItems, queue);

        while (!queue.empty()) {
            currentItemSet = queue.front();
            queue.pop();
            currentCost = calculateCurrentCost(&currentItemSet, instance);
            if (currentCost >= bestCostSoFar) {
                bestCostSoFar = currentCost;
                currentBestSolution = currentItemSet;
            }

            remainingCost = calculateRemainingCost(&currentItemSet, instance);

            if (currentCost + remainingCost >= bestCostSoFar) {
                currentWeight = calculateCurrentWeight(&currentItemSet, instance);
                currentPosition = calculatePosition(&currentItemSet);
                for (int i = currentPosition + 1; i < amountOfItems; ++i) {
                    if ((currentWeight + instance->getWeight().at(i)) <= capacity)
                        queue.push(generateNextBit(&currentItemSet, i));
                }
            }
        }
    }
    time = clock()-time;

    instance->setTimeForSolution(((double)time/CLOCKS_PER_SEC)/instance->getMULTIPLIKATOR());
    instance->setTotalCostOfSolution(bestCostSoFar);
    instance->setResultSet(currentBestSolution);
    instance->setTotalWeightOfSolution();
    std::cout << *instance << ::std::endl;
}



void
BranchAndBound::pushBitSetToQ(const int amountOfItems, std::queue<std::vector<bool>> &queue) const {
    std::vector<bool> bitSet;
    for (int i = 0; i < amountOfItems; i++) {
        bitSet.push_back(false);
    }
    queue.push(bitSet);
}


int BranchAndBound::calculateCurrentCost(std::vector<bool> *bitSet, Instance *inst) {
    int cost = 0;
    int index = 0;
    for (auto it = bitSet->begin(); it != bitSet->end(); ++it) {
        if (*it == 1) cost += inst->getCost().at(index);
        ++index;
    }
    return cost;
}

int BranchAndBound::calculateRemainingCost(std::vector<bool> *bitSet, Instance *pInstance) {
    int cost = 0;
    int offset = calculatePosition(bitSet) + 1;
    for (auto it = bitSet->begin() + offset; it != bitSet->end(); ++it) {
        cost += pInstance->getCost().at(offset);
        ++offset;
    }
    return cost;
}

int BranchAndBound::calculatePosition(std::vector<bool> *items) {
    int temp = 0;
    int i = -1;
    for (auto it = items->begin(); it != items->end(); ++it) {
        if (*it == 1)
            i = temp;

        ++temp;
    }
    return i;
}

int BranchAndBound::calculateCurrentWeight(std::vector<bool> *items, Instance *pInstance) {
    int weight = 0;
    int i = 0;
    for (auto it = items->begin(); it != items->end(); ++it) {
        if (*it == 1) weight += pInstance->getWeight().at(i);
        ++i;
    }
    return weight;
}

std::vector<bool> BranchAndBound::generateNextBit(std::vector<bool> *items, int position) {
    std::vector<bool> tmp = *items;
    tmp.at(position) = 1;
    return tmp;
}
void BranchAndBound::clear( std::queue<std::vector<bool>> &q )
{
    std::queue<std::vector<bool>> empty;
    std::swap( q, empty );
}
void BranchAndBound::clear( std::vector<bool> &v )
{
    std::vector<bool> empty;
    std::swap( v, empty );
}