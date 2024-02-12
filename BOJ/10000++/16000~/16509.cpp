//
//  16509.cpp
//  BOJ
//
//  Created by J213h on 2/9/24.
//

#include <bits/stdc++.h>

using namespace std;

int r1, c1, r2, c2;
int fm[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int sm[4][2][2] = { {{-1, -1}, {-1, 1}}, {{1, -1}, {1, 1}}, {{-1, -1}, {1, -1}}, {{-1, 1}, {1, 1}} };

void BFS(int x, int y) {
    queue<pair<int, int>> myqueue;
    int visited[10][9];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            visited[i][j] = -1;
        }
    }
    visited[x][y] = 0;
    myqueue.push(make_pair(x, y));
    
    while (!myqueue.empty()) {
        int x = myqueue.front().first;
        int y = myqueue.front().second;
        myqueue.pop();
        
        if (x == r2 && y == c2) {
            cout << visited[x][y] << "\n";
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + fm[i][0];
            int ny = y + fm[i][1];
            
            if (nx < 0 || nx >= 10 || ny < 0 || ny >= 9) {
                continue;
            }
            
            for (int j = 0; j < 2; j++) {
                int flag = 0;
                int nnx = nx;
                int nny = ny;
                for (int k = 0; k < 2; k++) {
                    if (nnx == r2 && nny == c2) {
                        flag = 1;
                        break;
                    }
                    nnx += sm[i][j][0];
                    nny += sm[i][j][1];
                    
                    if (nnx < 0 || nnx >= 10 || nny < 0 || nny >= 9) {
                        flag = 1;
                        break;
                    }
                }
                
                if (flag) {
                    continue;
                }
                
                if (visited[nnx][nny] != -1) {
                    continue;
                }
                
                visited[nnx][nny] = visited[x][y] + 1;
                myqueue.push(make_pair(nnx, nny));
            }
        }
    }
    
    cout << -1 << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r1 >> c1 >> r2 >> c2;
    BFS(r1, c1);
    
    return 0;
}
