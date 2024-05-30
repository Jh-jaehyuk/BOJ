//
//  14433.cpp
//  BOJ
//
//  Created by J213h on 5/30/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, K1, K2;
vector<vector<int>> graph1;
vector<vector<int>> graph2;
int res[301];
int vis[301];

int DFS(int x, vector<vector<int>>& graph) {
    for (int i: graph[x]) {
        if (vis[i]) {
            continue;
        }
        
        vis[i] = 1;
        if (!res[i] || DFS(res[i], graph)) {
            res[i] = x;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> N >> M >> K1 >> K2;
    
    graph1.resize(N + 1);
    graph2.resize(N + 1);
    
    for (int i = 0; i < K1; i++) {
        int a, b;
        cin >> a >> b;
        graph1[a].push_back(b);
    }
    
    for (int i = 0; i < K2; i++) {
        int a, b;
        cin >> a >> b;
        graph2[a].push_back(b);
    }
    
    int ans1 = 0;
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        if (DFS(i, graph1)) {
            ans1++;
        }
    }
    
    int ans2 = 0;
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        if (DFS(i, graph2)) {
            ans2++;
        }
    }
    cout << (ans1 < ans2 ? "네 다음 힐딱이" : "그만 알아보자") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
