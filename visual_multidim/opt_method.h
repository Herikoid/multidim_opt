#pragma once
#include <iostream>
#include <vector>
#include "vector_operations.h"
#include "opt_function.h"
#include "stop_crit.h"
#include "opt_area.h"
/// \brief ����������� ����� ������� �����������
class opt_method
{
protected:
	/// �������� x �� ���������� ������ ���������
	std::vector<std::vector<double>> x;
	/// ������� ����� �������� ���������
	long int iter = 0;

	/// ������� ��� �����������
	opt_function *func = nullptr;
	/// �������� ���������
	stop_crit* stop = nullptr;
	/// ������� �����������
	opt_area* area = nullptr;
public:
    virtual ~opt_method();

	/// \brief �������� x
	std::vector<std::vector<double>> get_x();
	/// \brief �������� ������� ��������
	double get_iter();

	/// \brief ����� ����������� �������� ���������
	virtual std::vector<double> calc(std::vector<double>) = 0;
};

