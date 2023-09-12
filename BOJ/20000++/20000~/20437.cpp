//
//  20437.cpp
//  BOJ
//
//  Created by J213h on 2023/09/12.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> alpha[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        string W;
        int K;
        cin >> W >> K;
        
        for (int i = 0; i < 26; i++) {
            alpha[i].clear();
        }
        
        int result3 = 10001;
        int result4 = -1;
        
        int l = (int)W.length();
        
        for (int i = 0; i < l; i++) {
            alpha[W[i] - 'a'].push_back(i);
        }
        
        for (int i = 0; i < 26; i++) {
            int vl = (int)alpha[i].size() - K;
            
            if (vl < 0) {
                continue;
            }
            
            for (int j = 0; j <= vl; j++) {
                result3 = min(result3, alpha[i][j + K - 1] - alpha[i][j] + 1);
                result4 = max(result4, alpha[i][j + K - 1] - alpha[i][j] + 1);
            }
        }
        
        if (result3 == 10001 || result4 == -1) {
            cout << -1 << "\n";
        }
        
        else {
            cout << result3 << " " << result4 << "\n";
        }
    }
    
    return 0;
}
