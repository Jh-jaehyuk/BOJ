//
//  10021.cpp
//  BOJ
//
//  Created by J213h on 4/18/24.
//

#include <bits/stdc++.h>

using namespace std;

# define ar array

int N, C;
vector<pair<int, int>> edges;
vector<ar<int, 3>> V;
int parent[2001];

int get_dist(pair<int, int>& a, pair<int, int>& b) {
    int x1, x2, y1, y2;
    x1 = a.first;
    y1 = a.second;
    x2 = b.first;
    y2 = b.second;
    
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int find_parent(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    a = parent[a];
    b = parent[b];
    
    if (a > b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> C;
    
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        int x, y;
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            int cost = get_dist(edges[i], edges[j]);
            V.push_back({cost, i, j});
        }
    }
    
    sort(V.begin(), V.end());
    int vs = (int)V.size();
    int cnt = 0;
    int result = 0;
    for (int i = 0; i < vs; i++) {
        if (V[i][0] < C) {
            continue;
        }
        int u, v, c;
        c = V[i][0];
        u = V[i][1];
        v = V[i][2];
        
        if (find_parent(u) != find_parent(v)) {
            union_parent(u, v);
            cnt++;
            result += c;
        }
    }
    cout << (cnt != N - 1 ? -1 : result) << "\n";

    return 0;
}

