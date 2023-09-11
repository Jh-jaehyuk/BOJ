//
//  29703.cpp
//  BOJ
//
//  Created by J213h on 2023/09/11.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M, sx, sy, hx, hy;
static char board[1002][1002];
static int visited_p[1002][1002];
static int visited_f[1002][1002];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };

void BFS_f(int x, int y);
void BFS_p(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            
            if (board[i][j] == 'H') {
                hx = i;
                hy = j;
            }
        }
    }
    
    fill(&visited_p[0][0], &visited_p[N - 1][M], -1);
    fill(&visited_f[0][0], &visited_f[N - 1][M], -1);
    
    BFS_f(sx, sy);
    BFS_p(hx, hy);
    
    int Min = 1e9;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'F' && visited_f[i][j] != -1 && visited_p[i][j] != -1) {
                int tmp = visited_f[i][j] + visited_p[i][j];
                Min = min(Min, tmp);
            }
        }
    }
    cout << (Min == 1e9 ? -1 : Min) << "\n";
    
    return 0;
}

void BFS_f(int x, int y) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(x, y));
    visited_f[x][y] = 0;
    
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            
            if (board[nx][ny] == 'D') {
                continue;
            }
            
            if (visited_f[nx][ny] != -1) {
                continue;
            }
            
            visited_f[nx][ny] = visited_f[x][y] + 1;
            myqueue.push(make_pair(nx, ny));
        }
    }
}

void BFS_p(int x, int y) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(x, y));
    visited_p[x][y] = 0;
    
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            
            if (board[nx][ny] == 'D') {
                continue;
            }
            
            if (visited_p[nx][ny] != -1) {
                continue;
            }
            
            visited_p[nx][ny] = visited_p[x][y] + 1;
            myqueue.push(make_pair(nx, ny));
        }
    }
}
