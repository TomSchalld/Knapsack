//
// Created by tscha on 13/11/2016.
//

#include <ctime>
#include "KnapsackCostDecomposition.h"

int KnapsackCostDecomposition::pack(Instance *instance) {

    int rowsOFCost = instance->getTotalCostOfInstance();
    int mass = instance->getCapacity();
    int amountOfElements = instance->getAmountOfItems();
    int table[amountOfElements + 1][rowsOFCost + 1];
    std::vector<bool> resultset(amountOfElements);
    //std::cout << resultset.size() << std::endl;
    time_t time = clock();



    for (int i = 0; i <= amountOfElements; i++) {
        for (int j = 0; j <= rowsOFCost; j++) {
            if (i == 0 && j == 0) {
                table[i][j] = 0;
            } else if (i == 0 && j > 0) {
                table[i][j] = 1 << 30;
            } else if (instance->getCost().at(i - 1) <= j) {
                /*std::cout << "I: " << i << " J:" << j << " cost: " << instance->getCost().at(i - 1) << " totalcost:"
                          << rowsOFCost << std::endl;
                std::cout << "instance->getWeight().at(i)" << instance->getWeight().at(i - 1) << std::endl;
                std::cout << "table[i - 1][j - instance->getCost().at(i)]"
                          << table[i - 1][j - instance->getCost().at(i - 1)] << std::endl;
                std::cout << "table[i - 1][j]" << table[i - 1][j] << std::endl;*/
                table[i][j] = std::min(
                        instance->getWeight().at(i - 1) + table[i - 1][j - instance->getCost().at(i - 1)],
                        table[i - 1][j]);
            } else {
                table[i][j] = table[i - 1][j];
            }

        }

    }

    int lineIndex = amountOfElements;
    int totalCost = 0;
    int exitPoint = 0;
    for (int k = rowsOFCost; k >= 0; --k) {
        if (table[lineIndex][k] <= mass) {
            exitPoint = k;
            break;
        }
    }
    //totalCost = instance->getCost().at(exitPoint);


    /*//retrieve resultset from table
    int deltaCost = rowsOFCost;
    for (int i = amountOfElements; i >= 0; i--) {
        if (table[i][deltaCost] > table[i - 1][deltaCost]) {

            resultset.push_back(true);
            deltaCost = deltaCost - instance->getCost().at(i - 1);
        } else {
            resultset.push_back(false);
        }

    }*/

    //}
    time = clock() - time;
    instance->setTotalCostOfSolution(exitPoint);
    instance->setTimeForSolution(((double) time) / CLOCKS_PER_SEC / instance->getMULTIPLIKATOR());
    instance->setResultSet(resultset);
    std::cout << *instance << std::endl;
    //this->setCostSum(table[amountOfElements][rowsOFCost]);
    return exitPoint;//able[amountOfElements][rowsOFCost];


}
double KnapsackCostDecomposition::packFptas(Instance *instance) {




/*
    def fptas(eps, arr, max_weight):
    global sol
    n = len(arr)
    process_arr = arr[:]
    max_item = max(list(el.cost for el in process_arr))
# print(eps, max_item, len(arr))
    k = (eps * max_item) / len(arr)
# print("k=", k)
    for i in range(len(arr)):
# print(process_arr[i].cost)
    process_arr[i].cost //= k
    process_arr[i].cost = int(process_arr[i].cost)
# print(process_arr[i].cost)
    total_cost = sum(el.cost for el in process_arr)
    sol = [[-1 for x in range(total_cost + 1)] for y in range(n + 1)]
    dp_ans = dpKNAP_Cost(process_arr, total_cost, max_weight)
    return dp_ans[0] * k
    */
    double tmp=0;
    int totalCost = instance->getTotalCostOfInstance();
    double eps = this->getEps();
    int maxCost = instance->getMaxCost();
    std::vector<int> newCost;
    double k = (eps * maxCost)/instance->getAmountOfItems();
    std::cout<<"K: "<<k<<std::endl;
    for (int l = 0; l < instance->getCost().size(); ++l) {
        tmp = instance->getCost().at(l) / k;
        newCost.push_back(tmp);
    }
    instance->setCost(newCost);
    return (this->pack(instance)*k);
}








KnapsackCostDecomposition::KnapsackCostDecomposition(Instances *instances) : instances(instances) {}

void KnapsackCostDecomposition::doInstance() {
    std::cout<<"finalResult:"<<this->packFptas(instances->getNextInstance())<<std::endl;
    //this->pack(instances->getNextInstance());
}

void KnapsackCostDecomposition::setInstances(Instances *instances) {
    KnapsackCostDecomposition::instances = instances;
}

double KnapsackCostDecomposition::getEps() const {
    return eps;
}

void KnapsackCostDecomposition::setEps(double eps) {
    KnapsackCostDecomposition::eps = eps;
}
