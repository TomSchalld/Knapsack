//
// Created by Thomas Schalldach on 03/10/2016.
//

#ifndef KNAPSACK_KNAP_ITEM_H
#define KNAPSACK_KNAP_ITEM_H

#include <iostream>

class knap_Item {
    int cost;
    int weight;
    int id;
public:
    knap_Item(int cost, int weight, int id);
    void print() const;

    int getCost() const;

    int getWeight() const;

    int getId() const;
};


#endif //KNAPSACK_KNAP_ITEM_H
