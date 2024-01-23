//
//  18405.cpp
//  BOJ
//
//  Created by J213h on 1/23/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, K, S, X, Y;
int board[201][201];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<queue<pair<int, int>>> V;

void Spread(int idx) {
    if (V[idx].empty()) {
        return;
    }
    
    int num = (int)V[idx].size();
    
    for (int k = 0; k < num; k++) {
        int x = V[idx].front().first;
        int y = V[idx].front().second;
        V[idx].pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            
            if (board[nx][ny]) {
                continue;
            }
            
            board[nx][ny] = idx;
            V[idx].push(make_pair(nx, ny));
        }
    }
    
    return;
}

void Solve() {
    for (int i = 1; i <= K; i++) {
        Spread(i);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    V.resize(K + 1);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            
            if (!board[i][j]) {
                continue;
            }
            
            V[board[i][j]].push(make_pair(i, j));
        }
    }
    
    int time = 0;
    cin >> S >> X >> Y;
    
    while (time++ < S) {
        Solve();
    }
    cout << board[X - 1][Y - 1] << "\n";

    return 0;
}

