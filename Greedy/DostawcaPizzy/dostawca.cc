#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5 + 1;

int N, K;
int v, u, d;
ll opt_time;

ll dist[MAXN];
ll depth[MAXN];
int parent[MAXN];
int cool_child[MAXN];
priority_queue<pair<ll, int>> PQ;
vector<pair<int, int>> graph[MAXN];

ll DFS(int v, int p) {
    parent[v] = p;

    for(auto e : graph[v]) {
        if(e.first == p)
            continue;

        dist[e.first] = dist[v] + e.second;
        ll child_dist = e.second + DFS(e.first, v);
        if(child_dist > depth[v])
            depth[v] = child_dist,
            cool_child[v] = e.first; 
    }

    return depth[v];
}

int main() {
    scanf("%d%d", &N, &K); 
    
    for(int i = 1; i < N; ++i) {
        scanf("%d%d%d", &v, &u, &d);

        graph[v].push_back({u, d});
        graph[u].push_back({v, d});

        opt_time += 2 * d;
    }

    DFS(1, 0);
    PQ.push({depth[1], 1});

    for(int i = 1; i <= K; ++i) {
        if(PQ.empty() || PQ.top().first < 1)
            break;

        opt_time -= PQ.top().first;
        v = PQ.top().second;
        PQ.pop();

        while(depth[v]) {
            for(auto e : graph[v]) {
                if(e.first == parent[v] || e.first == cool_child[v])
                    continue;
                PQ.push({e.second + depth[e.first] - dist[v], e.first});
            }

            v = cool_child[v];
        }
    }

    printf("%lld\n", opt_time);
    return 0;
}
