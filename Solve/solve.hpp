//
// Created by Milica on 9.2.2023..
//
#include "../Tridiag_matrix/Tridiagonal_matrix.h"

std::vector<double> solve(Tridiagonal_matrix &M, std::vector<double>& f) {

    unsigned long long int n = M.size();
    std::vector<double> p(n);
    std::vector<double> q(n);
    std::vector<double> x(n);

    p[0] = -M[0][2] / M[0][1];
    q[0] = -f[0] / M[0][1];

    for (unsigned long long int i = 0; i < n; i++) {
        p[i+1] = -M[i][2] / (M[i][0] * p[i] + M[i][1]);
        q[i+1] = (f[i] - (M[i][0]*q[i]))/(M[i][0]*p[i]+M[i][1]);
    }
    x[n-1] = (f[n-1]-(M[n-1][0]*q[n-1]))/(M[n-1][0]*p[n-1]+M[n-1][1]);
    for(unsigned long long int i = n-1; i-- > 0; i){
        x[i] = x[i+1]*p[i+1] + q[i+1];
    }
    return x;
}