//
//  4386.cpp
//  BOJ
//
//  Created by J213h on 10/16/23.
//

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int x, y;
    double v;
    
    bool operator < (const Edge& tmp) const {
        return v < tmp.v;
    }
};

static vector<int> parent;
static vector<pair<int, int>> points;
static vector<Edge> edges;

double get_distance(double x1, double y1, double x2, double y2);
int find_parent(int x);
void union_parent(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    parent.resize(N);
    
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    
    int ps = (int)points.size();
    for (int i = 0; i < ps; i++) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        
        for (int j = i + 1; j < ps; j++) {
            int x2 = points[j].first;
            int y2 = points[j].second;
            
            double dist = get_distance(x1, y1, x2, y2);
            Edge tmp = { i, j, dist };
            edges.push_back(tmp);
        }
    }
    
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    
    sort(edges.begin(), edges.end());
    
    int count = 0;
    int idx = 0;
    double result = 0;
    
    while (count < N - 1) {
        double dist = edges[idx].v;
        int idx1 = edges[idx].x;
        int idx2 = edges[idx].y;

        if (find_parent(idx1) != find_parent(idx2)) {
            union_parent(idx1, idx2);
            result += dist;
            count++;
        }
        idx++;
    }
    
    cout.precision(3);
    cout << fixed;
    
    cout << result << "\n";

    return 0;
}

int find_parent(int x) {
    if (x == parent[x]) {
        return x;
    }
    
    return parent[x] = find_parent(parent[x]);
}

double get_distance(double x1, double y1, double x2, double y2) {
    double x = (x1 - x2) * (x1 - x2);
    double y = (y1 - y2) * (y1 - y2);
    
    return sqrt(x + y);
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
