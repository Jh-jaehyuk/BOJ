//
//  1965.cpp
//  BOJ
//
//  Created by J213h on 2023/09/14.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<int> dp(N, 1);
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int result = *max_element(dp.begin(), dp.end());
    
    cout << result << "\n";
    return 0;
}
