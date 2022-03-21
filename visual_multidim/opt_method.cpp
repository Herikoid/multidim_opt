#include "opt_method.h"

opt_method::~opt_method()
{
	area = nullptr;
	func = nullptr;
	stop = nullptr;
}

std::vector<std::vector<double>> opt_method::get_x()
{
	return x;
}

double opt_method::get_iter()
{
	return iter;
}

