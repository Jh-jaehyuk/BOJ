//
//  31827.cpp
//  BOJ
//
//  Created by J213h on 5/16/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    for (int i = 2; i < 1000001; i++) {
        int flag = 0;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            primes.push_back(i);
        }
    }
    
    int cnt = 0;
    for (int i: primes) {
        if (i % K == 1) {
            cout << i << " ";
            if (++cnt == N) {
                break;
            }
        }
    }
    
    return 0;
}

