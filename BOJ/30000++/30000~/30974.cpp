//
//  30974.cpp
//  BOJ
//
//  Created by J213h on 1/4/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

vector<vector<pair<int, int>>> graph;
priority_queue<pair<long long, int>> pq;
int code[400001];
bool prime[10000001];
long long result[400001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> code[i];
    }
    
    graph.resize(N + 1);
    
    for (int i = 2; i <= 10000000; i++) {
        prime[i] = true;
    }
    
    for (int i = 2; i <= sqrt(10000000); i++) {
        if (!prime[i]) {
            continue;
        }
        
        for (int j = i + i; j <= 10000000; j += i) {
            prime[j] = false;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        int x = code[u] + code[v];
        
        if (!prime[x]) {
            continue;
        }
        
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    for (int i = 2; i <= N; i++) {
        result[i] = INF;
    }
    
    pq.push(make_pair(0, 1));
    
    while (!pq.empty()) {
        pair<long long, int> tmp = pq.top();
        long long dist = -tmp.first;
        int now = tmp.second;
        pq.pop();
        
        if (result[now] < dist) {
            continue;
        }
        
        for (pair<int, int> edge : graph[now]) {
            int next = edge.first;
            int cost = edge.second;
            
            long long _dist = dist + cost;
            
            if (_dist < result[next]) {
                result[next] = _dist;
                pq.push(make_pair(-_dist, next));
            }
        }
    }
    
    if (result[N] == INF) {
        cout << "Now where are you?" << "\n";
    }
    
    else {
        cout << result[N] << "\n";
    }
 
    return 0;
}

