//
//  30827.cpp
//  BOJ
//
//  Created by J213h on 2/6/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> V;
int R[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    V.resize(N + 1);
    
    for (int i = 0; i < N; i++) {
        cin >> V[i].second >> V[i].first;
    }
    
    sort(V.begin(), V.end());
    int result = 0;
    for (pair<int, int> next: V) {
        int idx = -1;
        int Max = -1;
        for (int i = 0; i < K; i++) {
            if (R[i] < next.second) {
                if (Max < R[i]) {
                    Max = R[i];
                    idx = i;
                }
            }
        }
        
        if (idx != -1) {
            R[idx] = next.first;
            ++result;
        }
    }
    cout << result << "\n";

    return 0;
}

