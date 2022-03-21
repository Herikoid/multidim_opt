#pragma once
#include "opt_method.h"
/// \brief Метод оптимизации fletcher reeves

class fletcher_reeves :
    public opt_method
{
private:
    /// вектор p
    std::vector<double> p;
    /// решение оптимизационной задачи вдоль направления
    double one_dim_optim(double, double, double, int);
public:
    fletcher_reeves(opt_function&, stop_crit&, opt_area&);
    virtual std::vector<double> calc(std::vector<double>) override;
};

