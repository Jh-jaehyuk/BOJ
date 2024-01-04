//
//  30972.cpp
//  BOJ
//
//  Created by J213h on 12/30/23.
//

#include <bits/stdc++.h>

using namespace std;

int board[5001][5001];
int prefix[5001][5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            prefix[i][j] = board[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    
    int Q;
    cin >> Q;
    
    for (int q = 0; q < Q; q++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        int val1 = prefix[r2 - 1][c2 - 1] - prefix[r2 - 1][c1] - prefix[r1][c2 - 1] + prefix[r1][c1];
        int val2 = prefix[r2][c2] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2] + prefix[r1 - 1][c1 - 1];
        
        cout << 2 * val1 - val2 << "\n";
    }
    
    return 0;
}
