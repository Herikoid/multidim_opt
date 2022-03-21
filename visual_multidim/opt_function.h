#pragma once
#include<vector>
#include <iostream>
#include <cmath>
/// \brief Абстрактный класс функций для оптимизации
class opt_function
{
private:
	/// значение функции в точке
	double value;
public:
	/// \brief Вычисление функции в точке
	virtual double calc(std::vector<double>) = 0;
	/// \brief Взятие градиента в точке
	virtual std::vector<double> grad(std::vector<double>) = 0;
	/// Вычисление функции в точке
	double operator()(std::vector<double>);
};

