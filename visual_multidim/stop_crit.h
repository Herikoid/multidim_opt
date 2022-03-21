#pragma once
#include "sup_struct.h"
#include "vector_operations.h"
/// \brief ����������� ����� �������� ���������
class stop_crit
{
protected:
	/// ������������ ����� �������� ���������
	long int max_iter = 10000;
	/// ��������
	double eps = 1e-3;
public:
	/// \brief ������ ������������ ����� ��������
	void set_maxiter(long int);
	/// \brief ������ ��������
	void set_eps(double);
	/// \brief ���������, ������������� �� ������� ��� ��������� ��������
	virtual bool check(sup_struct&) = 0;
};

