//
//  1941.cpp
//  BOJ
//
//  Created by J213h on 2023/09/23.
//

#include <bits/stdc++.h>

using namespace std;

static int result = 0;
static char board[6][6];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static bool visited[25];

bool check();
bool BFS(int idx);
void Solve(int idx, int depth);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    
    fill(visited, visited + 25, false);
    Solve(0, 0);
    cout << result << "\n";
    
    return 0;
}

bool check() {
    int count = 0;
    
    for (int i = 0; i < 25; i++) {
        if (visited[i]) {
            int x = i / 5;
            int y = i % 5;
            
            if (board[x][y] == 'S') {
                count++;
            }
        }
    }
    
    if (count >= 4) {
        return true;
    }
    
    return false;
}

bool BFS(int idx) {
    bool A[6][6];
    fill(&A[0][0], &A[5][6], false);
    
    int x = idx / 5;
    int y = idx % 5;
    A[x][y] = true;

    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(x, y));
    
    int s = 1;
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) {
                continue;
            }
            
            if (A[nx][ny]) {
                continue;
            }
            
            if (visited[nx * 5 + ny]) {
                s++;
                A[nx][ny] = true;
                myqueue.push(make_pair(nx, ny));
            }
        }
    }
    
    if (s == 7) {
        return true;
    }
    
    return false;
}


void Solve(int idx, int depth) {
    if (depth == 7 && BFS(idx) && check()) {
        result++;
        return;
    }
    
    for (int i = idx; i < 25; i++) {
        if (visited[i]) {
            continue;
        }
        
        visited[i] = true;
        Solve(i, depth + 1);
        visited[i] = false;
    }
}
