#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

template<class T>
struct Matrix {
    int N;
    vector<vector<T>> data;

    Matrix(int size) : N(size) {
        this->data = vector<vector<T>>(N, vector<int>(N, 0));
    }

    void operator=(const Matrix<T> &B) {
        this->data = B.data;
    }

    void operator=(int value) {
        for(auto &i : data)
            for(auto &j : i)
                j = value;
    }

    Matrix<T> operator*(const Matrix<T> &B) {
        Matrix<T> C(N);

        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                for(int k = 1; k <= N; ++k)
                    C.data[i][j] += this->data[i][k] * B.data[k][j];

        return C;
    }

    void operator*=(const Matrix<T> &B) {
        Matrix<T> C(N);

        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                for(int k = 1; k <= N; ++k)
                    C.data[i][j] += this->data[i][k] * B.data[k][j];

        this->data = C.data;
    }

    Matrix<T> operator^(int K) {
        Matrix<T> A(N);
        Matrix<T> B(N);
        A.data = this->data;
        B.data = this->data;

        while(K) {
            if(K & 1) A *= B;
            B *= B;

            K /= 2;
        }

        return A;
    }

    void operator^=(int K) {
        Matrix<T> A(N);
        Matrix<T> B(N);
        A.data = this->data;
        B.data = this->data;

        while(K) {
            if(K & 1) A *= B;
            B *= B;

            K /= 2;
        }

        this->data = A.data;
    }

};


int main() {
    return 0;
}
