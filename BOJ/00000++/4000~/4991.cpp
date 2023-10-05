//
//  4991.cpp
//  BOJ
//
//  Created by J213h on 2023/10/05.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static char board[21][21];
static vector<pair<int, int>> V;
static int visited[21][21][21][21];

static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static int result;

void Solve();
void Swap(pair<int, int>& a, pair<int, int>& b);
void DFS(vector<pair<int, int>>& A, int depth, int count);
void BFS(int sx, int sy);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        cin >> M >> N;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        Solve();
    }
    
    return 0;
}

void Solve() {
    V.clear();
    fill(&visited[0][0][0][0], &visited[20][20][20][21], -1);
    result = (int)1e9;
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == '*') {
                V.push_back(make_pair(i, j));
                count++;
            }
            
            if (board[i][j] == 'o') {
                V.insert(V.begin(), make_pair(i, j));
                board[i][j] = '.';
            }
        }
    }
    
    for (pair<int, int> i : V) {
        BFS(i.first, i.second);
    }
    
    DFS(V, 1, count + 1);
    cout << (result == (int)1e9 ? -1 : result) << "\n";
}

void Swap(pair<int, int>& a, pair<int, int>& b) {
    pair<int, int> tmp = a;
    a = b;
    b = tmp;
}

void DFS(vector<pair<int, int>>& A, int depth, int count) {
    if (depth == count) {
        int tmp = 0;
        
        for (int i = 0; i < count - 1; i++) {
            int d = visited[A[i].first][A[i].second][A[i + 1].first][A[i + 1].second];
            
            if (d == -1) {
                return;
            }
            
            else {
                tmp += d;
            }
        }
        
        result = min(result, tmp);
        return;
    }
    
    for (int i = depth; i < count; i++) {
        Swap(A[depth], A[i]);
        DFS(A, depth + 1, count);
        Swap(A[depth], A[i]);
    }
}

void BFS(int sx, int sy) {
    int dist[21][21];
    fill(&dist[0][0], &dist[20][21], -1);
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(sx, sy));
    dist[sx][sy] = 0;
    
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
        visited[sx][sy][x][y] = dist[x][y];
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            
            if (board[nx][ny] == 'x') {
                continue;
            }
            
            if (dist[nx][ny] != -1) {
                continue;
            }
            
            dist[nx][ny] = dist[x][y] + 1;
            myqueue.push(make_pair(nx, ny));
        }
    }
}
