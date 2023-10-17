//
//  9536.cpp
//  BOJ
//
//  Created by J213h on 10/17/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<string> V;
static set<string> myset;

void Solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    
    for (int i = 0; i < T; i++) {
        Solve();
    }
    
    return 0;
}

void Solve() {
    V.clear();
    myset.clear();
    
    cin.ignore();
    string s;
    getline(cin, s);
    
    int ss = (int)s.size();
    string tmp = "";
    for (int i = 0; i < ss; i++) {
        if (s[i] == ' ') {
            V.push_back(tmp);
            tmp = "";
        }
        
        else {
            tmp += s[i];
        }
        
        if (i == ss - 1) {
            V.push_back(tmp);
        }
    }
    
    while (true) {
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            string temp;
            cin >> temp;
            
            if (temp == "what") {
                string trash;
                for (int j = 0; j < 4; j++) {
                    cin >> trash;
                }
                flag = true;
                break;
            }
            
            if (i == 2 && myset.find(temp) == myset.end()) {
                myset.insert(temp);
            }
        }
        
        if (flag) {
            break;
        }
    }
    
    int vs = (int)V.size();
    for (int i = 0; i < vs; i++) {
        if (myset.find(V[i]) == myset.end()) {
            cout << V[i] << " ";
        }
    }
    cout << "\n";
}
