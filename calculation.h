#ifndef CALCULATION_H
#define CALCULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::sort;
using std::pow;
using std::length_error;

//calculate sum
double sum(const vector<double>& vec){
    double total = 0;
    for (auto i : vec) 
        total += i;
    return total;
}

//calculate mean
double mean(const vector<double>& vec){
    return sum(vec) / vec.size();
}

//calculate median
double median (const vector<double>& vec){
    int n = vec.size();
    
    //copy vector list to not change original
    vector<double> new_vec = vec;
    //sort the list to find median
    sort(new_vec.begin(), new_vec.end());

    //if the vector list size is even, then returns
    //the average between the middle two numbers
    if(new_vec.size() % 2 == 0)
        return (new_vec[n/2-1] + new_vec[n/2]) / 2;
    return new_vec[n/2];
}

double square_sum(const vector<double>& vec){
    double s = 0;
    for (auto i : vec)
        s += pow(i, 2);
    return s;
}

double standard_dev(const vector<double>& vec){
    double n = vec.size();
    double numerator = n * square_sum(vec) - pow(sum(vec), 2);
    double denominator = n * (n-1);
    return pow(numerator/denominator, 0.5);
}
vector <double> operator-(const vector<double>& h1_data, double b){
    vector<double> ret_vec;
    for (auto i : h1_data){
        ret_vec.push_back(i - b);
    }
    return ret_vec;

}
vector<double> operator *(const vector<double>& h1_data, vector<double>& h2_data){
    if (h1_data.size() != h2_data.size()){
        throw length_error("Data sizes are not equal length.");
        exit(1);
    }
    size_t i = 0;
    size_t j = 0;
    vector<double> result;
    
    while (i < h1_data.size() && j < h2_data.size()){
        result.push_back(h1_data[i] * h2_data[i]);
        i++;
        j++;
    }
    return result;
}

double pearson_correlation(const vector<double>& h1_data, const vector<double>& h2_data){
    if (h1_data.size() != h2_data.size()){
        throw length_error("Data sizes are not equal length.");
        exit(1);
    }
    double n = h1_data.size();
    double numerator = (n * (sum(h1_data) * sum(h2_data)) - sum(h1_data) * sum(h2_data));
    double denominator = (n * (n-1) * standard_dev(h1_data) * standard_dev(h2_data));
    return numerator / denominator;
}


#endif