//
//  10384.cpp
//  BOJ
//
//  Created by J213h on 10/11/23.
//

#include <bits/stdc++.h>

using namespace std;

static int check[26];
static string S[4] = { "Not a pangram", "Pangram!", "Double pangram!!", "Triple pangram!!!" };

void Solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    cin.ignore();
    
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        Solve();
    }
    
    return 0;
}

void Solve() {
    fill(check, check + 26, 0);
    string s;
    getline(cin, s);
    
    for (char& c : s) {
        c = toupper(c);
    }
    
    for (char c : s) {
        if (c < 65 || c > 90) {
            continue;
        }
        check[c - 'A']++;
    }

    int flag = 4;
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 26; j++) {
            if (check[j] < i) {
                flag = i - 1;
                break;
            }
        }
        if (flag != 4) {
            break;
        }
    }
    
    if (flag == 4) {
        flag = 3;
    }
    
    cout << S[flag] << "\n";
}
