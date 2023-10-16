//
//  14588.cpp
//  BOJ
//
//  Created by J213h on 10/16/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<pair<int, int>> V;
static int mdistance[301][301];

bool check(pair<int, int> i, pair<int, int> j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    V.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    
    fill(&mdistance[0][0], &mdistance[300][301], (int)1e9);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                mdistance[i][j] = 0;
                continue;
            }
            
            if (check(V[i], V[j])) {
                mdistance[i][j] = 1;
                mdistance[j][i] = 1;
            }
        }
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                mdistance[i][j] = min(mdistance[i][j], mdistance[i][k] + mdistance[k][j]);
            }
        }
    }
    
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        
        cout << (mdistance[a][b] == (int)1e9 ? -1 : mdistance[a][b]) << "\n";
    }
    
    return 0;
}

bool check(pair<int, int> i, pair<int, int> j) {
    int l1, r1, l2, r2;
    if (j < i) {
        pair<int, int> tmp;
        tmp = i;
        i = j;
        j = tmp;
    }
    
    l1 = i.first;
    r1 = i.second;
    l2 = j.first;
    r2 = j.second;
    
    if (l1 <= l2 && l2 <= r1) {
        return true;
    }
    
    return false;
}
