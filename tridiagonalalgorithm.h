#ifndef TRIDIAGONALALGORITHM_H
#define TRIDIAGONALALGORITHM_H
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

namespace TridiagonalSolve {

void tridiagonalSolve (const vector<float>& a, const vector<float>& b, vector<float> c, vector<float> d, vector<float>& x, unsigned int n){


    c[0] /= -b[0];
    d[0] /= b[0];
    for (unsigned int i = 1; i < n; i++){
        double id = (b[i] + c[i-1] * a[i-1]);
        c[i] /= -id;
        d[i] = (d[i] - d[i-1] * a[i-1]) / id;
    }

    x[n - 1] = d[n - 1];
    for (int i = n - 2; i >= 0; i--)
        x[i] = d[i] + c[i] * x[i + 1];
}

void solve(vector<vector<float>> a, //квадратна матриця
           vector<float> b, //вектор вільних елементів
           vector<float>& x, //сюди буде записано розв'язок
           const float allowed_error) //допустима похибка
{
    const int n = x.size();
    vector<float> va(n-1);
    vector<float> vb(n);
    vector<float> vc(n-1);
    for(int i = 1; i < n; ++i){
        va[i-1] = a[i][i-1];
        vc[i-1] = a[i-1][i];
        vb[i] = a[i][i];
    }
    vb[0] = a[0][0];
    tridiagonalSolve(va, vb, vc, b, x, n);
}
}
#endif // TRIDIAGONALALGORITHM_H
