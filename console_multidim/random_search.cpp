#include "random_search.h"

random_search::random_search(opt_function& f, stop_crit& s, parallel& a, double d, double p_)
{
    func = &f;
    stop = &s;
    par = &a;

    if (p_ < 0 || p_ > 1) {
        throw std::invalid_argument("p must be from 0 to 1");
    }

    if (delta < 0) {
        throw std::invalid_argument("delta must be positive");
    }

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

    double start_alpha = 1;
    double alpha = start_alpha;
    sup_struct ss;
    std::vector<double> x_p{};

    while (stop->check(ss)) {
        if (getu01_sing() < p) {
            x_p = par->get_point();
            alpha = start_alpha;
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
