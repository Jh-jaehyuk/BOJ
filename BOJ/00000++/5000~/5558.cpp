//
//  5558.cpp
//  BOJ
//
//  Created by J213h on 4/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int R, C, N, result = 0, S = 1;
int sx, sy;
char board[1005][1005];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS(int x, int y, int s) {
    int temp = 0;
    int vis[1005][1005];
    fill_n(&vis[0][0], 1005 * 1005, -1);
    vis[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (board[x][y] - '0' == s) {
            temp = vis[x][y];
            S++;
            sx = x;
            sy = y;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                continue;
            }
            
            if (vis[nx][ny] != -1) {
                continue;
            }
            
            if (board[nx][ny] == 'X') {
                continue;
            }
            
            vis[nx][ny] = vis[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    
    while (S <= N) {
        result += BFS(sx, sy, S);
    }
    cout << result << "\n";

    return 0;
}

