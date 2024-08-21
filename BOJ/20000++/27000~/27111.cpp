//
//  27111.cpp
//  BOJ
//
//  Created by J213h on 8/21/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
int A[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        
        if (A[a] != b) {
            A[a] = b;
        }
        else {
            ans++;
        }
    }
    for (int i = 1; i <= 200000; i++) {
        if (A[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}

