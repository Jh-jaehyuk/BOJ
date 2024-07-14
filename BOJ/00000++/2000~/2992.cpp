//
//  2992.cpp
//  BOJ
//
//  Created by J213h on 7/14/24.
//

#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int X;
    cin >> X;
    
    string sx = to_string(X);
    int ss = (int)sx.size();
    for (int i = 0; i < ss; i++) {
        cnt[sx[i] - '0']++;
    }
    
    int ans = 1e6;
    int Max = pow(10, ss);
    
    for (int i = X + 1; i < Max; i++) {
        string si = to_string(i);
        int temp[10];
        int flag = 0;
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < ss; j++) {
            temp[si[j] - '0']++;
        }
        for (int j = 0; j < 10; j++) {
            if (temp[j] != cnt[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    
    return 0;
}

