//
// Created by tscha on 06/11/2016.
//

#ifndef KNAPSACK_INSTANCES_H
#define KNAPSACK_INSTANCES_H


#include <vector>
#include <ostream>
#include "Instance.h"

class Instances {
private:
    int instancePointer;
    std::vector<Instance *> instances;
public:
    virtual ~Instances();

    void addInstance(Instance *instance);

    Instance *getNextInstance();

    friend std::ostream &operator<<(std::ostream &os, const Instances &instances);

    void exportToDesktop();

};


#endif //KNAPSACK_INSTANCES_H
