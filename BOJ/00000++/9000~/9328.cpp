//
//  9328.cpp
//  BOJ
//
//  Created by J213h on 10/20/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static char board[105][105];
static int visited[105][105];
static int check[26];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static vector<pair<int, int>> V;

pair<int, int> find_lock(char c);
void Solve();
int BFS();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        Solve();
    }
    
    return 0;
}

bool move(int x, int y) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx > N + 1 || ny < 0 || ny > N + 1) {
            continue;
        }
        
        if (visited[nx][ny]) {
            count++;
            break;
        }
        
        else {
            if (isupper(board[nx][ny])) {
                if (check[board[nx][ny] - 'A']) {
                    count++;
                    break;
                }
            }
            
            else if (islower(board[nx][ny])) {
                count++;
                break;
            }
        }
    }
    
    if (count) {
        return true;
    }
    
    return false;
}

pair<int, int> find_lock(char c) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!visited[i][j] && board[i][j] == toupper(c) && move(i, j)) {
                return make_pair(i, j);
            }
        }
    }
    
    return make_pair(-1, -1);
}

void Solve() {
    cin >> N >> M;
    
    fill(&visited[0][0], &visited[104][105], 0);
    fill(check, check + 26, 0);
    V.clear();
    
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            if (i == 0 || i == N + 1 || j == 0 || j == M + 1) {
                board[i][j] = '.';
                continue;
            }
            cin >> board[i][j];
        }
    }
    
    string key;
    cin >> key;
    
    if (key != "0") {
        for (char i : key) {
            check[i - 'a']++;
        }
    }
    
    cout << BFS() << "\n";
    
}

int BFS() {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(0, 0));
    visited[0][0] = 1;
    int count = 0;
    
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1) {
                continue;
            }
            
            if (visited[nx][ny]) {
                continue;
            }
            
            if (board[nx][ny] == '*') {
                continue;
            }
            
            if (isupper(board[nx][ny])) {
                if (check[board[nx][ny] - 'A']) {
                    visited[nx][ny] = 1;
                    myqueue.push(make_pair(nx, ny));
                }
            }
            
            else if (islower(board[nx][ny])) {
                if (!check[board[nx][ny] - 'a']) {
                    check[board[nx][ny] - 'a']++;
                    pair<int, int> tmp = find_lock(board[nx][ny]);
                    
                    if (tmp.first == -1 && tmp.second == -1) {
                        continue;
                    }
                    
                    fill(&visited[0][0], &visited[104][105], 0);
                    while (!myqueue.empty()) {
                        myqueue.pop();
                    }
                    visited[tmp.first][tmp.second] = 1;
                    myqueue.push(make_pair(tmp.first, tmp.second));
                }
            }
            
            else {
                if (board[nx][ny] == '$') {
                    count++;
                }
                visited[nx][ny] = 1;
                myqueue.push(make_pair(nx, ny));
            }
        }
    }
    
    return count;
}
