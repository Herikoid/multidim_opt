#pragma once
#include <iostream>
#include<vector>
#include <cmath>

/// \brief Сумма векторов
std::vector<double> operator+(const std::vector<double>&, const std::vector<double>&);
/// \brief Разность векторов
std::vector<double> operator-(const std::vector<double>&, const std::vector<double>&);
/// \brief Умножение вектора на константу
std::vector<double> operator*(double, const std::vector<double>&);
/// \brief Деление вектора на константу
std::vector<double> operator/(const std::vector<double>&, double);

/// \brief Модуль вектора
double abs(std::vector<double>);
/// \brief Скалярное произведение векторов
double scal_compose(std::vector<double>, std::vector<double>);
