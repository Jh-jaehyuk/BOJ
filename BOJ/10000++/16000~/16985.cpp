//
//  16985.cpp
//  BOJ
//
//  Created by J213h on 10/12/23.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, z;
};

static int board[5][5][5];
static int copy_board[5][5][5];
static int visited[5][5][5];
static int board_order[5] = { -1, -1, -1, -1, -1 };
static int board_turn[5] = { -1, -1, -1, -1, -1};
static int dx[6] = { -1, 1, 0, 0, 0, 0 };
static int dy[6] = { 0, 0, -1, 1, 0, 0 };
static int dz[6] = { 0, 0, 0, 0, -1, 1 };

static int result = (int)1e9;

void Maze();
int BFS(int A[5][5][5]);
void Turn(int depth);
void Make_order(int depth);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> board[k][i][j];
            }
        }
    }
    
    Make_order(0);
    
    cout << (result == (int)1e9 ? -1 : result) << "\n";
    
    return 0;
}

void Maze() {
    fill(&copy_board[0][0][0], &copy_board[4][4][5], 0);
    
    for (int i = 0; i < 5; i++) {
        int idx = board_order[i];
        int t = board_turn[i];
        
        if (t == 0) {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    copy_board[i][row][col] = board[idx][row][col];
                }
            }
        }
        
        else if (t == 1) {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    copy_board[i][col][4 - row] = board[idx][row][col];
                }
            }
        }
        
        else if (t == 2) {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    copy_board[i][4 - row][4 - col] = board[idx][row][col];
                }
            }
        }
        
        else {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    copy_board[i][4 - col][row] = board[idx][row][col];
                }
            }
        }
    }
}

int BFS(int A[5][5][5]) {
    queue<Node> myqueue;
    myqueue.push({ 0, 0, 0 });
    visited[0][0][0] = 0;
    
    int tmp = -1;
    
    while (!myqueue.empty()) {
        int x = myqueue.front().x;
        int y = myqueue.front().y;
        int z = myqueue.front().z;
        myqueue.pop();
        
        if (x == 4 && y == 4 && z == 4) {
            tmp = visited[z][x][y];
            break;
        }
        
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) {
                continue;
            }
            
            if (visited[nz][nx][ny] != -1) {
                continue;
            }
            
            if (A[nz][nx][ny] == 0) {
                continue;
            }
            
            visited[nz][nx][ny] = visited[z][x][y] + 1;
            myqueue.push({ nx, ny, nz });
        }
    }
    
    return tmp;
}

void Turn(int depth) {
    if (depth == 5) {
        Maze();
        
        if (copy_board[0][0][0] == 1 && copy_board[4][4][4] == 1) {
            fill(&visited[0][0][0], &visited[4][4][5], -1);
            
            int count = BFS(copy_board);
            
            if (count != -1) {
                result = min(result, count);
            }
        }
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        board_turn[depth] = i;
        Turn(depth + 1);
    }
}

void Make_order(int depth) {
    if (depth == 5) {
        Turn(0);
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        if (board_order[i] != -1) {
            continue;
        }
        
        board_order[i] = depth;
        Make_order(depth + 1);
        board_order[i] = -1;
    }
}
