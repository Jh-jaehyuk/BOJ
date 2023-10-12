//
//  18223.cpp
//  BOJ
//
//  Created by J213h on 10/12/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<vector<pair<int, int>>> graph;
static int mdistance[5001];
static int visited[5001];

int dijkstra(int S, int E);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int V, E, P;
    cin >> V >> E >> P;
    
    graph.resize(V + 1);
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    
    int d1 = dijkstra(1, P) + dijkstra(P, V);
    int d2 = dijkstra(1, V);
    
    cout << (d1 > d2 ? "GOOD BYE" : "SAVE HIM") << "\n";
    
    return 0;
}

int dijkstra(int S, int E) {
    fill(mdistance, mdistance + 5001, (int)1e9);
    fill(visited, visited + 5001, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, S));
    mdistance[S] = 0;
    
    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        
        if (visited[now]) {
            continue;
        }
        
        visited[now] = 1;
        
        for (pair<int, int> i : graph[now]) {
            if (!visited[i.first] && mdistance[i.first] > mdistance[now] + i.second) {
                mdistance[i.first] = mdistance[now] + i.second;
                pq.push(make_pair(mdistance[i.first], i.first));
            }
        }
    }
    
    return mdistance[E];
}
