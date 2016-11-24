//
// Created by tscha on 13/11/2016.
//

#include <ctime>
#include "KnapsackCostDecomposition.h"
int KnapsackCostDecomposition::pack(Instance * instance) {

    const int rowsOFCost = instance->getTotalCostOfInstance();
    const int mass = instance->getCapacity();
    const int amountOfElements = instance->getAmountOfItems();
    int table[amountOfElements + 1][rowsOFCost + 1];
    std::vector<bool> resultset(amountOfElements);
    time_t time = clock();

    //for (int k = 0; k < instance->getMULTIPLIKATOR(); ++k) {


        for (int i = 0; i <= amountOfElements; i++) {
            for (int j = 0; j <= rowsOFCost; j++) {
                if (i == 0 || j == 0) {
                    table[i][j] = 0;
                } else if (instance->getCost().at(i - 1) <= j) {
                    table[i][j] = std::max(
                            instance->getWeight().at(i - 1) + table[i - 1][j - instance->getCost().at(i - 1)],
                            table[i - 1][j]);
                } else {
                    table[i][j] = table[i - 1][j];
                }

            }

        }
        //retrieve resultset from table
        int deltaCost = rowsOFCost;
        for (int i = amountOfElements; i >= 0; i--) {
            if (table[i][deltaCost] > table[i - 1][deltaCost]) {

                resultset.push_back(true);
                deltaCost = deltaCost - instance->getCost().at(i - 1);
            } else {
                resultset.push_back(false);
            }

        }

    //}
    time = clock() - time;
    instance->setTotalCostOfSolution(deltaCost);
    instance->setTimeForSolution(((double)time)/CLOCKS_PER_SEC/instance->getMULTIPLIKATOR());
    instance->setResultSet(resultset);
    std::cout<<*instance<<std::endl;
    //this->setCostSum(table[amountOfElements][rowsOFCost]);
    return table[amountOfElements][rowsOFCost];


}

KnapsackCostDecomposition::KnapsackCostDecomposition(Instances *instances) : instances(instances) {}

void KnapsackCostDecomposition::doInstance() {
    this->pack(instances->getNextInstance());
}

void KnapsackCostDecomposition::setInstances(Instances *instances) {
    KnapsackCostDecomposition::instances = instances;
}
