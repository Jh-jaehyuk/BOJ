//
//  17069.cpp
//  BOJ
//
//  Created by J213h on 2023/09/14.
//

#include <bits/stdc++.h>

using namespace std;

static int board[33][33];
static int dp[33][33];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    fill(&dp[0][0], &dp[32][33], 0);
    dp[0][1] = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 2; j < N; j++) {
            if (i == 0) {
                dp[i][j] += dp[i][j - 1];
            }
            
            else {
                dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    
    
    return 0;
}
