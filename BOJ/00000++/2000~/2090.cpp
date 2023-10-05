//
//  2090.cpp
//  BOJ
//
//  Created by J213h on 2023/10/05.
//

#include <bits/stdc++.h>

using namespace std;

static int A[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    if (N == 1) {
        int x;
        cin >> x;
        cout << x << '/' << 1 << "\n";
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    long long g = gcd(A[0], A[1]);
    long long l = (A[0] * A[1]) / g;
    
    for (int i = 2; i < N; i++) {
        g = gcd(l, 1LL * A[i]);
        l = (l * (1LL * A[i])) / g;
    }
    
    long long x = 0;
    
    for (int i = 0; i < N; i++) {
        x += l / gcd(l, 1LL * A[i]);
    }
    
    cout << l / gcd(l, x) << '/' << x / gcd(l, x) << "\n";
    
    return 0;
}
