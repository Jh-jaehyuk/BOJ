//
//  17069.cpp
//  BOJ
//
//  Created by J213h on 2023/09/14.
//

#include <bits/stdc++.h>

using namespace std;

static int board[33][33];
static long long dp[33][33][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    
    fill(&dp[0][0][0], &dp[32][33][3], 0);
    dp[1][2][0] = 1;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1 && j == 2) {
                continue;
            }
            
            if (board[i][j] == 0) {
                if (board[i][j - 1] == 0) {
                    dp[i][j][0] = (dp[i][j - 1][0] + dp[i][j - 1][2]);
                }
                
                else {
                    dp[i][j][0] = 0;
                }
                
                if (board[i - 1][j] == 0) {
                    dp[i][j][1] += (dp[i - 1][j][1] + dp[i - 1][j][2]);
                }
                
                else {
                    dp[i][j][1] = 0;
                }
                
                if (board[i - 1][j] == 0 && board[i][j - 1] == 0) {
                    dp[i][j][2] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
                }
                
                else {
                    dp[i][j][2] = 0;
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < 3; k++) {
                cout << dp[i][j][k] << ',';
            }
            cout << " ";
        }
        cout << "\n";
    }
    
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << "\n";
    
    return 0;
}
