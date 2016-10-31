#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include "rs/BackPack.h"
#include "Knapsack_logic.h"
#include "rs/TreeNode.h"

void readIn(std::vector<std::string> &dataFromFile, std::string &line,
            const std::string &path);

void createNodes(std::vector<int> &instance, std::vector<TreeNode *> &nodes);

void lineToInt(const std::string &line, std::vector<int> &instance);

int main() {


    std::vector<std::string> dataFromFile;
    std::string line;
    std::vector<int> instance;
    std::vector<TreeNode *> nodes;
    std::string path = "C:\\Users\\tscha\\ClionProjects\\Knapsack\\inst\\knap_4.inst.dat";
    readIn(dataFromFile, line, path);
    lineToInt(dataFromFile.at(0), instance);
    createNodes(instance, nodes);
    std::sort(nodes.begin(), nodes.end(), TreeNode::compareRatio);
    nodes.insert(nodes.begin(), new TreeNode());
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << *nodes.at(i) << std::endl;
    }










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

/*    BackPack *r = new BackPack("C:\\Users\\tscha\\ClionProjects\\Knapsack\\rs\\knaller.dat");


    r->pack();
    r->print();


    delete r;

if (isBruteforce){
    bruteForce();
    exportToDesktop();
    printResultSet();
} else{
    greedy();
    exportToDesktop();
    printResultSet();
}

*/
    return 0;
}

void createNodes(std::vector<int> &instance, std::vector<TreeNode *> &nodes) {
    TreeNode *tmp = nullptr;
    for (int i = 3; i < instance.size(); i++) {
        tmp = new TreeNode();
        tmp->setWeight(instance.at(i++));
        tmp->setCost(instance.at(i));
        tmp->setCostWeightRatio((double) (tmp->getCost() / tmp->getWeight()));
        nodes.push_back(tmp);
    }
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