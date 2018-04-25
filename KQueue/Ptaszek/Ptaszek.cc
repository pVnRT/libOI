#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e6 + 1;

template <class T>
struct KQueue {
    deque<pair<T, int>> DQ;

    void push(T val) {
        int q = 0;
        while(!DQ.empty() && val < DQ.back().first)
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

struct Tree {
    int cost;
    int height;

    bool operator<(const Tree &t) const {
        if(cost == t.cost)
            return height > t.height;
        return cost < t.cost;
    }
};

int N, K;
int k;

int tree[MAXN];

int solve(int k) {
    KQueue<Tree> KQ;
    KQ.push({0, tree[1]});

    for(int i = 2; i <= k; ++i) {
        if(tree[i] < KQ.min().height)
            KQ.push({KQ.min().cost, tree[i]});
        else
            KQ.push({KQ.min().cost + 1, tree[i]});
    }

    for(int i = (k + 1); i < N; ++i) {
        if(tree[i] < KQ.min().height)
            KQ.push({KQ.min().cost, tree[i]});
        else
            KQ.push({KQ.min().cost + 1, tree[i]});
        KQ.pop();
    }

    if(KQ.min().height > tree[N])
        return KQ.min().cost;
    return KQ.min().cost + 1;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", tree + i);

    scanf("%d", &K);
    for(int i = 1; i <= K; ++i)
        scanf("%d", &k),
        printf("%d\n", solve(k));

    return 0;
}
