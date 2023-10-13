//
//  6118.cpp
//  BOJ
//
//  Created by J213h on 10/13/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<vector<int>> graph;
static vector<int> depth;
static queue<int> myqueue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    graph.resize(N + 1);
    depth.resize(N + 1);
    fill(depth.begin(), depth.end(), -1);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    myqueue.push(1);
    depth[1] = 0;
    
    while (!myqueue.empty()) {
        int now = myqueue.front();
        myqueue.pop();
        
        for (int i : graph[now]) {
            if (depth[i] != -1) {
                continue;
            }
            
            depth[i] = depth[now] + 1;
            myqueue.push(i);
        }
    }
    
    int Max = *max_element(depth.begin(), depth.end());
    
    int idx = -1;
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (depth[i] == Max) {
            if (idx == -1) {
                idx = i;
            }
            count++;
        }
    }
    
    cout << idx << " " << Max << " " << count << "\n";
    
    return 0;
}
