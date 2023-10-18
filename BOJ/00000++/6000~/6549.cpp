//
//  6549.cpp
//  BOJ
//
//  Created by J213h on 10/18/23.
//

#include <bits/stdc++.h>

using namespace std;

static int H[100001];

void Solve(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        int N;
        cin >> N;
        
        if (N == 0) {
            break;
        }
        
        Solve(N);
    }
    
    return 0;
}

void Solve(int n) {
    stack<int> mystack;
    
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }
    H[n] = -1;
    
    long long result = 0;
    for (int i = 0; i <= n; i++) {
        while (!mystack.empty() && H[i] < H[mystack.top()]) {
            int idx = mystack.top();
            mystack.pop();
            int w = -1;
            
            if (mystack.empty()) {
                w = i;
            }
            
            else {
                w = i - mystack.top() - 1;
            }
            
            result = max(result, 1LL * H[idx] * w);
        }
        
        mystack.push(i);
    }
    
    cout << result << "\n";
}
