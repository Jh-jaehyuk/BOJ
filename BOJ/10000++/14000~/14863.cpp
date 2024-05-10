//
//  14863.cpp
//  BOJ
//
//  Created by J213h on 5/8/24.
//

#include <bits/stdc++.h>

using namespace std;

int dp[101][100001];
int t1, c1, t2, c2;
int result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    fill_n(&dp[0][0], 101 * 100001, -1);
    
    cin >> t1 >> c1 >> t2 >> c2;
    dp[0][t1] = c1;
    dp[0][t2] = max(dp[0][t2], c2);
    
    for (int i = 1; i < N; i++) {
        cin >> t1 >> c1 >> t2 >> c2;

        for (int j = 0; j <= K; j++) {
            if (dp[i - 1][j] == -1) {
                continue;
            }

            if (t1 + j <= K) {
                dp[i][t1 + j] = max(dp[i][t1 + j], dp[i - 1][j] + c1);
            }
            
            if (t2 + j <= K) {
                dp[i][t2 + j] = max(dp[i][t2 + j], dp[i - 1][j] + c2);
            }
        }
    }
    
    for (int i = 0; i <= K; i++) {
        result = max(result, dp[N - 1][i]);
    }
    cout << result << "\n";

    return 0;
}
