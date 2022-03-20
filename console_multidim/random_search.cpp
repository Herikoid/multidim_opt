#include "random_search.h"

random_search::random_search(opt_function& f, stop_crit& s, parallel& a, double d, double p_)
{
    func = &f;
    stop = &s;
    par = &a;
    delta = d;
    p = p_;
}

random_search::~random_search()
{
    par = nullptr;
}

std::vector<double> random_search::calc(std::vector<double> start)
{
    if (!par->in_area(start)) {
        throw std::invalid_argument("start point not in area");
    }

    x.clear();
    x.push_back(start);
    iter = 0;

    double alpha = 1;
    sup_struct ss;
    std::vector<double> x_p{};

    while (stop->check(ss)) {
        if (getu01_sing() < p) {
            x_p = par->get_point();
        }
        else {
            x_p = cross_area(*par, x.back(), (alpha /= 1.5) * delta).get_point();
        }

        ++iter;
        if (func->calc(x_p) < func->calc(x.back())) {
            x.push_back(x_p);
            ss.suc_iter = iter;
        }
        ss.iter = iter;
    }

    return x.back();
}
