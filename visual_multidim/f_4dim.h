#pragma once
#include "opt_function.h"

/// \brief Функция f(x, y, z, t) = x^2 + y^2 + z^3 + t^4

class f_4dim :
    public opt_function
{
public:
    double calc(std::vector<double>) override;
    std::vector<double> grad(std::vector<double>) override;

    virtual ~f_4dim() {};
};

