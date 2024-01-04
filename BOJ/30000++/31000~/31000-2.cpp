//
//  31000-2.cpp
//  BOJ
//
//  Created by J213h on 12/30/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int result = (2 * N + 1) * (2 * N + 1);
    
    for (int i = -N; i <= N; i++) {
        if (i == 0) {
            continue;
        }
        
        for (int j = -N; j <= N; j++) {
            if (1 - i - j >= -N && 1 - i - j <= N) {
                result++;
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}
