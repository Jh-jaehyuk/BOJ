//
//  31216.cpp
//  BOJ
//
//  Created by J213h on 1/9/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
vector<int> super_prime;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 2; i < 1000001; i++) {
        bool flag = false;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        
        if (!flag) {
            prime.push_back(i);
        }
    }
    
    int count = 0;
    for (int i: prime) {
        super_prime.push_back(prime[i - 1]);
        
        if (++count == 3000) {
            break;
        }
    }

    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        cout << super_prime[n - 1] << "\n";
    }
    
    return 0;
}
