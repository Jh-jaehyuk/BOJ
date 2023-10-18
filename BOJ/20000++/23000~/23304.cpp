//
//  23304.cpp
//  BOJ
//
//  Created by J213h on 10/18/23.
//

#include <bits/stdc++.h>

using namespace std;

static string s;
static bool flag = false;
static string result = "AKARAKA";

void akaraka(string s);
bool is_palindrome(string s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    akaraka(s);
    
    cout << result << "\n";
    
    return 0;
}

void akaraka(string s) {
    int ss = (int)s.size();
    if (ss == 1 || flag) {
        return;
    }
    
    if (is_palindrome(s)) {
        akaraka(s.substr(0, (int)(ss / 2)));
    }
    
    if (flag) {
        result = "IPSELENTI";
    }
    return;
}

bool is_palindrome(string s) {
    int ss = (int)s.size();
    
    if (ss == 1) {
        return true;
    }
    
    for (int i = 0; i < ss / 2; i++) {
        if (s[i] != s[ss - i - 1]) {
            flag = true;
            return false;
        }
    }
    
    return true;
}
