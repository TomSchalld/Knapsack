//
// Created by Thomas Schalldach on 03/10/2016.
//

#include <iostream>
#include "ops.h"

void ops::readInFile() {
    std::string line;

    file.open (this->path);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            this->convertLineToInstance(line);
           // std::cout << line << std::endl;
        }
        file.close();
    } else{
        std::cout << "Error while opening" << std::endl;
    }
}

void ops::convertLineToInstance(std::string &line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    knap_Inst *instance = new knap_Inst(std::stoi(tokens.at(0)),std::stoi(tokens.at(1)),std::stoi(tokens.at(2)));
    instance->dataToInstance(tokens);
    this->instances.push_back(*instance);
}

ops::ops() {
    //this->instances = new std::vector<knap_Inst>();
}

ops::~ops() {
   // std::cout << "destructor ops"<< std::endl;
    this->instances.erase(this->instances.cbegin(), this->instances.cend());
   // std::cout << "destructor ops ended"<< std::endl;

}

void  ops::print() {
    for (auto it = this->instances.cbegin(); it != this->instances.cend(); ++it) {
        it->print();
    }
}

void ops::bruteForce() {
    for (auto it = this->instances.cbegin(); it != this->instances.cend(); ++it) {
        it->bruteForce();
    }
}
