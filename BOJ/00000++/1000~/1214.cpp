//
//  1214.cpp
//  BOJ
//
//  Created by J213h on 6/9/24.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long D, P, Q;
    cin >> D >> P >> Q;
    if (P < Q) {
        swap(P, Q);
    }
    
    long long ans = LONG_LONG_MAX;
    
    for (int i = 0; i < min(Q, D / P + 2); i++) {
        long long temp = (D - P * i) / Q;
        
        for (int j = max((long long)0, temp - 2); j < temp + 2; j++) {
            if (P * i + Q * j < D) {
                continue;
            }
            ans = min(ans, P * i + Q * j);
        }
    }
    cout << ans << "\n";

    return 0;
}

