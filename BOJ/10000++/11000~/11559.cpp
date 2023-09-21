//
//  11559.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

static char board[12][7];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static bool visited[12][7];
static bool isboom[12][7];
static int result = 0;

void check();
void move();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }
    
    int prev = result;

    while (true) {
        check();
        move();
        
        if (result == prev) {
            break;
        }
        prev = result;
    }
    
    cout << result << "\n";
    
    return 0;
}

void check() {
    fill(&visited[0][0], &visited[11][7], false);
    fill(&isboom[0][0], &isboom[11][7], false);
    bool flag = false;
    
    function<void (int, int)> BFS = [&](int x, int y) {
        queue<pair<int, int>> myqueue;
        myqueue.push(make_pair(x, y));
        visited[x][y] = true;
        char tmp = board[x][y];
        int count = 1;
        vector<pair<int, int>> v;
        v.push_back(make_pair(x, y));
        
        while (!myqueue.empty()) {
            int x = myqueue.front().first;
            int y = myqueue.front().second;
            myqueue.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) {
                    continue;
                }
                
                if (visited[nx][ny]) {
                    continue;
                }
                
                if (board[nx][ny] != tmp) {
                    continue;
                }
                
                visited[nx][ny] = true;
                count++;
                myqueue.push(make_pair(nx, ny));
                v.push_back(make_pair(nx, ny));
            }
        }
        
        if (count >= 4) {
            flag = true;
            for (auto i : v) {
                isboom[i.first][i.second] = true;
            }
        }
    };
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (!visited[i][j] && board[i][j] != '.') {
                BFS(i, j);
            }
        }
    }
    
    if (flag) {
        result++;
    }
}

void move() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (isboom[i][j]) {
                board[i][j] = '.';
            }
        }
    }
    
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] != '.') {
                int idx = i + 1;
                
                while (true) {
                    if (board[idx][j] != '.' || idx >= 12) {
                        break;
                    }
                    idx++;
                }
                idx--;
                char tmp = board[i][j];
                board[i][j] = '.';
                board[idx][j] = tmp;
            }
        }
    }
}
