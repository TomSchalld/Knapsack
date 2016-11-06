//
// Created by tscha on 06/11/2016.
//

#include "DataImport.h"

void DataImport::readIn() {
    static std::ifstream file;
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

void DataImport::lineToInt(const std::string &line, std::vector<int> &instance) {
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
        instance.push_back((stoi(*it)));
    }
}


Instances * DataImport::createInstances() {
    auto instances = new Instances();
    std::string line="";
    for (int i = 0; i < dataFromFile.size() ; ++i) {
        line = dataFromFile.at(i);
        std::istringstream iss(line);
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>{}};
        std::vector<int> instanceLine;
        for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
            instanceLine.push_back((stoi(*it)));
        }
        instances->addInstance(createInstance(instanceLine));
    }
    return instances;
}

Instance * DataImport::createInstance(std::vector<int> &instance) {
    return new Instance(instance);
}
