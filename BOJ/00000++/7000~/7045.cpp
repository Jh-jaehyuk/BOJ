//
//  7045.cpp
//  BOJ
//
//  Created by J213h on 2023/09/18.
//

#include <bits/stdc++.h>

using namespace std;

static int N;
static vector<vector<int>> edges;

vector<int> Centroid(const vector<vector<int>> &edges);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    vector<int> result = Centroid(edges);
    
    if (result.size() == 1) {
        cout << result[0] << "\n";
    }
    
    else {
        int x = result[0];
        int y = result[1];
        
        cout << min(x, y) << "\n";
        cout << max(x, y) << "\n";
    }
    
    return 0;
}

vector<int> Centroid(const vector<vector<int>> &edges) {
    int n = (int)edges.size();
    vector<int> centroid;
    vector<int> tree_size(n);
    
    function<void (int, int)> DFS = [&](int u, int prev) {
        tree_size[u] = 1;
        bool is_centroid = true;
        
        for (auto v : edges[u]) {
            if (v != prev) {
                DFS(v, u);
                tree_size[u] += tree_size[v];
                
                if (tree_size[v] > n / 2) {
                    is_centroid = false;
                }
            }
        }
        
        if (n - tree_size[u] > n / 2) {
            is_centroid = false;
        }
        
        if (is_centroid) {
            centroid.push_back(u + 1);
        }
    };
    
    DFS(0, -1);
    
    return centroid;
}
