#include <iostream>
#include <string>
#include "calculation.h"
#include "processing.h"

using std::cout;
using std::vector;

int main (int argc, char* argv[]){
    if (argc != 3){
        cout << "Follow format: ./main [stock1].csv [stock2].csv\n";
        return -1;
    }
    else{
        vector<double> adj_return1 = adj_ret(argv[1]);
        vector<double> adj_return2 = adj_ret(argv[2]);

        if (adj_return1.size() != adj_return2.size()){
            cout << "Data of unequal size. Exiting...\n";
            return -1;
        }

    }
}