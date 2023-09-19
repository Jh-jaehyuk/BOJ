//
//  10451.cpp
//  BOJ
//
//  Created by J213h on 2023/09/19.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> A;
static vector<bool> visited;

void DFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        
        A.clear();
        A.resize(N + 1);
        visited.resize(N + 1);
        fill(visited.begin(), visited.end(), false);
        
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        
        int result = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                result++;
                DFS(i);
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}

void DFS(int node) {
    visited[node] = true;
    
    if (!visited[A[node]]) {
        DFS(A[node]);
    }
}
