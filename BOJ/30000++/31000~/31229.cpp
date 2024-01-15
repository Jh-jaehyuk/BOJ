//
//  31229.cpp
//  BOJ
//
//  Created by J213h on 1/15/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> prime;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 2; i < 1000001; i++) {
        bool flag = false;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        
        if (prime.size() >= N) {
            break;
        }
        
        if (!flag) {
            prime.push_back(i);
        }
    }
    
    for (int i = 0; i < N - 1; i++) {
        cout << prime[i] << " ";
    }
    cout << prime[N - 1] << "\n";
    
    return 0;
}
