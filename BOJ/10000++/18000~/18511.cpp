//
//  18511.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

static int N, K;
static int A[3];
static int result = -1;

void check(string tmp);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < K; i++) {
        check(to_string(A[i]));
    }
    
    cout << result << "\n";
    
    return 0;
}

void check(string tmp) {
    int x = stoi(tmp);
    if (x <= N) {
        result = max(result, x);
    }
    
    else {
        return;
    }
    
    for (int i = 0; i < K; i++) {
        check(tmp + to_string(A[i]));
    }
}
