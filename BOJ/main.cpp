//
//  main.cpp
//  BOJ
//
//  Created by 한재혁 on 2023/09/11.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N, M, K;
        cin >> N >> M >> K;
        
        if (M * K == 1) {
            if (N == 1) {
                cout << 1 << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        
        else {
            int result = 0;
            while (true) {
                N -= M * K;
                result++;
                
                if (N <= 0) {
                    break;
                }
                
                N++;
                result++;
            }
            cout << result << "\n";
        }
    }
    
    return 0;
}
