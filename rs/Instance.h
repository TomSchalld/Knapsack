//
// Created by tscha on 06/11/2016.
//

#ifndef KNAPSACK_INSTANCE_H
#define KNAPSACK_INSTANCE_H


#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>

class Instance {
private:
    const int MULTIPLIKATOR = 1;
    int id;
    int amountOfItems;
    int capacity;
    int totalCostOfSolution;
    int totalWeightOfSolution;
    double timeForSolution;
    std::vector<int> cost;
    std::vector<int> weight;
    std::vector<bool> resultSet;
public:
    friend std::ostream &operator<<(std::ostream &os, const Instance &instance);

    Instance(std::vector<int> &instanceAsInt);

    const int getMULTIPLIKATOR() const;

    void setTotalCostOfSolution(int totalCostOfSolution);

    void setTotalWeightOfSolution();

    void setResultSet(const std::vector<bool, std::allocator<bool>> &resultSet);

    int getId() const;

    int getAmountOfItems() const;

    int getCapacity() const;

    int getTotalCostOfSolution() const;

    int getTotalWeightOfSolution() const;

    const std::vector<int> &getCost() const;

    const std::vector<int> &getWeight() const;

    const std::vector<bool, std::allocator<bool>> &getResultSet() const;

    double getTimeForSolution() const;

    void setTimeForSolution(double timeForSolution);

    int getTotalCostOfInstance();
    int getTotalWeightOfInstance();

    const int getMaxCost();

    void setCost(const std::vector<int> &cost);
};


#endif //KNAPSACK_INSTANCE_H
