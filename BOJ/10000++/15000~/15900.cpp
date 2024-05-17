//
//  15900.cpp
//  BOJ
//
//  Created by J213h on 5/17/24.
//

#include <bits/stdc++.h>

using namespace std;

long long ans;
vector<vector<int>> graph;
int vis[500001];
vector<long long> V;

void DFS(int node, long long depth) {
    if (node != 1 && (int)graph[node].size() == 1) {
        V.push_back(depth);
        return;
    }
    
    for (int i: graph[node]) {
        if (!vis[i]) {
            vis[i] = 1;
            DFS(i, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    graph.resize(N + 1);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    DFS(1, 0);
    for (long long i: V) {
        ans += i;
    }

    cout << (ans % 2 ? "Yes" : "No") << "\n";

    return 0;
}

