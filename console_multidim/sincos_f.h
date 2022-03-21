#pragma once
#include "opt_function.h"
/// \brief Функция f(x, y) = sin(0.5 * x^2 - 0.25 * y^2 + 3) * cos(2 * x + 1 - e^y)
class sincos_f :
    public opt_function
{
public:
    double calc(std::vector<double>) override;
    std::vector<double> grad(std::vector<double>) override;
};

