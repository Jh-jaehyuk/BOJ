//
//  1275.cpp
//  BOJ
//
//  Created by J213h on 5/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long A[100001];
vector<long long> tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = A[start];
    }
    else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(int node, int start, int end, int index, int val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        A[index] = val;
        tree[node] = val;
        return;
    }
    update(node * 2, start, (start + end) / 2, index, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    
    if (left <= start && end <= right) {
        return tree[node];
    }
    
    long long lq = query(node * 2, start, (start + end) / 2, left, right);
    long long rq = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    
    return lq + rq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> Q;
    int h = (int)ceil(log2(N)) + 1;
    tree.resize(1 << h);
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    init(1, 1, N);
    
    for (int i = 0; i < Q; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        
        int temp = x;
        x = min(x, y);
        y = max(temp, y);
        
        cout << query(1, 1, N, x, y) << "\n";
        update(1, 1, N, a, b);
    }

    return 0;
}

