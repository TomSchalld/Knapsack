#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include "rs/BackPack.h"
#include "Knapsack_logic.h"

int main() {

    std::vector<std::string> dataFromFile;
    std::string line;

    file.open("C:\\Users\\tscha\\ClionProjects\\Knapsack\\inst\\knap_40.inst.dat");
    if (file.is_open()) {
        while (getline(file, line)) {
            dataFromFile.push_back(line);
            //std::cout << line << std::endl;
        }
        file.close();

    } else {
        std::cout << "Error while opening" << std::endl;
    }


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