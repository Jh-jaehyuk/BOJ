#include <bits/stdc++.h>

using namespace std;

int dp[1000001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    fill_n(&dp[0][0], (b + 1) * 2, 1e9);
    dp[a][0] = 0;
    
    for (int i = a; i < b; i++) {
        for (int j = 0; j < 2; j++) {
            if (i + 1 <= b) {
                dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j] + 1);
            }
            
            if (i * 2 <= b) {
                dp[i * 2][j] = min(dp[i * 2][j], dp[i][j] + 1);
            }
            
            if (!j && i * 10 <= b) {
                dp[i * 10][1] = min(dp[i * 10][1], dp[i][0] + 1);
            }
        }
    }
    cout << min(dp[b][0], dp[b][1]) << "\n";

    return 0;
}
