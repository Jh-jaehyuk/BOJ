//
//  1455.cpp
//  BOJ
//
//  Created by J213h on 4/25/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, result;
int board[101][101];

int f() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void flip(int r, int c) {
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            board[i][j] = (1 & ~board[i][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    
    while (!f()) {
        ++result;
        int flag = 0;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (board[i][j]) {
                    flip(i, j);
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
    }
    
    cout << result << "\n";

    return 0;
}

