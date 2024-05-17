//
//  11401.cpp
//  BOJ
//
//  Created by J213h on 5/13/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long npow(long long a, long long b) {
    long long result = 1;
    while (b) {
        if (b % 2) {
            result *= a;
            result %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, R;
    cin >> N >> R;
    
    long long ans = 1;
    long long a = 1;
    long long b = 1;
    
    for (long long i = 1; i <= N; i++) {
        a *= i;
        a %= MOD;
    }
    
    for (long long i = 1; i <= R; i++) {
        b *= i;
        b %= MOD;
    }
    
    for (long long i = 1; i <= N - R; i++) {
        b *= i;
        b %= MOD;
    }
    
    long long c = npow(b, MOD - 2);
    c %= MOD;
    ans = a * c;
    ans %= MOD;
    cout << ans << "\n";
    
    return 0;
}

