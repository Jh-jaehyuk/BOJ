//
//  2250.cpp
//  BOJ
//
//  Created by J213h on 2023/09/15.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int root, left, right;
};

static int N, idx = 0;
static vector<Node> tree;
static vector<pair<int, int>> visited;

int BFS(int node);
void inorder(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    tree.resize(N + 1);
    visited.resize(N + 1);
    
    for (int i = 0; i <= N; i++) {
        Node tmp;
        tmp.root = -1;
        tmp.left = -1;
        tmp.right = -1;
        tree[i] = tmp;
        visited[i].first = -1;
        visited[i].second = -1;
    }
    
    for (int i = 0; i < N; i++) {
        int R, l, r;
        cin >> R >> l >> r;
        tree[R].left = l;
        tree[R].right = r;
        tree[l].root = N;
        tree[r].root = N;
    }
    
    int R = -1;
    for (int i = 1; i <= N; i++) {
        if (tree[i].root == -1) {
            R = i;
        }
    }
    
    int Max = BFS(R);
    inorder(R);
    
    int max_width = 0;
    int min_depth = 1e9;
    
    if (N == 1) {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    
    for (int j = 0; j <= Max; j++) {
        int min_val = 1e9;
        int max_val = 0;
        
        for (int i = 1; i <= N; i++) {
            if (j == visited[i].first) {
                min_val = min(min_val, visited[i].second);
                max_val = max(max_val, visited[i].second);
            }
        }
        
        if (max_width < (max_val - min_val + 1)) {
            min_depth = j + 1;
            max_width = max_val - min_val + 1;
        }
    }
    
    cout << min_depth << " " << max_width << "\n";
    
    return 0;
}

int BFS(int node) {
    int max_depth = 0;
    queue<int> myqueue;
    myqueue.push(node);
    visited[node].first = 0;
    
    while (!myqueue.empty()) {
        int Root = myqueue.front();
        int L = tree[Root].left;
        int R = tree[Root].right;
        myqueue.pop();
        
        if (L != -1) {
            if (visited[L].first == -1) {
                visited[L].first = visited[Root].first + 1;
                max_depth = max(visited[L].first, max_depth);
                myqueue.push(L);
            }
        }
        
        if (R != -1) {
            if (visited[R].first == -1) {
                visited[R].first = visited[Root].first + 1;
                max_depth = max(visited[R].first, max_depth);
                myqueue.push(R);
            }
        }
    }
    
    return max_depth;
}

void inorder(int node) {
    if (tree[node].left != -1) {
        inorder(tree[node].left);
    }
    
    visited[node].second = ++idx;
    
    if (tree[node].right != -1) {
        inorder(tree[node].right);
    }
}
