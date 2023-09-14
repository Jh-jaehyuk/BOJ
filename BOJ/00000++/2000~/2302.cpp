//
//  2302.cpp
//  BOJ
//
//  Created by J213h on 2023/09/14.
//

#include <bits/stdc++.h>

using namespace std;

static int dp[41];
static bool check[41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    fill(dp, dp + 41, 1);
    
    for (int i = 2; i < 41; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    int N, M;
    cin >> N >> M;
    
    if (M == 0) {
        cout << dp[N] << "\n";
        return 0;
    }
    
    int result = 1;
    
    fill(check, check + 41, false);
    
    int Last = -1;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        Last = x;
        check[x] = true;
    }
    
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            count++;
        }
        
        else {
            result *= dp[count];
            count = 0;
        }
    }
    
    result *= dp[N - Last];
    cout << result << "\n";
    
    return 0;
}
