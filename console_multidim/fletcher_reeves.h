#pragma once
#include "opt_method.h"
/// \brief ����� ����������� fletcher reeves

class fletcher_reeves :
    public opt_method
{
private:
    /// ������ p
    std::vector<double> p;
    /// ������� ��������������� ������ ����� �����������
    double one_dim_optim(double, double, double, int);
public:
    fletcher_reeves(opt_function&, stop_crit&, opt_area&);
    virtual std::vector<double> calc(std::vector<double>) override;
};

