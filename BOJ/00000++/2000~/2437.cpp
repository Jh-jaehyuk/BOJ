//
//  2437.cpp
//  BOJ
//
//  Created by J213h on 5/31/24.
//

#include <bits/stdc++.h>

using namespace std;

int A[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A + N);
    
    int total = 1;
    for (int i = 0; i < N; i++) {
        if (total < A[i]) {
            break;
        }
        total += A[i];
    }
    cout << total << "\n";

    return 0;
}

