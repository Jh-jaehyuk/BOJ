//
//  11780.cpp
//  BOJ
//
//  Created by J213h on 10/16/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N, M;
static int mdistance[101][101];
static int A[101][101];
static vector<int> result;

void DFS(int S, int E);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                mdistance[i][j] = 0;
            }
            
            else {
                mdistance[i][j] = (int)1e9;
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        mdistance[a][b] = min(mdistance[a][b], c);
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j]) {
                    A[i][j] = k;
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp = mdistance[i][j];
            
            cout << (tmp == (int)1e9 ? 0 : tmp) << " ";
        }
        cout << "\n";
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            result.clear();
            int dist = mdistance[i][j];
            
            if (dist == 0 || dist == (int)1e9) {
                cout << 0 << "\n";
            }
            
            else {
                DFS(i, j);
                cout << (int)result.size() << " ";
                for (int k : result) {
                    cout << k << " ";
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}

void DFS(int S, int E) {
    if (A[S][E] == 0) {
        result.push_back(S);
        result.push_back(E);
        return;
    }
    
    DFS(S, A[S][E]);
    result.pop_back();
    DFS(A[S][E], E);
}
