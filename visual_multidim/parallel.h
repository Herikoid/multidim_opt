#pragma once
#include "opt_area.h"
#include "SingletonGenerator.h"
/// \brief Класс параллепипедов 
class parallel :
    public opt_area
{
private:
    /// левые границы
    std::vector<double> limits_left{};
    /// правые границы
    std::vector<double> limits_right{};
public:
 //   parallel(std::vector<double>, std::vector<double>);
    /// \brief Удалить границы
    void clear_limits();
    /// \brief Добавить границу
    void add_limits(double, double);
    /// \brief Получить размерность
    int get_dim();
    /// \brief Получить i-ую границу 
    std::pair<double, double> get_lim(int i);

    /// \brief Сгенерировать случайную точку из равномерного распределения в области
    std::vector<double> get_point();

    bool in_area(std::vector<double>) override;
    std::pair<std::vector<double>, std::vector<bool>> corret_arg(std::vector<double>) override;

    virtual ~parallel() {};
};

/// \brief Пересечение области с чебышёвской окрестностью точки
parallel cross_area(parallel&, std::vector<double>, double);
