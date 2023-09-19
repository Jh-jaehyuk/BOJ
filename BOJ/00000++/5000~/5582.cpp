//
//  5582.cpp
//  BOJ
//
//  Created by J213h on 2023/09/19.
//

#include <bits/stdc++.h>

using namespace std;

static int dp[4001][4001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    int l1 = (int)s1.size();
    int l2 = (int)s2.size();
    fill(&dp[0][0], &dp[4000][4001], 0);
    
    int result = 0;
    
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}
