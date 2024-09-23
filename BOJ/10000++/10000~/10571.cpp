//
//  10571.cpp
//  BOJ
//
//  Created by J213h on 9/23/24.
//

#include <bits/stdc++.h>

using namespace std;

pair<double, double> A[201];
int dp[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        
        fill_n(dp, 201, 1);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first >> A[i].second;
        }
        
        int ans = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i].first > A[j].first && A[i].second < A[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        cout << *max_element(dp, dp + N) << "\n";
    }
    
    return 0;
}
