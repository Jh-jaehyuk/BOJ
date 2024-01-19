//
//  31230.cpp
//  BOJ
//
//  Created by J213h on 1/15/24.
//

#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator() (int const & i, int const & j) {
        return i < j;
    }
};

const long long INF = 9e18;
vector<vector<pair<int, int>>> graph;
vector<long long> mdistance;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
vector<vector<int>> path;
set<int> result;

void dijkstra(int start);
void DFS(int now);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    
    graph.resize(N + 1);
    mdistance.resize(N + 1);
    path.resize(N + 1);
    
    fill(mdistance.begin(), mdistance.end(), INF);
    
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    
    dijkstra(A);
    result.insert(B);
    DFS(B);
    cout << result.size() << "\n";
    
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }

    return 0;
}

void dijkstra(int start) {
    mdistance[start] = 0;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        long long dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (mdistance[now] < dist) {
            continue;
        }
        
        for (pair<int, int> i: graph[now]) {
            long long _dist = dist + i.second;
            int next = i.first;
            
            if (mdistance[next] > _dist) {
                mdistance[next] = _dist;
                path[next].clear();
                path[next].push_back(now);
                pq.push(make_pair(_dist, next));
            }
            
            else if (mdistance[next] == _dist) {
                path[next].push_back(now);
            }
        }
    }
}

void DFS(int now) {
    if (path[now].empty()) {
        return;
    }
    
    for (int i: path[now]) {
        result.insert(i);
        DFS(i);
    }
}

