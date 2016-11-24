//
// Created by tscha on 06/11/2016.
//

#ifndef KNAPSACK_DATAIMPORT_H
#define KNAPSACK_DATAIMPORT_H


#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include "Instance.h"
#include "Instances.h"

class DataImport {

private:

    std::vector<std::string> dataFromFile;
    std::string line;
    std::vector<int> instance;
    const std::string path = "C:\\Users\\tscha\\ClionProjects\\Knapsack\\inst\\knap_4.inst.dat";

public:
    void readIn();

    void lineToInt(const std::string &line, std::vector<int> &instance);

    Instances * createInstances();
    Instance * createInstance(std::vector<int> &instance);


};


#endif //KNAPSACK_DATAIMPORT_H
