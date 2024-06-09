//
//  16496.cpp
//  BOJ
//
//  Created by J213h on 6/9/24.
//

#include <bits/stdc++.h>

using namespace std;

string S[1001];

bool cmp(string& i, string& j) {
    return i + j > j + i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    sort(S, S + N, cmp);
    if (S[0] == "0") {
        cout << 0 << "\n";
    }
    
    else {
        for (int i = 0; i < N; i++) {
            cout << S[i];
        }
        cout << "\n";
    }

    return 0;
}

