//
//  14442.cpp
//  BOJ
//
//  Created by J213h on 2023/09/16.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, count;
};

static int N, M, K;
static int board[1001][1001];
static int visited[1001][1001][11];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };

void BFS();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '0') {
                board[i][j] = 0;
            }
            else {
                board[i][j] = 1;
            }
        }
    }
    
    fill(&visited[0][0][0], &visited[1000][1000][11], 0);
    
    BFS();

    return 0;
}

void BFS() {
    queue<Node> myqueue;
    visited[0][0][0] = 1;
    myqueue.push({ 0, 0, 0 });
    
    while (!myqueue.empty()) {
        int x = myqueue.front().x;
        int y = myqueue.front().y;
        int c = myqueue.front().count;
        myqueue.pop();
        
        if (x == N - 1 && y == M - 1) {
            cout << visited[x][y][c] << "\n";
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            
            if (visited[nx][ny][c]) {
                continue;
            }
            
            if (board[nx][ny] == 0) {
                visited[nx][ny][c] = visited[x][y][c] + 1;
                myqueue.push({ nx, ny, c });
            }
            
            else {
                if (c < K && !visited[nx][ny][c + 1]) {
                    visited[nx][ny][c + 1] = visited[x][y][c] + 1;
                    myqueue.push({ nx, ny, c + 1 });
                }
            }
        }
    }
    
    cout << -1 << "\n";
    return;
}
