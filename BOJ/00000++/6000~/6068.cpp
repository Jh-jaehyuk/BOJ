//
//  6068.cpp
//  BOJ
//
//  Created by J213h on 12/9/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    V.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> V[i].second >> V[i].first;
    }
    
    sort(V.begin(), V.end());
    int s = V[0].first - V[0].second;
    
    if (s < 0) {
        cout << -1 << "\n";
        return 0;
    }
    
    int ans = -1;

    for (int i = s; i + 1; i--) {
        int now = i + V[0].second;
        int flag = 0;

        for (int j = 1; j < N; j++) {
            if (now + V[j].second > V[j].first) {
                flag = 1;
                break;
            }
            else {
                now += V[j].second;
            }
        }
        
        if (!flag) {
            ans = i;
            break;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
