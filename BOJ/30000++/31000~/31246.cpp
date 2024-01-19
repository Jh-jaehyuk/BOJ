//
//  31246.cpp
//  BOJ
//
//  Created by J213h on 1/15/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        
        if (A >= B) {
            count++;
        }
        
        else {
            X.push_back(B - A);
        }
    }
    
    if (count >= K) {
        cout << 0 << "\n";
    }
    
    else {
        sort(X.begin(), X.end());
        cout << X[K - count - 1] << "\n";
    }
    
    return 0;
}
