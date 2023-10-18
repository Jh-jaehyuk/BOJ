//
//  3107.cpp
//  BOJ
//
//  Created by J213h on 10/18/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<string> V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ':') {
            while (tmp.size() < 4) {
                tmp = '0' + tmp;
            }
            V.push_back(tmp);
            tmp = "";
            
            if (s[i + 1] == ':') {
                V.push_back("0");
                i++;
            }
        }
        
        else {
            tmp += s[i];
        }
    }
    
    while (tmp.size() < 4) {
        tmp = '0' + tmp;
    }
    V.push_back(tmp);
    
    string result = "0";
    for (string i : V) {
        if (i != "0") {
            result += i;
        }
        
        else {
            int ks = 8 - (int)V.size() + 1;
            for (int k = 0; k < ks; k++) {
                result += "0000";
            }
        }
    }
    
    for (int i = 1; i <= 32; i++) {
        cout << result[i];
        
        if (i % 4 == 0 && i != 32) {
            cout << ':';
        }
    }
    cout << "\n";
    
    return 0;
}
