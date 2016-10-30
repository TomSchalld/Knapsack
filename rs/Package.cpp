//
//  BummPacket.cpp
//  Rucksack
//
//  Created by Thomas Schalldach on 15.12.14.
//  Copyright (c) 2014 Thomas Schalldach. All rights reserved.
//

#include "Package.h"

Package::Package(int packageID, int weight, int cost, int capacity)
{
    int amount = 1;
    this->weight=weight;
    this->value=cost*amount;
    this->cost=cost;
    this->packageID=packageID;
    this->used=false;
    this->capacity = capacity;
}

void Package::setWeight(int val){
    if(val<this->capacity){this->weight = val;}
    else{std::cout<<"To Heavy"<<std::endl;}
};
void Package::setValue(int anzahl, int durchmesser) {
    this->value = anzahl*durchmesser;
};
