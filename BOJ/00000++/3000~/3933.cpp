//
//  3933.cpp
//  BOJ
//
//  Created by J213h on 5/30/24.
//

#include <bits/stdc++.h>

using namespace std;

int dp[1 << 15];

void solve(int N) {
    if (dp[N]) {
        cout << dp[N] << "\n";
        return;
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int temp = i * i;
        if (temp == N) {
            ans++;
        }
        if (temp > N) {
            break;
        }
        for (int j = i; j <= N; j++) {
            temp = i * i + j * j;
            if (temp == N) {
                ans++;
            }
            if (temp > N) {
                break;
            }
            for (int k = j; k <= N; k++) {
                temp = i * i + j * j + k * k;
                if (temp == N) {
                    ans++;
                }
                if (temp > N) {
                    break;
                }
                
                for (int l = k; l <= N; l++) {
                    temp = i * i + j * j + k * k + l * l;
                    if (temp == N) {
                        ans++;
                    }
                    if (temp > N) {
                        break;
                    }
                }
            }
        }
    }
    dp[N] = ans;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        int N;
        cin >> N;
        if (!N) {
            break;
        }
        solve(N);
    }
    
    return 0;
}

