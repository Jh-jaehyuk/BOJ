//
//  1765.cpp
//  BOJ
//
//  Created by J213h on 2/2/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, p, q;
vector<int> parent;
vector<vector<int>> E;

int find_parent(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    
    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    parent.resize(N + 1);
    E.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        char flag;
        cin >> flag >> p >> q;
        
        if (flag == 'E') {
            E[p].push_back(q);
            E[q].push_back(p);
        }
        else {
            union_parent(p, q);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j: E[i]) {
            for (int k: E[j]) {
                union_parent(i, k);
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 1; j <= N; j++) {
            if (find_parent(parent[j]) == i) {
                flag = 1;
                break;
            }
        }
        
        if (flag) {
            result++;
        }
    }
    cout << result << "\n";
    
    return 0;
}

