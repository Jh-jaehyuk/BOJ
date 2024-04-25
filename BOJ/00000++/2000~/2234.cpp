//
//  2234.cpp
//  BOJ
//
//  Created by J213h on 4/18/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, Max, Cnt, Max2;
int board[51][51];
int area[51][51];
int vis[51][51];
int ar[251];
int dir[4] = { 1 << 0, 1 << 1, 1 << 2, 1 << 3};
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int BFS(int x, int y, int idx) {
    vis[x][y] = 1;
    area[x][y] = idx;
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            if (board[x][y] & dir[i]) {
                continue;
            }
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (vis[nx][ny]) {
                continue;
            }
            
            vis[nx][ny] = 1;
            area[nx][ny] = idx;
            cnt++;
            q.push(make_pair(nx, ny));
        }
    }
    
    ar[idx] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j]) {
                Cnt++;
                Max = max(Max, BFS(i, j, idx++));
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                
                if (area[i][j] == area[nx][ny]) {
                    continue;
                }
                
                Max2 = max(Max2, ar[area[i][j]] + ar[area[nx][ny]]);
            }
        }
    }
    cout << Cnt << "\n" << Max << "\n" << Max2 << "\n";

    return 0;
}

