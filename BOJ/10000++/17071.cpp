//
//  17071.cpp
//  BOJ
//
//  Created by J213h on 2023/09/11.
//

#include <bits/stdc++.h>

using namespace std;

static queue<pair<int, int>> myqueue;
static int visited[500001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    fill(&visited[0][0], &visited[500000][2], -1);
    myqueue.push(make_pair(N, 0));
    
    while (!myqueue.empty()) {
        int v = myqueue.front().first;
        int t = myqueue.front().second;
        myqueue.pop();
        
        if (v < 0 || v > 500000) {
            continue;
        }
        
        if (visited[v][t % 2] != -1) {
            continue;
        }
        
        visited[v][t % 2] = t;
        
        for (int i: { 2 * v, v + 1, v - 1 }) {
            myqueue.push(make_pair(i, t + 1));
        }
    }
    
    for (int i = 0; i < 500001; i++) {
        int _K = K + (i * (i + 1)) / 2;
        
        if (_K > 500000) {
            break;
        }
        
        if (visited[_K][i % 2] != -1 && visited[_K][i % 2] <= i) {
            cout << i << "\n";
            
            return 0;
        }
    }
    cout << -1 << "\n";
    
    return 0;
}
