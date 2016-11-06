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
    int id;
    int amountOfItems;
    int capacity;
    int totalCostOfSolution;
    int totalWeightOfSolution;
    std::vector<int> cost;
    std::vector<int> weight;
    std::vector<bool> resultSet;
public:
    friend std::ostream &operator<<(std::ostream &os, const Instance &instance);

    Instance(std::vector<int> &instanceAsInt);


    void setTotalCostOfSolution(int totalCostOfSolution);

    void setTotalWeightOfSolution(int totalWeightOfSolution);

    void setResultSet(const std::vector<bool, std::allocator<bool>> &resultSet);

    int getId() const;

    int getAmountOfItems() const;

    int getCapacity() const;

    int getTotalCostOfSolution() const;

    int getTotalWeightOfSolution() const;

    const std::vector<int> &getCost() const;

    const std::vector<int> &getWeight() const;

    const std::vector<bool, std::allocator<bool>> &getResultSet() const;
};


#endif //KNAPSACK_INSTANCE_H
