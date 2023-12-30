//
//  31000.cpp
//  BOJ
//
//  Created by J213h on 12/27/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    

    int result = (N * 2 + 1) * (N * 2 + 1);
    
    for (int a = -N; a <= N; a++) {
        if (a == 0) {
            continue;
        }
        
        if (a < 0) {
            result += N + (N + a);
        }
        
        else {
            result += N + (N - a + 2);
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
