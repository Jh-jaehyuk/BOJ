//
//  5557.cpp
//  BOJ
//
//  Created by J213h on 2023/09/12.
//

#include <bits/stdc++.h>

using namespace std;

static int A[101];
static long long dp[101][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    fill(&dp[0][0], &dp[100][21], 0);
    dp[0][A[0]] = 1;
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 21; j++) {
            if (dp[i][j] == 0) {
                continue;
            }
            
            if (j + A[i + 1] >= 0 && j + A[i + 1] < 21) {
                dp[i + 1][j + A[i + 1]] += dp[i][j];
            }
            
            if (j - A[i + 1] >= 0 && j - A[i + 1] < 21) {
                dp[i + 1][j - A[i + 1]] += dp[i][j];
            }
        }
    }
    cout << dp[N - 2][A[N - 1]] << "\n";
    
    return 0;
}
