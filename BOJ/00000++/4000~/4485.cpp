//
//  4485.cpp
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
            return i.dist > j.dist;
        }
        return i.x < j.x;
    }
};

static int N;
static int board[125][125];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static int mdistance[125][125];

void Solve(int N);
int dijkstra();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int idx = 1;
    while (true) {
        cin >> N;
        
        if (N == 0) {
            break;
        }
        cout << "Problem " << idx << ": ";
        Solve(N);
        idx++;
    }
    
    return 0;
}

void Solve(int N) {
    fill(&mdistance[0][0], &mdistance[124][125], (int)1e9);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int result = dijkstra();
    
    cout << result << "\n";
}

int dijkstra() {
    priority_queue<Node, vector<Node>, compare> pq;
    pq.push({ board[0][0], 0, 0 });
    mdistance[0][0] = board[0][0];
    
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
            
            nd += board[nx][ny];
            
            if (nd < mdistance[nx][ny]) {
                mdistance[nx][ny] = nd;
                pq.push({ nd, nx, ny });
            }
        }
    }
    
    return mdistance[N - 1][N - 1];
}
