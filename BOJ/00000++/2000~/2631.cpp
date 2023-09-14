//
//  2631.cpp
//  BOJ
//
//  Created by J213h on 2023/09/14.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> A;
static vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    A.resize(N);
    dp.resize(N);
    
    fill(dp.begin(), dp.end(), 1);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int Max = *max_element(dp.begin(), dp.end());
    cout << N - Max << "\n";
    
    return 0;
}
