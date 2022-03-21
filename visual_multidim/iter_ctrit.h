#pragma once
#include "stop_crit.h"
/// \brief  ритерий остановки по числу итераций с последнего успеха
class iter_ctrit :
    public stop_crit
{
private:
    /// „исло итераций с момента последнего успеха до остановки
    int iter_dist = 1000;
public:
    /// \brief «адать число итераций
    void set_dist(int);
    bool check(sup_struct&) override;
};

