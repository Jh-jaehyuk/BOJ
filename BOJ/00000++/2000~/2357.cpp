//
//  2357.cpp
//  BOJ
//
//  Created by J213h on 5/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
int A[100001];
vector<int> min_tree;
vector<int> max_tree;

void init(int node, int start, int end) {
    if (start == end) {
        min_tree[node] = A[start];
        max_tree[node] = A[start];
    }
    else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
        max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
    }
}

pair<int, int> query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return { 1e9 + 1, 0 };
    }
    else if (left <= start && end <= right) {
        return { min_tree[node], max_tree[node] };
    }
    else {
        pair<int, int> lq = query(node * 2, start, (start + end) / 2, left, right);
        pair<int, int> rq = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        return { min(lq.first, rq.first), max(lq.second, rq.second) };
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int M;
    cin >> N >> M;
    
    int h = (int)ceil(log2(N)) + 1;
    min_tree.resize(1 << h);
    max_tree.resize(1 << h);
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    init(1, 1, N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> ans = query(1, 1, N, a, b);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
