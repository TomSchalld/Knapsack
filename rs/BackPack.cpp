#include <sstream>
#include <iterator>
#include <bitset>
#include <ctime>
#include "BackPack.h"


void BackPack::stringToInt(std::string line){
    std::string instance = line;
    std::istringstream iss(instance);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};
    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
        this->data.push_back((std::stoi(*it)));
    }
    this->capacity = data.at(2);
    this->lines = data.at(1);
}
void BackPack::dataToPackage() {

   while(!this->space.empty()){
       this->space.pop_back();
   }
    for (int i = 3, j = 0; i < this->data.size(); i += 2) {
        this->space.push_back(new Package(j++, this->data.at(i), this->data.at(i + 1), this->capacity));
    }
}

BackPack::BackPack(int multiplicator) {
    this->multiplicator = multiplicator;

}

int BackPack::pack() {

    int lines = this->lines;
    int mass = this->capacity;
    int table[lines + 1][mass + 1];
    time = clock();

    for (int k = 0; k < this->multiplicator; ++k) {
        dataToPackage();

        for (int i = 0; i <= lines; i++) {
            for (int j = 0; j <= mass; j++) {
                if (i == 0 || j == 0) {
                    table[i][j] = 0;
                } else if (this->space.at(i - 1)->getWeight() <= j) {
                    table[i][j] = std::max(
                            this->space.at(i - 1)->getCost() + table[i - 1][j - this->space.at(i - 1)->getWeight()],
                            table[i - 1][j]);
                } else {
                    table[i][j] = table[i - 1][j];
                }

            }

        }
        int deltaMass = mass;
        for (int i = lines; i >= 0; i--) {
            if (table[i][deltaMass] > table[i - 1][deltaMass]) {
                this->space.at(i - 1)->isUsed(true);
                deltaMass = deltaMass - this->space.at(i - 1)->getWeight();

            }

        }

    }
    time = clock() - time;
    this->setCostSum(table[lines][mass]);
    return table[lines][mass];


}

int BackPack::sum() {
    int summe = 0;
    for (int i = 0; i < this->space.size(); i++) {
        summe += this->space.at(i)->getWert();
    }
    return summe;
}

void BackPack::print() {

    int sumCost = 0;
    int sumWeight = 0;
    for (int i = 0; i < this->space.size(); i++) {
        this->resultSet.push_back(0);
        if (this->space.at(i)->isUsed()) {
            //std::cout << this->space.at(i)->getID() << " .PackageID" << std::endl;
            this->resultSet.at(i) = 1;
            sumCost += this->space.at(i)->getCost();
            sumWeight += this->space.at(i)->getWeight();
        }
    }
    this->setCostSum(sumCost);
    this->setWeightSum(sumWeight);
    std::cout << "_________________________________" << std::endl;
    std::cout << this->getCostSum() << " .Cost Sum" << std::endl;
    std::cout << this->getSumWeight() << " .Cost Sum" << std::endl;
    std::cout << "Bitset: ";
    for (int i = 0; i < this->getResultSet().size(); i++) {
        std::cout << this->getResultSet().at(i);
    }
    std::cout << std::endl;
    std::cout << "Computational time: " << ((double) time / CLOCKS_PER_SEC)/this->multiplicator << std::endl;
}


BackPack::~BackPack() {
    this->space.clear();
}

void BackPack::setWeightSum(int sumWeight) {
    this->sumWeight = sumWeight;
}

int BackPack::getSumWeight() const {
    return sumWeight;
}

const std::vector<int> &BackPack::getResultSet() const {
    return resultSet;
}

const std::string &BackPack::getDataLine() const {
    return dataLine;
}

void BackPack::setDataLine(const std::string &dataLine) {
    BackPack::dataLine = dataLine;
}
