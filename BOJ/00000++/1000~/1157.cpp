//
//  1157.cpp
//  BOJ
//
//  Created by J213h on 2023/10/04.
//

#include <bits/stdc++.h>

using namespace std;

static int check[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for (char& i : s) {
        i = toupper(i);
        check[i - 'A']++;
    }
    
    int Max = *max_element(check, check + 26);
    char result = '?';
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (check[i] == Max) {
            count++;
            result = (char)('A' + i);
        }
    }
    
    if (count > 1) {
        cout << '?' << "\n";
    }
    
    else {
        cout << result << "\n";
    }
    
    return 0;
}
