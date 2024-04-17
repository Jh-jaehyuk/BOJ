//
//  2174.cpp
//  BOJ
//
//  Created by J213h on 4/17/24.
//

#include <bits/stdc++.h>

using namespace std;

# define ar array
int N, M, A, B;
int board[101][101];
vector<ar<int, 3>> robots;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int char2int(char c) {
    if (c == 'W') {
        return 0;
    }
    else if (c == 'N') {
        return 1;
    }
    else if (c == 'E') {
        return 2;
    }
    else {
        return 3;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> M >> N >> A >> B;
    robots.resize(A + 1);
    
    for (int i = 1; i <= A; i++) {
        int y, x;
        char d;
        cin >> y >> x >> d;
        robots[i] = { x, y, char2int(d) };
        board[x][y] = i;
    }
    
    int flag = 0;
    for (int i = 0; i < B; i++) {
        int num, k;
        char com;
        
        cin >> num >> com >> k;
        int x = robots[num][0];
        int y = robots[num][1];
        int d = robots[num][2];
        board[x][y] = 0;
        
        if (com == 'F') {
            for (int j = 0; j < k; j++) {
                x += dx[d];
                y += dy[d];
                
                if (x <= 0 || x > N || y <= 0 || y > M) {
                    flag = 1;
                    cout << "Robot " << num << " crashes into the wall" << "\n";
                    break;
                }
                
                if (board[x][y] != 0) {
                    flag = 1;
                    cout << "Robot " << num << " crashes into robot " << board[x][y] << "\n";
                    break;
                }
            }
            
            if (flag) {
                break;
            }
            
            board[x][y] = num;
            robots[num][0] = x;
            robots[num][1] = y;
            robots[num][2] = d;
        }
        
        else {
            if (com == 'R') {
                d = (d + k) % 4;
            }
            else {
                d = (d + 4 - (k % 4)) % 4;
            }
            robots[num][2] = d;
        }
    }
    
    if (!flag) {
        cout << "OK" << "\n";
    }

    return 0;
}

