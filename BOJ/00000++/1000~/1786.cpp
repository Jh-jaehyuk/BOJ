//
//  1786.cpp
//  BOJ
//
//  Created by J213h on 10/16/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> pi;
static vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    
    int n = (int)text.size();
    int m = (int)pattern.size();
    
    pi.resize(m);
    
    pi[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        
        if (pattern[i] == pattern[j]) {
            pi[i] = ++j;
        }
    }
    
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        
        if (text[i] == pattern[j]) {
            if (j == m - 1) {
                result.push_back(i - m + 2);
                j = pi[j];
            }
            
            else {
                j++;
            }
        }
    }
    
    if (result.empty()) {
        cout << 0 << "\n";
    }
    
    else {
        cout << (int)result.size() << "\n";
        
        for (int i : result) {
            cout << i << " ";
        }
    }
    
    return 0;
}
