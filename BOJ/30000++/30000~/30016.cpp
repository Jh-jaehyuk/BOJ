//
//  30016.cpp
//  BOJ
//
//  Created by J213h on 2023/09/24.
//

#include <bits/stdc++.h>

using namespace std;

static int S[101][101];
static int D[101];
static int dp[101][101];
static vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, T;
    cin >> N >> T;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            cin >> S[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            cout << S[i][j] << " ";
        }
        cout << "\n";
    }
    
    for (int i = 0; i <= T; i++) {
        cin >> D[i];
    }
    
    fill(&dp[0][0], &dp[100][101], (int)-1e9);

    for (int i = 0; i <= T; i++) {
        dp[0][i] = S[0][i];
    }

    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = dp[i - 1][T - j] + S[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] -= D[j];
        }
    }
    
    int Max = (int)-1e9;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    
    for (int i = 0; i <= T; i++) {
        if (Max < dp[N - 1][i]) {
            Max = dp[N - 1][i];
        }
    }
    


    return 0;
}
