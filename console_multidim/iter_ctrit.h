#pragma once
#include "stop_crit.h"
/// \brief �������� ��������� �� ����� �������� � ���������� ������
class iter_ctrit :
    public stop_crit
{
private:
    /// ����� �������� � ������� ���������� ������ �� ���������
    int iter_dist = 1000;
public:
    /// \brief ������ ����� ��������
    void set_dist(int);
    bool check(sup_struct&) override;
};

