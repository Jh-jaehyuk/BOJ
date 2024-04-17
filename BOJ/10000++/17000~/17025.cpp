//
//  17025.cpp
//  BOJ
//
//  Created by J213h on 4/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, A = 0, P = 0;
char board[1005][1005];
int vis[1001][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS(int x, int y) {
    int a = 1, p = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                p++;
                continue;
            }
            
            if (vis[nx][ny]) {
                continue;
            }
            
            if (board[nx][ny] == '.') {
                p++;
                continue;
            }
            
            vis[nx][ny] = 1;
            a++;
            q.push(make_pair(nx, ny));
        }
    }
    
    if (A < a) {
        A = a;
        P = p;
    }
    
    else if (A == a) {
        P = min(P, p);
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '#' && !vis[i][j]) {
                BFS(i, j);
            }
        }
    }
    cout << A << " " << P << "\n";

    return 0;
}

