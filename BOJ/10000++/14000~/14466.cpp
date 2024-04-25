//
//  14466.cpp
//  BOJ
//
//  Created by J213h on 4/19/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, K, R, result;
pair<int, int> ar[101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<set<pair<int, int>>>> roads(101, vector<set<pair<int, int>>>(101));

void BFS(int x, int y, int idx) {
    int vis[101][101];
    fill_n(&vis[0][0], 101 * 101, 0);
    queue<pair<int, int>> q;
    
    vis[x][y] = 1;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx <= 0 || nx > N || ny <= 0 || ny > N) {
                continue;
            }
            
            if (roads[x][y].find(make_pair(nx, ny)) != roads[x][y].end()) {
                continue;
            }
            
            if (vis[nx][ny]) {
                continue;
            }
            
            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    
    for (int i = 0; i < idx; i++) {
        if (!vis[ar[i].first][ar[i].second]) {
            result++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K >> R;
    for (int i = 0; i < R; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        roads[r1][c1].insert(make_pair(r2, c2));
        roads[r2][c2].insert(make_pair(r1, c1));
    }
    
    for (int i = 0; i < K; i++) {
        cin >> ar[i].first >> ar[i].second;
        BFS(ar[i].first, ar[i].second, i);
    }

    cout << result << "\n";

    return 0;
}
