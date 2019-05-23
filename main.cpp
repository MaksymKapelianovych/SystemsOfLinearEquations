#include <vector>
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include "gauss.h"
#include "jacobi.h"
#include "seidel.h"
#include "tridiagonalalgorithm.h"

using namespace std;

int N = 100;

void generateB(vector<float>& b, int n){
    for(int i = 0; i < n; i++){
        b[i] = rand()%10;
    }
}

void generateMatrixGauss(vector<vector<float>>& a, int n){
    for(int i = 0; i < n; i++){
        a[i] = vector<float>(n);
        for(int j = 0; j < n; j++){
            a[i][j] = rand()%N;
        }
    }
}

void generateMatrixJacobiZeidel(vector<vector<float>>& a, int n){
    for(int i = 0; i < n; i++){
        a[i] = vector<float>(n);
        float sum = 0;
        for(int j = 0; j < n; j++){
            a[i][j] = rand()%N;
            if(i != j){
                sum += a[i][j];
            }
        }

        if(a[i][i] <= sum){
            a[i][i] = sum + 1;
        }
    }
}

void generateGilbertMatrix(vector<vector<float>>& a, int n){
    for(int i = 0; i < n; i++){
        a[i] = vector<float>(n);
        for(int j = 0; j < n; j++){
            a[i][j] = 1.0/(i+j+1);
        }
    }
}

void generateTridiagonalMatrix(vector<vector<float>>& a, int n){
    for(int i = 0; i < n; i++){
        a[i] = vector<float>(n);
        for(int j = 0; j < n; j++){
            if( i == j+1 || i == j-1 || i == j){
                a[i][j] = rand()%N + 1.0;
            }else{
                a[i][j] = 0.0;
            }
        }
    }
}


int main()
{
    unsigned n;
    srand(time(0));

    cout << "\nEnter dimension of system:\nn = ";
    cin >> n;

    vector<float> x(n);
    vector<vector<float>> a(n);
    vector<float> b(n);

    generateB(b, n);
    generateTridiagonalMatrix(a, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << b[i];
        cout << endl;
    }
    cout << endl;
//    cout << "\nEnter vector b: \n";
//    for (auto& b_elem : b)
//    {
//        cin >> b_elem;
//    }

//    cout << "\nEnter coefficients of system: \n";
//    for (auto& a_elem : a)
//    {
//        a_elem = vector<float>(n);
//        for(auto& elem : a_elem){
//            cin >> elem;
//        }

//    }

    float allowed_error;
    cout << "\nEnter permissible error (using for Jacobi and Seidel methods): \n";
    cin >> allowed_error;


    //Choose method to solve equations
    TridiagonalSolve::solve(a, b, x, allowed_error);

    cout << "\nSolution:: \n";
    for (unsigned i = 0; i < n; ++i)
    {
        cout << "\nx[" << i << "]=  " << x[i];
    }
}
