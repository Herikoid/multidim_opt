#pragma once
#include "opt_function.h"
/// \brief Функция f(x, y, z, t) = x^2 + y^2
class sq_sum :
    public opt_function
{
public:
    double calc(std::vector<double>) override;
    std::vector<double> grad(std::vector<double>) override;

    virtual ~sq_sum() {};
};

