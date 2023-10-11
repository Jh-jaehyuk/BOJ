//
//  16987.cpp
//  BOJ
//
//  Created by J213h on 10/11/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N;
static int S[8];
static int W[8];
static int result = 0;

bool Check(int idx);
void DFS(int idx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S[i] >> W[i];
    }
    
    DFS(0);
    
    cout << result << "\n";
    
    return 0;
}

bool Check(int idx) {
    for (int i = 0; i < N; i++) {
        if (i == idx) {
            continue;
        }
        
        if (S[i] > 0) {
            return true;
        }
    }
    
    return false;
}

void DFS(int idx) {
    if (idx == N || !Check(idx)) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] <= 0) {
                tmp++;
            }
        }
        
        result = max(result, tmp);
        return;
    }
    
    if (S[idx] <= 0) {
        DFS(idx + 1);
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (S[i] <= 0 || i == idx) {
            continue;
        }
        
        S[i] -= W[idx];
        S[idx] -= W[i];
        DFS(idx + 1);
        S[i] += W[idx];
        S[idx] += W[i];
    }
}
