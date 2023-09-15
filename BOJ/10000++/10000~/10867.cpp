//
//  10867.cpp
//  BOJ
//
//  Created by J213h on 2023/09/15.
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
    A.erase(unique(A.begin(), A.end()), A.end());
    
    int l = (int)A.size();
    
    for (int i = 0; i < l; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}

