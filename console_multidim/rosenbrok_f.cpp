#include "rosenbrok_f.h"

double rosenbrok_f::calc(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return pow(1 - x[0], 2) + 100 * pow(x[1] - pow(x[0], 2), 2);
}

std::vector<double> rosenbrok_f::grad(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return std::vector<double> { 400 * pow(x[0], 3) - 400 * x[0] * x[1] + 2 * x[0] - 2 , 200 * (x[1] - pow(x[0], 2))};
}
