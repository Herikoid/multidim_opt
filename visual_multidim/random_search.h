#pragma once
#include "opt_method.h"
#include "parallel.h"
/// \brief Метод оптимизации случайный поиск
class random_search :
    public opt_method
{
private:
    /// стартовый радиус окрестности точки
    double delta;
    /// вероятность выбрать не окрестность точки
    double p;
    /// область определния - праллепипед
    parallel* par = nullptr;
public:
    random_search(opt_function& f, stop_crit& s, parallel& a, double delta = 0.1, double p_ = 0.5);
    virtual std::vector<double> calc(std::vector<double>) override;

    virtual ~random_search();
};

