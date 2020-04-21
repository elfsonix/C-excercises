#include "matlab.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>

MatVect::MatVect(std::size_t n)
{
    for(unsigned int i=0; i<n; i++)
    {
        _v.push_back(0);
    }
}
MatVect::MatVect(std::vector<int> v1)
{
    _v=v1;
}
int MatVect::getElem(std::size_t pos)
{
    return _v[pos];
}
void MatVect::setElem(std::size_t pos,int val)
{
    _v[pos]=val;
}
std::size_t MatVect::size()
{
    return _v.size();
}



MatVect add_vectors(MatVect v1, MatVect v2) {
  MatVect v_sum (v1.size());

  for (std::size_t i = 0; i < v1.size(); i++) {
    v_sum.setElem(i,v1.getElem(i)+v2.getElem(i));
  }

  return v_sum;
}

// FIXME: refactor `print_vector` function
void print_vector(MatVect v) {
  for (std::size_t i = 0; i < v.size(); i++) {
    std::cout << v.getElem(i) << " ";
  }
  std::cout << std::endl;
}
