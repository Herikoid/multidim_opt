#include "sq_sum.h"

double sq_sum::calc(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return pow(x[0], 2) + pow(x[1], 2);
}

std::vector<double> sq_sum::grad(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return std::vector<double> {2 * x[0], 2 * x[1]};
}
