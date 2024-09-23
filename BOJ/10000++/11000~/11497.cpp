//
//  11497.cpp
//  BOJ
//
//  Created by J213h on 9/23/24.
//

#include <bits/stdc++.h>

using namespace std;

int A[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A, A + N);
        int ans = 0;
        for (int i = 0; i < N - 2; i += 2) {
            ans = max(ans, A[i + 2] - A[i]);
        }
        for (int i = 1; i < N - 2; i += 2) {
            ans = max(ans, A[i + 2] - A[i]);
        }
        cout << ans << '\n';
    }

    
    return 0;
}
