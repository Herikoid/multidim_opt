#pragma once
#include<vector>
#include<iostream>
/// \brief Абстрактный класс с областью определения функции
class opt_area
{
public:
	/// \brief Проверка, лежит ли точка в области
	virtual bool in_area(std::vector<double>) = 0;
	/// \brief Корректировка координат точки, если она выходит за границы области
	virtual std::pair<std::vector<double>, std::vector<bool>> corret_arg(std::vector<double>) = 0;

    virtual ~opt_area() {};
};

