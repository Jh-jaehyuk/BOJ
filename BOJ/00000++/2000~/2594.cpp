//
//  2594.cpp
//  BOJ
//
//  Created by J213h on 2/1/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> V;

int get_val(string s, int flag) {
    int tmp = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(2, 2));
    
    if (flag) {
        tmp -= 10;
    }
    
    else {
        tmp += 10;
    }
    
    if (tmp < 600) {
        tmp = 600;
    }
    
    if (tmp > 1320) {
        tmp = 1320;
    }
    
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    V.push_back(make_pair(600, 600));
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        int S = get_val(a, 1);
        int E = get_val(b, 0);
        V.push_back(make_pair(S, E));
    }
    sort(V.begin(), V.end());
    V.push_back(make_pair(1320, 1320));
    
    int result = 0;
    int vs = (int)V.size();
    int S = V[0].first;
    int E = V[0].second;
    for (int i = 1; i < vs; i++) {
        if (S <= V[i].first && V[i].second <= E) {
            continue;
        }
        if (S <= V[i].first && E <= V[i].second && V[i].first <= E) {
            E = V[i].second;
        }
        else {
            result = max(result, V[i].first - E);
            S = V[i].first;
            E = V[i].second;
        }
    }
    cout << result << "\n";
    
    return 0;
}
