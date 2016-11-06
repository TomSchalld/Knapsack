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

Instance* Instances::getNextInstance() {
    if(instancePointer<this->instances.size())
    return this->instances.at(instancePointer++);
}

std::ostream &operator<<(std::ostream &os, const Instances &instances) {

    for (int i = 0; i <instances.instances.size() ; ++i) {
        os<< instances.instances.at(i);
    }
    return os;
}
