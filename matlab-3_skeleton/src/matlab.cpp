#include "matlab.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

MatVect add_vectors(const MatVect& v1,const MatVect& v2)
{
    MatVect v_sum(v1.size());

    std::transform (v1.begin(), v1.end(), v2.begin(), v_sum.begin(), std::plus<int>());

    return v_sum;
}

void print_vector(const MatVect v)
{
    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
std::string to_string(const MatVect& v)
{
    std::ostringstream vs;
    for(const auto& it: v)
    {
        vs<<it<<" ";
    }
    return vs.str();
}
