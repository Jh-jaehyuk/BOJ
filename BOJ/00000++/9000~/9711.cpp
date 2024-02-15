//
//  9711.cpp
//  BOJ
//
//  Created by J213h on 2/15/24.
//

#include <bits/stdc++.h>

using namespace std;

long long dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int P, Q;
        cin >> P >> Q;
        
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= P; i++) {
            dp[i] = dp[i - 1] % Q + dp[i - 2] % Q;
        }
        
        cout << "Case #" << t << ": " << dp[P] % Q << "\n";
    }

    return 0;
}
