#ifndef EXP_F_H
#define EXP_F_H

#include "opt_function.h"

class exp_f : public opt_function
{
public:
    double calc(std::vector<double>) override;
    std::vector<double> grad(std::vector<double>) override;

    virtual ~exp_f() {};
};

#endif // EXP_F_H
