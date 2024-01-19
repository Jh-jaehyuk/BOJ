//
//  17178.cpp
//  BOJ
//
//  Created by J213h on 1/19/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> sortedV;
vector<queue<int>> V;
stack<int> S;

int get_number(string &s) {
    int tmp = 1000 * (s[0] - 'A' + 1);
    string s_ = "";
    
    for (int i = 2; i < s.size(); i++) {
        s_ += s[i];
    }
    
    tmp += stoi(s_);
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    V.resize(N);
    sortedV.resize(N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            string s;
            cin >> s;
            int num = get_number(s);
            sortedV[i].push_back(num);
            V[i].push(num);
        }
        sort(sortedV[i].begin(), sortedV[i].end());
    }
    
    for (int i = 0; i < N; i++) {
        int idx = 0;
        int now = sortedV[i][idx];
        
        while (!V[i].empty()) {
            if (V[i].front() == now) {
                V[i].pop();
                if (now == sortedV[i][4]) {
                    break;
                }
                now = sortedV[i][++idx];
            }
            
            else {
                if (S.empty()) {
                    int move = V[i].front();
                    V[i].pop();
                    S.push(move);
                }
                
                else {
                    if (S.top() == now) {
                        S.pop();
                        if (now == sortedV[i][4]) {
                            break;
                        }
                        now = sortedV[i][++idx];
                    }
                    
                    else if (S.top() < now) {
                        cout << "BAD" << "\n";
                        return 0;
                    }
                    
                    else {
                        int move = V[i].front();
                        V[i].pop();
                        S.push(move);
                    }
                }
            }
        }
        
        while (!S.empty()) {
            if (S.top() == now) {
                S.pop();
                if (now == sortedV[i][4]) {
                    break;
                }
                now = sortedV[i][++idx];
            }
            
            else {
                cout << "BAD" << "\n";
                return 0;
            }
        }
    }
    cout << "GOOD" << "\n";
    
    return 0;
}
