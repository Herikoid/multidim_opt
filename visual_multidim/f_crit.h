#pragma once
#include "stop_crit.h"
/// \brief �������� ��������� ���� |f_i - f_{i - 1}| < eps
class f_crit :
    public stop_crit
{
public:
    bool check(sup_struct&) override;
};

