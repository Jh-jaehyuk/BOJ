//
//  22865.cpp
//  BOJ
//
//  Created by J213h on 2/5/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long INF = 9e18;
int N, A, B, C, M, D, E, L;
array<int, 3> ar;
long long result[3][100001];
vector<vector<pair<int, int>>> graph;

void dijkstra(int idx) {
    long long mdistance[100001];
    for (int i = 0; i < 100001; i++) {
        mdistance[i] = INF;
    }
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    pq.push(make_pair(0, ar[idx]));
    mdistance[ar[idx]] = 0;
    
    while (!pq.empty()) {
        int now = pq.top().second;
        long long dist = pq.top().first;
        pq.pop();
        
        if (mdistance[now] < dist) {
            continue;
        }
        
        for (pair<int, int> tmp: graph[now]) {
            int next = tmp.first;
            long long _dist = tmp.second + dist;
            
            if (mdistance[next] < _dist) {
                continue;
            }
            
            mdistance[next] = _dist;
            pq.push(make_pair(_dist, next));
        }
    }
    
    for (int i = 1; i <= N; i++) {
        result[idx][i] = mdistance[i];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> A >> B >> C >> M;
    ar = { A, B, C };
    graph.resize(N + 1);
    
    for (int i = 0; i < M; i++) {
        cin >> D >> E >> L;
        graph[D].push_back(make_pair(E, L));
        graph[E].push_back(make_pair(D, L));
    }
    
    dijkstra(0);
    dijkstra(1);
    dijkstra(2);
    
    int idx = -1;
    long long max_val = -1;
    for (int i = 1; i <= N; i++) {
        long long tmp = min(result[0][i], min(result[1][i], result[2][i]));

        if (max_val < tmp) {
            max_val = tmp;
            idx = i;
        }
    }
    cout << idx << "\n";
    
    return 0;
}
