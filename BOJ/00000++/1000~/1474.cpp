//
//  1474.cpp
//  BOJ
//
//  Created by J213h on 4/25/24.
//

#include <bits/stdc++.h>

using namespace std;

string S[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    int len = 0;
    for (int i = 0; i < 2 * N - 1; i += 2) {
        cin >> S[i];
        len += (int)S[i].size();
    }
    
    int div = (M - len) / (N - 1);
    int mod = (M - len) % (N - 1);
    
    for (int i = 1; i < 2 * N - 1; i += 2) {
        for (int j = 0; j < div; j++) {
            S[i] += '_';
        }
    }
    
    for (int i = 1; i < N; i++) {
        if (mod == 0) {
            break;
        }
        if (S[2 * i][0] >= 'a' && S[2 * i][0] <= 'z') {
            mod--;
            S[2 * i - 1] += '_';
        }
    }
    
    for (int i = N - 1; i > 0; i--) {
        if (mod == 0) {
            break;
        }
        if (S[2 * i][0] >= 'A' && S[2 * i][0] <= 'Z') {
            mod--;
            S[2 * i - 1] += '_';
        }
    }
    
    for (string s: S) {
        cout << s;
    }
    cout << "\n";

    return 0;
}

