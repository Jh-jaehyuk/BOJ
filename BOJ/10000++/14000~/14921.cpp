//
//  14921.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    
    sort(A.begin(), A.end());
    
    int s = 0;
    int e = N - 1;
    
    int result = 1e9;
    while (s < e) {
        int tmp = A[s] + A[e];
        
        if (abs(tmp) < abs(result)) {
            result = tmp;
        }
        
        if (tmp < 0) {
            s++;
        }
        
        else if (tmp > 0) {
            e--;
        }
        
        else {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << result << "\n";
    
    return 0;
}
