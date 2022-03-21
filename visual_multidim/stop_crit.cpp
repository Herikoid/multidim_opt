#include "stop_crit.h"

void stop_crit::set_maxiter(long int x)
{
	max_iter = x;
}

void stop_crit::set_eps(double x)
{
	eps = x;
}
