//
// Created by tscha on 13/11/2016.
//

#ifndef KNAPSACK_KNAPSACKCOSTDECOMPOSITION_H
#define KNAPSACK_KNAPSACKCOSTDECOMPOSITION_H


#include "Instances.h"

class KnapsackCostDecomposition {

Instances * instances;
double eps = 0.01;
public:
    double getEps() const;

    void setEps(double eps);

public:
    KnapsackCostDecomposition(Instances *instances);

    void setInstances(Instances *instances);

    void doInstance();
    int pack(Instance * instance);

    double packFptas(Instance *instance);
};


#endif //KNAPSACK_KNAPSACKCOSTDECOMPOSITION_H
