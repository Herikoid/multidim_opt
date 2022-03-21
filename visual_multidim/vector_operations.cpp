#include"vector_operations.h"

std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b) 
{
    if (a.size() != b.size())
        throw("vectors with incomparable sizes");
    std::vector<double> c(a.size());
    for (int i = 0; i < a.size(); ++i)
        c[i] = a[i] + b[i];
    return c;
}
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b) 
{
    if (a.size() != b.size())
        throw("vectors with incomparable sizes");
    std::vector<double> c(a.size());
    for (int i = 0; i < a.size(); ++i)
        c[i] = a[i] - b[i];
    return c;
}

std::vector<double> operator*(double b, const std::vector<double>& a) 
{
    std::vector<double> c(a.size());
    for (int i = 0; i < a.size(); ++i)
        c[i] = b * a[i];
    return c;
}

std::vector<double> operator/(const std::vector<double>& a, double b) 
{
    std::vector<double> c(a.size());
    for (int i = 0; i < a.size(); ++i)
        c[i] = a[i] / b;
    return c;
}

double abs(std::vector<double> v) 
{
    double sum = 0;
    for (int i = 0; i < v.size(); ++i)
        sum += (v[i] * v[i]);
    return sqrt(sum);
};

double scal_compose(std::vector<double> a, std::vector<double> b) 
{
    if (a.size() != b.size())
        throw("a.size()!=b.size()");
    double sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}