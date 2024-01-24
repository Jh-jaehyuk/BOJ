//
//  26007.cpp
//  BOJ
//
//  Created by J213h on 1/24/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, K, X;
int A[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K >> X;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        X += num;
        
        A[i] = A[i - 1];
        if (X < K) {
            A[i]++;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        cout << A[r - 1] - A[l - 1] << "\n";
    }
    
    return 0;
}

