//
//  2665.cpp
//  BOJ
//
//  Created by J213h on 10/12/23.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int dist, x, y;
};

struct compare {
    bool operator() (Node& i, Node& j) {
        if (i.dist != j.dist) {
            return i.dist < j.dist;
        }
        
        else {
            if (i.x != j.x) {
                return i.x < j.x;
            }
            
            else {
                return i.y < j.y;
            }
        }
    }
};

static int N;
static int board[51][51];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static int mdistance[51][51];
static priority_queue<Node, vector<Node>, compare> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    
    fill(&mdistance[0][0], &mdistance[50][51], (int)1e9);
    
    pq.push({ 0, 0, 0 });
    mdistance[0][0] = 0;
    
    while (!pq.empty()) {
        int d = pq.top().dist;
        int x = pq.top().x;
        int y = pq.top().y;
        pq.pop();
        
        for (int i = 0; i < 4; i++) {
            int nd = d;
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            
            if (board[nx][ny] == 0) {
                nd++;
            }
            
            if (nd < mdistance[nx][ny]) {
                mdistance[nx][ny] = nd;
                pq.push({ nd, nx, ny });
            }
        }
    }
    
    cout << mdistance[N - 1][N - 1] << "\n";
    
    return 0;
}
