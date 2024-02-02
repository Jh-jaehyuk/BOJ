//
//  19598.cpp
//  BOJ
//
//  Created by J213h on 2/2/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> V;
set<pair<int, int>> S;

bool cmp(const pair<int, int>& i, const pair<int, int>& j) {
    if (i.second != j.second) {
        return i.second < j.second;
    }
    
    return i.first < j.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        V.push_back(make_pair(a, b));
    }
    
    sort(V.begin(), V.end(), cmp);
    for (int i = 0; i < N; i++) {
        auto iter = S.lower_bound(make_pair(V[i].first, i));
        if (iter != S.begin()) {
            --iter;
            S.erase(iter);
        }
        S.insert(make_pair(V[i].second, i));
    }
    cout << S.size() << "\n";
    return 0;
}
