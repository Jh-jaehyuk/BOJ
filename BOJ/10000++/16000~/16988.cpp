//
//  16988.cpp
//  BOJ
//
//  Created by J213h on 10/11/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static int board[21][21];
static int visited[21][21];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static int result = 0;

int BFS(int x, int y);
void Solve(int idx, int depth);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    Solve(0, 0);
    
    cout << result << "\n";
    
    return 0;
}

void Check() {
    fill(&visited[0][0], &visited[20][21], 0);
    int tmp = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2 && !visited[i][j]) {
                tmp += BFS(i, j);
            }
        }
    }
    
    result = max(result, tmp);
    return;
}

int BFS(int x, int y) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(x, y));
    visited[x][y] = 1;
    int count = 1;
    bool flag = false;
    
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
            
            if (visited[nx][ny]) {
                continue;
            }
            
            if (board[nx][ny] == 1) {
                continue;
            }
            
            if (board[nx][ny] == 0) {
                flag = true;
            }
            
            if (board[nx][ny] == 2) {
                visited[nx][ny] = 1;
                myqueue.push(make_pair(nx, ny));
                count++;
            }
        }
    }
    
    if (!flag) {
        return count;
    }
    
    return 0;
}

void Solve(int idx, int depth) {
    if (depth == 2) {
        Check();
        return;
    }
    
    for (int i = idx; i < N * M; i++) {
        int x = i / M;
        int y = i % M;
        
        if (board[x][y] != 0) {
            continue;
        }
        
        board[x][y] = 1;
        Solve(i, depth + 1);
        board[x][y] = 0;
    }
}
