//
//  17141.cpp
//  BOJ
//
//  Created by J213h on 2023/10/04.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static int board[51][51];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static int visited[51][51];
static vector<pair<int, int>> virus;
static bool check[10];
static int result = (int)1e9;

void DFS(int idx, int count);
void BFS(queue<pair<int, int>> Q);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }
    
    DFS(0, 0);
    cout << (result == (int)1e9 ? -1 : result) << "\n";
    
    return 0;
}

void DFS(int idx, int count) {
    if (count == M) {
        fill(&visited[0][0], &visited[50][51], -1);
        queue<pair<int, int>> myqueue;
        
        for (int i = 0; i < virus.size(); i++) {
            if (check[i]) {
                visited[virus[i].first][virus[i].second] = 0;
                myqueue.push(make_pair(virus[i].first, virus[i].second));
            }
        }
        BFS(myqueue);
        return;
    }
    
    for (int i = idx; i < virus.size(); i++) {
        if (check[i]) {
            continue;
        }
        
        check[i] = true;
        DFS(i, count + 1);
        check[i] = false;
    }
}

void BFS(queue<pair<int, int>> Q) {
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            
            if (board[nx][ny] == 1) {
                continue;
            }
            
            if (visited[nx][ny] != -1) {
                continue;
            }
            
            visited[nx][ny] = visited[x][y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    
    int Max = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 1) {
                if (visited[i][j] != -1) {
                    Max = max(Max, visited[i][j]);
                }
                else {
                    return;
                }
            }
        }
    }
    
    result = min(result, Max);
}
