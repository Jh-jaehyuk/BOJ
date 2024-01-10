//
//  Softeer_우물안개구리.cpp
//  BOJ
//
//  Created by J213h on 12/30/23.
//

#include <bits/stdc++.h>

using namespace std;

int W[1000001];

vector<vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }
    
    graph.resize(N + 1);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 0) {
            result++;
            continue;
        }
        
        bool flag = false;
        for (int j: graph[i]) {
            if (W[i] <= W[j]) {
                flag = true;
                break;
            }
        }
        
        if (!flag) {
            result++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
