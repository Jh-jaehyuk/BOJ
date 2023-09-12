//
//  29733.cpp
//  BOJ
//
//  Created by 한재혁 on 2023/09/11.
//

#include <bits/stdc++.h>

using namespace std;

static int R, C, H;
static char board[102][102][102];
static int result[102][102][102];

static int dx[26] = { -1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1 };
static int dy[26] = { -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
static int dz[26] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int Check(int x, int y, int z);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> C >> H;
    
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> board[k][i][j];
            }
        }
    }
    
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[k][i][j] != '*') {
                    result[k][i][j] = Check(i, j, k);
                }

                else {
                    result[k][i][j] = 10;
                }
            }
        }
    }
    
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (result[k][i][j] > 9) {
                    cout << '*';
                }
                
                else {
                    cout << result[k][i][j];
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}

int Check(int x, int y, int z) {
    int count = 0;
    
    for (int d = 0; d < 26; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nz = z + dz[d];
        
        if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= H) {
            continue;
        }
        
        if (board[nz][nx][ny] == '*') {
            count++;
        }
    }
    
    return count % 10;
}
