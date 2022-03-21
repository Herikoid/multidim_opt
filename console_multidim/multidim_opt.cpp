#include <iostream>
#include <vector>
#include "fletcher_reeves.h"
#include "x_crit.h"
#include "f_crit.h"
#include "grad_crit.h"
#include "iter_ctrit.h"
#include "sq_sum.h"
#include "f_3dim.h"
#include "f_4dim.h"
#include "rosenbrok_f.h"
#include "parallel.h"
#include "random_search.h"
#include "sincos_f.h"

std::mt19937 SingletonGenerator::mersennetwister;

///@example
int main()
{
    stop_crit* crit = nullptr;
    opt_function* f = nullptr;
    parallel area;
    opt_method* om = nullptr;

    std::vector<double> start{};
    std::vector<double> res;
    int input, input1;
    double right, left;
    try
    {
        std::cout << "Chose function:" << std::endl;
        std::cout << "type 1 for f(x, y) = x^2 + y^2" << std::endl;
        std::cout << "type 2 for f(x, y, z) = x^2 + y^2 + z^3" << std::endl;
        std::cout << "type 3 for f(x, y, z, t) = x^2 + y^2 + z^3 + t^4" << std::endl;
        std::cout << "type 4 for f(x, y) = (1 - x)^2 + 100 * (y - x^2)^2" << std::endl;
        std::cin >> input1;
        if (input1 < 1 || input1 > 4) {
            throw std::invalid_argument("type form 1 to 4");
        }
        switch (input1)
        {
        case 1:
            f = new sq_sum;
            break;
        case 2:
            f = new f_3dim;
            break;
        case 3:
            f = new f_4dim;
            break;
        case 4:
            f = new rosenbrok_f;
            input1 = 1;
            break;
        default:
            break;
        }

        std::cout << input1 + 1 << "d area:" << std::endl;
        for (int i = 0; i < input1 + 1; ++i) {
            std::cout << "enter lelft border: " << std::endl;
            std::cin >> left;
            std::cout << "enter right border: " << std::endl;
            std::cin >> right;
            area.add_limits(left, right);
        }

        std::cout << "Chose method:" << std::endl;
        std::cout << "type 1 for random search" << std::endl;
        std::cout << "type 2 for fletcher reeves" << std::endl;
        std::cin >> input;
        if (input < 1 || input > 2) {
            throw std::invalid_argument("type 1 or 2");
        }
        if (input == 1) {
            crit = new iter_ctrit;
            om = new random_search(*f, *crit, area);
        }
        else {
            std::cout << "Chose stop criteria:" << std::endl;
            std::cout << "type 1 for x criteria" << std::endl;
            std::cout << "type 2 for f criteria" << std::endl;
            std::cout << "type 3 for gradient criteria" << std::endl;
            std::cin >> input;
            

            if (input < 1 || input > 3) {
                throw std::invalid_argument("type form 1 to 3");
            }
            switch (input)
            {
            case 1:
                crit = new x_crit;
                break;
            case 2:
                crit = new f_crit;
                break;
            default:
                crit = new grad_crit;
                break;
            }
            std::cout << "Input eps, type 0 for default" << std::endl;
            double eps;
            std::cin >> eps;
            if (eps) {
                crit->set_eps(eps);
            }
            std::cout << "Input maxiter, type 0 for default" << std::endl;
            long int maxiter;
            std::cin >> maxiter;
            if (maxiter) {
                crit->set_maxiter(maxiter);
            }

            om = new fletcher_reeves(*f, *crit, area);
        }
        std::cout << "enter start point: " << std::endl;
        for (int i = 0; i < input1 + 1; ++i) {
            std::cin >> left;
            start.push_back(left);
        }


        res = om->calc(start);
        std::cout << "Result:" << std::endl;
        std::cout << "x = (";
        for (int i = 0; i < res.size() - 1; ++i) {
            std::cout << res[i] << ", ";
        }
        std::cout << res.back() << "), f(x) = " << f->calc(res) << ", iter = " << om->get_iter() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "There was an exception: " << e.what() << std::endl;
    }
    
    delete f;
    delete crit;
    delete om;

    return 0;
}