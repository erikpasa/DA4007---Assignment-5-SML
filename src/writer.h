#pragma once
#include <random>
#include <string>
#include <vector>
#include <cstddef>
#include "reader.h"

class writer{
public:
    writer(const reader& r, double pseudocount, std::size_t lengthoutput, std::size_t sizekgram);
    std::string writeoutput(); 

private:
    std::mt19937 engine;
    std::vector<double> weights;
    double alpha;
    const reader& r;
    std::size_t length;
    std::size_t sizekgram;
    std::vector<char> alphabetvector; //lets us look up a number directly, which is not possible with set

    void createweights(const std::string& kgram); //creates weight distribution for each next letter


 };