#pragma once
#include<vector>
#include <iostream>
#include <cmath>
/// \brief ����������� ����� ������� ��� �����������
class opt_function
{
private:
	/// �������� ������� � �����
	double value;
public:
	/// \brief ���������� ������� � �����
	virtual double calc(std::vector<double>) = 0;
	/// \brief ������ ��������� � �����
	virtual std::vector<double> grad(std::vector<double>) = 0;
	/// ���������� ������� � �����
	double operator()(std::vector<double>);
};

