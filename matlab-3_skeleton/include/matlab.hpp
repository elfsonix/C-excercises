#ifndef MATLAB_HPP_
#define MATLAB_HPP_

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class MatVect {
  public:
    MatVect(std::size_t n) : _v(n, 0) {}

    MatVect(const std::vector<int> v) : _v(v) {}

    std::size_t size() const {return _v.size();}

    std::vector<int>::iterator begin() {return _v.begin();}

    std::vector<int>::const_iterator begin() const {return _v.cbegin();}

    std::vector<int>::iterator end() {return _v.end();}

    std::vector<int>::const_iterator end() const {return _v.cend();}

    const int& operator[](std::size_t pos) const { return _v[pos]; }  // inspector
    int& operator[](std::size_t pos) { return _v[pos]; }  // mutator
private:
    std::vector<int> _v;
};

MatVect add_vectors(const MatVect& v1,const MatVect& v2);
void print_vector(const MatVect& v);
std::string to_string(const MatVect& v);

#endif /* MATLAB_HPP_ */
