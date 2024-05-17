//
//  2831.cpp
//  BOJ
//
//  Created by J213h on 5/14/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> nm, pm, nw, pw;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            nm.push_back(-1 * x);
        }
        else {
            pm.push_back(x);
        }
    }
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            nw.push_back(-1 * x);
        }
        else {
            pw.push_back(x);
        }
    }
    
    sort(nm.begin(), nm.end(), greater<int>());
    sort(pm.begin(), pm.end(), greater<int>());
    sort(nw.begin(), nw.end(), greater<int>());
    sort(pw.begin(), pw.end(), greater<int>());
    
    int ans = 0;
    
    int x = 0;
    int y = 0;
    while (x < (int)nm.size() && y < (int)pw.size()) {
        if (nm[x] > pw[y]) {
            ans++;
            x++;
            y++;
        }
        else {
            y++;
        }
    }
    
    x = 0;
    y = 0;
    while (x < (int)pm.size() && y < (int)nw.size()) {
        if (pm[x] >= nw[y]) {
            x++;
        }
        else {
            ans++;
            x++;
            y++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}

