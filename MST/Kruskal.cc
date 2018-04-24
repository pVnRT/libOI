#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e6 + 1;

int N, M;
int v, u, w;

struct Edge {
    int v;
    int u;
    int w; // weight

    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};

vector<Edge> edgeList;

int component[MAXN];
int find(int v) {
    if(component[v] == v)
        return v;
    return component[v] = find(component[v]);
}

void unite(int v, int u) {
    component[find(v)] = find(u);
}


int main() {
    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; ++i)
        component[i] = i;
    for(int i = 1; i <= M; ++i) {
        scanf("%d%d%d", &v, &u, &w);
        edgeList.push_back({v, u, w});
    }

    sort(edgeList.begin(), edgeList.end());

    int mst = 0;
    for(auto e : edgeList)
        if(find(e.v) != find(e.u))
            unite(e.v, e.u),
            mst += e.w;

    printf("%d\n", mst);
    return 0;
}
