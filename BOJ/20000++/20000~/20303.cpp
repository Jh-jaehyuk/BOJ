//
//  20303.cpp
//  BOJ
//
//  Created by J213h on 7/12/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
pair<int, int> A[30001];
int parent[30001];
vector<pair<int, int>> V;
int dp[30001][3001];

int find_parent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    
    if (A[a] < A[b]) {
        parent[a] = b;
        A[b].first += A[a].first;
        A[a].first = 0;
        A[b].second += A[a].second;
        A[a].second = 0;
    }
    else {
        parent[b] = a;
        A[a].first += A[b].first;
        A[b].first = 0;
        A[a].second += A[b].second;
        A[b].second = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = 1;
        parent[i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        if (find_parent(a - 1) != find_parent(b - 1)) {
            union_parent(a - 1, b - 1);
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (parent[i] == i) {
            V.push_back(A[i]);
        }
    }
    
    if (V.empty()) {
        cout << 0 << "\n";
        return 0;
    }
    
    int vs = (int)V.size();
    

    for (int i = 0; i < vs; i++) {
        if (V[i].second < K) {
            dp[i][V[i].second] = max(dp[i][V[i].second], V[i].first);
        }
        
        if (!i) {
            continue;
        }
        
        for (int j = 0; j < K; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            
            if (j < V[i].second) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            else {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - V[i].second] + V[i].first);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < K; i++) {
        ans = max(ans, dp[vs - 1][i]);
    }
    
    cout << ans << "\n";
    return 0;
}

