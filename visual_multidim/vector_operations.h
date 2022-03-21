#pragma once
#include <iostream>
#include<vector>
#include <cmath>

/// \brief ����� ��������
std::vector<double> operator+(const std::vector<double>&, const std::vector<double>&);
/// \brief �������� ��������
std::vector<double> operator-(const std::vector<double>&, const std::vector<double>&);
/// \brief ��������� ������� �� ���������
std::vector<double> operator*(double, const std::vector<double>&);
/// \brief ������� ������� �� ���������
std::vector<double> operator/(const std::vector<double>&, double);

/// \brief ������ �������
double abs(std::vector<double>);
/// \brief ��������� ������������ ��������
double scal_compose(std::vector<double>, std::vector<double>);
