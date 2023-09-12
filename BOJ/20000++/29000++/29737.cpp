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
    int len, freeze, day, fail;
};

static vector<Friend> A;

bool cmp(Friend i, Friend j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, W;
    cin >> N >> W;
    
    for (int t = 0; t < N; t++) {
        string s;
        cin >> s;
        
        string board = "";
        
        for (int i = 0; i < 7; i++) {
            string tmp;
            cin >> tmp;
            board += tmp;
        }
        
        int Max_L, Max_F, Max_D, L, fail_count, F, D, cnt, f;
        Max_L = Max_F = Max_D = L = fail_count = F = D = cnt = f = 0;
        
        for (int j = 0; j < W; j++) {
            for (int i = 0; i < 7; i++) {
                if (board[W * i + j] == 'O') {
                    if (L == 0) {
                        L++;
                        D = cnt;
                    }
                    
                    else {
                        L++;
                        F += f;
                        f = 0;
                    }
                }
                
                else if (board[W * i + j] == 'F') {
                    if (L != 0) {
                        f++;
                    }
                }
                
                else if (board[W * i + j] == 'X') {
                    if (L > Max_L) {
                        Max_L = L;
                        Max_D = D;
                        Max_F = F;
                    }
                    
                    else if (L == Max_L) {
                        if (Max_F > F) {
                            Max_F = F;
                            Max_D = D;
                        }
                    }
                    
                    L = F = D = f = 0;
                    fail_count++;
                }
                cnt++;
            }
        }
        if (L > Max_L) {
            Max_L = L;
            Max_D = D;
            Max_F = F;
        }
        
        else if (L == Max_L) {
            if (Max_F > F) {
                Max_F = F;
                Max_D = D;
            }
        }
        
        Friend temp;
        temp.name = s;
        temp.freeze = Max_F;
        temp.len = Max_L;
        temp.fail = fail_count;
        temp.day = Max_D;
        
        A.push_back(temp);
    }
    
    sort(A.begin(), A.end(), cmp);
    
    int idx = 1;
    Friend prev = A[0];
    
    for (int a = 0; a < N; a++) {
        Friend i = A[a];
        
        if (a != 0 && (i.len != prev.len || i.freeze != prev.freeze || i.day != prev.day || i.fail != prev.fail)) {
            idx++;
        }
        
        prev = i;
        cout << idx << ". " << i.name << "\n";
    }
    
    return 0;
}

bool cmp(Friend i, Friend j) {
    if (i.len != j.len) {
        return i.len > j.len;
    }
    
    else {
        if (i.freeze != j.freeze) {
            return i.freeze < j.freeze;
        }
        
        else {
            if (i.day != j.day) {
                return i.day < j.day;
            }
            
            else {
                if (i.fail != j.fail) {
                    return i.fail < j.fail;
                }
                
                else {
                    return i.name < j.name;
                }
            }
        }
    }
}
