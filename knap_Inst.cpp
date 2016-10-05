//
// Created by Thomas Schalldach on 03/10/2016.
//


#include "knap_Inst.h"

knap_Inst::knap_Inst(int ID, int numberOfItems, int capacity) : ID(ID), numberOfItems(numberOfItems),
                                                                capacity(capacity) {
    //this->items = new std::vector<knap_Item>();

}

knap_Inst::~knap_Inst() {
    //this->print();
    //std::cout << "destructor knap inst"<< std::endl;
    this->items.erase(this->items.cbegin(), this->items.cend());
    //std::cout << "destructor knap inst ended"<< std::endl;

}

void knap_Inst::dataToInstance(std::vector<std::string> &data) {
    int id = 0;
    for (int i = 3; i < data.size() - 1; i += 2) {
        this->items.push_back(*(new knap_Item(std::stoi(data.at(i + 1)), std::stoi(data.at(i)), id++)));
    }

}


void knap_Inst::print() const {
    std::cout << "ID: " << ID << " NumberOfItems: " << numberOfItems << " Capacity: " << capacity << std::endl;

    for (auto it = this->items.cbegin(); it != this->items.cend(); ++it) {
        it->print();
    }
}



void knap_Inst::bruteForce() const{   // C   W
    int sets[15][6]{{0, -1, -1, -1, -1, -1},
                    {1, -1, -1, -1, -1, -1},
                    {2, -1, -1, -1, -1, -1},
                    {3, -1, -1, -1, -1, -1},
                    {0, 1,  -1, -1, -1, -1},
                    {0, 2,  -1, -1, -1, -1},
                    {0, 3,  -1, -1, -1, -1},
                    {1, 2,  -1, -1, -1, -1},
                    {1, 3,  -1, -1, -1, -1},
                    {2, 3,  -1, -1, -1, -1},
                    {0, 1,  2,  -1, -1, -1},
                    {0, 1,  3,  -1, -1, -1},
                    {0, 2,  3,  -1, -1, -1},
                    {1, 2,  3,  -1, -1, -1},
                    {0, 1,  2,  3,  -1, -1}};
    weightCostValues best;
    weightCostValues temp;
    int lineResult;
    int resultArray[4];
    best.totalWeight=0;
    best.totalCost=0;

    for (int i = 0; i < 15; i++) {
        temp.totalCost=0;
        temp.totalWeight=0;
        for (int j = 0; j < 6; j++) {
            if (j < 4) {
                temp.totalCost+=items[j].getCost();
                temp.totalWeight+=items[j].getWeight();
                if(sets[i][j+1]==-1){
                    sets[i][4]=temp.totalCost;
                    sets[i][5]=temp.totalWeight;
                    if(temp.totalWeight<capacity){
                        if(best.totalCost<temp.totalCost){
                            best.totalCost=temp.totalCost;
                            best.totalWeight=temp.totalWeight;
                            lineResult=i;
                        }
                    }
                    break;
                }
            }
        }
    }

    bestCombination result;
    for(int i=0; i<4;i++){
        resultArray[i]=sets[lineResult][i];
    }
    result.best=best;
    result.combination=resultArray;
    this->setResult(result);
    this->printResult();

}

void knap_Inst::printResult() {
    std::cout << "Result: "<<std::ends;
    for(int i =0; i<4 ; i++){
        std::cout << result.combination[i]<< " " << std::ends;
    }
    std::cout<<"Cost: " <<result.best.totalCost <<" Weight: "<<result.best.totalWeight << std::endl;
}

void knap_Inst::setResult(const knap_Inst::bestCombination &result) {
    knap_Inst::result = result;
}
