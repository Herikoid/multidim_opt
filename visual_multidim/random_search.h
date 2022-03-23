#pragma once
#include "opt_method.h"
#include "parallel.h"
/// \brief ����� ����������� ��������� �����
class random_search :
    public opt_method
{
private:
    /// ��������� ������ ����������� �����
    double delta;
    /// ����������� ������� �� ����������� �����
    double p;
    /// ������� ���������� - �����������
    parallel* par = nullptr;
public:
    random_search(opt_function& f, stop_crit& s, parallel& a, double delta = 0.1, double p_ = 0.5);
    virtual std::vector<double> calc(std::vector<double>) override;

    virtual ~random_search();
};

