#include "sincos_f.h"

double sincos_f::calc(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return sin(0.5 * pow(x[0], 2) - 0.25 * pow(x[1], 2) + 3) * cos(2 * x[0] + 1 - exp(x[1]));
}

std::vector<double> sincos_f::grad(std::vector<double> x)
{
    if (x.size() != 2) {
        throw std::invalid_argument("argument must be 2d");
    }
    return std::vector<double> {
        x[0] * cos(2 * x[0] - exp(x[1]) + 1)* cos(0.5 * pow(x[0], 2) - 0.25 * pow(x[1], 2) + 3) -
        2 * sin(2 * x[0] - exp(x[1]) + 1) * sin(0.5 * pow(x[0], 2) - 0.25 * pow(x[1], 2) + 3),
        exp(x[1]) * sin(2 * x[0] - exp(x[1]) + 1) * sin(0.5 * pow(x[0], 2) - 0.25 * pow(x[1], 2) + 3) -
        0.5 * x[1] * exp(x[1]) * cos(2 * x[0] - exp(x[1]) + 1) * cos(0.5 * pow(x[0], 2) - 0.25 * pow(x[1], 2) + 3)
    };
}
