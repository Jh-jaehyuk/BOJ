//
//  31829.cpp
//  BOJ
//
//  Created by J213h on 5/16/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
int N, K, X, Y;
vector<vector<array<int, 3>>> graph;
long long dist[200001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

long long dijkstra(int start) {
    fill_n(&dist[0], N + 1, INF);
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while (!pq.empty()) {
        long long d = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dist[now] < d) {
            continue;
        }
        
        for (auto i: graph[now]) {
            long long nd = i[2];
            if (d < K) {
                if (i[0]) {
                    nd += K;
                }
                else {
                    nd += d;
                }
            }
            else {
                nd += d;
            }
            int nxt = i[1];
            
            if (dist[nxt] > nd) {
                dist[nxt] = nd;
                pq.push(make_pair(nd, nxt));
            }
        }
    }
    
    return dist[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K >> X >> Y;
    graph.resize(N + 1);
    for (int i = 0; i < X; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({ 0, v, d });
        graph[v].push_back({ 0, u, d });
    }
    
    for (int i = 0; i < Y; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({ 1, v, d });
        graph[v].push_back({ 1, u, d });
    }
    cout << dijkstra(1) << "\n";

    return 0;
}

