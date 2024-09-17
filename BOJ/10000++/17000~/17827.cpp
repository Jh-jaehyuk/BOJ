//
//  17827.cpp
//  BOJ
//
//  Created by J213h on 9/18/24.
//

#include <bits/stdc++.h>

using namespace std;

int A[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, V;
    cin >> N >> M >> V;
    
    V--;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        
        if (K < N) {
            cout << A[K] << "\n";
        }
        else {
            cout << A[V + ((K - V) % (N - V))] << "\n";
        }
    }

    return 0;
}
