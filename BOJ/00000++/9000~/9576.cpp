//
//  9576.cpp
//  BOJ
//
//  Created by J213h on 5/30/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> graph;
int res[1001];
int vis[1001];

int DFS(int x) {
    for (int i: graph[x]) {
        if (vis[i]) {
            continue;
        }
        
        vis[i] = 1;
        if (!res[i] || DFS(res[i])) {
            res[i] = x;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> N >> M;
    memset(res, 0, sizeof(res));
    graph.resize(M + 1);
    
    for (int i = 1; i <= M; i++) {
        graph[i].clear();
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            graph[i].push_back(j);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        memset(vis, 0, sizeof(vis));
        if (DFS(i)) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}
