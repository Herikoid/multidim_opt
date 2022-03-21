#include "fletcher_reeves.h"

double fletcher_reeves::one_dim_optim(double a = 0, double b = 1, double eps = 1e-5, int maxiter = 1000)
{
    int i = 0;
    double left = a;
    double right = b;
    double li = a;
    double ri = b;

    while (abs(left - right) > eps && i < maxiter) {
        li = (2 * left + right) / 3;
        ri = (2 * right + left) / 3;

        if (func->calc(x[iter] + li * p) > func->calc(x[iter] + ri * p) && area->in_area(x[iter] + ri * p)) {
            left = li;
        }
        else {
            right = ri;
        }

        ++i;
    }

    return (left + right) / 2;
}

fletcher_reeves::fletcher_reeves(opt_function& f, stop_crit& s, opt_area& a)
{
    func = &f;
    stop = &s;
    area = &a;
}

std::vector<double> fletcher_reeves::calc(std::vector<double> start)
{
    if (!area->in_area(start)) {
        throw std::invalid_argument("start point not in area");
    }

    x.clear();
    x.push_back(start);
    p = (-1) * func->grad(x[0]);
    iter = 0;

    double alpha, beta;
    sup_struct ss;
    ss.gradient = func->grad(x[0]);
    
    while (stop->check(ss)) {
        ss.x_old = x[iter];
        ss.f_old = (*func)(ss.x_old);
        
        alpha = one_dim_optim();
        x.push_back(x[iter] + alpha * p);

        ++iter;

        if (!area->in_area(x[iter])) {
            std::pair<std::vector<double>, std::vector<bool>> mask = area->corret_arg(x[iter]);
            for (int i = 0; i < mask.first.size(); ++i) {
                std::cout << x[iter][i] << " ";
                if (mask.second[i]) {
                    x[iter][i] = mask.first[i];
                }
            }
            std::cout << std::endl;
            return x[iter];
        }

        ss.x = x[iter];
        ss.f = (*func)(ss.x);
        ss.iter = iter;
        ss.gradient = func->grad(x[iter]);

        beta = scal_compose(func->grad(x[iter]), func->grad(x[iter])) / scal_compose(func->grad(x[iter - 1]), func->grad(x[iter - 1]));

        p = (-1) * func->grad(x[iter]) + beta * p;
    }

    return x[iter];
}
