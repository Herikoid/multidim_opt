#pragma once
#include "sup_struct.h"
#include "vector_operations.h"
/// \brief Абстрактный класс криетрия остановки
class stop_crit
{
protected:
	/// максимальное число итераций алгоритма
	long int max_iter = 10000;
	/// Точность
	double eps = 1e-3;
public:
	/// \brief Задать максимальное число итераций
	void set_maxiter(long int);
	/// \brief Задать точность
	void set_eps(double);
	/// \brief Проверить, удовлетворяет ли текущий шаг алгоритма критерию
	virtual bool check(sup_struct&) = 0;
};

