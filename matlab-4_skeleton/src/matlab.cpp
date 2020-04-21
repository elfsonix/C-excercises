#include "matlab.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>


// EXT
MatVect::MatVect(std::string str) {
    std::istringstream iss(str);

    std::vector<int> elems;
    int elem;
    while(iss) {
        if(!isdigit(iss.peek())) {
            iss.get();
        } else {
            iss >> elem;
            elems.push_back(elem);
        }
    }
    _v = elems;
}

int MatVect::sum() const {
    return std::accumulate(_v.begin(), _v.end(), 0);
}

MatVect add_vectors(const MatVect& v1, const MatVect& v2) {
    MatVect v_sum(v1.size());

    std::transform(v1.begin(), v1.end(), v2.begin(), v_sum.begin(), std::plus<int>());

    return v_sum;
}

std::string to_string(const MatVect& v) {
    std::ostringstream oss;

    oss << "[";
    for(auto it = v.cbegin(); it != v.cend(); ++it) {
        oss << " " << *it << ((it != v.cend() - 1) ? "," : " ");
    }
    oss << "]";

    return oss.str();
}

Matrix::Matrix(const std::vector<std::vector<int>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(_matrix));
}

int Matrix::sum() const {
    return std::accumulate(_matrix.begin(), _matrix.end(), 0,
    [](int acc, const auto & v) {
        return acc + v.sum();
    });
}

Matrix add_matrices(const Matrix& m1, const Matrix& m2) {
    std::size_t n_rows = m1.size();
    std::size_t n_cols = (m1.size() == 0) ? 0 : m1[0].size();
    Matrix m_sum(n_rows, n_cols);

    std::transform(m1.begin(), m1.end(), m2.begin(), m_sum.begin(),
    [](const auto & v1, const auto & v2) {
        return add_vectors(v1, v2);
    });
    return m_sum;
}

std::string to_string(const Matrix& m) {
    std::ostringstream oss;

    oss << "[" << "\n";
    for(auto it = m.cbegin(); it != m.cend(); ++it) {
        oss << "  " << to_string(*it) << ((it != m.cend() - 1) ? "," : "") << "\n";
    }
    oss << "]";

    return oss.str();
}
