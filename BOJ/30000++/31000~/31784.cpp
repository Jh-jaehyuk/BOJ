//
//  31784.cpp
//  BOJ
//
//  Created by J213h on 5/10/24.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    string s;
    cin >> N >> K >> s;

    int ss = (int)s.size();
    for (int i = 0; i < ss - 1; i++) {
        if (s[i] == 'A') {
            continue;
        }
        
        if (91 - s[i] <= K) {
            K -= (91 - s[i]);
            s[i] = 'A';
        }
    }
    
    for (int i = 0; i < K % 26; i++) {
        s[ss - 1] = (s[ss - 1] + 1);
        if (s[ss - 1] >= 91) {
            s[ss - 1] = 'A';
        }
    }
    cout << s << "\n";
    return 0;
}
