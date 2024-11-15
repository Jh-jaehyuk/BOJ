//
//  1996.cpp
//  BOJ
//
//  Created by J213h on 11/15/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
int board[1001][1001];
char ans[1001][1001];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int check(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
            continue;
        }
        cnt += board[nx][ny];
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char temp;
            cin >> temp;
            
            if (temp == '.') {
                board[i][j] = 0;
            }
            else {
                board[i][j] = temp - '0';
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                ans[i][j] = '*';
            }
            else {
                int temp = check(i, j);
                char x = '0' + temp;
                ans[i][j] = (temp >= 10 ? 'M' : x);
            }
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}
