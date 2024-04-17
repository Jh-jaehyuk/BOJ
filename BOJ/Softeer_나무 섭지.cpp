//
//  Softeer_나무 섭지.cpp
//  BOJ
//
//  Created by J213h on 3/12/24.
//

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int N, M;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char board[1005][1005];
int N_vis[1001][1001];
int G_vis[1001][1001];

int nx, ny, ex, ey;
vector<pair<int, int>> Ghost;

void Solve() {
    queue<pair<int, int>> nq, gq;
    
    nq.push(make_pair(nx, ny));
    N_vis[nx][ny] = 0;
    for (pair<int, int> i: Ghost) {
        gq.push(i);
        G_vis[i.first][i.second] = 0;
    }
    
    while (!gq.empty()) {
        int x = gq.front().first;
        int y = gq.front().second;
        gq.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            
            if (G_vis[nx][ny] != INF) {
                continue;
            }
            
            G_vis[nx][ny] = G_vis[x][y] + 1;
            gq.push(make_pair(nx, ny));
        }
    }
    
    int flag = 0;
    while (!nq.empty()) {
        int x = nq.front().first;
        int y = nq.front().second;
        nq.pop();
        
        if (x == ex && y == ey) {
            flag = 1;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            
            if (board[nx][ny] == '#') {
                continue;
            }
            
            if (N_vis[nx][ny] != INF) {
                continue;
            }
            
            if (G_vis[nx][ny] <= N_vis[x][y] + 1) {
                continue;
            }
            
            N_vis[nx][ny] = N_vis[x][y] + 1;
            nq.push(make_pair(nx, ny));
        }
    }
    
    if (flag) {
        cout << "Yes" << "\n";
    }
    
    else {
        cout << "No" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            N_vis[i][j] = INF;
            G_vis[i][j] = INF;
            
            if (board[i][j] == 'D') {
                ex = i;
                ey = j;
            }
            
            else if (board[i][j] == 'N') {
                nx = i;
                ny = j;
            }
            
            else if (board[i][j] == 'G') {
                Ghost.push_back(make_pair(i, j));
            }
        }
    }
    
    Solve();
    
    return 0;
}

