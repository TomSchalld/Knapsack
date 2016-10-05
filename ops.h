//
// Created by Thomas Schalldach on 03/10/2016.
//

#ifndef KNAPSACK_OPS_H
#define KNAPSACK_OPS_H


#include <string>
#include <fstream>
#include "knap_Inst.h"

class ops {
    const std::string path = "/Users/Thomas/ClionProjects/Knapsack/inst/knap_4.inst.dat";
    std::ifstream file;
    std::vector<knap_Inst> instances;

public:
    void readInFile();
    void convertLineToInstance(std::string &line);
    ops();
    void print();
    void bruteForce() ;
    virtual ~ops();
};


#endif //KNAPSACK_OPS_H
