//
//  16933.cpp
//  BOJ
//
//  Created by J213h on 10/19/23.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, c, w;
};

static int board[1001][1001];
static int visited[1001][1001][11];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static queue<Node> myqueue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char tmp;
            cin >> tmp;
            board[i][j] = tmp - '0';
        }
    }
    
    fill(&visited[0][0][0], &visited[1000][1000][11], 0);
    visited[0][0][0] = 1;
    myqueue.push({ 0, 0, 1, 0 });
    
    while (!myqueue.empty()) {
        int x = myqueue.front().x;
        int y = myqueue.front().y;
        int now = myqueue.front().c;
        int wall = myqueue.front().w;
        myqueue.pop();
        
        if (x == N - 1 && y == M - 1) {
            cout << now << "\n";
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next = now + 1;
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            
            if (board[nx][ny]) {
                if (wall == K) {
                    continue;
                }
                
                if (visited[nx][ny][wall + 1]) {
                    continue;
                }
                
                if (now % 2 == 1) {
                    visited[nx][ny][wall + 1] = 1;
                    myqueue.push({ nx, ny, now + 1, wall + 1 });
                }
                
                else {
                    myqueue.push({ x, y, now + 1, wall });
                }
            }
            
            else {
                if (visited[nx][ny][wall]) {
                    continue;
                }
                
                visited[nx][ny][wall] = 1;
                myqueue.push({ nx, ny, now + 1, wall });
            }
        }
    }
    
    cout << -1 << "\n";
    
    return 0;
}
