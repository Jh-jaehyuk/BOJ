//
//  11441.cpp
//  BOJ
//
//  Created by J213h on 1/27/24.
//

#include <bits/stdc++.h>

using namespace std;

int A[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        cout << A[r] - A[l - 1] << "\n";
    }

    return 0;
}

