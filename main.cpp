#include <iostream>
#include <fstream>
#include <sstream>
#include "knap_Inst.h"
#include "ops.h"

int main() {

    ops *o = new ops();
    o->readInFile();
    std::cout << "Read in completed \n\n\n\n" << std::endl;
    o->print();
    delete(o);
    return 0;
}