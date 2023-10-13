//
//  6497.cpp
//  BOJ
//
//  Created by J213h on 10/13/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge& tmp) const {
        return v > tmp.v;
    }
} Edge;

static int N, M;
static vector<int> parent;

int find_parent(int x);
void union_parent(int a, int b);
void Solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        Solve();
    }

    return 0;
}

int find_parent(int x) {
    if (x == parent[x]) {
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

void Solve() {
    parent.resize(N);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    
    int total = 0;
    for (int i = 0; i < M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        total += v;
        pq.push(Edge{ s, e, v });
    }
    
    int count = 0;
    int result = 0;
    
    while (count < N - 1) {
        Edge now = pq.top();
        pq.pop();
        
        if (find_parent(now.s) != find_parent(now.e)) {
            union_parent(now.s, now.e);
            result += now.v;
            count++;
        }
    }
    
    cout << total - result << "\n";
}
