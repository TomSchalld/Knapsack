/*
 * instance | n | M | w1 | c1 | w2 | c2 | ...
 * argv[1] file to parse
 * argv[2] file to output
 * argv[3] iterations for every instance (if set to 1, solutions are shown)
 * g++ -Wall -std=c++11 knapsackbrute.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
int M = 0;
int n = 0;
int number = 0;
int s_index = 0;
int best = 0;
double elapsed_t=0;
int iterations=0;
int debug=0;
//parsing tool
int getnextval(std::string line){
    int s_index_old=s_index;
    s_index=line.find(" ",s_index_old+1);
    return std::stoi(line.substr(s_index_old,s_index));
}

//evaluate the current knapsack
int eval(int costs[], int weights[], int bin_rep[]) {
    int totW = 0;
    int totV = 0;
    for(int i=0;i<n;i++){
        if(debug==1) std::cout<<bin_rep[i];
        totW+=weights[i]*bin_rep[i];
        totV+=costs[i]*bin_rep[i];
    }
    if(debug==1) std::cout<<"\n";
    if(totW<=M){
        //accepted
        if(totV>best) best = totV;
        return totV;
    } else {
        //broken
        return -1;
    }
}

int upperbound(int index, int costs[], int bin_rep[]){
    int ub=0;
    for(int i=0;i<n;i++){
        if(i<=index){//items in the sack 
            ub+=costs[i]*bin_rep[i];
        } else {//potential items
            ub+=costs[i];
        }
    }
    return ub;
}

//recursive function
void recurse(int index, int costs[], int weights[], int bin_rep[]) {
    while(index<n){
        bin_rep[index]=1;
        //evaluate before recursing 
        int val = eval(costs, weights, bin_rep);
        //recursive call
        if(index+1<n 
            && upperbound(index, costs, bin_rep)>best 
            && val>=0) 
        {
            recurse(index+1, costs, weights, bin_rep);
        }
        bin_rep[index]=0;
        index++;
    }
}

void display_results(std::ofstream& ofile){
    ofile<<number<<' '<<elapsed_t<<' '<<iterations<<'\n';
    std::cout<<"================================"
        "\ninstance: "<<number<<
        "\nbest cost: "<<best<<
        "\ntime: "<<elapsed_t/iterations<<"s, "<<
        "\n================================\n";

}

int main(int argc, char* argv[]) {
    std::ifstream file (argv[1]);
    std::ofstream ofile (argv[2]);
    std::string line;

    //iterate for each instance
    while(getline(file,line)){
        best=0;
        //parse a line
        s_index=0;
        number=getnextval(line);
        n=getnextval(line);
        M=getnextval(line);
        int weights[n];
        int costs[n];
        for (int i=0;i<n;i++) {
            weights[i]=getnextval(line);
            costs[i]=getnextval(line);
        }
        //initiate binary representation
        int bin_rep[n];
        for (int i=0;i<n;i++) {
            bin_rep[i]=0;
        }
        //start time
        std::clock_t begin = clock();
        iterations=std::stoi(argv[3]);
        debug = std::stoi(argv[4]);
        for(int i=0;i<iterations;i++) {
	    //recursive call
            recurse(0, costs, weights, bin_rep);
        }
        std::clock_t end = clock();
        elapsed_t=double(end - begin) / CLOCKS_PER_SEC;
        // stop time
        display_results(ofile);
    }
    file.close();
    ofile.close();
}
