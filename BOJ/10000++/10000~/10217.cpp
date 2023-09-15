//
//  10217.cpp
//  BOJ
//
//  Created by J213h on 2023/09/15.
//

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int arrive, cost, dist;
};

static int N, M, K;
static vector<vector<Edge>> edges;
static int dp[101][10001];
static queue<Edge> myqueue;

bool cmp(Edge i, Edge j);

int Solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    
    edges.resize(N + 1);
    fill(&dp[0][0], &dp[100][10001], (int)1e9);
    
    for (int i = 0; i < K; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        Edge tmp;
        tmp.arrive = v;
        tmp.cost = c;
        tmp.dist = d;
        edges[u].push_back(tmp);
    }
    
    for (int i = 1; i <= N; i++) {
        sort(edges[i].begin(), edges[i].end(), cmp);
    }
    
    myqueue.push({ 1, 0, 0 });
    dp[1][0] = 0;
    
    while (!myqueue.empty()) {
        Edge tmp = myqueue.front();
        int d = tmp.dist;
        int c = tmp.cost;
        int now = tmp.arrive;
        myqueue.pop();
        
        if (d > dp[now][c]) {
            continue;
        }
        
        for (Edge i: edges[now]) {
            int next = i.arrive;
            int _d = d + i.dist;
            int _c = c + i.cost;
            
            if (_c <= M && _d < dp[next][_c]) {
                for (int j = _c; j <= M; j++) {
                    if (dp[next][j] > _d) {
                        dp[next][j] = _d;
                    }
                    
                    else {
                        break;
                    }
                }
                myqueue.push({ next, _c, _d });
            }
        }
    }
    
    int result = dp[N][M];
    if (result == 1e9) {
        cout << "Poor KCM" << "\n";
    }
    
    else {
        cout << result << "\n";
    }
    
    return 0;
}

bool cmp(Edge i, Edge j) {
    if (i.cost != j.cost) {
        return i.cost < j.cost;
    }
    
    else {
        if (i.dist != j.dist) {
            return i.dist < j.dist;
        }
        
        else {
            return i.arrive < j.arrive;
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        Solve();
    }
    
    return 0;
}
