#pragma once
#include "stop_crit.h"
/// \brief Критерий остановки вида |x_i - x_{i - 1}| < eps
class x_crit :
    public stop_crit
{
public:
    bool check(sup_struct&) override;

    virtual ~x_crit() {};
};

