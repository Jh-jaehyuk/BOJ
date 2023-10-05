//
//  17140.cpp
//  BOJ
//
//  Created by J213h on 2023/10/04.
//

#include <bits/stdc++.h>

using namespace std;

static int r, c, k;
static int row = 3;
static int col = 3;
static int board[101][101];
static int Count[101];

void func_R(int board[][101]);
void func_C(int board[][101]);
void Solve(int row, int col);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r >> c >> k;
    
    fill(&board[0][0], &board[100][101], 0);
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> board[i][j];
        }
    }
    
    int result = 0;
    while (true) {
        if (board[r][c] == k || result > 100) {
            break;
        }
        
        Solve(row, col);
        result++;
    }
    cout << (result > 100 ? -1 : result) << "\n";
    
    return 0;
}

void func_R(int board[][101]) {
    int Max = -1;
    for (int i = 1; i <= row; i++) {
        vector<pair<int, int>> V;
        fill(Count, Count + 101, 0);
        
        for (int j = 1; j <= col; j++) {
            Count[board[i][j]]++;
            board[i][j] = 0;
        }
        
        for (int j = 1; j <= 100; j++) {
            if (!Count[j]) {
                continue;
            }
            
            V.push_back(make_pair(Count[j], j));
        }
        
        sort(V.begin(), V.end());
        int idx = 1;
        int vs = (int)V.size();
        
        for (int j = 0; j < vs; j++) {
            board[i][idx++] = V[j].second;
            board[i][idx++] = V[j].first;
        }
        
        Max = max(Max, idx - 1);
    }
    col = Max;
    return;
}

void func_C(int board[][101]) {
    int Max = -1;
    for (int j = 1; j <= col; j++) {
        vector<pair<int, int>> V;
        fill(Count, Count + 101, 0);
        
        for (int i = 1; i <= row; i++) {
            Count[board[i][j]]++;
            board[i][j] = 0;
        }
        
        for (int i = 1; i <= 100; i++) {
            if (Count[i] == 0) {
                continue;
            }
            
            V.push_back(make_pair(Count[i], i));
        }
        
        sort(V.begin(), V.end());
        int idx = 1;
        int vs = (int)V.size();
        
        for (int i = 0; i < vs; i++) {
            board[idx++][j] = V[i].second;
            board[idx++][j] = V[i].first;
        }
        
        Max = max(Max, idx - 1);
    }
    row = Max;
    return;
}

void Solve(int row, int col) {
    if (row >= col) {
        func_R(board);
    }
    
    else {
        func_C(board);
    }
}
