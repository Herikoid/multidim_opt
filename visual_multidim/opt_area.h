#pragma once
#include<vector>
#include<iostream>
/// \brief ����������� ����� � �������� ����������� �������
class opt_area
{
public:
	/// \brief ��������, ����� �� ����� � �������
	virtual bool in_area(std::vector<double>) = 0;
	/// \brief ������������� ��������� �����, ���� ��� ������� �� ������� �������
	virtual std::pair<std::vector<double>, std::vector<bool>> corret_arg(std::vector<double>) = 0;

    virtual ~opt_area() {};
};

