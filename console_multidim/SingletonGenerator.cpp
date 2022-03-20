#include "SingletonGenerator.h"

std::mt19937& SingletonGenerator::get_mt() 
{
    return mersennetwister;
}

double getu01_sing() 
{
    std::uniform_real_distribution<double> unif_real_01(0.0, 1.0);
    return unif_real_01(SingletonGenerator::get_mt());
}