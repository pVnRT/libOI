#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

template <class T>
struct KQueue {
    deque<pair<T, int>> DQ;

    void push(T val) {
        int q = 0;
        while(!DQ.empty() && DQ.back().first >= val)
            q += DQ.back().second + 1,
            DQ.pop_back();
        DQ.push_back({val, q});
    }

    void pop() {
        if(DQ.front().second == 0)
            DQ.pop_front();
        else
            --DQ.front().second;
    }

    inline T min() {
        return DQ.front().first;
    }
};

int main() {
    return 0;
}
