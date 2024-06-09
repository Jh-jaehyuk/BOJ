//
//  1422.cpp
//  BOJ
//
//  Created by J213h on 6/9/24.
//

#include <bits/stdc++.h>

using namespace std;

string S1[51], S2[51];

bool cmp1(string& i, string& j) {
    return i + j > j + i;
}

bool cmp2(string& i, string& j) {
    if (i.size() != j.size()) {
        return i.size() < j.size();
    }
    
    return i < j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int K, N;
    cin >> K >> N;
    
    for (int i = 0; i < K; i++) {
        cin >> S1[i];
        S2[i] = S1[i];
    }
    
    sort(S1, S1 + K, cmp1);
    sort(S2, S2 + K, cmp2);
    
    int flag = 0;
    for (int i = 0; i < K; i++) {
        cout << S1[i];
        if (!flag && S1[i] == S2[K - 1]) {
            flag = 1;
            for (int j = 0; j < N - K; j++) {
                cout << S1[i];
            }
        }
    }
    cout << "\n";
    
    return 0;
}

