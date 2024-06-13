//
//  31946.cpp
//  BOJ
//
//  Created by J213h on 6/13/24.
//

#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int vis[101][101];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, X;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    cin >> X;
    
    int flag = board[0][0];
    q.push(make_pair(0, 0));
    vis[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = -X; i <= X; i++) {
            for (int j = -X; j <= X; j++) {
                if (abs(i) + abs(j) > X) {
                    continue;
                }
                
                int nx = x + i;
                int ny = y + j;
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                
                if (vis[nx][ny]) {
                    continue;
                }
                
                if (board[nx][ny] != flag) {
                    continue;
                }
                
                vis[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << (vis[N - 1][M - 1] ? "ALIVE" : "DEAD") << "\n";
    
    return 0;
}

