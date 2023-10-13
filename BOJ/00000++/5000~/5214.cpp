//
//  5214.cpp
//  BOJ
//
//  Created by J213h on 10/13/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<vector<int>> graph;
static vector<int> mdistance;
static queue<int> myqueue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K, M;
    cin >> N >> K >> M;
    
    graph.resize(N + 1 + M);
    mdistance.resize(N + 1 + M);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            
            graph[x].push_back(N + 1 + i);
            graph[N + 1 + i].push_back(x);
        }
    }
    
    fill(mdistance.begin(), mdistance.end(), -1);
    mdistance[1] = 1;
    myqueue.push(1);
    
    while (!myqueue.empty()) {
        int now = myqueue.front();
        myqueue.pop();
        
        for (int i : graph[now]) {
            if (mdistance[i] != -1) {
                continue;
            }
            
            if (i > N) {
                mdistance[i] = mdistance[now];
            }
            
            else {
                mdistance[i] = mdistance[now] + 1;
            }
            
            myqueue.push(i);
        }
    }
    
    cout << (mdistance[N] == (int)1e9 ? -1 : mdistance[N]) << "\n";
    
    return 0;
}
