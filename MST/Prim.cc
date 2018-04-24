#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e6 + 1;

int N, M;
int v, u, w;

bool inMST[MAXN];
vector<pair<int, int> > graph[MAXN];
priority_queue<pair<int, int> > PQ;


int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 1; i <= M; ++i) {
        scanf("%d%d%d", &v, &u, &w);
        graph[v].push_back({-w, u});
    }

    
    int mst = 0;
    PQ.push({0, 1});

    while(!PQ.empty()) {
        auto e = PQ.top();
        PQ.pop();
        
        mst += e.first;
        inMST[e.second] = true;
        for(auto u : graph[e.second])
            if(!inMST[u.second])
                PQ.push(u);

        while(!PQ.empty() && inMST[PQ.top().second])
            PQ.pop();
    }

    mst *= -1;
    printf("%d\n", mst);
    return 0;
}
