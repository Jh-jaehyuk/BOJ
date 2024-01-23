//
//  3568.cpp
//  BOJ
//
//  Created by J213h on 1/23/24.
//

#include <bits/stdc++.h>

using namespace std;

string bs;

string solve(string s) {
    string var = "";
    string ss = "";
    string tmp = bs;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            var += s[i];
        }
        
        else if (s[i] >= 97 && s[i] <= 122) {
            var += s[i];
        }
        
        else {
            ss += s[i];
        }
    }
    
    if (ss.size() == 0) {
        return tmp + " " + var + ";";
    }
    
    else {
        for (int i =
             (int)ss.size() - 1; i >= 0; i--) {
            if (ss[i] == ']') {
                tmp += "[]";
                i--;
            }
            else {
                tmp += ss[i];
            }
        }
        return tmp + " " + var + ";";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> bs;
    
    while (true) {
        string s;
        cin >> s;
        
        cout << solve(s.substr(0, (int)s.size() - 1)) << "\n";
        
        if (s[(int)s.size() - 1] == ';') {
            break;
        }
    }
    return 0;
}
