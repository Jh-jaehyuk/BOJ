//
//  main.cpp
//  BOJ
//
//  Created by 한재혁 on 2023/09/11.
//

    
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<array<int, 3>> V;
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, D;
    cin >> N >> D;
    
    V.resize(N);
    for (int i = 0; i <= D; i++) {
        dp[i] = INF;
    }

    for (int i = 0; i < N; i++) {
        cin >> V[i][0] >> V[i][1] >> V[i][2];
    }
    
    sort(V.begin(), V.end());
    
    for (int i = 0; i <= D; i++) {
        if (i == 0) {
            dp[i] = 0;
        }
        else {
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }
        for (int j = 0; j < N; j++) {
            int u, v, c;
            u = V[j][0];
            v = V[j][1];
            c = V[j][2];
            
            if (u == i && v <= D) {
                dp[v] = min(dp[v], dp[i] + c);
            }
        }
    }
    
    cout << dp[D] << "\n";
    return 0;
}
