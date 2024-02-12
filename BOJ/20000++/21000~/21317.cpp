//
//  21317.cpp
//  BOJ
//
//  Created by J213h on 2/12/24.
//

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int dp[21][2];
int jump[20][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> jump[i][0] >> jump[i][1];
    }
    cin >> K;
    
    if (N == 1) {
        cout << 0 << "\n";
    }
    
    else if (N == 2) {
        cout << jump[1][0] << "\n";
    }
    
    else {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = INF;
            }
        }
        
        dp[1][0] = 0;
        dp[2][0] = jump[1][0];
        dp[3][0] = min(jump[1][0] + jump[2][0], jump[1][1]);
        for (int i = 4; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][0] + jump[i - 1][0], dp[i - 2][0] + jump[i - 2][1]);
            dp[i][1] = min(dp[i - 3][0] + K, min(dp[i - 1][1] + jump[i - 1][0], dp[i - 2][1] + jump[i - 2][1]));
        }
        cout << min(dp[N][0], dp[N][1]) << "\n";
    }

    return 0;
}
