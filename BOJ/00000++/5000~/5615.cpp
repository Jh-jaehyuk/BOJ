//
//  5615.cpp
//  BOJ
//
//  Created by J213h on 10/19/23.
//

#include <bits/stdc++.h>

using namespace std;

static unsigned long long MR[3] = { 2, 7, 61 };

unsigned long long npow(unsigned long long a, unsigned long long b, unsigned long long mod);
bool Miller_Rabin(unsigned long long x, unsigned long long a);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int result = N;
    for (int i = 0; i < N; i++) {
        unsigned long long x;
        cin >> x;
        x = x * 2 + 1;
        
        for (int j = 0; j < 3; j++) {
            if (!Miller_Rabin(x, MR[j])) {
                result--;
                break;
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

unsigned long long npow(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long tmp = 1;
    a %= mod;
    
    while (b > 0) {
        if (b % 2 != 0) {
            tmp = (tmp * a) % mod;
        }
        b /= 2;
        a = (a * a) % mod;
    }
    
    return tmp;
}

bool Miller_Rabin(unsigned long long x, unsigned long long a) {
    if (a % x == 0) {
        return true;
    }
    
    unsigned long long k = x - 1;
    while (true) {
        unsigned long long ak = npow(a, k, x);
        
        if (ak == x - 1) {
            return true;
        }
        
        if (k % 2 != 0) {
            if (ak == 1 || ak == x - 1) {
                return true;
            }
            
            else {
                return false;
            }
        }
        
        k /= 2;
    }
}
