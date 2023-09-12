//
//  9084.cpp
//  BOJ
//
//  Created by J213h on 2023/09/12.
//

#include <bits/stdc++.h>

using namespace std;

void Solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        Solve();
    }
    
    return 0;
}

void Solve() {
    int N;
    cin >> N;
    
    int dp[10001];
    fill(dp, dp + 10001, 0);
    vector<int> coin;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        coin.push_back(x);
    }
    
    int M;
    cin >> M;
    
    dp[0] = 1;
    
    for (int i: coin) {
        for (int j = i; j <= M; j++) {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[M] << "\n";
    
    return;
}
