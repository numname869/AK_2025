#pragma once
#include <vector>

double x1 = 1.00E+21;
double x2 = 17.0;
double x3 = -10.0;
double x4 = 130.0;
double x5 = -1.00E+21;
long double exact = 137.0L; 

std::vector<double> x = { x1,x2,x3,x4,x5};
int count = 0;
std::vector<int> idx = { 0, 1, 2, 3, 4 };

struct Result {
    std::vector<double> perm;
    double approx;
    double errorAbs;
};

std::vector<Result> results;