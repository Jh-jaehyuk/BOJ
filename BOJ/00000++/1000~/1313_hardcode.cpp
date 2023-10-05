//
//  1313_hardcode.cpp
//  BOJ
//
//  Created by J213h on 2023/10/04.
//

#include <bits/stdc++.h>

using namespace std;

static int prime[10000001];
bool isPrime(int x);
bool Check(string s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i <= 10000000; i++) {
        if (isPrime(i)) {
            prime[i] = 1;
        }
    }
    
    for (int i = 100; i <= 10000000; i++) {
        if (!prime[i] && Check(to_string(i))) {
            cout << i << "\n";
        }
    }
    
    return 0;
}

bool isPrime(int x) {
    int sq = (int)sqrt(x);
    for (int i = 2; i <= sq; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    
    return true;
}

bool Check(string s) {
    int ss = (int)s.size();
    
    bool flag = false;
    for (int i = 2; i < ss; i++) {
        for (int j = 0; j <= ss - i; j++) {
            int tmp = stoi(s.substr(j, i));
            if (!prime[tmp]) {
                flag = true;
                break;
            }
        }
        
        if (flag) {
            break;
        }
    }
    
    if (!flag) {
        return true;
    }
    
    return false;
}
