//
//  4149.cpp
//  BOJ
//
//  Created by J213h on 10/19/23.
//

#include <bits/stdc++.h>

using namespace std;

void factorize(long long n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    cin >> N;
    
    factorize(N);
    
    return 0;
}

void factorize(long long n) {
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            cout << 2 << "\n";
        }
    }
    
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        
        if (count > 0) {
            for (int j = 0; j < count; j++) {
                cout << i << "\n";
            }
        }
    }
    
    if (n > 2) {
        cout << n << "\n";
    }
}
