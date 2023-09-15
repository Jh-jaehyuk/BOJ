//
//  1145.cpp
//  BOJ
//
//  Created by J213h on 2023/09/15.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int A[5];
    
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }
    
    int result = 1e9;
    
    for (int i = 0; i <= 2; i++) {
        for (int j = i + 1; j <= 3; j++) {
            for (int k = j + 1; k < 5; k++) {
                int g = gcd(A[i], A[j]);
                int l = (A[i] * A[j]) / g;
                
                int _g = gcd(l, A[k]);
                int _l = (l * A[k]) / _g;
                result = min(result, _l);
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}
