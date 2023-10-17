//
//  2999.cpp
//  BOJ
//
//  Created by J213h on 10/17/23.
//

#include <bits/stdc++.h>

using namespace std;

static char A[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int ss = (int)s.size();
    
    int r = -1;
    int c = -1;
    for (int i = 1; i < ss; i++) {
        if (ss % i == 0) {
            int j = ss / i;
            
            if (i > j) {
                break;
            }
            
            r = i;
            c = j;
        }
    }
    
    int idx = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            A[i][j] = s[idx++];
        }
    }
    
    string result = "";
    for (int j = 0; j < r; j++) {
        for (int i = 0; i < c; i++) {
            result += A[i][j];
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
