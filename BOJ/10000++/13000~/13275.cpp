//
//  13275.cpp
//  BOJ
//
//  Created by J213h on 2023/09/19.
//

#include <bits/stdc++.h>

using namespace std;

static int A[100001 * 2];
static string s = "", tmp;

void manachers(string s, int N);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> tmp;
    
    int l = (int)tmp.size();
    
    for (int i = 0; i < l; i++) {
        s += '#';
        s += tmp[i];
    }
    
    s += '#';
    
    manachers(s, (int)s.size());
    
    l = (int)s.size();
    int result = -1;
    
    for (int i = 0; i < l; i++) {
        result = max(result, A[i]);
    }
    
    cout << result << "\n";
    
    return 0;
}

void manachers(string s, int N) {
    int r = 0;
    int p = 0;
    
    for (int i = 0; i < N; i++) {
        if (i <= r) {
            A[i] = min(A[2 * p - i], r - i);
        }
        
        else {
            A[i] = 0;
        }
        
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && s[i - A[i] - 1] == s[i + A[i] + 1]) {
            A[i]++;
        }
        
        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}
