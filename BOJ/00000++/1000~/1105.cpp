//
//  1105.cpp
//  BOJ
//
//  Created by J213h on 4/22/24.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string L, R;
    cin >> L >> R;
    
    if (L.size() != R.size()) {
        cout << 0 << "\n";
    }
    else {
        int result = 0;
        for (int i = 0; i < L.size(); i++) {
            if (L[i] == R[i]) {
                if (L[i] == '8') {
                    result++;
                }
            }
            else {
                break;
            }
        }
        cout << result << "\n";
    }
    
    return 0;
}

