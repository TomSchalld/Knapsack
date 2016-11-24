//
// Created by tscha on 06/11/2016.
//


#include "Instance.h"


Instance::Instance(std::vector<int> &instanceAsInt) {
    this->id = instanceAsInt.at(0);
    this->amountOfItems = instanceAsInt.at(1);
    this->capacity = instanceAsInt.at(2);
    this->totalCostOfSolution = 0;
    this->totalWeightOfSolution = 0;
    for (int i = 3; i < instanceAsInt.size(); i++) {
        //w|c
        this->weight.push_back(instanceAsInt.at(i++));
        this->cost.push_back(instanceAsInt.at(i));
    }

}

std::ostream &operator<<(std::ostream &os, const Instance &instance) {
    os << "id: " << instance.id << " totalCostOfSolution: " << instance.totalCostOfSolution
       << " totalWeightOfSolution: " << instance.totalWeightOfSolution << " resultSet: ";
    for (int i = 0; i < instance.resultSet.size(); ++i) {
        os << instance.resultSet.at(i);
    }
    os << " timeForSolution: " << instance.getTimeForSolution();
    return os;
}

int Instance::getId() const {
    return id;
}

int Instance::getAmountOfItems() const {
    return amountOfItems;
}

int Instance::getCapacity() const {
    return capacity;
}

int Instance::getTotalCostOfSolution() const {
    return totalCostOfSolution;
}

int Instance::getTotalWeightOfSolution() const {
    return totalWeightOfSolution;
}

const std::vector<int> &Instance::getCost() const {
    return cost;
}

void Instance::setCost(const std::vector<int> &cost) {
    Instance::cost = cost;
}

const std::vector<int> &Instance::getWeight() const {
    return weight;
}

const std::vector<bool, std::allocator<bool>> &Instance::getResultSet() const {
    return resultSet;
}

void Instance::setTotalCostOfSolution(int totalCostOfSolution) {

    Instance::totalCostOfSolution = totalCostOfSolution;
}

void Instance::setTotalWeightOfSolution() {
    for (int i = 0; i < this->resultSet.size(); i++) {
        if (this->resultSet.at(i)) {
            this->totalWeightOfSolution += this->getWeight().at(i);
        }
    }
}

void Instance::setResultSet(const std::vector<bool, std::allocator<bool>> &resultSet) {
    Instance::resultSet = resultSet;
}

const int Instance::getMULTIPLIKATOR() const {
    return MULTIPLIKATOR;
}

double Instance::getTimeForSolution() const {
    return timeForSolution;
}

void Instance::setTimeForSolution(double timeForSolution) {
    Instance::timeForSolution = timeForSolution;
}

int Instance::getTotalCostOfInstance() {
    int tmp = 0;
    for (int i = 0; i < this->cost.size(); i++) {
        tmp += this->cost.at(i);
    }
    return tmp;
}

int Instance::getTotalWeightOfInstance() {
    int tmp = 0;
    for (int i = 0; i < this->weight.size(); i++) {
        tmp += this->weight.at(i);
    }
    return tmp;

}

const int Instance::getMaxCost() {
    int tmp =0;
    for (int i = 0; i < this->getCost().size(); ++i) {
        if (this->getCost().at(i)>tmp) {
            tmp = this->getCost().at(i);
        }
    }
    return tmp;
}
