//
//  1584.cpp
//  BOJ
//
//  Created by J213h on 1/19/24.
//

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int N, M;
int board[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> myqueue;
int visited[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int _x1 = min(x1, x2);
        int _x2 = max(x1, x2);
        int _y1 = min(y1, y2);
        int _y2 = max(y1, y2);
        
        for (int x = _x1; x <= _x2; x++) {
            for (int y = _y1; y <= _y2; y++) {
                board[x][y] |= 1;
            }
        }
    }
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int _x1 = min(x1, x2);
        int _x2 = max(x1, x2);
        int _y1 = min(y1, y2);
        int _y2 = max(y1, y2);
        
        for (int x = _x1; x <= _x2; x++) {
            for (int y = _y1; y <= _y2; y++) {
                board[x][y] |= -1;
            }
        }
    }
    
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            visited[i][j] = INF;
        }
    }
    
    myqueue.push(make_pair(0, 0));
    visited[0][0] = 0;
    
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > 500 || ny < 0 || ny > 500) {
                continue;
            }
            
            if (board[nx][ny] == -1) {
                continue;
            }
            

            if (visited[nx][ny] <= visited[x][y] + board[nx][ny]) {
                continue;
            }

            visited[nx][ny] = visited[x][y] + board[nx][ny];
            myqueue.push(make_pair(nx, ny));
        }
    }
    
    cout << (visited[500][500] == INF ? -1 : visited[500][500]) << "\n";
    
    return 0;
}
