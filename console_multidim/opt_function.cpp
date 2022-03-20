#include "opt_function.h"

double opt_function::operator()(std::vector<double> x)
{
    return calc(x);
}
