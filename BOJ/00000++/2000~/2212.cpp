//
//  2212.cpp
//  BOJ
//
//  Created by J213h on 6/7/24.
//

#include <bits/stdc++.h>

using namespace std;

int A[10001];
vector<int> temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    if (N <= K) {
        cout << 0 << "\n";
    }
    
    else {
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A, A + N);
        
        for (int i = 0; i < N - 1; i++) {
            temp.push_back(A[i + 1] - A[i]);
        }
        sort(temp.begin(), temp.end());
        
        
        for (int i = 0; i < K - 1; i++) {
            temp.pop_back();
        }
        
        long long ans = 0;
        for (int i: temp) {
            ans += 1LL * i;
        }
        cout << ans << "\n";
    }
    
    return 0;
}

