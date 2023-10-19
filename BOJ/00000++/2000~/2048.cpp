//
//  2048.cpp
//  BOJ
//
//  Created by J213h on 10/19/23.
//

#include <bits/stdc++.h>

using namespace std;

int Solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cout << Solve() << "\n";
    }
    
    return 0;
}

int Solve() {
    int l, r;
    cin >> l >> r;
    
    if (l == r) {
        return r;
    }
    
    if (r <= 3) {
        if (l == 0 && r == 3) {
            return 5;
        }
        
        if (r - l == 1) {
            return r + 1;
        }
        
        return r;
    }
    
    return r;
}
