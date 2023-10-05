//
//  1313.cpp
//  BOJ
//
//  Created by J213h on 2023/10/04.
//

#include <bits/stdc++.h>

using namespace std;

static int precomputation[53] = { 111, 117, 119, 171, 231, 237, 297, 319, 371, 411, 413, 417, 437, 471, 473, 531, 537, 597, 611, 671, 679, 711, 713, 717, 731, 737, 831, 837, 897, 973, 979, 1131, 1137, 1311, 1313, 1317, 1379, 1797, 1971, 3113, 3131, 3173, 3179, 4197, 4311, 4313, 4317, 4797, 6137, 6179, 7197, 7971, 31373 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        if (x < 111) {
            cout << -1 << "\n";
        }
        
        else if (x >= 31373) {
            cout << 31373 << "\n";
        }
        
        else {
            for (int i = 1; i < 53; i++) {
                if (x < precomputation[i]) {
                    cout << precomputation[i - 1] << "\n";
                    break;
                }
            }
        }
    }
    
    return 0;
}
