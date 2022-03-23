#include "exp_f.h"

double exp_f::calc(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return exp(- x[0] - x[1]) + x[0] + x[1];
}

std::vector<double> exp_f::grad(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return std::vector<double> {-exp(- x[0]  - x[1]) + 1, -exp(- x[0]  - x[1]) + 1};
}

