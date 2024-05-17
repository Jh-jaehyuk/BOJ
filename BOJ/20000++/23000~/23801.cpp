//
//  23801.cpp
//  BOJ
//
//  Created by J213h on 5/13/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int N, M, X, Z, P;
vector<vector<pair<int, long long>>> graph;
vector<long long> dist1;
vector<long long> dist2;
vector<int> V;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    graph.resize(N + 1);
    dist1.resize(N + 1);
    dist2.resize(N + 1);
    
    fill_n(&dist1[0], N + 1, INF);
    fill_n(&dist2[0], N + 1, INF);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    cin >> X >> Z >> P;
    V.resize(P);
    for (int i = 0; i < P; i++) {
        cin >> V[i];
    }
    
    pq.push(make_pair(0, X));
    dist1[X] = 0;
    while (!pq.empty()) {
        long long cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dist1[now] < cost) {
            continue;
        }
        
        for (auto i: graph[now]) {
            long long ncost = i.second;
            int nxt = i.first;
            
            long long _cost = cost + ncost;
            
            if (_cost < dist1[nxt]) {
                dist1[nxt] = _cost;
                pq.push(make_pair(_cost, nxt));
            }
        }
    }
    
    pq.push(make_pair(0, Z));
    dist2[Z] = 0;
    while (!pq.empty()) {
        long long cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dist2[now] < cost) {
            continue;
        }
        
        for (auto i: graph[now]) {
            long long ncost = i.second;
            int nxt = i.first;
            
            long long _cost = cost + ncost;
            
            if (_cost < dist2[nxt]) {
                dist2[nxt] = _cost;
                pq.push(make_pair(_cost, nxt));
            }
        }
    }
    
    long long ans = INF;
    for (int i: V) {
        ans = min(ans, dist1[i] + dist2[i]);
    }
    cout << (ans == INF ? -1 : ans) << "\n";
    
    return 0;
}

