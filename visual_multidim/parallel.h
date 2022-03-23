#pragma once
#include "opt_area.h"
#include "SingletonGenerator.h"
/// \brief ����� �������������� 
class parallel :
    public opt_area
{
private:
    /// ����� �������
    std::vector<double> limits_left{};
    /// ������ �������
    std::vector<double> limits_right{};
public:
 //   parallel(std::vector<double>, std::vector<double>);
    /// \brief ������� �������
    void clear_limits();
    /// \brief �������� �������
    void add_limits(double, double);
    /// \brief �������� �����������
    int get_dim();
    /// \brief �������� i-�� ������� 
    std::pair<double, double> get_lim(int i);

    /// \brief ������������� ��������� ����� �� ������������ ������������� � �������
    std::vector<double> get_point();

    bool in_area(std::vector<double>) override;
    std::pair<std::vector<double>, std::vector<bool>> corret_arg(std::vector<double>) override;

    virtual ~parallel() {};
};

/// \brief ����������� ������� � ����������� ������������ �����
parallel cross_area(parallel&, std::vector<double>, double);
