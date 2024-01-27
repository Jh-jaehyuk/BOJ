//
//  19638.cpp
//  BOJ
//
//  Created by J213h on 1/27/24.
//

#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, H, T;
    cin >> N >> H >> T;
    
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        pq.push(h);
    }
    
    int result = 0;
    for (int t = 0; t < T; t++) {
        int now = pq.top();
        if (now < H || now == 1) {
            break;
        }
        result++;
        pq.pop();
        pq.push(now / 2);
    }
    
    if (pq.top() >= H) {
        cout << "NO" << "\n" << pq.top() << "\n";
    }
    
    else {
        cout << "YES" << "\n" << result << "\n";
    }

    return 0;
}
