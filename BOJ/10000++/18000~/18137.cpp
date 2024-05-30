//
//  18137.cpp
//  BOJ
//
//  Created by J213h on 5/30/24.
//

#include <bits/stdc++.h>

using namespace std;

int dx[8] = { -2, -2, -1, 1, 2, 2, -1, 1 };
int dy[8] = { -1, 1, 2, 2, -1, 1, -2, -2 };
set<int> s;

int get_number(int x, int y) {
    int p1 = x + y - 1;
    int p2 = x + y - 2;
    
    if (p1 % 2) {
        p2 /= 2;
    }
    else {
        p1 /= 2;
    }

    return (p1 * p2) + y;
}

array<int, 3> get_next_number(int x, int y) {
    vector<pair<int, int>> nxt;
    for (int i = 0; i < 8; i++) {
        if (x + dx[i] < 1 || y + dy[i] < 1) {
            continue;
        }
        
        int num = get_number(x + dx[i], y + dy[i]);
        if (s.find(num) != s.end()) {
            continue;
        }
        nxt.push_back(make_pair(num, i));
    }
    sort(nxt.begin(), nxt.end());
    
    if (nxt.empty()) {
        return { -1, x, y };
    }
    else {
        return { nxt[0].first, x + dx[nxt[0].second], y + dy[nxt[0].second] };
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int k;
    cin >> k;
    
    int x = 1;
    int y = 1;
    int now = 1;
    s.insert(now);
    
    for (int i = 0; i < k; i++) {
        array<int, 3> temp = get_next_number(x, y);
        now = temp[0];
        x = temp[1];
        y = temp[2];
        
        if (now == -1) {
            now = get_number(x, y);
            break;
        }
        s.insert(now);
    }
    cout << now << "\n";
    
    return 0;
}

