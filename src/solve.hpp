#include "Tridiagonal_matrix.hpp"

template<typename T>
std::vector<T> solve(const Tridiagonal_matrix<T> &M, const std::vector<T>& f) {

    unsigned long long int n = M.size();
    std::vector<T> p(n);
    std::vector<T> q(n);
    std::vector<T> x(n);

    p[0] = -M(0,2) / M(0,1);
    q[0] = -f[0] / M(0,1);

    for (unsigned long long int i = 0; i < n; i++) {
        p[i+1] = -M(i,2) / (M(i,0) * p[i] + M(i,1));
        q[i+1] = (f[i] - (M(i,0)*q[i]))/(M(i,0)*p[i]+M(i,1));
    }
    x[n-1] = (f[n-1]-(M(n-1,0)*q[n-1]))/(M(n-1,0)*p[n-1]+M(n-1,1));
    for(unsigned long long int i = n-1; i-- > 0; i){
        x[i] = x[i+1]*p[i+1] + q[i+1];
    }
    return x;
}