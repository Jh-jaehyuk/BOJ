//
//  12908.cpp
//  BOJ
//
//  Created by J213h on 5/29/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
long long xs, ys, xe, ye;
vector<pair<long long, long long>> V(8);
long long dist[8][8];

long long get_dist(pair<long long, long long>& i, pair<long long, long long>& j) {
    return abs(i.first - j.first) + abs(i.second - j.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> xs >> ys >> xe >> ye;
    fill_n(&dist[0][0], 8 * 8, INF);
    
    for (int i = 0; i < 8; i++) {
        dist[i][i] = 0;
    }
    
    V[0] = { xs, ys };
    V[1] = { xe, ye };
    
    for (int i = 2; i < 8; i++) {
        long long x, y;
        cin >> x >> y;
        V[i] = { x, y };
    }
    
    for (int i = 2; i <= 6; i+=2) {
        dist[i][i + 1] = min(dist[i][i + 1], 1LL * 10);
        dist[i + 1][i] = dist[i][i + 1];
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dist[i][j] = min(dist[i][j], get_dist(V[i], V[j]));
        }
    }
    
    for (int k = 0; k < 8; k++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    cout << dist[0][1] << "\n";

    return 0;
}
