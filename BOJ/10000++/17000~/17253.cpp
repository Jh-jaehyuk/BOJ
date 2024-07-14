//
//  17253.cpp
//  BOJ
//
//  Created by J213h on 7/14/24.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    cin >> N;
    
    if (!N) {
        cout << "NO" << "\n";
        return 0;
    }
    
    string res = "";
    
    while (N) {
        int mod = N % 3;
        res += to_string(mod);
        N /= 3;
    }
    
    cout << res << "\n";
    int rs = (int)res.size();
    for (int i = 0; i < rs; i++) {
        if (res[i] - '0' > 1) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    
    return 0;
}

