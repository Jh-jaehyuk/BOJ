//
//  Centroid Decomposition.cpp
//  BOJ
//
//  Created by J213h on 2023/09/18.
//

#include <bits/stdc++.h>

using namespace std;

struct centroid {
    int N;
    vector<int> tree_size, vis, par;
    vector<vector<int>> _edges, edges;
    
    centroid(int N) : N(N), tree_size(N), vis(N), _edges(N), edges(N), par(N) {}
    
    void add_edge(int u, int v) {
        _edges[u].push_back(v);
    }
    
    int get_size(int cur, int p) {
        tree_size[cur] = 1;
        
        for (int to : _edges[cur]) {
            if (to != p && !vis[to]) {
                tree_size[cur] += get_size(to, cur);
            }
        }
        
        return tree_size[cur];
    }
    
    int get_centroid(int cur, int p, int cap) {
        for (int to : _edges[cur]) {
            if (to != p && !vis[to] && tree_size[to] * 2 > cap) {
                return get_centroid(to, cur, cap);
            }
        }
        
        return cur;
    }
    
    int build_tree(int cur, int p = -1) {
        cur = get_centroid(cur, -1, get_size(cur, -1));
        par[cur] = p;
        vis[cur] = 1;
        for (int to : _edges[cur]) {
            if (!vis[to]) {
                to = build_tree(to, cur);
                edges[cur].push_back(to);
                edges[to].push_back(cur);
            }
        }

        return cur;
    }
};


int main() {
    
    return 0;
}
