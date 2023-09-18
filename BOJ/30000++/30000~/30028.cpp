//
//  30028.cpp
//  BOJ
//
//  Created by J213h on 2023/09/18.
//

#include <bits/stdc++.h>

using namespace std;

static int N;
static vector<vector<int>> edges;
static vector<bool> dead;
static vector<int> leaf;
static vector<bool> visited;

int Centroid(int root, const vector<vector<int>> &edges, const vector<bool> &dead);

void find_leaf(int root);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    edges.resize(N);
    dead.resize(N);
    visited.resize(N);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int l = (int)leaf.size();
    
    cout << l - 1 << "\n";
    
    for (int i = 0; i < l - 1; i++) {
        
    }
    
    int centroid = Centroid(0, edges, dead);
    
    return 0;
}

int Centroid(int root, const vector<vector<int>> &edges, const vector<bool> &dead) {
    static vector<int> tree_size(edges.size());
    
    function<void (int, int)> get_size = [&](int u, int prev) {
        tree_size[u] = 1;
        
        for (auto v : edges[u]) {
            if (v != prev && !dead[v]) {
                get_size(v, u);
                tree_size[u] += tree_size[v];
            }
        }
    };
    
    get_size(root, -1);
    int n = tree_size[root];
    
    function<int (int, int)> DFS = [&](int u, int prev) {
        for (auto v : edges[u]) {
            if (v != prev && !dead[v]) {
                if (tree_size[v] > n / 2) {
                    return DFS(v, u);
                }
            }
        }
        
        return u;
    };
    
    return DFS(root, -1);
}

void find_leaf(int root) {
    visited[root] = true;
    
    if (edges[root].empty()) {
        leaf.push_back(root);
    }
    
    for (auto i : edges[root]) {
        if (!visited[i]) {
            find_leaf(i);
        }
    }
}
