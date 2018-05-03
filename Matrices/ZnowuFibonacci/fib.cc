#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 123456789;

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

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    C.data[i][j] = (C.data[i][j] + (ll)this->data[i][k] * B.data[k][j]) % MOD;

        return C;
    }

    void operator*=(const Matrix<T> &B) {
        Matrix<T> C(N);

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    C.data[i][j] = (C.data[i][j] + (ll)this->data[i][k] * B.data[k][j]) % MOD;

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

    void print() {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j)
                printf("[%d]", data[i][j]);
            printf("\n");
        }
    }
};

int N;

int main() {
    scanf("%d", &N);

    Matrix<int> F(2);
    F = 1;
    F.data[0][0] = 0;

    F^=N;
    printf("%d\n", F.data[0][0]);

    return 0;
}
