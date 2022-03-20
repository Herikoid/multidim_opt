#include "parallel.h"

//parallel::parallel(std::vector<double> ll, std::vector<double> lr)
//{
//	if (ll.size() != lr.size()) {
//		throw std::invalid_argument("wrong limits dim");
//	}
//	for (int i = 0; i < ll.size(); ++i) {
//		if (ll[i] > lr[i]) {
//			throw std::invalid_argument("invalid limits");
//		}
//	}
//	limits_left = ll;
//	limits_right = lr;
//}

void parallel::clear_limits()
{
	limits_left.clear();
	limits_right.clear();
}

void parallel::add_limits(double left, double right)
{
	if (left > right) {
		throw std::invalid_argument("invalid limits");
	}
	limits_left.push_back(left);
	limits_right.push_back(right);
}

int parallel::get_dim()
{
	return limits_left.size();
}

std::pair<double, double> parallel::get_lim(int i)
{
	if (i >= get_dim()) {
		throw std::invalid_argument("out of range");
	}

	return std::pair<double, double>(limits_left[i], limits_right[i]);
}

std::vector<double> parallel::get_point()
{
	std::vector<double> point;
	for (int i = 0; i < limits_left.size(); ++i)
		point.push_back(((limits_right[i] - limits_left[i]) * getu01_sing()) + limits_left[i]);
	return point;
}

bool parallel::in_area(std::vector<double> x)
{
	if (x.size() != limits_left.size()) {
		throw std::invalid_argument("wrong argument dim");
	}
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] < limits_left[i] || x[i] > limits_right[i]) {
			return false;
		}
	}

	return true;
}

std::pair<std::vector<double>, std::vector<bool>> parallel::corret_arg(std::vector<double> x)
{
	if (x.size() != limits_left.size()) {
		throw std::invalid_argument("wrong argument dim");
	}

	std::pair<std::vector<double>, std::vector<bool>> mask{};
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] < limits_left[i]) {
			mask.first.push_back(limits_left[i]);
			mask.second.push_back(true);
		}
		else {
			if (x[i] > limits_right[i]) {
				mask.first.push_back(limits_right[i]);
				mask.second.push_back(true);
			}
			else {
				mask.first.push_back(0);
				mask.second.push_back(false);
			}
		}
	}
	return mask;
}

parallel cross_area(parallel& p, std::vector<double> x, double delta)
{
	if (p.get_dim() != x.size()) {
		throw std::invalid_argument("wrong arg dim");
	}

	parallel tmp;
	for (int i = 0; i < x.size(); ++i) {
		tmp.add_limits(std::max(p.get_lim(i).first, x[i] - delta), std::min(p.get_lim(i).second, x[i] + delta));
	}
	return tmp;
}
