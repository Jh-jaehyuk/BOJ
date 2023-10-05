//
//  15685.cpp
//  BOJ
//
//  Created by J213h on 2023/10/04.
//

#include <bits/stdc++.h>

using namespace std;

struct Curve {
    int y, x, d, g;
};

static int board[101][101];
static int dxdy[4][2] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
static vector<Curve> C;

void Draw(Curve tmp);
bool Check(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    C.resize(N);
    
    fill(&board[0][0], &board[100][101], 0);
    
    for (int i = 0; i < N; i++) {
        cin >> C[i].y >> C[i].x >> C[i].d >> C[i].g;

        Draw(C[i]);
    }
    
    int result = 0;
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (Check(i, j)) {
                result++;
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}

void Draw(Curve tmp) {
    vector<int> V;
    int x = tmp.x;
    int y = tmp.y;
    board[x][y] = 1;
    int nx = x + dxdy[tmp.d][0];
    int ny = y + dxdy[tmp.d][1];
    
    if (nx < 0 || nx > 100 || ny < 0 || ny > 100) {
        return;
    }
    board[nx][ny] = 1;
    V.push_back(tmp.d);
    
    for (int gen = 1; gen <= tmp.g; gen++) {
        int vs = (int)V.size();
        
        for (int i = vs - 1; i >= 0; i--) {
            int nd = V[i] + 1;
            
            if (nd >= 4) {
                nd -= 4;
            }
            
            nx += dxdy[nd][0];
            ny += dxdy[nd][1];
            
            if (x < 0 || x > 100 || y < 0 || y > 100) {
                return;
            }
            
            V.push_back(nd);
            board[nx][ny] = 1;
        }
    }
    
    return;
}

bool Check(int x, int y) {
    if (board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1]) {
        return true;
    }
    
    return false;
}
