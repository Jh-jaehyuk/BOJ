//
//  30026.cpp
//  BOJ
//
//  Created by J213h on 2023/09/18.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> edges;
static vector<int> parent;
static vector<pair<int, int>> result;

int find_parent(int x);
void union_parent(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    edges.resize(N + 1);
    parent.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> edges[i];
        parent[edges[i]] = i;
    }
    
    int prev = 1;
    int count = 0;
    int mana = 0;
    
    for (int i = 2; i <= N; i++) {
        if (find_parent(prev) != find_parent(i)) {
            count++;
            mana += (i - prev) * (i - prev);
            union_parent(prev, i);
            result.push_back(make_pair(prev, i));
            prev = i;
        }
    }
    
    cout << count << " " << mana << "\n";
    
    if (!result.empty()) {
        for (pair<int, int> i : result) {
            cout << i.first << " " << i.second << "\n";
        }
    }
    
    return 0;
}

int find_parent(int x) {
    if (parent[x] == x) {
        return x;
    }
    
    else {
        return parent[x] = find_parent(parent[x]);
    }
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    
    if (a != b) {
        parent[b] = a;
    }
}
