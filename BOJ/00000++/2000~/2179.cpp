//
//  2179.cpp
//  BOJ
//
//  Created by J213h on 11/14/24.
//

#include <bits/stdc++.h>

using namespace std;

set<string> S;
vector<pair<string, int>> V;
pair<string, int> s, t;

bool cmp(pair<string, int>& i, pair<string, int>& j) {
    if ((int)i.first.size() != (int)j.first.size()) {
        return (int)i.first.size() < (int)j.first.size();
    }
    return i.second < j.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        
        if (S.find(temp) != S.end()) {
            continue;
        }
        S.insert(temp);
        V.push_back(make_pair(temp, i));
    }
    
    sort(V.begin(), V.end(), cmp);
    
    int vs = (int)V.size();
    int Max = -1;
    for (int i = 0; i < vs; i++) {
        int is = (int)V[i].first.size();
        
        for (int j = i + 1; j < vs; j++) {
            int cnt = 0;
            
            for (int k = 0; k < is; k++) {
                if (V[i].first[k] != V[j].first[k]) {
                    break;
                }
                cnt++;
            }
            
            if (Max < cnt) {
                Max = cnt;
                if (V[i].second < V[j].second) {
                    s = V[i];
                    t = V[j];
                }
                else {
                    s = V[j];
                    t = V[i];
                }
            }
            
            else if (Max == cnt) {
                if (V[i].second < V[j].second) {
                    if (V[i].second < s.second) {
                        s = V[i];
                        t = V[j];
                    }
                    
                    else if (V[i].second == s.second && V[j].second < t.second) {
                        s = V[i];
                        t = V[j];
                    }
                }
                else {
                    if (V[j].second < s.second) {
                        s = V[j];
                        t = V[i];
                    }
                    
                    else if (V[j].second == s.second && V[i].second < t.second) {
                        s = V[j];
                        t = V[i];
                    }
                }
            }
        }
    }
    cout << s.first << "\n" << t.first << "\n";

    return 0;
}
