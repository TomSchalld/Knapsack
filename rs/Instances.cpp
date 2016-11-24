//
// Created by tscha on 06/11/2016.
//

#include "Instances.h"

Instances::~Instances() {
//   delete this->instances;
}

void Instances::addInstance(Instance *instance) {
    this->instances.push_back(instance);
}

Instance *Instances::getNextInstance() {
    if (instancePointer < this->instances.size())
        return this->instances.at(instancePointer++);
}

std::ostream &operator<<(std::ostream &os, const Instances &instances) {

    for (int i = 0; i < instances.instances.size(); ++i) {
        os << instances.instances.at(i);
    }
    return os;
}

void Instances::exportToDesktop() {
    std::string path;
    std::string home;
    std::string version = "bANDb";
    const int n = this->instances.at(0)->getAmountOfItems();
#ifdef _WIN32
    home = getenv("HOMEPATH");
#else
    home= getenv("HOME");
#endif
    /* if(isBruteforce){
         version = "Brute";
     }else{
         version = "Greedy";
     }*/
    path = home + "/Desktop/result_" + std::to_string(n) + version + ".csv";
    std::ofstream results;
    results.open(path);
    for (auto it = this->instances.cbegin(); it != this->instances.cend(); ++it) {
        results << "Instance ID," << (*it)->getId() << ",Total Wieght," << (*it)->getTotalWeightOfSolution()
                << ",Total Cost," << (*it)->getTotalCostOfSolution()
                << ",BitSet,'";
        for (int i = 0; i < n; i++) {
            results << (*it)->getResultSet().at(i);
        }
        results << "' ,Computational Time in seconds," << (*it)->getTimeForSolution() << "\n";
    }
    results.close();
}