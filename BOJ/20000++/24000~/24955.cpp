//
//  24955.cpp
//  BOJ
//
//  Created by J213h on 9/21/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int N, Q;
long long A[1001];
long long ans[1001];
vector<vector<int>> graph;

long long solve(long long a, long long b) {
    long long temp = a;
    for (long long i = b; i; i /= 10) {
        temp = (temp * 10) % MOD;
    }
    temp = (temp + b) % MOD;
    return temp;
}

long long BFS(int s, int e) {
    fill_n(ans, 1001, -1);
    queue<int> q;
    q.push(s);
    ans[s] = A[s];
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        if (now == e) {
            break;
        }
        
        for (int nxt: graph[now]) {
            if (ans[nxt] != -1) {
                continue;
            }
            ans[nxt] = solve(ans[now], A[nxt]);
            q.push(nxt);
        }
    }
    
    return ans[e];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        cout << BFS(x, y) << "\n";
    }
    
    return 0;
}
