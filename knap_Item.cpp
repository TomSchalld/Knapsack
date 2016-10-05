//
// Created by Thomas Schalldach on 03/10/2016.
//

#include "knap_Item.h"

knap_Item::knap_Item(int cost, int weight, int id) : cost(cost), weight(weight), id(id) {}

void knap_Item::print() const{
    std::cout << "ID: "<<id<<" Cost: "<<cost<<" Weight: "<<weight<< std::endl;

}

int knap_Item::getCost() const {
    return cost;
}

int knap_Item::getWeight() const {
    return weight;
}

int knap_Item::getId() const {
    return id;
}
