#pragma once
#include "opt_function.h"
/// \brief Функция Розенброка
class rosenbrok_f :
    public opt_function
{
public:
    double calc(std::vector<double>) override;
    std::vector<double> grad(std::vector<double>) override;

    virtual ~rosenbrok_f() {};
};

