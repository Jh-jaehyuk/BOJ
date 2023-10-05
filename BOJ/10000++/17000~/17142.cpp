//
//  17142.cpp
//  BOJ
//
//  Created by J213h on 2023/10/05.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static int board[51][51];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static int check[10];
static vector<pair<int, int>> virus;
static int visited[51][51];
static int result = (int)1e9;

void DFS(int idx, int count);
void BFS(queue<pair<int, int>> myqueue);

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
                myqueue.push(make_pair(virus[i].first, virus[i].second));
                visited[virus[i].first][virus[i].second] = 0;
            }
        }
        
        BFS(myqueue);
        return;
    }
    
    for (int i = idx; i < virus.size(); i++) {
        if (check[i]) {
            continue;
        }
        
        check[i] = 1;
        DFS(i, count + 1);
        check[i] = 0;
    }
}

void BFS(queue<pair<int, int>> myqueue) {
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
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
            myqueue.push(make_pair(nx, ny));
        }
    }
    
    int Max = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                if (visited[i][j] != -1) {
                    Max = max(Max, visited[i][j]);
                }
                
                else {
                    return;
                }
            }
        }
    }
    if (Max == -1) {
        Max = 0;
    }

    result = min(result, Max);
}
