#pragma once
#include "stop_crit.h"
/// \brief �������� ��������� |gradient(f)| < eps
class grad_crit :
    public stop_crit
{
public:
    bool check(sup_struct&) override;
};
