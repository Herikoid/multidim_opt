#include "f_3dim.h"

double f_3dim::calc(std::vector<double> x)
{
    if (x.size() != 3) {
        throw std::invalid_argument("argument must be 3d");
    }
    return pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 3);
}

std::vector<double> f_3dim::grad(std::vector<double> x)
{
    if (x.size() != 3) {
        throw std::invalid_argument("argument must be 3d");
    }
    return std::vector<double> {2 * x[0], 2 * x[1], 3 * pow(x[2], 2)};
}
