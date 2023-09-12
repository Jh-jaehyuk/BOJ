//
//  1245.cpp
//  BOJ
//
//  Created by J213h on 2023/09/12.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static int board[101][71];
static bool visited[101][71];
static int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
static int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
static bool flag;

void BFS(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    fill(&visited[0][0], &visited[100][71], false);
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && board[i][j] != 0) {
                flag = false;
                BFS(i, j);
                
                if (!flag) {
                    result++;
                }
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}

void BFS(int x, int y) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(x, y));
    visited[x][y] = true;
    
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }
            
            if (board[nx][ny] > board[x][y]) {
                flag = true;
            }
            
            if (visited[nx][ny] || board[nx][ny] != board[x][y]) {
                continue;
            }
            
            visited[nx][ny] = true;
            myqueue.push(make_pair(nx, ny));
        }
    }
}
