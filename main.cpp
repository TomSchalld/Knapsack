#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include "rs/BackPack.h"
#include "Knapsack_logic.h"
#include "rs/BranchAndBound.h"
#include "rs/KnapsackCostDecomposition.h"

void readIn(std::vector<std::string> &dataFromFile, std::string &line,
            const std::string &path);

void lineToInt(const std::string &line, std::vector<int> &instance);


int main() {
    DataImport import;
    import.readIn();
    KnapsackCostDecomposition sack(import.createInstances());
    sack.doInstance();

   /* BranchAndBound bab;
    bab.solvePrintAndExportToDesktop();*/


    /*std::vector<std::string> dataFromFile;
    std::string line;
    std::vector<int> instance;
    std::string path = "C:\\Users\\tscha\\ClionProjects\\Knapsack\\inst\\knap_10.inst.dat";
    readIn(dataFromFile, line, path);
    lineToInt(dataFromFile.at(0), instance);*/

/*
    BackPack *b;
    for (int i = 0; i < 50; i++) {
        b = new BackPack(100);
        b->stringToInt(dataFromFile.at(i));
        try {
            b->pack();
        }catch (const std::out_of_range& oor){
           std::cerr<<oor.what()<<std::endl;
        }

        b->print();
        delete b;
    }
*/

    return 0;
}

void readIn(std::vector<std::string> &dataFromFile, std::string &line,
            const std::string &path) {
    file.open(path);
    if (file.is_open()) {
        while (getline(file, line)) {
            dataFromFile.push_back(line);
//std::cout << line << std::endl;
        }
        file.close();

    } else {
        std::cout << "Error while opening" << std::endl;
    }


}

void lineToInt(const std::string &line, std::vector<int> &instance) {
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
        instance.push_back((stoi(*it)));
    }
}