//
//  1371.cpp
//  BOJ
//
//  Created by J213h on 2023/10/02.
//

#include <bits/stdc++.h>

using namespace std;

static int check[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    while (!cin.eof()) {
        getline(cin, s);
        
        for (char i : s) {
            if (i == ' ') {
                continue;
            }
            
            check[i - 'a']++;
        }
    }
    
    int Max = *max_element(check, check + 26);
    
    for (int i = 0; i < 26; i++) {
        if (check[i] == Max) {
            cout << (char)(i + 97);
        }
    }
    
    return 0;
}

