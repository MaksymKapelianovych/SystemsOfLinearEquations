#ifndef GAUSS_H
#define GAUSS_H
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
namespace Gauss {

    bool swap(vector<vector<float>>& a, vector<float>& b, int k, int n){
        double max = 0;
        int index;
        for(int j = k+1; j < n; ++j){
            if(fabs(a[j][k]) > max){
                max = fabs(a[j][k]);
                index = j;
            }
        }
        if(max != 0){
            vector<float> row = a.at(index);
            a[index] = a[k];
            a[k] = row;

            float temp = b[index];
            b[index] = b[k];
            b[k] = temp;

//            a.erase(a.begin()+index);
//            a.insert(a.begin()+k, row);
            return true;
        }

        return false;
    }
    void getLower(vector<vector<float>>& a, vector<float>& b,  int n){
        for(int i = n-1; i >= 0; --i){
            for(int j = i+1; j < n; ++j){
                for(int k = i; k >=0; --k){
                    b[k] -= b[j]*a[k][j];
                    a[k][j] -= a[k][j];
                }
            }
        }
    }
    bool getUpper(vector<vector<float>>& a, vector<float>& b,  int n){
        for (int row = 0;row < n; ++row) {
            if(a[row][row] == 0 and !swap(a, b, row, n)){
                return false;
            }
            vector<float> r = a[row];

            float d = r[row];
            b[row] /= d;

            for(int column = n-1; column >= row; --column){
                r[column] /= d;

            }
            a.erase(a.begin()+row);
            a.insert(a.begin()+row, r);
            for(int tempRow = row+1; tempRow < n; ++tempRow){
                d = a[tempRow][row];
                b[tempRow] -=b[row]*d;
                for(int tempColumn = 0; tempColumn < n; ++tempColumn){
                    a[tempRow][tempColumn] -= a[row][tempColumn]*d;
                }
            }


        }

        getLower(a, b, n);
        return true;
    }



    void solve(vector<vector<float>> a, //квадратна матриця
               vector<float> b, //вектор вільних елементів
               vector<float>& x, //сюди буде записано розв'язок
               const float allowed_error) //допустима похибка
    {
        if(!getUpper(a, b, x.size())){
            cout << "Matrix is degenerate\n";
            return ;
        }

        x = b;


    }
}
#endif // GAUSS_H
