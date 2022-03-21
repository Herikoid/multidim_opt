#include "f_4dim.h"

double f_4dim::calc(std::vector<double> x)
{
    if (x.size() != 4) {
        throw std::invalid_argument("argument must be 4d");
    }
    return pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 3) + pow(x[3], 4);
}

std::vector<double> f_4dim::grad(std::vector<double> x)
{
    if (x.size() != 4) {
        throw std::invalid_argument("argument must be 4d");
    }
    return std::vector<double> {2 * x[0], 2 * x[1], 3 * pow(x[2], 2), 4 * pow(x[3], 3)};
}
