//
//  9370.cpp
//  BOJ
//
//  Created by J213h on 5/17/24.
//

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int N, M, t, s, g, h;
vector<vector<pair<int, int>>> graph(2001);
int dist[2001];
int dist2[2001];
int dist3[2001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill_n(&dist[0], N + 1, INF);
    fill_n(&dist2[0], N + 1, INF);
    fill_n(&dist3[0], N + 1, INF);
    
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dist[now] < cost) {
            continue;
        }
        
        for (auto i: graph[now]) {
            int nc = cost + i.second;
            int nxt = i.first;
            
            if (dist[nxt] > nc) {
                dist[nxt] = nc;
                pq.push(make_pair(nc, nxt));
            }
        }
    }
    
    pq.push(make_pair(0, h));
    dist2[h] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dist2[now] < cost) {
            continue;
        }
        
        for (auto i: graph[now]) {
            int nc = cost + i.second;
            int nxt = i.first;
            
            if (dist2[nxt] > nc) {
                dist2[nxt] = nc;
                pq.push(make_pair(nc, nxt));
            }
        }
    }
    
    pq.push(make_pair(0, g));
    dist3[g] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dist3[now] < cost) {
            continue;
        }
        
        for (auto i: graph[now]) {
            int nc = cost + i.second;
            int nxt = i.first;
            
            if (dist3[nxt] > nc) {
                dist3[nxt] = nc;
                pq.push(make_pair(nc, nxt));
            }
        }
    }
}

void solve(int N, int M, int t) {
    for (int i = 1; i <= N; i++) {
        graph[i].clear();
    }
    cin >> s >> g >> h;
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    vector<int> temp;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        temp.push_back(x);
    }
    
    dijkstra();
    
    sort(temp.begin(), temp.end());
    for (int i: temp) {
        if (dist[i] == INF || dist2[i] == INF || dist3[i] == INF) {
            continue;
        }
        if (dist[g] + dist2[i] + dist2[g] == dist[i] || dist[h] + dist3[i] + dist3[h] == dist[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> M >> t;
        solve(N, M, t);
    }
 
    return 0;
}

