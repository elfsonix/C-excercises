#ifndef _MATLAB_HPP
#define _MATLAB_HPP
#endif // _MATLAB_HPP

#include <cstddef>
#include <vector>

class MatVect
{
    private: std::vector<int> _v;
    public:
    MatVect(std::size_t n);
    MatVect(std::vector<int> v1);
    int getElem(std::size_t pos);
    void setElem(std::size_t pos,int val);
    std::size_t size();
};


MatVect add_vectors(MatVect v1, MatVect v2);
void print_vector(MatVect v);
