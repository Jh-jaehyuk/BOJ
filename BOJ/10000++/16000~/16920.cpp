//
//  16920.cpp
//  BOJ
//
//  Created by J213h on 10/19/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M, P;
static char board[1001][1001];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static vector<queue<pair<int, int>>> V;
static int S[10];
static int result[10];

void BFS(queue<pair<int, int>>& Q);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> P;
    
    V.resize(P + 1);
    
    for (int i = 1; i <= P; i++) {
        cin >> S[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == '.' || board[i][j] == '#') {
                continue;
            }
            
            V[board[i][j] - '0'].push(make_pair(i, j));
        }
    }
    
    while (true) {
        for (int i = 1; i <= P; i++) {
            if (V[i].empty()) {
                continue;
            }
            BFS(V[i]);
        }
        
        int count = 0;
        for (int i = 1; i <= P; i++) {
            if (!V[i].empty()) {
                count++;
                break;
            }
        }
        
        if (count == 0) {
            break;
        }
    }
    
    fill(result, result + 10, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '.' || board[i][j] == '#') {
                continue;
            }
            result[board[i][j] - '0']++;
        }
    }
    
    for (int i = 1; i <= P; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}

void BFS(queue<pair<int, int>>& Q) {
    int now = board[Q.front().first][Q.front().second] - '0';
    
    for (int j = 0; j < S[now]; j++) {
        int qs = (int)Q.size();
        
        if (qs == 0) {
            return;
        }
        
        for (int i = 0; i < qs; i++) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                
                if (board[nx][ny] != '.') {
                    continue;
                }
                
                board[nx][ny] = board[x][y];
                Q.push(make_pair(nx, ny));
            }
        }
    }
}
