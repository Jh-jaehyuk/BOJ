//
//  20365.cpp
//  BOJ
//
//  Created by J213h on 1/19/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
char C[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> C;
    
    int B = 0;
    int R = 0;
    
    char prev = C[0];
    for (int i = 1; i < N; i++) {
        if (prev != C[i]) {
            if (prev == 'B') {
                B++;
            }
            else {
                R++;
            }
            
            prev = C[i];
        }
    }
    
    if (prev == 'B') {
        B++;
    }
    else {
        R++;
    }

    cout << 1 + min(B, R) << "\n";
    
    return 0;
}

