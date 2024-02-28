//
//  10211.cpp
//  BOJ
//
//  Created by J213h on 2/28/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> V;

void solve(int N) {
    V.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
        V[i] += V[i - 1];
    }
    
    int Max = -1e9;
    for (int i = N; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            Max = max(Max, V[i] - V[j]);
        }
    }
    
    cout << Max << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        solve(N);
    }

    return 0;
}
