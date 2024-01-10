//
//  31217.cpp
//  BOJ
//
//  Created by J213h on 1/10/24.
//

#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;
int A[100001];
long long result = 0;

long long get_val(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        A[u]++;
        A[v]++;
    }
    
    for (int i = 1; i <= N; i++) {
        result += get_val(A[i]);
        result %= MOD;
    }
    cout << result << "\n";
    
    return 0;
}

long long get_val(int n) {
    if (n < 2) {
        return 0;
    }
    return (n * (n - 1) * (n - 2)) / 6;
}

