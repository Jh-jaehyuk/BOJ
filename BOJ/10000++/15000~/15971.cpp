//
//  15971.cpp
//  BOJ
//
//  Created by J213h on 5/3/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, s, e, flag;
vector<vector<pair<int, int>>> graph;
int vis[100001];

void DFS(int now, int dist, int mx) {
    if (flag) {
        return;
    }
    
    vis[now] = 1;
    
    if (now == e) {
        cout << dist - mx << "\n";
        flag = 1;
        return;
    }
    
    for (pair<int, int> i: graph[now]) {
        int nxt = i.first;
        int cost = i.second;
        
        if (!vis[nxt]) {
            DFS(nxt, dist + cost, max(mx, cost));
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> s >> e;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }
    
    DFS(s, 0, 0);

    return 0;
}
