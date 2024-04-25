//
//  1141.cpp
//  BOJ
//
//  Created by J213h on 4/22/24.
//

#include <bits/stdc++.h>

using namespace std;

bool cmp(string& i, string& j) {
    if (i.size() == j.size()) {
        return i < j;
    }
    return i.size() < j.size();
}

int check(string& a, string& b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), cmp);
    int result = N;
    for (int i = 0; i < N; i++) {
        int flag = 0;
        for (int j = i + 1; j < N; j++) {
            if (check(v[i], v[j])) {
                flag = 1;
            }
        }
        if (flag) {
            result--;
        }
    }
    cout << result << "\n";
    
    return 0;
}

