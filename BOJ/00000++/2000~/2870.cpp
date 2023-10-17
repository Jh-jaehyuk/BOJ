//
//  2870.cpp
//  BOJ
//
//  Created by J213h on 10/16/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<string> result;

string remove_zero(string s);
bool cmp(string i, string j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        
        int ss = (int)s.size();
        string tmp = "";
        
        for (int j = 0; j < ss; j++) {
            if (s[j] >= 97 && s[j] <= 122) {
                if (tmp != "") {
                    result.push_back(remove_zero(tmp));
                    tmp = "";
                }
            }
            
            else {
                tmp += s[j];
            }
        }
        
        if (tmp != "") {
            result.push_back(remove_zero(tmp));
        }
    }
    
    sort(result.begin(), result.end(), cmp);
    
    for (string i : result) {
        int idx = 0;
        
        while (idx < i.size() && i[idx] == '0') {
            idx++;
        }
        
        if (idx >= i.size()) {
            cout << 0 << "\n";
        }
        
        else {
            cout << i.substr(idx) << "\n";
        }
    }
    
    return 0;
}

string remove_zero(string s) {
    if (s.find('0') == string::npos) {
        return s;
    }
    
    else {
        int idx = 0;
        int ss = (int)s.size();
        
        while (s[idx] == '0' && idx < ss) {
            idx++;
        }
        
        if (idx == ss) {
            return "0";
        }
        
        else {
            return s.substr(idx);
        }
    }
}

bool cmp(string i, string j) {
    if (i.size() == j.size()) {
        return i < j;
    }
    
    return i.size() < j.size();
}
