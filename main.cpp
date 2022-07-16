#include <iostream>
#include <string>
#include <iomanip>
#include "calculation.h"
#include "processing.h"

using std::cout;
using std::vector;
using std::setprecision;

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
        //Mean, median, standard deviation of first stock adjusted return
        double mean_return1 = mean(adj_return1);
        double median_return1 = median(adj_return1);
        double standard_dev1 = standard_dev(adj_return1);

        //Mean, median, standard deviation of second stock adjusted return
        double mean_return2 = mean(adj_return2);
        double median_return2 = median(adj_return2);
        double standard_dev2 = standard_dev(adj_return2);

        //Need to complete: output the mean, median, standard deviation of each stock
        cout << "Stock" << "    " << "Mean" << "    " << "Median" << "    " << "Standard Deviation\n";
        cout << "=====" << "    " << "====" << "    " << "======" << "    " << "==================\n";
        cout << argv[1] << "    " << mean_return1 << "    " << median_return1 << "    " << standard_dev1 << "\n";
        cout << argv[2] << "    " << mean_return2 << "    " << median_return2 << "    " << standard_dev2 << "\n";
        
        //Need to complete calculation of Pearson correlation coefficient of two stocks
        vector<double> log_ret1 = log_ret(adj_return1);
        vector<double> log_ret2 = log_ret(adj_return2);
        double pears_corr = pearson_correlation(log_ret1, log_ret2);  
        cout << "The Pearson Correlation Cofficient of " << argv[1] << " and "
        << argv[2] << " is: " << setprecision(6) << pears_corr << "\n";
    }
    return 0;
}