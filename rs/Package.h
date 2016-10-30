//
//  BummPacket.h
//  Rucksack
//
//  Created by Thomas Schalldach on 15.12.14.
//  Copyright (c) 2014 Thomas Schalldach. All rights reserved.
//

#ifndef __Rucksack__BummPacket__
#define __Rucksack__BummPacket__

#include <stdio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>


class Package{

public:
    Package(int packageID, int weight, int cost, int capacity);
    int getWeight() { return weight; }
    void setWeight(int val);
    int getWert() { return value; }
    void setValue(int anzahl, int durchmesser);
    int getCost(){return this->cost;};
    bool isUsed(){return this->used;};
    void isUsed(bool isUsed){ this->used=isUsed;};
    int getID(){return this->packageID;};
private:
    int cost;
    int weight;
    int value;
    int packageID;
    bool used;
    int capacity;
};

#endif /* defined(__Rucksack__BummPacket__) */
