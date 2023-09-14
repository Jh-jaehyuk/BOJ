//
//  10164.cpp
//  BOJ
//
//  Created by J213h on 2023/09/14.
//

#include <bits/stdc++.h>

using namespace std;

static int board[16][16];
static int dp[16][16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    int row = N;
    int col = M;
    
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = idx++;
            
            if (board[i][j] == K - 1) {
                row = i;
                col = j;
            }
        }
    }
    
    fill(&dp[0][0], &dp[15][16], 0);
    dp[0][0] = 1;
    
    for (int j = 1; j <= col; j++) {
        dp[0][j] += dp[0][j - 1];
    }
    
    for (int i = 1; i <= row; i++) {
        dp[i][0] += dp[i - 1][0];
    }
    
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
        }
    }
    
    if (K == 0) {
        cout << dp[N - 1][M - 1] << "\n";
        return 0;
    }
    
    for (int i = row; i < N; i++) {
        for (int j = col; j < M; j++) {
            if (i == row && j == col) {
                continue;
            }
            
            if (i == 0) {
                dp[i][j] += dp[i][j - 1];
            }
            
            else if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            }
            
            else {
                dp[i][j] += (dp[i][j - 1] + dp[i - 1][j]);
            }
        }
    }
    
    cout << dp[N - 1][M - 1] << "\n";
    
    return 0;
}
