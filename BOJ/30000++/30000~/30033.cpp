//
//  30033.cpp
//  BOJ
//
//  Created by J213h on 2023/09/18.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    A.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int result = 0;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        if (x >= A[i]) {
            result++;
        }
    }
    cout << result << "\n";
    
    return 0;
}
