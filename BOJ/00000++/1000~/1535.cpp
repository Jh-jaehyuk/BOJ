//
//  1535.cpp
//  BOJ
//
//  Created by J213h on 4/28/24.
//

#include <bits/stdc++.h>

using namespace std;

int A[21];
int B[21];
int dp[21][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    fill_n(&dp[0][0], 21 * 101, -1);
    for (int i = 0; i < N; i++) {
        dp[i][100] = 0;
        
        if (!i) {
            if (A[i] < 100) {
                dp[i][100 - A[i]] = B[i];
            }
            continue;
        }
        
        for (int j = 100; j; j--) {
            if (!(~(dp[i - 1][j]))) {
                continue;
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            
            if (j > A[i]) {
                dp[i][j - A[i]] = max(dp[i][j - A[i]], dp[i - 1][j] + B[i]);
            }

        }
    }

    int result = 0;
    for (int i = 1; i < 101; i++) {
        result = max(result, dp[N - 1][i]);
    }
    cout << result << "\n";
    
    return 0;
}
