//
//  11931.cpp
//  BOJ
//
//  Created by J213h on 2023/09/15.
//

#include <bits/stdc++.h>

using namespace std;

static int A[1000001];

bool cmp(int i, int j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A + N, cmp);
    
    for (int i = 0; i < N; i++) {
        cout << A[i] << "\n";
    }
    
    return 0;
}

bool cmp(int i, int j) {
    return i > j;
}
