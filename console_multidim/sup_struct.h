#pragma once
#include <vector>
#include <iostream>
/// \brief Вспомогательная структура для критериев остановки
struct  sup_struct
{
	std::vector<double> gradient = std::vector<double>{ 1 };
	std::vector<double> x = std::vector<double>{ 0 };
	std::vector<double> x_old = std::vector<double>{ 1 };
	double f = 1;
	double f_old = 0;
	long int iter = 0;
	long int suc_iter = 0;
};