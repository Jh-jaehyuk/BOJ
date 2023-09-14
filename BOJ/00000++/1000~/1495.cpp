//
//  1495.cpp
//  BOJ
//
//  Created by J213h on 2023/09/14.
//

#include <bits/stdc++.h>

using namespace std;

static int A[51];
static bool check[51][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, S, M;
    cin >> N >> S >> M;
    
    A[0] = S;
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    fill(&check[0][0], &check[50][1001], false);
    
    check[0][S] = true;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (check[i - 1][j]) {
                if (j + A[i] <= M) {
                    check[i][j + A[i]] = true;
                }
                
                if (j - A[i] >= 0) {
                    check[i][j - A[i]] = true;
                }
            }
        }
    }
    
    for (int i = M; i >= 0; i--) {
        if (check[N][i]) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    
    return 0;
}
