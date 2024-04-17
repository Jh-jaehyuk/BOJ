//
//  5052.cpp
//  BOJ
//
//  Created by J213h on 4/14/24.
//

#include <bits/stdc++.h>

using namespace std;

bool cmp(string& i, string& j) {
    if (i.size() != j.size()) {
        return i.size() < j.size();
    }
    return i < j;
}

void solve(int N) {
    vector<string> V;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        V.push_back(s);
    }
    sort(V.begin(), V.end(), cmp);
    
    int vs = (int)V.size();
    for (int i = 0; i < vs; i++) {
        string now = V[i];
        for (int j = i + 1; j < vs; j++) {
            if (now[0] != V[j][0]) {
                continue;
            }
            else {
                if (now.size() == V[j].size()) {
                    continue;
                }
            }
            string nxt = V[j].substr(0, now.size());
            
            if (now == nxt) {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        solve(N);
    }
    
    return 0;
}

