//
//  2798.cpp
//  BOJ
//
//  Created by J213h on 10/11/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static int A[101];
static int result = 0;
static int check[101];

void DFS(int idx, int depth);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    DFS(0, 0);
    cout << result << "\n";
    
    return 0;
}

void DFS(int idx, int depth) {
    if (depth == 3) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            if (check[i]) {
                tmp += A[i];
            }
        }
        if (tmp <= M) {
            result = max(result, tmp);
        }
        
        return;
    }
    
    for (int i = idx; i < N; i++) {
        if (check[i]) {
            continue;
        }
        
        check[i] = 1;
        DFS(i, depth + 1);
        check[i] = 0;
    }
}

