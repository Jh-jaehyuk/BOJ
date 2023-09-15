//
//  6359.cpp
//  BOJ
//
//  Created by J213h on 2023/09/15.
//

#include <bits/stdc++.h>

using namespace std;

static bool A[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        fill(A, A + 101, true);
        
        for (int i = 2; i <= N; i++) {
            for (int j = i; j <= N; j += i) {
                if (A[j]) {
                    A[j] = false;
                }
                else {
                    A[j] = true;
                }
            }
        }
        
        int result = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i]) {
                result++;
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
