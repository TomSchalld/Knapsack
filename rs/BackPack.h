//
//  BackPack.h
//  BackPack
//
//  Created by Thomas Schalldach on 15.12.14.
//  Copyright (c) 2014 Thomas Schalldach. All rights reserved.
//

#ifndef __Rucksack__Rucksack__
#define __Rucksack__Rucksack__

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Package.h"

class BackPack{


private:

    std::ifstream file;
    std::vector<int> data;
    std::vector<int> resultSet;
    std::vector<Package*> space;
    std::string dataLine;
    int costSum=0;
    int lines=0;
    int capacity=0;
    int sumWeight=0;
    time_t time;
    int multiplicator;
public:
    void setCostSum(int costSum){this->costSum=costSum;};
    int getCostSum(){return this->costSum;};
    const std::vector<int> &getResultSet() const;
    int getSumWeight() const;
    int getLines(){return this->lines;};
    int pack();
    int sum();
    void print();
    void dataToPackage();
    void setWeightSum(int sumWeight);

    const std::string &getDataLine() const;

    void setDataLine(const std::string &dataLine);

    BackPack(int multiplicator);
    ~BackPack();
    void stringToInt(std::string line);


};
#endif /* defined(__Rucksack__Rucksack__) */
