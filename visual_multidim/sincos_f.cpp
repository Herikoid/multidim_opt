#include "sincos_f.h"

double sincos_f::calc(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return sin(x[0]) * cos(x[1]);
}

std::vector<double> sincos_f::grad(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return std::vector<double> {
        cos(x[0]) * cos(x[1]), - sin(x[0]) * sin(x[1])
    };
}
