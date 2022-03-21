#pragma once
#include <iostream>
#include <random>
/// \brief Singelton Generator 
class SingletonGenerator 
{
    static std::mt19937 mersennetwister;
public:
    static std::mt19937& get_mt();
};

/// \brief смоделировать точку из U(0, 1)
double getu01_sing();

