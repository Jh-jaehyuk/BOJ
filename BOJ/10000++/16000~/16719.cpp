//
//  16719.cpp
//  BOJ
//
//  Created by J213h on 10/18/23.
//

#include <bits/stdc++.h>

using namespace std;

static string s;
static int visited[101];

void Recursive(int left, int right);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    
    Recursive(0, (int)s.size() - 1);

    return 0;
}

void Recursive(int left, int right) {
    int Min = (int)1e9;
    int idx = -1;
    
    for (int i = left; i < right + 1; i++) {
        if (!visited[i]) {
            if (Min > s[i]) {
                Min = s[i];
                idx = i;
            }
        }
    }
    
    if (Min == (int)1e9) {
        return;
    }
    visited[idx] = 1;
    
    for (int i = 0; i < s.size(); i++) {
        if (visited[i]) {
            cout << s[i];
        }
    }
    cout << "\n";
    
    Recursive(idx + 1, right);
    Recursive(left, idx - 1);
}
