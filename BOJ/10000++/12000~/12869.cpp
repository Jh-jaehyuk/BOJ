//
//  main.cpp
//  BOJ
//
//  Created by 한재혁 on 2023/09/11.
//

#include <bits/stdc++.h>

using namespace std;

int N;
int SCV[3];
int dir[6][3] = { { -9, -3, -1 }, { -9, -1, -3 }, { -3, -9, -1 }, { -1, -9, -3 }, { -3, -1, -9 }, { -1, -3, -9 } };
int dist[61][61][61];

void BFS(int SCV[3]) {
    queue<vector<int>> myqueue;
    myqueue.push({ SCV[0], SCV[1], SCV[2] });
    dist[SCV[0]][SCV[1]][SCV[2]] = 0;
    
    while (!myqueue.empty()) {
        vector<int> now = myqueue.front();
        int a = now[0];
        int b = now[1];
        int c = now[2];
        myqueue.pop();
        
        if (a == 0 && b == 0 && c == 0) {
            cout << dist[0][0][0] << "\n";
            return;
        }
        
        for (int i = 0; i < 6; i++) {
            int na = a + dir[i][0] < 0 ? 0 : a + dir[i][0];
            int nb = b + dir[i][1] < 0 ? 0 : b + dir[i][1];
            int nc = c + dir[i][2] < 0 ? 0 : c + dir[i][2];
            
            if (dist[na][nb][nc] != -1) {
                continue;
            }
            dist[na][nb][nc] = dist[a][b][c] + 1;
            myqueue.push({ na, nb, nc });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> SCV[i];
    }
    
    for (int i = 0; i < 61; i++) {
        for (int j = 0; j < 61; j++) {
            for (int k = 0; k < 61; k++) {
                dist[i][j][k] = -1;
            }
        }
    }
    
    BFS(SCV);

    return 0;
}
