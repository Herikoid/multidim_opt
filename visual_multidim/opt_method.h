#pragma once
#include <iostream>
#include <vector>
#include "vector_operations.h"
#include "opt_function.h"
#include "stop_crit.h"
#include "opt_area.h"
/// \brief Абстрактный класс методов оптимизации
class opt_method
{
protected:
	/// хначения x на протяжении работы алгоритма
	std::vector<std::vector<double>> x;
	/// текущее число итераций алгоритма
	long int iter = 0;

	/// функция для оптимизации
	opt_function *func = nullptr;
	/// критерий остановки
	stop_crit* stop = nullptr;
	/// область определения
	opt_area* area = nullptr;
public:
    virtual ~opt_method();

	/// \brief Получить x
	std::vector<std::vector<double>> get_x();
	/// \brief Получить текущую итерацию
	double get_iter();

	/// \brief Найти оптимальное значение аргумента
	virtual std::vector<double> calc(std::vector<double>) = 0;
};

