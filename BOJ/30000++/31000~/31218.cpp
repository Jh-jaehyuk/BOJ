//
//  31218.cpp
//  BOJ
//
//  Created by J213h on 1/9/24.
//

#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int result = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    
    result = N * M;
    
    for (int q = 0; q < Q; q++) {
        int num;
        cin >> num;
        
        if (num == 1) {
            int dy, dx, y, x;
            cin >> dy >> dx >> y >> x;
            
            if (board[x][y]) {
                continue;
            }
            
            int nx = x;
            int ny = y;
            while (!board[nx][ny]) {
                board[nx][ny] = 1;
                result--;
                
                nx += dx;
                ny += dy;
                
                if (nx < 1 || nx > N || ny < 1 || ny > M) {
                    break;
                }
            }
        }
        
        else if (num == 2) {
            int y, x;
            cin >> y >> x;
            
            cout << board[x][y] << "\n";
        }
        
        else {
            cout << result << "\n";
        }
    }
    
    return 0;
}
