//
//  1689.cpp
//  BOJ
//
//  Created by J213h on 9/17/24.
//

#include <bits/stdc++.h>

using namespace std;

pair<int, int> A[1000001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    sort(A, A + N);
    
    int ans = 1;
    pq.push(A[0].second);
    
    for (int i = 1; i < N; i++) {
        while (!pq.empty() && pq.top() <= A[i].first) {
            pq.pop();
        }
        pq.push(A[i].second);
        ans = max(ans, (int)pq.size());
    }
    
    cout << ans << "\n";
    
    return 0;
}
