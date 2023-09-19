//
//  30026.cpp
//  BOJ
//
//  Created by J213h on 2023/09/18.
//

#include <bits/stdc++.h>

using namespace std;

static int N;
static vector<int> A;
static vector<int> parent;
static vector<bool> visited;
static vector<vector<int>> cycle_decomposition;
static vector<pair<int, int>> result;

void DFS(int node, int count, int start);
int find_parent(int x);
void union_parent(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    A.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);
    cycle_decomposition.resize(N + 1);
    
    fill(visited.begin(), visited.end(), false);
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        parent[i] = i;
    }
    
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i, count, i);
            count++;
        }
    }
    
    if (count == 1) {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }
    
    int min_mana = 0;
    int use_magic = 0;
    
    int prev = 1;
    for (int i = 2; i <= N; i++) {
        if (find_parent(prev) != find_parent(i)) {
            union_parent(prev, i);
            min_mana += (i - prev) * (i - prev);
            use_magic++;
            result.push_back(make_pair(A[prev], A[i]));
        }
        prev = i;
    }
    
    cout << use_magic << " " << min_mana << "\n";
    
    for (auto i : result) {
        cout << i.first << " " << i.second << "\n";
    }
    
    return 0;
}

void DFS(int node, int count, int start) {
    visited[node] = true;
    cycle_decomposition[count].push_back(node);
    
    if (find_parent(start) != find_parent(node)) {
        union_parent(start, node);
    }
    
    if (!visited[A[node]]) {
        DFS(A[node], count, start);
    }
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
