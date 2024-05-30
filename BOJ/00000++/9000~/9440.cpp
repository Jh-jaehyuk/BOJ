//
//  9440.cpp
//  BOJ
//
//  Created by J213h on 5/30/24.
//

#include <bits/stdc++.h>

using namespace std;

int cnt[10];

void solve(int N) {
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    vector<vector<char>> ans(2, vector<char>());
    
    while (true) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 10; j++) {
                if (!cnt[j]) {
                    continue;
                }
                if (!j && ans[i].empty()) {
                    continue;
                }
                else {
                    ans[i].push_back('0' + j);
                    cnt[j]--;
                    break;
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < 10; i++) {
            if (cnt[i]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (int)ans[i].size(); j++) {
            if (!i) {
                s1 += ans[i][j];
            }
            else {
                s2 += ans[i][j];
            }
        }
    }
    
    cout << stoi(s1) + stoi(s2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        int N;
        cin >> N;
        if (!N) {
            break;
        }
        solve(N);
    }
    
    return 0;
}
