//
//  15591.cpp
//  BOJ
//
//  Created by J213h on 4/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<vector<pair<int, int>>> graph;

void BFS(int node, int K) {
    int result = 0;
    int vis[5001];
    memset(vis, 0, sizeof(vis));
    
    queue<pair<int, int>> q;
    q.push(make_pair(1e9, node));
    vis[node] = 1;
    
    while (!q.empty()) {
        int dist = q.front().first;
        int now = q.front().second;
        q.pop();
        
        if (dist < K) {
            continue;
        }
        
        for (pair<int, int> i: graph[now]) {
            int nxt = i.first;
            int ndist = min(i.second, dist);
            
            if (vis[nxt]) {
                continue;
            }
            
            if (ndist < K) {
                continue;
            }
            
            vis[nxt] = 1;
            q.push(make_pair(ndist, nxt));
            result++;
        }
    }
    
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> Q;
    graph.resize(N + 1);
    
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back(make_pair(q, r));
        graph[q].push_back(make_pair(p, r));
    }
    
    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        BFS(v, k);
    }

    return 0;
}

