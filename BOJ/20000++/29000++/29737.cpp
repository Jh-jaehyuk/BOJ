//
//  29737.cpp
//  BOJ
//
//  Created by 한재혁 on 2023/09/11.
//

#include <bits/stdc++.h>

using namespace std;

struct Friend {
    string name;
    int m;
    int c;
    int d;
    int f;
};

static vector<Friend> V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, W;
    cin >> N >> W;
    
    for (int n = 0; n < N; n++) {
        string s;
        cin >> s;
        
        Friend tmp;
        tmp.name = s;
        tmp.m = 0;
        tmp.c = 0;
        tmp.d = 0;
        tmp.f = 0;
        
        char tmp_board[7][102];
        char board[102][7];
        
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < W; j++) {
                cin >> tmp_board[i][j];
            }
        }
        
        for (int j = 0; j < W; j++) {
            for (int i = 0; i < 7; i++) {
                board[j][i] = tmp_board[i][j];
            }
        }
        
        int Max = 0;
        int Day = 0;
        int Count = 0;
        int Fail = 0;
        
        int cnt = 0;
        int f_cnt = 0;
        
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] == 'O') {
                    cnt++;
                    Max = max(Max, cnt);
                }
                
                else if (board[i][j] == 'F') {
                    f_cnt++;
                }
                
                else {
                    if (cnt == Max) {
                        Day = i + j + 1 - cnt;
                        Count = f_cnt;
                    }
                    
                    cnt = 0;
                    f_cnt = 0;
                    Fail++;
                }
            }
        }
        
        if (cnt > Max) {
            Max = cnt;
        }
        
        tmp.m = Max;
        tmp.d = Day;
        tmp.c = Count;
        
        
        V.push_back(tmp);
    }
    
    
    return 0;
}
