//
//  31997.cpp
//  BOJ
//
//  Created by J213h on 9/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, T;
vector<int> A[200001];
vector<int> B[200001];
vector<vector<int>> V(200001);
int check[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> T;
    
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        A[a].push_back(i);
        B[b].push_back(i);
    }
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    int ans = 0;
    fill_n(check, N + 1, 0);
    
    for (int i = 0; i < T; i++) {
        for (int j: B[i]) {
            check[j] = 0;
            
            for (int k: V[j]) {
                if (check[k]) {
                    ans--;
                }
            }
        }
        
        for (int j: A[i]) {
            check[j] = 1;
            
            for (int k: V[j]) {
                if (check[k]) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
